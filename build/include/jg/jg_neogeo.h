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

#ifndef JG_NEOGEO_H
#define JG_NEOGEO_H

enum jg_neogeo_input_type {
    JG_NEOGEO_UNCONNECTED,
    JG_NEOGEO_JS,
    JG_NEOGEO_SYS,
};

static const char *jg_neogeo_input_name[] = {
    "Unconnected",
    "Neo Geo Joystick",
    "Neo Geo System"
};

#define NDEFS_NEOGEOJS 10
static const char *defs_neogeojs[NDEFS_NEOGEOJS] = {
    "Up", "Down", "Left", "Right", "Select", "Start", "A", "B", "C", "D"
};

#define NDEFS_NEOGEOSYS 2
static const char *defs_neogeosys[NDEFS_NEOGEOSYS] = { "Coin1", "Coin2" };

static jg_inputinfo_t jg_neogeo_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_NEOGEO_JS: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "neogeojs1" : "neogeojs2";
            ret.fname = jg_neogeo_input_name[type];
            ret.defs = defs_neogeojs;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_NEOGEOJS;
            return ret;
        }
        case JG_NEOGEO_SYS: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "neogeosystem";
            ret.fname = jg_neogeo_input_name[type];
            ret.defs = defs_neogeosys;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_NEOGEOSYS;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_neogeo_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
