// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef __CRYPTER_H__
#define __CRYPTER_H__

#include "allocators.h" /* for SecureString */
#include "key.h"
#include "serialize.h"

const unsigned int WALLET_CRYPTO_KEY_SIZE = 32;
const unsigned int WALLET_CRYPTO_SALT_SIZE = 8;

class CMasterKey
{
public:
    std::vector<unsigned char> vchCryptedKey;
    std::vector<unsigned char> vchSalt;
    // 0 = EVP_sha512()
    // 1 = scrypt()
    unsigned int nDerivationMethod;
    unsigned int nDeriveIterations;
    std::vector<unsigned char> vchOtherDerivationParameters;

    IMPLEMENT_SERIALIZE
    (
        READWRITE(vchCryptedKey);
        READWRITE(vchSalt);
        READWRITE(nDerivationMethod);
        READWRITE(nDeriveIterations);
        READWRITE(vchOtherDerivationParameters);
    )
    CMasterKey()
    {
        // 25000 rounds is just under 0.1 seconds on a 1.86 GHz Pentium M
        // ie slightly lower than the lowest hardware we need bother supporting
        nDeriveIterations = 25000;
        nDerivationMethod = 1;
        vchOtherDerivationParameters = std::vector<unsigned char>(0);
    }

    CMasterKey(unsigned int nDerivationMethodIndex)
    {
        switch (nDerivationMethodIndex)
        {
            case 0: // sha512
            default:
                nDeriveIterations = 25000;
                nDerivationMethod = 0;
                vchOtherDerivationParameters = std::vector<unsigned char>(0);
            break;

            case 1: // scrypt+sha512
                nDeriveIterations = 10000;
                nDerivationMethod = 1;
                vchOtherDerivationParameters = std::vector<unsigned char>(0);
            break;
        }
    }

};

typedef std::vector<unsigned char, secure_allocator<unsigned char> > CKeyingMaterial;

class CCrypter
{
private:
    unsigned char chKey[WALLET_CRYPTO_KEY_SIZE];
    unsigned char chIV[WALLET_CRYPTO_KEY_SIZE];
    bool fKeySet;

public:
    bool SetKeyFromPassphrase(const SecureString &strKeyData, const std::vector<unsigned char>& chSalt, const unsigned int nRounds, const unsigned int nDerivationMethod);
    bool Encrypt(const CKeyingMaterial& vchPlaintext, std::vector<unsigned char> &vchCiphertext);
    bool Decrypt(const std::vector<unsigned char>& vchCiphertext, CKeyingMaterial& vchPlaintext);
    bool SetKey(const CKeyingMaterial& chNewKey, const std::vector<unsigned char>& chNewIV);

    void CleanKey()
    {
        OPENSSL_cleanse(&chKey, sizeof chKey);
        OPENSSL_cleanse(&chIV, sizeof chIV);
        fKeySet = false;
    }

    CCrypter()
    {
        fKeySet = false;
        LockedPageManager::instance.LockRange(&chKey[0], sizeof chKey);
        LockedPageManager::instance.LockRange(&chIV[0], sizeof chIV);
    }

    ~CCrypter()
    {
        CleanKey();
        LockedPageManager::instance.UnlockRange(&chKey[0], sizeof chKey);
        LockedPageManager::instance.UnlockRange(&chIV[0], sizeof chIV);
    }
};

bool EncryptSecret(CKeyingMaterial& vMasterKey, const CSecret &vchPlaintext, const uint256& nIV, std::vector<unsigned char> &vchCiphertext);
bool DecryptSecret(const CKeyingMaterial& vMasterKey, const std::vector<unsigned char> &vchCiphertext, const uint256& nIV, CSecret &vchPlaintext);

#endif
