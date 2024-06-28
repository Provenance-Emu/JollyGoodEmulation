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

#ifndef JG_2600_H
#define JG_2600_H

enum jg_2600_input_type {
    JG_2600_UNCONNECTED,
    JG_2600_JS,
    JG_2600_SYS
};

static const char *jg_2600_input_name[] = {
    "Unconnected",
    "2600 Joystick",
    "2600 System"
};

#define NDEFS_2600JS 5
static const char *defs_2600js[NDEFS_2600JS] = {
    "Up", "Down", "Left", "Right", "Fire"
};

#define NDEFS_2600SYS 5
static const char *defs_2600sys[NDEFS_2600SYS] = {
    "Reset", "Select", "LeftDifficulty", "RightDifficulty", "TVType"
};

static jg_inputinfo_t jg_2600_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_2600_JS: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "2600js1" : "2600js2";
            ret.fname = jg_2600_input_name[type];
            ret.defs = defs_2600js;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_2600JS;
            return ret;
        }
        case JG_2600_SYS: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "2600system";
            ret.fname = jg_2600_input_name[type];
            ret.defs = defs_2600sys;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_2600SYS;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_2600_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
