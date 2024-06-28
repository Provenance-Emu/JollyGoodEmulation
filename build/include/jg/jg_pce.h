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

#ifndef JG_PCE_H
#define JG_PCE_H

enum jg_pce_input_type {
    JG_PCE_UNCONNECTED,
    JG_PCE_PAD,
    JG_PCE_AP6
};

static const char *jg_pce_input_name[] = {
    "Unconnected",
    "TurboPad",
    "Avenue Pad 6"
};

// PC Engine Controller (Pad)
#define NDEFS_PCEPAD 10
static const char *defs_pcepad[NDEFS_PCEPAD] = {
    "Up", "Down", "Left", "Right", "Select", "Run",
    "I", "II", "TurboI", "TurboII"
};

// Avenue/Arcade Pad 6
#define NDEFS_PCEAP6 12
static const char *defs_pceap6[NDEFS_PCEAP6] = {
    "Up", "Down", "Left", "Right", "Select", "Run",
    "I", "II", "III", "IV", "V", "VI" //"ModeSelect" forced on
};

static jg_inputinfo_t jg_pce_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_PCE_PAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "turbopad1" :
                index == 1 ? "turbopad2" :
                index == 2 ? "turbopad3" :
                index == 3 ? "turbopad4" : "turbopad5";
            ret.fname = jg_pce_input_name[type];
            ret.defs = defs_pcepad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_PCEPAD;
            return ret;
        }
        case JG_PCE_AP6: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "ap6p1" : "ap6p2";
            ret.fname = jg_pce_input_name[type];
            ret.defs = defs_pcepad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_PCEAP6;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_pce_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
