// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef ECOIN_INIT_H
#define ECOIN_INIT_H

#include "wallet.h"

extern CWallet* pwalletMain;
extern std::string strWalletFileName;
void StartShutdown();
void Shutdown(void* parg);
bool AppInit2();
std::string HelpMessage();

#endif
