/*
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

#ifndef JG_MD_H
#define JG_MD_H

enum jg_md_input_type {
    JG_MD_UNCONNECTED,
    JG_MD_PAD3B,
    JG_MD_PAD6B,
    JG_MD_JUSTIFIER,
    JG_MD_MENACER
};

static const char *jg_md_input_name[] = {
    "Unconnected",
    "3 Button Control Pad",
    "6 Button Control Pad",
    "Justifier",
    "Menacer"
};

// 3 Button Control Pad
#define NDEFS_MDPAD3B 8
static const char *defs_mdpad3b[NDEFS_MDPAD3B] = {
    "Up", "Down", "Left", "Right", "Start", "A", "B", "C"
};

// 6 Button Control Pad
#define NDEFS_MDPAD6B 12
static const char *defs_mdpad6b[NDEFS_MDPAD6B] = {
    "Up", "Down", "Left", "Right", "Mode", "Start",
    "A", "B", "C", "X", "Y", "Z"
};

// Justifier
#define NDEFS_MDJUSTIFIER 3
static const char *defs_mdjustifier[NDEFS_MDJUSTIFIER] = {
    "Trigger", "Offscreen", "Pause"
};

// Menacer
#define NDEFS_MENACER 5
static const char *defs_menacer[NDEFS_MENACER] = {
    "Trigger", "Offscreen", "Button1", "Button2", "Pause"
};

static jg_inputinfo_t jg_md_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_MD_PAD3B: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.fname = index == 0 ? "pad3b1" : index == 1 ? "pad3b2" :
                index == 2 ? "pad3b3" : index == 3 ? "pad3b4" :
                index == 4 ? "pad3b5" : index == 5 ? "pad3b6" :
                index == 6 ? "pad3b7" : "pad3b8";
            ret.fname = jg_md_input_name[type];
            ret.defs = defs_mdpad3b;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_MDPAD3B;
            return ret;
        }
        case JG_MD_PAD6B: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "pad6b1" : index == 1 ? "pad6b2" :
                index == 2 ? "pad6b3" : index == 3 ? "pad6b4" :
                index == 4 ? "pad6b5" : index == 5 ? "pad6b6" :
                index == 6 ? "pad6b7" : "pad6b8";
            ret.fname = jg_md_input_name[type];
            ret.defs = defs_mdpad6b;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_MDPAD6B;
            return ret;
        }
        case JG_MD_JUSTIFIER: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "mdjustifier";
            ret.fname = jg_md_input_name[type];
            ret.defs = defs_mdjustifier;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_MDJUSTIFIER;
            return ret;
        }
        case JG_MD_MENACER: {
            ret.type = JG_INPUT_POINTER;
            ret.index = index;
            ret.name = "menacer";
            ret.fname = jg_md_input_name[type];
            ret.defs = defs_menacer;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_MENACER;
            return ret;
        }
        case JG_MD_MENACER | 0x80: { // Menacer with Crosshair
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "menacer";
            ret.fname = jg_md_input_name[4];
            ret.defs = defs_menacer;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_MENACER;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_md_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
