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

#ifndef JG_COLECO_H
#define JG_COLECO_H

enum jg_coleco_input_type {
    JG_COLECO_UNCONNECTED,
    JG_COLECO_PAD,
    JG_COLECO_ROLLER,
    JG_COLECO_SAC,
    JG_COLECO_SKETCH,
    JG_COLECO_WHEEL
};

static const char *jg_coleco_input_name[] = {
    "Unconnected",
    "ColecoVision Paddle",
    "Roller Controller",
    "Super Action Controller",
    "Super Sketch",
    "Steering Wheel"
};

#define NDEFS_COLECOPAD 18
static const char *defs_colecopad[NDEFS_COLECOPAD] = {
    "Up", "Down", "Left", "Right", "FireL", "FireR",
    "Button1", "Button2", "Button3", "Button4", "Button5", "Button6",
    "Button7", "Button8", "Button9", "Button0", "Star", "Pound"
};

#define NDEFS_COLECOSAC 22
static const char *defs_colecosac[NDEFS_COLECOSAC] = {
    "Up", "Down", "Left", "Right", "Yellow", "Orange", "Purple", "Blue",
    "Button1", "Button2", "Button3", "Button4", "Button5", "Button6",
    "Button7", "Button8", "Button9", "Button0", "Star", "Pound",
    "RollerL", "RollerR"
};

#define NDEFS_COLECOSKETCH 4
static const char *defs_colecosketch[NDEFS_COLECOSKETCH] = {
    "Lift", "Select", "Release", "Menu"
};

#define NDEFS_COLECOWHEEL 17
static const char *defs_colecowheel[NDEFS_COLECOWHEEL] = {
    "Accelerator", "StickUp", "StickDown", "StickLeft", "StickRight",
    "Button1", "Button2", "Button3", "Button4", "Button5", "Button6",
    "Button7", "Button8", "Button9", "Button0", "Star", "Pound"
};

static jg_inputinfo_t jg_coleco_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_COLECO_PAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "colecopad1" : "colecopad2";
            ret.fname = jg_coleco_input_name[type];
            ret.defs = defs_colecopad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_COLECOPAD;
            return ret;
        }
        case JG_COLECO_ROLLER: {
            ret.type = JG_INPUT_POINTER;
            ret.index = index;
            ret.name = index == 0 ? "colecoroller1" : "colecoroller2";
            ret.fname = jg_coleco_input_name[type];
            ret.defs = defs_colecopad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_COLECOPAD;
            return ret;
        }
        case JG_COLECO_SAC: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "colecosac1" : "colecosac2";
            ret.fname = jg_coleco_input_name[type];
            ret.defs = defs_colecosac;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_COLECOSAC;
            return ret;
        }
        case JG_COLECO_SKETCH: {
            ret.type = JG_INPUT_POINTER;
            ret.index = index;
            ret.name = "colecosketch";
            ret.fname = jg_coleco_input_name[type];
            ret.defs = defs_colecosketch;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_COLECOSKETCH;
            return ret;
        }
        case JG_COLECO_WHEEL: {
            ret.type = JG_INPUT_SPINNER;
            ret.index = index;
            ret.name = "colecowheel";
            ret.fname = jg_coleco_input_name[type];
            ret.defs = defs_colecowheel;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_COLECOWHEEL;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_coleco_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
