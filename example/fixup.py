#!/usr/bin/env python

import sys

data = None
with open(sys.argv[1], 'rb') as fin:
    data = bytearray(fin.read())

if not data is None:
    # loader flag: request fast ram
    data[0x81] = 'F' 
    # loader falg: request slow ram
    # data[0x81] = 'G'

    with open(sys.argv[1], 'wb') as fout:
        fout.write(data)

