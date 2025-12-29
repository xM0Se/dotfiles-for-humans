#!/bin/bash
source "$CONFIG_DIR/colors.sh"

CASE=$(/usr/sbin/system_profiler SPBluetoothDataType | /run/current-system/sw/bin/rg -A6 "Moritz’s AirPods:" | tail -n +5 | head -n 1 | /run/current-system/sw/bin/rg -o '\d+')

LEFT=$(/usr/sbin/system_profiler SPBluetoothDataType | /run/current-system/sw/bin/rg -A6 "Moritz’s AirPods:" | tail -n +6 | head -n 1 | /run/current-system/sw/bin/rg -o '\d+')

RIGHT=$(/usr/sbin/system_profiler SPBluetoothDataType | /run/current-system/sw/bin/rg -A6 "Moritz’s AirPods:" | tail -n +7 | head -n 1 | /run/current-system/sw/bin/rg -o '\d+')

sketchybar -m --set casep label="${CASE}%" label.color=$TEXT

sketchybar -m --set lpodp label="${LEFT}%" label.color=$TEXT

sketchybar -m --set rpodp label="${RIGHT}%" label.color=$TEXT
