#!/bin/bash
# ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
# Create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/ecoin.ico
convert ../../src/qt/res/icons/ecoin-16.png ../../src/qt/res/icons/ecoin-32.png ../../src/qt/res/icons/ecoin-48.png ${ICON_DST}
