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

#ifndef JG_7800_H
#define JG_7800_H

enum jg_7800_input_type {
    JG_7800_UNCONNECTED,
    JG_7800_JS,
    JG_7800_GUN,
    JG_7800_SYS
};

static const char *jg_7800_input_name[] = {
    "Unconnected",
    "7800 Joystick",
    "XG-1 Lightgun",
    "7800 System"
};

#define NDEFS_7800JS 6
static const char *defs_7800js[NDEFS_7800JS] = {
    "Up", "Down", "Left", "Right", "Button1", "Button2"
};

#define NDEFS_7800GUN 1
static const char *defs_7800gun[NDEFS_7800GUN] = {
    "Trigger"
};

#define NDEFS_7800SYS 5
static const char *defs_7800sys[NDEFS_7800SYS] = {
    "Reset", "Select", "Pause", "LeftDifficulty", "RightDifficulty"
};

static jg_inputinfo_t jg_7800_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_7800_JS: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "7800js1" : "7800js2";
            ret.fname = jg_7800_input_name[type];
            ret.defs = defs_7800js;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_7800JS;
            return ret;
        }
        case JG_7800_GUN: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "7800gun";
            ret.fname = jg_7800_input_name[type];
            ret.defs = defs_7800gun;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_7800GUN;
            return ret;
        }
        case JG_7800_SYS: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "7800system";
            ret.fname = jg_7800_input_name[type];
            ret.defs = defs_7800sys;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_7800SYS;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_7800_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
