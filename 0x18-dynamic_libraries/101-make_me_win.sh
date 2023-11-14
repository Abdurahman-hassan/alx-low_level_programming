#!/bin/bash
wget -P /tmp/ https://github.com/Abdurahman-hassan/alx-low_level_programming/blob/main/0x18-dynamic_libraries/make_me_win.so
export LD_PRELOAD=/tmp/make_me_win.so