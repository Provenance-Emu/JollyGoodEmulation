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

#ifndef JG_SS_H
#define JG_SS_H

enum jg_ss_input_type {
    JG_SS_UNCONNECTED,
    JG_SS_PAD,
    JG_SS_3DPAD,
    JG_SS_VIRTUAGUN
};

static const char *jg_ss_input_name[] = {
    "Unconnected",
    "Saturn Control Pad",
    "Saturn 3D Control Pad",
    "Virtua Gun"
};

#define NDEFS_SSPAD 13
static const char *defs_sspad[NDEFS_SSPAD] = {
    "Up", "Down", "Left", "Right", "Start",
    "A", "B", "C", "X", "Y", "Z", "L", "R"
};

#define NDEFS_SS3DPAD 16
static const char *defs_ss3dpad[NDEFS_SS3DPAD] = {
    "StickX", "StickY", "L", "R",
    "Up", "Down", "Left", "Right", "Start",
    "A", "B", "C", "X", "Y", "Z", "Analog"
};

#define NDEFS_SSVIRTUAGUN 3
static const char *defs_ssvirtuagun[NDEFS_SSVIRTUAGUN] = {
	"Trigger", "Offscreen", "Start"
};

static jg_inputinfo_t jg_ss_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_SS_PAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name =  index == 0 ? "sspad1" : index == 1 ? "sspad2" :
                index == 2 ? "sspad3" : index == 3 ? "sspad4" :
                index == 4 ? "sspad5" : index == 5 ? "sspad6" :
                index == 6 ? "sspad7" : index == 7 ? "sspad8" :
                index == 8 ? "sspad9" : index == 9 ? "sspad10" :
                index == 10 ? "sspad11" : "sspad12";
            ret.fname = jg_ss_input_name[type];
            ret.defs = defs_sspad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SSPAD;
            return ret;
        }
        case JG_SS_3DPAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "ss3dpad1" : index == 1 ? "ss3dpad2" :
                index == 2 ? "ss3dpad3" : index == 3 ? "ss3dpad4" :
                index == 4 ? "ss3dpad5" : index == 5 ? "ss3dpad6" :
                index == 6 ? "ss3dpad7" : index == 7 ? "ss3dpad8" :
                index == 8 ? "ss3dpad9" : index == 9 ? "ss3dpad10" :
                index == 10 ? "ss3dpad11" : "ss3dpad12";
            ret.fname = jg_ss_input_name[type];
            ret.defs = defs_ss3dpad;
            ret.numaxes = 4;
            ret.numbuttons = NDEFS_SS3DPAD - 4;
            return ret;
        }
        case JG_SS_VIRTUAGUN: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "virtuagun";
            ret.fname = jg_ss_input_name[type];
            ret.defs = defs_ssvirtuagun;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SSVIRTUAGUN;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_ss_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
