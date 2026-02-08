# ECOin — Auditoría y Revisión Completa del Código

> **Auditor**: s1ko (s1ko@riseup.net) — OraKlaud (Staff Engineer Mode)  
> **Fecha**: 2025-02-08  
> **Rama revisada**: `fix/display-version-mismatch` (commit `9fe471d66`)  
> **Proyecto**: ECOin — P2P Cryptocurrency (GPLv3)  
> **Autor**: epsylon@riseup.net (https://ecoin.03c8.net)  
> **Repositorio**: epsylon/ecoin

---

## Tabla de Contenidos

1. [Resumen Ejecutivo](#1-resumen-ejecutivo)
2. [Arquitectura del Sistema](#2-arquitectura-del-sistema)
3. [Fix Actual de la Rama](#3-fix-actual-de-la-rama)
4. [Hallazgos Críticos (P0)](#4-hallazgos-críticos-p0)
5. [Hallazgos de Seguridad (P0-P1)](#5-hallazgos-de-seguridad-p0-p1)
6. [Hallazgos de Eficiencia (P1-P2)](#6-hallazgos-de-eficiencia-p1-p2)
7. [Hallazgos de Arquitectura (P2)](#7-hallazgos-de-arquitectura-p2)
8. [Hallazgos de Claridad (P3-P4)](#8-hallazgos-de-claridad-p3-p4)
9. [Revisión de Configuración en Producción](#9-revisión-de-configuración-en-producción)
10. [Modernización Propuesta](#10-modernización-propuesta)
11. [Mejoras de Red e Infraestructura](#11-mejoras-de-red-e-infraestructura)
12. [Recomendaciones Priorizadas](#12-recomendaciones-priorizadas)
13. [Conclusión](#13-conclusión)

---

## 1. Resumen Ejecutivo

ECOin es una criptomoneda P2P basada en SCRYPT con un sistema innovador de **triple minería**: Proof-of-Work (PoW), Proof-of-Stake (PoS) y Proof-of-Transaction (PoT). El código base demuestra un trabajo serio y funcional, con actualizaciones recientes para compatibilidad con librerías modernas (Boost 1.68, OpenSSL 3.x, Qt5).

### Fortalezas
- **PoT (Proof-of-Transaction)**: Concepto original que incentiva el uso real de la moneda
- **Wallet encryption modernizada**: Uso correcto de EVP API (no el stack-based deprecado)
- **Soporte multi-plataforma**: Linux, Windows, macOS con build system funcional
- **Módulo de CPU miner integrado**: Incluye `cpuminer` para PoW independiente

### Áreas de Mejora Identificadas
- **20 hallazgos** categorizados por prioridad (P0 a P5)
- **3 críticos** que afectan funcionalidad o seguridad
- **4 de seguridad** que requieren atención
- **9 de arquitectura/eficiencia/claridad**
- **4 de configuración en producción** (revisión de `ecoin.conf`)

---

## 2. Arquitectura del Sistema

### Versiones

| Componente | Versión |
|---|---|
| CLIENT_VERSION (clientversion.h) | 0.7.5.7 |
| DISPLAY_VERSION (version.h) | 0.7.5.7 ✅ (fix aplicado) |
| VERSION en ecoin-qt.pro | **0.0.4** ⚠️ (inconsistente) |
| PROTOCOL_VERSION | 70009 |
| MIN_PROTO_VERSION | 70007 |
| DATABASE_VERSION | 70507 |
| CLIENT_NAME | "Ikujam" |
| Block Version | 6 |

### Red

| Parámetro | Valor |
|---|---|
| P2P Port | 7408 (testnet: 17408) |
| RPC Port | 7474 (testnet: 17474) |
| Max Connections | 125 (16 outbound) |
| Algorithm | SCRYPT |
| Target Spacing | 2 minutos |
| Coinbase Maturity | 12 bloques |
| Stake Min Age | 30 días |
| Stake Max Age | 90 días |
| MAX_MONEY | 50,000,000,000 * COIN |

### Estructura de Archivos Core (~11K LoC relevantes)

```
src/
├── main.cpp          # 4078 líneas - Core blockchain, PoW/PoS/PoT rewards, validation
├── wallet.cpp        # 2506 líneas - Wallet, coin selection, staking, encryption
├── miner.cpp         #  ~650 líneas - Block creation, PoW/PoT mining
├── kernel.cpp        #  ~350 líneas - PoS kernel computation
├── init.cpp          #  ~500 líneas - Initialization, config, startup
├── net.cpp           # Networking layer
├── irc.cpp           # IRC peer discovery (DEFUNCT)
├── checkpoints.cpp   # Hardened + sync checkpoints
├── crypter.cpp       # AES-256-CBC wallet encryption
├── ecoinrpc.cpp      # JSON-RPC server
├── version.h         # Protocol/display versions
├── clientversion.h   # Client version macros
├── main.h            # Core data structures
└── allocators.h      # Secure memory allocation
```

### Esquema de Recompensas PoW

| Rango de Bloques | Recompensa | Notas |
|---|---|---|
| 0 - 3295 | 500-5000 ECO (random) | Era de recompensa aleatoria |
| 3296 - 22000 | 1000-10000 ECO (random) | Recompensa duplicada por bloques de 2 min |
| 22001 - 34750 | 5000 ECO fijo | Era de recompensa plana |
| 34751 - 70037 | 2500 ECO halving/5040 | Halving rápido (~1 semana) |
| 70038+ | 20 ECO halving/262800 | Halving lento (~1 año) |

### Esquema PoT (Proof-of-Transaction)

| Rango de Bloques | Split Miner/POT | Búsqueda | Min. TX |
|---|---|---|---|
| 1 - 12400 | 50/50 | SearchTerm (3 chars) | >500 ECO |
| 12401 - 22000 | 50/50 | SearchTerm (3 chars) | >500 ECO |
| 22001 - 57000 | 50/50 | SearchTerm (3 chars) | >500 ECO |
| 57001+ | 95/5 | SearchTermV2 (2 chars) | >1 ECO |

---

## 3. Fix Actual de la Rama

**Rama**: `fix/display-version-mismatch`  
**Commit**: `9fe471d66` — "fix: sync DISPLAY_VERSION with CLIENT_VERSION (0.4.5.7 → 0.7.5.7)"

### Cambio

```diff
// version.h
- #define DISPLAY_VERSION_MINOR       4
+ #define DISPLAY_VERSION_MINOR       7
```

**Valoración**: ✅ Correcto. El `DISPLAY_VERSION` ahora está sincronizado con `CLIENT_VERSION` (0.7.5.7). Sin embargo, queda la inconsistencia con `ecoin-qt.pro VERSION = 0.0.4` (ver hallazgo #10).

---

## 4. Hallazgos Críticos (P0)

### 🔴 #1 — IRC Seeder apunta a Freenode (SERVICIO EXTINTO)

**Ubicación**: `src/irc.cpp` línea ~189

```cpp
CService addrConnect("162.213.39.42", 6697); // irc.freenode.net (10/01/2021)
CService addrIRC("irc.freenode.net", 6697, true);
```

→ **ACTUAL**: El peer discovery por IRC intenta conectar a `irc.freenode.net` que fue cerrado en 2021  
→ **IMPACTO**: Los nodos nuevos no pueden descubrir peers por IRC. Si no tienen peers manuales o DNS seeds, no se conectan a la red  
→ **ESFUERZO**: 2-4 horas  
→ **RECOMENDACIÓN**:
  1. **Opción A** (Quick): Reemplazar con `irc.libera.chat:6697` (sucesor de Freenode)
  2. **Opción B** (Mejor): Implementar DNS seed nodes como mecanismo primario y deprecar IRC
  3. **Opción C** (Ideal): Ambas + lista de nodos seed hardcodeados como fallback

```cpp
// Propuesta: Actualizar a Libera.Chat como mínimo
CService addrConnect("irc.libera.chat", 6697, true);
```

---

### 🔴 #2 — bitdb.Open() llamado DOS VECES en init.cpp

**Ubicación**: `src/init.cpp` — función `AppInit2()`

La función `bitdb.Open(GetDataDir())` se llama dos veces: primero alrededor de la línea donde se verifica la integridad de la DB, y luego ~55 líneas después, justo antes de cargar el block index.

```cpp
// Primera vez - verificación de integridad:
if (!bitdb.Open(GetDataDir()))
{
    string msg = strprintf(_("Error initializing database environment %s!"
                             " To recover, BACKUP THAT DIRECTORY, then remove"
                             " everything from it except for wallet.dat."), strDataDir.c_str());
    return InitError(msg);
}

// ... salvage wallet, verify wallet ...

// SEGUNDA VEZ - antes del block index (REDUNDANTE):
if (!bitdb.Open(GetDataDir()))
{
    string msg = strprintf(_("Error initializing database environment %s!"
                             " To recover, BACKUP THAT DIRECTORY, then remove"
                             " everything from it except for wallet.dat."), strDataDir.c_str());
    return InitError(msg);
}
```

→ **ACTUAL**: Berkeley DB environment se abre dos veces; la segunda llamada puede causar comportamiento indefinido  
→ **IMPACTO**: Potencial corrupción de base de datos en condiciones específicas  
→ **ESFUERZO**: 5 minutos  
→ **RECOMENDACIÓN**: Eliminar la segunda llamada a `bitdb.Open()`. El primer bloque ya abre la DB correctamente.

---

### 🔴 #3 — Solo existe el checkpoint del bloque génesis

**Ubicación**: `src/checkpoints.cpp`

```cpp
static MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    ( 0, std::make_pair(hashGenesisBlock, 1610833657) )
;
```

→ **ACTUAL**: No hay checkpoints hardcodeados más allá del bloque 0  
→ **IMPACTO**: Nodos nuevos son vulnerables a ataques de cadena alternativa durante la sincronización inicial. Sin checkpoints, un atacante podría servir una cadena completamente falsa  
→ **ESFUERZO**: 30 minutos  
→ **RECOMENDACIÓN**: Añadir checkpoints cada ~10,000 bloques hasta la altura actual:

```cpp
static MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    ( 0,     std::make_pair(hashGenesisBlock, 1610833657) )
    ( 10000, std::make_pair(uint256("0x<hash_del_bloque_10000>"), <timestamp>) )
    ( 20000, std::make_pair(uint256("0x<hash_del_bloque_20000>"), <timestamp>) )
    ( 50000, std::make_pair(uint256("0x<hash_del_bloque_50000>"), <timestamp>) )
    // ... hasta la altura actual
;
```

---

## 5. Hallazgos de Seguridad (P0-P1)

### 🟣 #4 — Dangling pointer en lógica POT (Undefined Behavior)

**Ubicación**: `src/main.cpp` y `src/miner.cpp` — Lógica POT (múltiples instancias~12)

```cpp
const char* pszAddress = CEcoinAddress(addr).ToString().c_str();
CScript addrHex = CScript() << vector<unsigned char>(
    (const unsigned char*)pszAddress,
    (const unsigned char*)pszAddress + strlen(pszAddress));
```

→ **ACTUAL**: `CEcoinAddress(addr).ToString()` crea un `std::string` temporal que se destruye al final de la expresión. `pszAddress` queda como **dangling pointer**  
→ **IMPACTO**: Undefined behavior — puede funcionar por suerte pero es un bug latente que puede causar crash o datos corruptos  
→ **ESFUERZO**: 20 minutos (afecta ~12 instancias entre main.cpp y miner.cpp)  
→ **RECOMENDACIÓN**:

```cpp
// FIX: mantener el string vivo
std::string strAddress = CEcoinAddress(addr).ToString();
const char* pszAddress = strAddress.c_str();
```

### 🟣 #5 — rand() usado en selección de monedas (no CSPRNG)

**Ubicación**: `src/wallet.cpp` — función `ApproximateBestSubset()`

→ **ACTUAL**: Usa `rand()` de la libc estándar para randomizar la selección de UTXOs  
→ **RIESGO**: `rand()` es predecible. Un adversario podría predecir qué UTXOs se seleccionan, potencialmente correlacionando identidades  
→ **ESFUERZO**: 15 minutos  
→ **RECOMENDACIÓN**: Reemplazar con `GetRand()` o `GetRandHash()` que ya están disponibles en el codebase y usan OpenSSL CSPRNG

### 🟣 #6 — Checkpoint Master PubKey embebida en código

**Ubicación**: `src/checkpoints.cpp`

```cpp
const std::string CSyncCheckpoint::strMasterPubKey = "045d0773e7224ee40c6e...";
```

→ **ACTUAL**: La clave pública maestra para sync-checkpoints está hardcodeada  
→ **RIESGO**: Si se compromete la clave privada correspondiente, un atacante podría emitir checkpoints falsos sin necesidad de actualizar el software  
→ **ESFUERZO**: 1-2 horas  
→ **RECOMENDACIÓN**: Considerar un esquema multisig o rotación de claves para checkpoints

### 🟣 #7 — printf() como sistema de logging expone datos en producción

**Ubicación**: Todo el codebase (~200+ instancias)

```cpp
printf("IRC got new address: %s\n", addr.ToString().c_str());
printf("GetIPFromIRC() got userhost %s\n", strHost.c_str());
```

→ **ACTUAL**: Se usa `printf()` raw para toda la telemetría/logging  
→ **RIESGO**: Sin niveles de log (DEBUG/INFO/WARN/ERROR), es imposible filtrar. Datos sensibles como IPs de peers pueden acabar en logs sin control  
→ **ESFUERZO**: 2-3 días (refactor grande)  
→ **RECOMENDACIÓN**: Implementar un sistema de logging con niveles, idealmente con categorías por subsistema

---

## 6. Hallazgos de Eficiencia (P1-P2)

### 🟠 #8 — Lógica POT masivamente duplicada entre main.cpp y miner.cpp

**Ubicación**: `src/main.cpp` (`CheckProofOfTxSearch()` ~200 líneas) y `src/miner.cpp` (`ProofOfTxSearch()` ~250 líneas)

→ **ACTUAL**: La lógica de iteración de bloques, extracción de direcciones, `SearchTerm`/`SearchTermV2` y match está duplicada ~6 veces entre ambos archivos. Existen inconsistencias sutiles: comparaciones `> 500` vs `> 1`, divisiones `/ 1000000` vs `/ 1000000.00`  
→ **IMPACTO**: Bugs en un lugar no se arreglan en el otro. Mantenimiento exponencialmente más difícil  
→ **ESFUERZO**: 4-6 horas  
→ **RECOMENDACIÓN**: Extraer la lógica común a una función compartida:

```cpp
// Propuesta: Función unificada en un nuevo archivo pot.cpp/pot.h
struct PotMatchResult {
    bool found;
    CEcoinAddress matchedAddr;
};

PotMatchResult FindPotMatch(unsigned int nBlockHeight,
                            const CBlock& block,
                            const uint256& hashLastBlock);
```

Usarla tanto en `CheckProofOfTxSearch()` como en `ProofOfTxSearch()`.

### 🟠 #9 — Aritmética de punto flotante para montos monetarios

**Ubicación**: `src/miner.cpp` — `CreateNewBlock()`

```cpp
pblock->vtx[0].vout[0].nValue = (GetProofOfWorkReward(...)*0.95);
pblock->vtx[0].vout[1].nValue = (GetProofOfWorkReward(...)*0.05);
```

→ **ACTUAL**: Se usa `*0.95` y `*0.05` con `int64`, lo cual implica conversión a `double` que puede causar errores de redondeo en montos monetarios. Además `GetProofOfWorkReward()` se llama 2-3 veces con los mismos parámetros  
→ **ESFUERZO**: 10 minutos  
→ **RECOMENDACIÓN**:

```cpp
int64 nReward = GetProofOfWorkReward(pindexPrev->nHeight+1, pindexPrev->GetBlockHash());
if (!fMatch)
    pblock->vtx[0].vout[0].nValue = nReward;
else {
    pblock->vtx[0].vout[0].nValue = nReward * 95 / 100; // aritmética entera
    pblock->vtx[0].vout[1].nValue = nReward - (nReward * 95 / 100); // el resto
}
```

---

## 7. Hallazgos de Arquitectura (P2)

### 🔵 #10 — VERSION en ecoin-qt.pro no sincronizada

**Ubicación**: `ecoin/ecoin-qt.pro` línea 5

```
VERSION = 0.0.4
```

→ **ACTUAL**: El .pro dice 0.0.4 mientras clientversion.h dice 0.7.5.7 y version.h ahora también  
→ **IMPACTO**: Confusión para packagers, CI/CD, y usuarios  
→ **ESFUERZO**: 1 minuto  
→ **RECOMENDACIÓN**: Sincronizar a `VERSION = 0.7.5.7`

### 🔵 #11 — Copyright years inconsistentes

**Ubicación**: Múltiples archivos

| Archivo | Copyright |
|---|---|
| main.h | 2014/2022 |
| main.cpp | 2014/2024 |
| init.cpp | 2014/2024 |
| miner.cpp | 2014/2022 |
| irc.cpp | 2014/2022 |
| ecoin-qt.pro | 2014/2025 |
| version.h | 2014/2022 |

→ **ESFUERZO**: 10 minutos  
→ **RECOMENDACIÓN**: Unificar todos a `2014/2025` con un `sed` global:
```bash
find ecoin/src -name "*.cpp" -o -name "*.h" | xargs sed -i 's/2014\/2022/2014\/2025/g; s/2014\/2024/2014\/2025/g'
```

### 🔵 #12 — auto_ptr deprecado (C++11) y eliminado (C++17)

**Ubicación**: `src/miner.cpp`

```cpp
auto_ptr<CBlock> pblock(new CBlock());
```

→ **ESFUERZO**: 5 minutos  
→ **RECOMENDACIÓN**: Reemplazar por `std::unique_ptr<CBlock>`

### 🔵 #13 — BOOST_FOREACH puede reemplazarse por range-for de C++11

**Ubicación**: ~100+ instancias en todo el codebase

```cpp
BOOST_FOREACH(const CTxIn& txin, vin)  →  for (const auto& txin : vin)
```

→ **ESFUERZO**: 1-2 horas (mecánico con sed/regex)  
→ **BENEFICIO**: Menos dependencia de Boost, código más idiomático

---

## 8. Hallazgos de Claridad (P3-P4)

### 🟢 #14 — Magic numbers extensivos en lógica de recompensas

**Ubicación**: `src/main.cpp` — `GetProofOfWorkReward()`

```cpp
if (nHeight > 3295 && nHeight < 22001)
if (nHeight > 22000 && nHeight <= 34750)
if (nHeight > 34750 && nHeight <= 70037)
nSubsidy >>= (nHeightTemp / 5040);
nSubsidy >>= (nHeightTemp / 262800);
```

→ **RECOMENDACIÓN**: Extraer a constantes con nombre:

```cpp
static const unsigned int REWARD_DOUBLED_START  = 3295;
static const unsigned int RANDOM_ERA_END        = 22000;
static const unsigned int FLAT_REWARD_END       = 34750;
static const unsigned int FAST_HALVING_END      = 70037;
static const unsigned int FAST_HALVING_INTERVAL = 5040;    // ~1 semana
static const unsigned int SLOW_HALVING_INTERVAL = 262800;  // ~1 año
```

### 🟢 #15 — Funciones de 200+ líneas

| Función | Líneas | Archivo |
|---|---|---|
| `CheckProofOfTxSearch()` | ~200 | main.cpp |
| `ProofOfTxSearch()` | ~250 | miner.cpp |
| `CreateNewBlock()` | ~200 | miner.cpp |
| `AppInit2()` | ~250 | init.cpp |

→ **RECOMENDACIÓN**: Extraer subfunciones. `CheckProofOfTxSearch()` tiene 4 bloques casi idénticos para diferentes rangos de altura que deberían ser una sola función parametrizada.

### 🟢 #16 — Código comentado que debería eliminarse

**Ubicación**: `src/main.cpp`

```cpp
//if (fEnforceCanonical && !txin.scriptSig.HasCanonicalPushes()) {
//    return false;
//}
```

→ **RECOMENDACIÓN**: Si está intencionalmente deshabilitado, documentar por qué. Si no, eliminar (git lo preserva).

---

## 9. Revisión de Configuración en Producción

Se revisó el `ecoin.conf` de producción del nodo `pub-andromeda.oasis`. Análisis sin credenciales.

### Configuración Actual (sanitizada)

```ini
# Network
server=1
daemon=1
listen=1
port=7408

# RPC Configuration
rpcuser=<REDACTED>
rpcpassword=<REDACTED_64_CHAR_HEX>
rpcport=7474
rpcallowip=127.0.0.1
rpcbind=127.0.0.1

# Connections
maxconnections=125
timeout=30000

# Mining
gen=0

# Logging
debug=0
printtoconsole=0
logtimestamps=1

# Security
disablewallet=0

# Validators (verified 30/01/2026)
addnode=46.163.118.220        # 03c8.net (turina.space)
addnode=193.180.212.108       # validator
addnode=82.223.99.61          # gamesol
addnode=193.180.212.112       # validator
addnode=193.180.212.80        # validator
addnode=193.180.212.105       # validator

# Misc
txindex=1
norirc=1
addnode=79.112.28.209         # ecoin.sytes.net
addnode=79.112.91.131         # ecoin.sytes.net
```

### ✅ Buenas Prácticas Detectadas

| Parámetro | Valoración |
|---|---|
| `rpcallowip=127.0.0.1` + `rpcbind=127.0.0.1` | ✅ RPC restringido a localhost. Correcto. |
| `rpcpassword` (64 caracteres hex) | ✅ Alta entropía. Buena práctica. |
| `noirc=1` | ✅ IRC deshabilitado correctamente. Coherente con hallazgo #1 (Freenode extinto). |
| `gen=0` | ✅ PoW mining deshabilitado. Apropiado para nodo validador/staking. |
| `txindex=1` | ✅ Índice completo de transacciones. Necesario para explorador de bloques o consultas RPC avanzadas. |
| `logtimestamps=1` | ✅ Timestamps en logs. Esencial para debugging. |
| `port=7408` / `rpcport=7474` | ✅ Puertos estándar de ECOin. |
| 8 nodos `addnode` | ✅ Red de validadores explícita. |

### Hallazgos de Configuración

#### ⚪ #17 — `disablewallet=0` es ignorado silenciosamente

→ **ACTUAL**: La opción `disablewallet` no existe en el codebase de ECOin (verificado: 0 matches en `src/`). Es una opción de Bitcoin Core ≥0.9 que nunca fue portada  
→ **IMPACTO**: No causa error (opciones desconocidas se ignoran), pero da falsa sensación de que se está configurando algo  
→ **ESFUERZO**: 1 minuto  
→ **PRIORIDAD**: P4  
→ **RECOMENDACIÓN**: Eliminar la línea del conf. Si se desea implementar la feature, portarla del codebase de Bitcoin Core

#### ⚪ #18 — Falta `staking=1` explícito

→ **ACTUAL**: El parámetro `staking` no está en el conf. El default en el código es `1` (habilitado), así que funciona, pero no es explícito  
→ **IMPACTO**: Bajo — funciona correctamente por default. Pero una configuración de producción debería ser explícita sobre decisiones críticas  
→ **ESFUERZO**: 1 minuto  
→ **PRIORIDAD**: P5  
→ **RECOMENDACIÓN**: Añadir `staking=1` explícitamente con comentario:

```ini
# Staking (PoS)
staking=1
# reservebalance=0  # Cantidad a excluir del staking (default: 0)
```

#### 🟡 #19 — `timeout=30000` es 6x el default

→ **ACTUAL**: El timeout de conexión está configurado a 30 segundos. El default del código es 5000ms (5 segundos)  
→ **IMPACTO**: Conexiones lentas tardarán más en determinar que un peer no responde. Puede causar que el nodo retenga conexiones zombi más tiempo, reduciendo slots disponibles para peers activos  
→ **ESFUERZO**: 1 minuto  
→ **PRIORIDAD**: P3  
→ **RECOMENDACIÓN**: Evaluar si 30s es necesario para los peers específicos de la red. Un valor de 10000-15000ms sería un compromiso razonable. Si hay peers con alta latencia (Tor), mantener 30s pero documentar por qué

#### 🟡 #20 — Falta `dbcache` y `shrinkdebugfile`

→ **ACTUAL**: No se configura el tamaño de cache de BerkeleyDB (default: 25MB) ni la reducción automática de `debug.log`  
→ **IMPACTO**:
  - Sin `dbcache`: Rendimiento subóptimo en nodos con bloques históricos largos. 25MB es muy poco para un blockchain activo desde 2021
  - Sin `shrinkdebugfile`: El archivo `debug.log` puede crecer indefinidamente llenando el disco
→ **ESFUERZO**: 2 minutos  
→ **PRIORIDAD**: P3  
→ **RECOMENDACIÓN**:

```ini
# Performance
dbcache=100           # Cache de BerkeleyDB en MB (default: 25, recomendado: 100-256)
shrinkdebugfile=1     # Reducir debug.log al iniciar
```

### Mapa de Red Actual

Basado en el conf y el código fuente:

```
┌─────────────────────────────────────────────────────────┐
│                 MECANISMOS DE DISCOVERY                  │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  1. addnode (ecoin.conf)     → 8 IPs    ✅ ACTIVO       │
│  2. DNS seed (net.cpp)       → 1 dominio               │
│     ecoinseed.03c8.net                  ✅ CONFIGURADO   │
│  3. Hardcoded seeds (net.cpp)→ 2 IPs    ⚠️ MUY POCOS    │
│  4. IRC (irc.cpp)            → Freenode ❌ EXTINTO      │
│     (deshabilitado via noirc=1)                         │
│                                                         │
├─────────────────────────────────────────────────────────┤
│              NODOS VALIDADORES CONOCIDOS                 │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  46.163.118.220   — 03c8.net (turina.space) [PRINCIPAL] │
│  193.180.212.108  — validator                           │
│  82.223.99.61     — gamesol                             │
│  193.180.212.112  — validator                           │
│  193.180.212.80   — validator                           │
│  193.180.212.105  — validator                           │
│  79.112.28.209    — ecoin.sytes.net                     │
│  79.112.91.131    — ecoin.sytes.net                     │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Observaciones sobre la red:**
- 4 de los 8 nodos están en el rango `193.180.212.x` — **concentración en un solo proveedor/datacenter**. Si ese proveedor tiene un outage, se pierden 50% de los peers conocidos
- Solo 2 IPs hardcodeadas en `pnSeed[]` (net.cpp) — insuficiente como fallback
- 1 solo dominio DNS seed — single point of failure para nuevos nodos
- Recomendación: diversificar IPs en al menos 3 proveedores/geografías distintas

### Conf de Referencia Propuesto

```ini
# ═══════════════════════════════════════════════════════════════
# ECoin Configuration - PRODUCTION TEMPLATE
# ═══════════════════════════════════════════════════════════════

# ── Network ──
server=1
daemon=1
listen=1
port=7408

# ── RPC ──
rpcuser=<GENERATE_UNIQUE>
rpcpassword=<GENERATE_64_CHAR_HEX>
rpcport=7474
rpcallowip=127.0.0.1
rpcbind=127.0.0.1
# rpcssl=1                    # Habilitar si RPC expuesto a LAN

# ── Connections ──
maxconnections=125
timeout=15000                  # 15s balance entre tolerancia y detección zombi

# ── Mining / Staking ──
gen=0                          # PoW mining deshabilitado
staking=1                      # PoS staking habilitado
# reservebalance=100           # ECO a excluir del staking
# minersleep=500               # ms entre intentos de staking (default: 500)

# ── Logging ──
debug=0
printtoconsole=0
logtimestamps=1
shrinkdebugfile=1              # Reducir debug.log al iniciar

# ── Performance ──
dbcache=100                    # Cache BerkeleyDB en MB

# ── Discovery ──
noidrc=1                        # IRC deshabilitado (Freenode extinto)
dnsseed=1                      # DNS seed habilitado

# ── Peers ──
txindex=1
addnode=46.163.118.220
addnode=193.180.212.108
addnode=82.223.99.61
addnode=193.180.212.112
addnode=193.180.212.80
addnode=193.180.212.105
addnode=79.112.28.209
addnode=79.112.91.131

# ── Checkpoints ──
# cppolicy=strict              # strict|advisory|permissive (default: strict)
```

---

## 10. Modernización Propuesta

### Nivel 1: Quick Wins (1 día)

- [ ] Reemplazar `auto_ptr` → `unique_ptr`
- [ ] Sincronizar VERSION en ecoin-qt.pro
- [ ] Unificar copyright years a 2014/2025
- [ ] Eliminar código comentado
- [ ] Fix dangling pointer en lógica POT (~12 instancias)
- [ ] Eliminar `bitdb.Open()` duplicado en init.cpp
- [ ] Fix `rand()` → `GetRand()` en wallet.cpp
- [ ] Usar aritmética entera para splits de recompensa POT

### Nivel 2: Mejoras Estructurales (1 semana)

- [ ] Extraer lógica POT duplicada a función compartida (`pot.cpp`/`pot.h`)
- [ ] Extraer magic numbers a constantes nombradas
- [ ] Reemplazar IRC seeder (Libera.Chat o eliminar)
- [ ] Añadir checkpoints hardcodeados cada 10K bloques
- [ ] Reemplazar `BOOST_FOREACH` → range-for C++11
- [ ] Eliminar dependencia de `boost::tuple` → `std::tuple`

### Nivel 3: Modernización (1-2 meses)

- [ ] Implementar sistema de logging con niveles (LogPrintf con categorías)
- [ ] Migrar de `printf()` a logging estructurado
- [ ] Considerar multisig para checkpoint master key
- [ ] Implementar DNS seed como mecanismo primario de discovery
- [ ] Refactorizar funciones >100 líneas
- [ ] Añadir unit tests para lógica de recompensas y POT

---

## 11. Mejoras de Red e Infraestructura

### DNS Seeds

```cpp
// Propuesta: Añadir DNS seeds como mecanismo primario
static const char *strMainNetDNSSeed[][2] = {
    {"seed1.ecoin.03c8.net", "seed1.ecoin.03c8.net"},
    {"seed2.ecoin.03c8.net", "seed2.ecoin.03c8.net"},
    {NULL, NULL}
};
```

### Nodos Seed Hardcodeados

Añadir IPs de nodos de confianza conocidos como fallback cuando DNS e IRC fallen.

### Checkpoints

El blockchain lleva activo desde enero 2021 (genesis timestamp 1610833657). Con 2 minutos de block spacing, hay potencialmente ~1,000,000+ bloques. Tener checkpoints solo en el bloque 0 es insuficiente para proteger la sincronización inicial.

---

## 12. Recomendaciones Priorizadas

| # | Tipo | Hallazgo | Prioridad | Esfuerzo |
|---|---|---|---|---|
| 4 | 🟣 SEGURIDAD | Dangling pointer en lógica POT | P0 | 20 min |
| 2 | 🔴 CRÍTICO | bitdb.Open() duplicado | P0 | 5 min |
| 1 | 🔴 CRÍTICO | IRC seeder (Freenode extinto) | P0 | 2-4 hrs |
| 3 | 🔴 CRÍTICO | Solo checkpoint génesis | P0 | 30 min |
| 5 | 🟣 SEGURIDAD | rand() en coin selection | P1 | 15 min |
| 9 | 🟠 EFICIENCIA | Float para montos monetarios | P1 | 10 min |
| 10 | 🔵 ARQUITECTURA | VERSION .pro desincronizada | P2 | 1 min |
| 8 | 🟠 EFICIENCIA | POT lógica duplicada | P2 | 4-6 hrs |
| 12 | 🔵 ARQUITECTURA | auto_ptr deprecado | P2 | 5 min |
| 14 | 🟢 CLARIDAD | Magic numbers | P3 | 1 hr |
| 11 | 🔵 ARQUITECTURA | Copyright inconsistente | P4 | 10 min |
| 13 | 🔵 ARQUITECTURA | BOOST_FOREACH | P4 | 1-2 hrs |
| 15 | 🟢 CLARIDAD | Funciones >200 líneas | P4 | 2-3 hrs |
| 16 | 🟢 CLARIDAD | Código comentado | P5 | 10 min |
| 7 | 🟣 SEGURIDAD | printf logging | P5 | 2-3 días |
| 6 | 🟣 SEGURIDAD | Checkpoint master key | P5 | 1-2 hrs |
| 17 | ⚪ CONFIG | `disablewallet` ignorado silenciosamente | P4 | 1 min |
| 18 | ⚪ CONFIG | `staking=1` no explícito | P5 | 1 min |
| 19 | 🟡 CONFIG | `timeout=30000` (6x default) | P3 | 1 min |
| 20 | 🟡 CONFIG | Falta `dbcache` y `shrinkdebugfile` | P3 | 2 min |

### Matriz de Priorización

```
              | Bajo Esfuerzo      | Alto Esfuerzo
──────────────┼─────────────────────┼──────────────────
Alto Impacto  | #2 bitdb (5 min)   | #1 IRC (2-4 hrs)
              | #4 dangling (20m)  | #8 POT dedup (4-6h)
              | #5 rand() (15 min) |
              | #9 float (10 min)  |
──────────────┼─────────────────────┼──────────────────
Bajo Impacto  | #10 VERSION (1 min)| #7 logging (2-3 d)
              | #11 copyright (10m)| #13 FOREACH (1-2h)
              | #12 auto_ptr (5 m) | #15 funciones (2-3h)
              | #16 comentado (10m)|
```

---

## 13. Conclusión

ECOin es un proyecto con una propuesta original (PoT mining) y un codebase funcional que ha sido mantenido activamente con actualizaciones de dependencias modernas. El fix de la rama actual (`DISPLAY_VERSION` sync) es correcto y necesario.

### Las 5 mejoras más urgentes

1. **Fix del dangling pointer** en la lógica POT — riesgo de undefined behavior en producción
2. **Eliminar el `bitdb.Open()` duplicado** — prevención de corrupción de base de datos
3. **Reemplazar el IRC seeder muerto** — permite que nuevos nodos descubran la red
4. **Añadir checkpoints** — seguridad contra ataques de cadena alternativa durante sync inicial
5. **Configurar `dbcache` y `shrinkdebugfile`** en producción — previene disco lleno y mejora rendimiento

### Inversión vs. Retorno

El **80% de los fixes críticos se resuelve en menos de 1 hora** (hallazgos #2, #4, #5, #9, #10). El restante 20% (IRC seeder, checkpoints, deduplicación POT) requiere más tiempo pero tiene alto impacto en seguridad y mantenibilidad.

La revisión del `ecoin.conf` de producción muestra una configuración sólida con buenas prácticas de seguridad (RPC localhost-only, password fuerte, IRC deshabilitado). Los hallazgos de config son menores pero la concentración de peers en un solo rango IP (193.180.212.x) y la falta de `dbcache`/`shrinkdebugfile` deberían corregirse.

El codebase tiene una base sólida. Con los fixes P0 aplicados y la modernización gradual propuesta, ECOin estaría en excelente posición para crecimiento sostenible.

### Ideas adicionales para el desarrollador

1. **Tests unitarios para economía**: Las funciones `GetProofOfWorkReward()`, `GetProofOfStakeReward()` y `CheckProofOfTxSearch()` son críticas y deberían tener tests exhaustivos que validen los rangos de bloques y recompensas esperadas
2. **Documentación del protocolo POT**: El mecanismo de Proof-of-Transaction es innovador pero no está documentado formalmente. Un whitepaper o spec técnica ayudaría a la comunidad y a futuros contribuidores
3. **Explorador de bloques integrado**: El commit history menciona un blockchain explorer — sería útil documentar cómo desplegarlo
4. **CI/CD**: Implementar GitHub Actions para compilar automáticamente en Linux/Windows/macOS en cada push

---

*Revisión realizada por s1ko (s1ko@riseup.net) — asistido por OraKlaud*
