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

#ifndef JG_SNES_H
#define JG_SNES_H

enum jg_snes_input_type {
    JG_SNES_UNCONNECTED,
    JG_SNES_PAD,
    JG_SNES_MOUSE,
    JG_SNES_SUPERSCOPE,
    JG_SNES_JUSTIFIER
};

static const char *jg_snes_input_name[] = {
    "Unconnected",
    "SNES Controller",
    "SNES Mouse",
    "Super Scope",
    "SNES Justifier"
};

// SNES Controller (Pad)
#define NDEFS_SNESPAD 12
static const char *defs_snespad[NDEFS_SNESPAD] = {
    "Up", "Down", "Left", "Right", "Select", "Start",
    "A", "B", "X", "Y", "L", "R"
};

#define NDEFS_SNESMOUSE 2
static const char *defs_snesmouse[NDEFS_SNESMOUSE] = {
    "Left", "Right"
};

#define NDEFS_SUPERSCOPE 5
static const char *defs_superscope[NDEFS_SUPERSCOPE] = {
    "Trigger", "Offscreen", "Cursor", "Turbo", "Pause"
};

#define NDEFS_SNESJUSTIFIER 3
static const char *defs_snesjustifier[NDEFS_SNESJUSTIFIER] = {
    "Trigger", "Offscreen", "Start"
};

static jg_inputinfo_t jg_snes_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_SNES_PAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name =  index == 0 ? "snespad1" : index == 1 ? "snespad2" :
                index == 2 ? "snespad3" : index == 3 ? "snespad4" :
                index == 4 ? "snespad5" : index == 5 ? "snespad6" :
                index == 6 ? "snespad7" : "snespad8";
            ret.fname = jg_snes_input_name[type];
            ret.defs = defs_snespad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SNESPAD;
            return ret;
        }
        case JG_SNES_MOUSE: {
            ret.type = JG_INPUT_POINTER;
            ret.index = index;
            ret.name = "snesmouse";
            ret.fname = jg_snes_input_name[type];
            ret.defs = defs_snesmouse;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SNESMOUSE;
            return ret;
        }
        case JG_SNES_SUPERSCOPE: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "superscope";
            ret.fname = jg_snes_input_name[type];
            ret.defs = defs_superscope;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SUPERSCOPE;
            return ret;
        }
        case JG_SNES_JUSTIFIER: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "snesjustifier";
            ret.fname = jg_snes_input_name[type];
            ret.defs = defs_snesjustifier;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SNESJUSTIFIER;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_snes_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
