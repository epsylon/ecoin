#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/ecoin.ico

convert ../../src/qt/res/icons/ecoin-16.png ../../src/qt/res/icons/ecoin-32.png ../../src/qt/res/icons/ecoin-48.png ${ICON_DST}
