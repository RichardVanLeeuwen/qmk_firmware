/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define USE_SERIAL
// Read which side the keyboard is from eeprom memory
#define EE_HANDS

// A rather long tapping_term reduces the probability of misinterpretation surrounding the home-row-mods.
#define TAPPING_TERM 220
// Permissive_hold makes it that home-row-mods can be used while typing fast.
// https://docs.qmk.fm/tap_hold#permissive-hold
#define PERMISSIVE_HOLD
#define TAP_CODE_DELAY 10

