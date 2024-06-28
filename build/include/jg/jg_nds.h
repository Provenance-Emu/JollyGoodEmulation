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

#ifndef JG_NDS_H
#define JG_NDS_H

enum jg_nds_input_type {
    JG_NDS_SYSTEM,
    JG_NDS_TOUCH
};

static const char *jg_nds_input_name[] = {
    "Nintendo DS",
    "NDS Touchscreen"
};

// NDS System
#define NDEFS_NDS 12
static const char *defs_ndspad[NDEFS_NDS] = {
    "Up", "Down", "Left", "Right", "Select", "Start",
    "A", "B", "X", "Y", "L", "R"
};

// NDS Stylus
#define NDEFS_NDSTOUCH 1
static const char *defs_ndstouch[NDEFS_NDSTOUCH] = {
    "Press"
};

static jg_inputinfo_t jg_nds_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_NDS_SYSTEM: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name =  index == 0 ? "nds1" : "nds2";
            ret.fname = jg_nds_input_name[type];
            ret.defs = defs_ndspad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_NDS;
            return ret;
        }
        case JG_NDS_TOUCH: {
            ret.type = JG_INPUT_TOUCH;
            ret.index = index;
            ret.name =  index == 1 ? "ndstouch1" : "ndstouch2";
            ret.fname = jg_nds_input_name[type];
            ret.defs = defs_ndstouch;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_NDSTOUCH;
            return ret;
        }
    }
}

#endif
