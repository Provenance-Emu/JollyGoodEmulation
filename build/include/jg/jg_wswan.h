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

#ifndef JG_WSWAN_H
#define JG_WSWAN_H

#define NDEFS_WSWAN 11
static const char *defs_wswan[NDEFS_WSWAN] = {
    "X1", "X2", "X3", "X4", "Y1", "Y2", "Y3", "Y4", "Start", "A", "B"
};

static jg_inputinfo_t jg_wswan_inputinfo(int index, int type) {
    if (type) { }
    jg_inputinfo_t ret;
    ret.type = JG_INPUT_CONTROLLER;
    ret.index = index;
    ret.name = "wswan";
    ret.fname = "WonderSwan";
    ret.defs = defs_wswan;
    ret.numaxes = 0;
    ret.numbuttons = NDEFS_WSWAN;
    return ret;
}

#endif
