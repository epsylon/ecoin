// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#include <QTest>
#include <QObject>
#include "uritests.h"

// This is all you need to run all the tests
int main(int argc, char *argv[])
{
    bool fInvalid = false;

    URITests test1;
    if (QTest::qExec(&test1) != 0)
        fInvalid = true;

    return fInvalid;
}
