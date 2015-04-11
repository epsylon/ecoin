Ecoin (ECO) -> http://myecoin.net

Scrypt Proof of Work/Proof of Stake Hybrid with Proof-of-Transaction

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

There is no maximum number of coins, through the estimated coinbase size will be roughly 225 million ECO.

Proof-Of-Stake Mining (POS) - Variable interest based on coin age

Proof-Of-Transaction Mining (POT) - Mining by matching address segment to block hash (on tansactions greater than 500 coins), 50% of the block subsidy

Increased security on Proof-of-Work blocks though verification of coinbase tx value, size, and destinations of coinbase transactions via Proof-Of-Transaction checking.

Default P2P Port: 7408

Default RPC Port: 7474

It is recomended that you use the official builds, only from the official Github repository to minimize the chance of malware, and ensure you are using the correct dependencies.

If you wish to build manually:

Build Dependencies - Please to not use other versions

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





