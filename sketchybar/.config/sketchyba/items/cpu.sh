#!/bin/bash

sketchybar --add item cpu right \
  --set cpu update_freq=1 \
  icon=􀫥 \
  label.color=$TEXT_COLOR \
  icon.color=$TEXT_COLOR \
  script="$PLUGIN_DIR/cpu.sh"
