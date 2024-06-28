/*
zlib License

Copyright (c) 2020-2022 Rupert Carmichael

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef JG_GB_H
#define JG_GB_H

enum jg_gb_input_type {
    JG_GB_SYSTEM,
    JG_GB_ACCELEROMETER
};

static const char *jg_gb_input_name[] = {
    "Game Boy",
    "Accelerometer"
};

#define NDEFS_GB 10
static const char *defs_gb[NDEFS_GB] = {
    "Up", "Down", "Left", "Right", "Select", "Start",
    "A", "B", "TurboA", "TurboB"
};

#define NDEFS_GBACCELEROMETER 2
static const char *defs_gbacclerometer[NDEFS_GBACCELEROMETER] = {
    "X", "Y"
};

static jg_inputinfo_t jg_gb_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_GB_SYSTEM: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "gameboy1" : "gameboy2";
            ret.fname = jg_gb_input_name[type];
            ret.defs = defs_gb;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_GB;
            break;
        }
        case JG_GB_ACCELEROMETER: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = "gbaccelerometer";
            ret.fname = jg_gb_input_name[type];
            ret.defs = defs_gbacclerometer;
            ret.numaxes = NDEFS_GBACCELEROMETER;
            ret.numbuttons = 0;
            break;
        }
    }

    return ret;
}

#endif
