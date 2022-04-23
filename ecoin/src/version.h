// ECOin - Copyright (c) - 2014/2022 - GPLv3 - epsylon@riseup.net (https://03c8.net)

#ifndef ECOIN_VERSION_H
#define ECOIN_VERSION_H

#include "clientversion.h"
#include <string>

//
// client versioning
//

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

//
// database format versioning
//
static const int DATABASE_VERSION = 70507;

//
// network protocol versioning
//

static const int PROTOCOL_VERSION = 70009;

// earlier versions not supported and are disconnected
static const int MIN_PROTO_VERSION = 70007;

// nTime field added to CAddress, starting with this version;
// if possible, avoid requesting addresses nodes older than this
static const int CADDR_TIME_VERSION = 70000;

// only request blocks from nodes outside this range of versions
static const int NOBLKS_VERSION_START = 1;
static const int NOBLKS_VERSION_END = 70006;

// BIP 0031, pong message, is enabled for all versions AFTER this one
static const int BIP0031_VERSION = 69999;

// "mempool" command, enhanced "getdata" behavior starts with this version:
static const int MEMPOOL_GD_VERSION = 70000;

#define DISPLAY_VERSION_MAJOR       0
#define DISPLAY_VERSION_MINOR       4
#define DISPLAY_VERSION_REVISION    5
#define DISPLAY_VERSION_BUILD       7

#endif
