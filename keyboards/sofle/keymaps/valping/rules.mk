# Build Options
# Comment out to disable the options.

# This file is part of the QMK Keyboard Firmware.
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.


TRI_LAYER_ENABLE = yes          # Enable tri-layer feature (third layer activates when two others are on)
OLED_ENABLE = yes               # Enable OLED screen support
LTO_ENABLE = yes                # Enable Link Time Optimization for smaller and faster firmware
VIA_ENABLE = yes                # Enable dynamic keymap configuration via VIA software

MOUSEKEY_ENABLE = yes           # Enable keyboard keys to control mouse pointer
EXTRAKEY_ENABLE = yes           # Enable extra keycodes like media and system controls
PIMORONI_TRACKBALL_ENABLE = no  # Disable Pimoroni trackball support
POINTING_DEVICE_ENABLE = no     # Disable support for pointing devices (mouse, trackball)

BACKLIGHT_ENABLE = no           # Disable single-color backlight LEDs
RGBLIGHT_ENABLE = no            # Disable simple RGB underglow lighting
RGB_MATRIX_ENABLE = no          # Disable advanced per-key RGB lighting effects
AUDIO_ENABLE = no               # Disable audio features (buzzer/speaker)

# Debug Options
VERBOSE = no                    # Disable verbose debug output
CONSOLE_ENABLE = no             # Disable QMK console debug interface
COMMAND_ENABLE = no             # Disable command mode via keyboard

# Feature Options
ENCODER_MAP_ENABLE = no	        # Enable rotary encoder mapping
ENCODER_ENABLE = yes            # Enable rotary encoder support
WPM_ENABLE = yes                # Enable words-per-minute typing measurement
TAP_DANCE_ENABLE = no           # Disable Tap Dance feature (multiple actions on tap sequences)
UNICODE_ENABLE = no             # Disable Unicode input support
COMBO_ENABLE = no               # Disable combo keys (multiple keys pressed together to trigger another)

SPACE_CADET_ENABLE = no         # Disable Space Cadet Shift (Shift key sends parentheses when tapped)
BLUETOOTH_ENABLE = no           # Disable Bluetooth support
MIDI_ENABLE = no                # Disable MIDI mode (musical keyboard functionality)
STENO_ENABLE = no               # Disable stenography mode
AUTO_SHIFT_ENABLE = no          # Disable Auto Shift (auto capitalize when holding keys)
KEY_LOCK_ENABLE = no            # Disable key lock (temporarily disables keys)
MAGIC_ENABLE = no               # Disable Magic keycodes (special QMK keycodes)
LEADER_ENABLE = no              # Disable Leader key feature (multi-key shortcuts)
HAPTIC_ENABLE = no              # Disable haptic (vibration) feedback
VIRTSER_ENABLE = no             # Disable Virtual Serial support
RAW_ENABLE = no                 # Disable RAW HID support

GRAVE_ESC_ENABLE = no           # Disable ESC key sending grave (`) when Shift is held
BOOTMAGIC_ENABLE = no           # Disable Bootmagic (boot-time keyboard configuration/reset)
