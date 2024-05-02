#include "miner.h"
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>
#include <openssl/evp.h> // Include for EVP functions

#include "sha3/sph_skein.h"

void skeinhash(void *state, const void *input)
{
    sph_skein512_context ctx_skein;
    uint32_t hash[16];

    sph_skein512_init(&ctx_skein);
    sph_skein512(&ctx_skein, input, 80);
    sph_skein512_close(&ctx_skein, hash);

    unsigned char hash2[32];
    SHA256_CTX sha256;
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new(); // Create a new message digest context

    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL); // Initialize the digest context with SHA256
    EVP_DigestUpdate(mdctx, hash, sizeof(hash)); // Update the digest with the hash
    EVP_DigestFinal_ex(mdctx, hash2, NULL); // Finalize the digest and store the result in hash2

    EVP_MD_CTX_free(mdctx); // Free the message digest context

    memcpy(state, hash2, 32);
}

int scanhash_skein(int thr_id, struct work *work, uint32_t max_nonce, uint64_t *hashes_done)
{
    uint32_t _ALIGN(128) hash32[8];
    uint32_t _ALIGN(128) endiandata[20];
    uint32_t *pdata = work->data;
    uint32_t *ptarget = work->target;

    const uint32_t Htarg = ptarget[7];
    const uint32_t first_nonce = pdata[19];

    uint32_t n = first_nonce;

    for (int i = 0; i < 19; i++)
    {
        be32enc(&endiandata[i], pdata[i]);
    };

    do
    {
        be32enc(&endiandata[19], n);
        skeinhash(hash32, endiandata);
        if (hash32[7] < Htarg && fulltest(hash32, ptarget))
        {
            work_set_target_ratio(work, hash32);
            *hashes_done = n - first_nonce + 1;
            pdata[19] = n;
            return true;
        }
        n++;

    } while (n < max_nonce && !work_restart[thr_id].restart);

    *hashes_done = n - first_nonce + 1;
    pdata[19] = n;

    return 0;
}

