#!/bin/bash
  sketchybar --add item clock.hh left \
             --set clock.hh \
               script="$PLUGIN_DIR/clock.sh" update_freq=30 \
               drawing=on icon.drawing=off label.drawing=on \
               label.font.size=30 label.color="$LIGHT_TEXT" \
               padding_left=0 padding_right=5 \
               y_offset=0

  # MINUTES
  sketchybar --add item clock.mm left \
             --set clock.mm \
               script="$PLUGIN_DIR/clock.sh" update_freq=30 \
               drawing=on icon.drawing=off label.drawing=on \
               label.font.size=22 label.color="$LIGHT_TEXT" \
               padding_left=0 padding_right=10 \
               y_offset=0

  # AM/PM  (make it clearly visible first)
  sketchybar --add item clock.ap left \
             --set clock.ap \
               script="$PLUGIN_DIR/clock.sh" update_freq=30 \
               drawing=on icon.drawing=off label.drawing=on \
               label.font.size=12 label.color="$LIGHT_TEXT" \
               padding_left=0 padding_right=0 \
               y_offset=0

  # Group them so there's no extra spacing between the three
  sketchybar --add bracket clock_group clock.hh clock.mm clock.ap \
             --set clock_group background.drawing=off
