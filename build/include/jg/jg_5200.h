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

#ifndef JG_5200_H
#define JG_5200_H

enum jg_5200_input_type {
    JG_5200_UNCONNECTED,
    JG_5200_JS
};

static const char *jg_5200_input_name[] = {
    "Unconnected",
    "5200 Joystick"
};

#define NDEFS_5200JS 21
static const char *defs_5200js[NDEFS_5200JS] = {
    "Up", "Down", "Left", "Right", "FireL", "FireR", "Start", "Pause", "Reset",
    "Button1", "Button2", "Button3", "Button4", "Button5", "Button6", "Button7",
    "Button8", "Button9", "Button0", "Star", "Pound"
};

static jg_inputinfo_t jg_5200_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_5200_JS: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "5200js1" : index == 1 ? "5200js2" :
                index == 2 ? "5200js3" : "5200js4";
            ret.fname = jg_5200_input_name[type];
            ret.defs = defs_5200js;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_5200JS;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_5200_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
