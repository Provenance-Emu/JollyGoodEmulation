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

#ifndef JG_NGP_H
#define JG_NGP_H

#define NDEFS_NGP 7
static const char *defs_ngp[NDEFS_NGP] = {
    "Up", "Down", "Left", "Right", "A", "B", "Option"
};

static jg_inputinfo_t jg_ngp_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    if (type) { }
    ret.type = JG_INPUT_CONTROLLER;
    ret.index = index;
    ret.name = "ngp";
    ret.fname = "Neo Geo Pocket";
    ret.defs = defs_ngp;
    ret.numaxes = 0;
    ret.numbuttons = NDEFS_NGP;
    return ret;
}

#endif
