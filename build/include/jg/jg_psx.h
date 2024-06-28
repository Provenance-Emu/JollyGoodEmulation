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

#ifndef JG_PSX_H
#define JG_PSX_H

enum jg_psx_input_type {
    JG_PSX_UNCONNECTED,
    JG_PSX_DUALSHOCK,
    JG_PSX_GUNCON,
    JG_PSX_JUSTIFIER
};

static const char *jg_psx_input_name[] = {
    "Unconnected",
    "DualShock",
    "GunCon",
    "Konami Justifier"
};

// PSX DualShock
#define NDEFS_DUALSHOCK 21
static const char *defs_dualshock[NDEFS_DUALSHOCK] = {
    "LeftStickX", "LeftStickY", "RightStickX", "RightStickY",
    "Up", "Down", "Left", "Right", "Select", "Start",
    "Triangle", "Cross", "Square", "Circle", "Analog",
    "L1", "L2", "L3", "R1", "R2", "R3"
};

#define NDEFS_PSXGUNCON 4
static const char *defs_psxguncon[NDEFS_PSXGUNCON] = {
    "Trigger", "Offscreen", "A", "B"
};

#define NDEFS_PSXJUSTIFIER 4
static const char *defs_psxjustifier[NDEFS_PSXJUSTIFIER] = {
    "Trigger", "Offscreen", "O", "Start"
};

static jg_inputinfo_t jg_psx_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_PSX_DUALSHOCK: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "dualshock1" : index == 1 ? "dualshock2" :
                index == 2 ? "dualshock3" : index == 3 ? "dualshock4" :
                index == 4 ? "dualshock5" : index == 5 ? "dualshock6" :
                index == 6 ? "dualshock7" : "dualshock8";
            ret.fname = jg_psx_input_name[type];
            ret.defs = defs_dualshock;
            ret.numaxes = 4;
            ret.numbuttons = NDEFS_DUALSHOCK - 4;
            return ret;
        }
        case JG_PSX_GUNCON: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "psxguncon";
            ret.fname = jg_psx_input_name[type];
            ret.defs = defs_psxguncon;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_PSXGUNCON;
            return ret;
        }
        case JG_PSX_JUSTIFIER: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "psxjustifier";
            ret.fname = jg_psx_input_name[type];
            ret.defs = defs_psxjustifier;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_PSXJUSTIFIER;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_psx_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
