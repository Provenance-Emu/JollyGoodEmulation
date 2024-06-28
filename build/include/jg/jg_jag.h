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

#ifndef JG_JAG_H
#define JG_JAG_H

enum jg_jag_input_type {
    JG_JAG_UNCONNECTED,
    JG_JAG_PAD
};

static const char *jg_jag_input_name[] = {
    "Unconnected",
    "Jaguar Gamepad"
};

#define NDEFS_JAGPAD 21
static const char *defs_jagpad[NDEFS_JAGPAD] = {
    "Up", "Down", "Left", "Right", "C", "B", "A", "Pause", "Option",
    "Button1", "Button2", "Button3", "Button4", "Button5", "Button6",
    "Button7", "Button8", "Button9", "Button0", "Star", "Pound"
};

static jg_inputinfo_t jg_jag_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_JAG_PAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "jagpad1" : "jagpad2";
            ret.fname = jg_jag_input_name[type];
            ret.defs = defs_jagpad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_JAGPAD;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_jag_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
