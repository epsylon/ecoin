# ECOin

![ECOin](ecoin/src/qt/res/icons/ecoin.png)

**P2P Ecological Crypto-Currency** — A long-term energy-efficient digital economy strategy

[Website](https://ecoin.03c8.net) | [Block Explorer](https://ecoin.03c8.net/blockexplorer) | [SolarNET.HuB](https://solarnethub.com)

----------

## Overview

[ECOin](https://ecoin.03c8.net) is a P2P crypto-currency with the goal of providing **a long-term energy-efficient digital economy strategy**.

It uses the [SCRYPT](https://en.wikipedia.org/wiki/Scrypt) algorithm and is **the only crypto in the market that implements three different mining systems simultaneously**:

- [Proof-Of-Work (PoW)](https://en.wikipedia.org/wiki/Proof_of_work) — Traditional CPU mining
- [Proof-Of-Stake (PoS)](https://en.wikipedia.org/wiki/Proof_of_stake) — Variable interest based on coin age
- [Proof-Of-Transaction (PoT)](https://cryptoticker.io/en/proof-transaction) — Mining by matching address segment to block hash on transactions > 500 ECO

ECOin includes [Zerocoin](https://en.wikipedia.org/wiki/Zerocoin_protocol) privacy extensions for enhanced transaction privacy.

----------

## Specifications

| Parameter         | Value                            |
| ----------------- | -------------------------------- |
| **Algorithm**     | SCRYPT                           |
| **Mining**        | PoW + PoS + PoT (triple mining)  |
| **Block Time**    | 2 minutes                        |
| **Total Supply**  | ~225,000,000 ECO                 |
| **PoW Halving**   | Every 262,800 blocks             |
| **PoT Threshold** | Transactions > 500 ECO           |
| **PoT Reward**    | 50% of block subsidy             |
| **P2P Port**      | 7408                             |
| **RPC Port**      | 7474                             |
| **Privacy**       | Zerocoin protocol                |
| **DNS Seed**      | ecoinseed.03c8.net:5353          |

----------

## Rewards

Proof-Of-Work Mining (PoW) rewards with halving every 262,800 blocks:

| Block Range        | Reward                             |
| ------------------ | ---------------------------------- |
| 1 - 3,263          | Random 500-5,000 (1 min blocks)    |
| 3,264 - 22,000     | Random 1,000-10,000 (2 min blocks) |
| 22,001 - 34,750    | 5,000 ECO                          |
| 34,751 - 39,791    | 2,500 ECO                          |
| 39,792 - 44,832    | 1,250 ECO                          |
| 44,833 - 49,873    | 625 ECO                            |
| 49,874 - 54,914    | 312.50 ECO                         |
| 54,915 - 59,955    | 156.25 ECO                         |
| 59,956 - 64,996    | 78.125 ECO                         |
| 64,997 - 70,037    | 39.0625 ECO                        |
| 70,038 - 332,838   | 20 ECO                             |

----------

## Translations

ECOin wallet is available in 10 languages:

| Code  | Language   |
| ----- | ---------- |
| en    | English    |
| ru    | Russian    |
| ca    | Catalan    |
| de    | German     |
| es    | Spanish    |
| eu    | Basque     |
| fr    | French     |
| it    | Italian    |
| pt    | Portuguese |
| zh_CN | Chinese    |

----------

## Building

ECOin builds on GNU/Linux, Windows (MinGW), and macOS. See [INSTALL](./ecoin/INSTALL) for detailed instructions.

### Quick Start (Debian/Ubuntu)

```bash
# Install dependencies
sudo apt-get install build-essential libssl-dev libdb5.3-dev libdb5.3++-dev \
  libleveldb-dev qt5-qmake qtbase5-dev

# Clone
git clone https://github.com/epsylon/ecoin
cd ecoin/ecoin/

# Build Wallet (GUI)
qmake USE_UPNP=- USE_IPV6=-
make
./ecoin-qt

# Build Daemon (headless server)
cd src/
make -f makefile.linux USE_UPNP=- USE_IPV6=-
strip ecoind
./ecoind
```

### Pre-built Packages

Pre-built `.deb` packages are available for:

- **ANDROID** (APK) — Wallet + Daemon
- **AMD64** (x86_64) — Wallet + Daemon
- **ARM64** (aarch64) — Daemon

See the [Releases](https://github.com/epsylon/ecoin/releases) page.

----------

## Configuration

Create `~/.ecoin/ecoin.conf` (chmod 600):

```ini
rpcuser=ecoinrpc
rpcpassword=<YOUR_SECURE_PASSWORD>
rpcallowip=127.0.0.1
testnet=0
noirc=1
listen=1
server=1
daemon=1
addnode=46.163.118.220
```

----------

## Bootstrap.dat

ECOin is using a bootstrap.dat binary file containing blockchain data, from the genesis block through first checkpoint that allows new wallets
to synchronize the first blocks without the need to connect to the network or wait for the peers to send the beginning of the blockchain.

This file must be placed next to the configuration file (`~/.ecoin/ecoin.conf`).

Download [bootstrap.dat](https://ecoin.03c8.net/ecoin/bootstrap.dat).

## Mining

Solo mining with the built-in CPU miner:

```bash
# Terminal 1: Start wallet or daemon
./ecoin-qt
# or: ./ecoind -daemon

# Terminal 2: Start miner
cd miner/ && sh build.sh
./cpuminer -o http://127.0.0.1:7474 -O ecoinrpc:<password> --coinbase-addr=<YOUR_ECOIN_ADDRESS>
```

See [MINING](./ecoin/doc/MINING.txt) and [REWARDS](./ecoin/doc/REWARDS.txt) for details.

----------

## SolarNET.HuB Integration

ECOin is the native currency of the [SolarNET.HuB](https://solarnethub.com/) ecosystem — a sustainable multilayer tool-artifact for data privacy and project networking.

Within the ecosystem, ECOin enables:

- **Universal Basic Income (UBI)** — Weekly ECOin allocations for ecosystem participants
- **Solar Mining** — PoW mining powered by solar panels via the [SNH-KIT](https://wiki.solarnethub.com/kit/hardware)
- **P2P Marketplace** — Exchange goods and services priced in ECO
- **Governance** — Voting and participation in the 9-House governance system

----------

## Screenshots

Wallet:

![Wallet](https://ecoin.03c8.net/ecoin/ecoin_wallet_zoom.png)

Settings:

![Settings](https://ecoin.03c8.net/ecoin/ecoin_settings_zoom.png)

Debug Console:

![Debug Console](https://ecoin.03c8.net/ecoin/ecoin_debug_zoom.png)

Mining:

![Mining](https://ecoin.03c8.net/ecoin/ecoin_mining_zoom.png)

Block Explorer:

![Block Explorer](https://ecoin.03c8.net/ecoin/ecoin-blockexplorer.png)

----------

## License

ECOin is free software released under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html).

----------

## Contact

- **Author**: psy ([epsylon@riseup.net](mailto:epsylon@riseup.net))
- **Web**: [03c8.net](https://03c8.net)
- **Code**: [code.03c8.net/epsylon](https://code.03c8.net/epsylon) | [github.com/epsylon](https://github.com/epsylon)

## Donate

| Currency | Address |
| -------- | ------- |
| Bitcoin | `19aXfJtoYJUoXEZtjNwsah2JKN9CK5Pcjw` |
| ECOin | `ETsRCBzaMawx3isvb5svX7tAukLdUFHKze` |
