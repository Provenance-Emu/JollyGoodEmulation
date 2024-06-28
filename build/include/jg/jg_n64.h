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

#ifndef JG_N64_H
#define JG_N64_H

enum jg_n64_input_type {
    JG_N64_UNCONNECTED,
    JG_N64_CONTROLLER
};

static const char *jg_n64_input_name[] = {
    "Unconnected",
    "N64 Controller"
};

#define NDEFS_N64CTRL 16
static const char *defs_n64ctrl[NDEFS_N64CTRL] = {
    "XAxis", "YAxis", "Up", "Down", "Left", "Right", "Start",
    "Z", "L", "R", "A", "B", "CUp", "CDown", "CLeft", "CRight"
};

static jg_inputinfo_t jg_n64_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_N64_CONTROLLER: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "n64ctrl1" : index == 1 ? "n64ctrl2" :
                index == 2 ? "n64ctrl3" : "n64ctrl4";
            ret.fname = jg_n64_input_name[type];
            ret.defs = defs_n64ctrl;
            ret.numaxes = 2;
            ret.numbuttons = NDEFS_N64CTRL - 2;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_n64_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
