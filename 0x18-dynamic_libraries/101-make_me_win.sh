#!/bin/bash
wget -P /tmp https://github.com/Abdurahman-hassan/alx-low_level_programming/raw/main/0x18-dynamic_libraries/i_will_win.so
export LD_PRELOAD=/tmp/i_will_win.so