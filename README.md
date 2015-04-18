==================================
Ecoin (ECO) -> http://myecoin.net
==================================

Warning: This code is experimental and can be unstable.

==================================================================

- Algorithm: Scrypt
- Mining system: PoW+PoS+PoT
- Num Coins: There is no maximum number of coins, through the estimated coinbase size will be roughly 225 million ECO.

==============================

Random Proof-Of-Work Mining (POW) Rewards (halving every 262,800 blocks)

|Block                 | Reward                                   |
|----------------------|------------------------------------------|
|Block 1     - 3263:   | Random 500 5000 (1 minute blocks)        |
|Block 3264  - 22000:  | Random 1000 10000 (2 minute blocks)      |
|Block 22001 - 34750:  | Static reward 5000                       |
|Block 34751 - 39791:  | Static reward 2500                       |
|Block 39792 - 44832:  | Static reward 1250                       |
|Block 44833 - 49873:  | Static reward 625                        |
|Block 49874 - 54914:  | Static reward 312.50                     |
|Block 54915 - 59955:  | Static reward 156.25                     |
|Block 59956 - 64996:  | Static reward 78.125                     |
|Block 64997 - 70037:  | Static reward 39.0625                    |
|Block 70038 - 332838: | static reward 20                         |

Halving every 262800 blocks

--------------------------------------------------------------------

Proof-Of-Stake Mining (POS) - Variable interest based on coin age

--------------------------------------------------------------------

Proof-Of-Transaction Mining (POT) - Mining by matching address segment to block hash (on tansactions greater than 500 coins), 50% of the block subsidy

Increased security on Proof-of-Work blocks though verification of coinbase tx value, size, and destinations of coinbase transactions via Proof-Of-Transaction checking.

----------------------------

Default P2P Port: 7408

Default RPC Port: 7474

----------------------------

It is recomended that you use the official builds, only from the official Github repository to minimize the chance of malware, and ensure you are using the correct dependencies. Build Dependencies - Please to not use other versions:

- "openssl-1.0.1g.tar.gz"
- "db-6.0.20.NC.tar.gz"
- "miniupnpc-1.8.tar.gz"
- "zlib-1.2.8.tar.gz"
- "libpng-1.6.8.tar.gz"
- "qrencode-3.4.3.tar.bz2"
- "boost_1_55_0.tar.bz2"
- "boost-mingw-gas-cross-compile-2013-03-03.patch"
- "qt-everywhere-opensource-src-4.8.3.tar.gz"

NOTE: For building on Linux, use the file makefile.linux (not the traditional makefile.unix)

-------------------------------------------------

To build daemon:

cd src/

makefile.linux USE_UPNP=- (or USE_UPNP=0)

strip ecoind

To launch it:

./ecoind

---------------------------------

To build wallet:

cd ..

qmake USE_UPNP=- (or USE_UPNP=0)

make

To launch it:

./ecoin-qt

-------------------------------------------------

Configuration example (/home/$USER/.ecoin/ecoin.conf)

rpcuser = ecoinrpc

rpcpassword = <your password here>

noirc = 1

listen = 1

server = 1

addnode = 176.28.23.46 #myecoin.net

==================================================================

Contact: epsylon[AT]riseup.net

==============================

-----BEGIN PGP PUBLIC KEY BLOCK-----
Version: GnuPG v1

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
tw==
=ZtHL

-----END PGP PUBLIC KEY BLOCK-----

==================================================================
