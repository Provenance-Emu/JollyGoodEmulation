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

#ifndef JG_SMS_H
#define JG_SMS_H

enum jg_sms_input_type {
    JG_SMS_UNCONNECTED,
    JG_SMS_PAD,
    JG_SMS_LIGHTPHASER,
    JG_SMS_PADDLE,
    JG_SMS_TEREBIOEKAKI,
    JG_SMS_SYS
};

static const char *jg_sms_input_name[] = {
    "Unconnected",
    "SMS Control Pad",
    "Light Phaser",
    "SMS Paddle",
    "Terebi Oekaki",
    "SMS System"
};

// SMS Control Pad
#define NDEFS_SMSPAD 6
static const char *defs_smspad[NDEFS_SMSPAD] = {
    "Up", "Down", "Left", "Right", "B1", "B2"
};

// Light Phaser
#define NDEFS_LIGHTPHASER 2
static const char *defs_lightphaser[NDEFS_LIGHTPHASER] = {
    "Trigger", "Offscreen"
};

// Paddle
#define NDEFS_SMSPADDLE 2
static const char *defs_smspaddle[NDEFS_SMSPADDLE] = {
    "Dial", "Button"
};

// SMS System Buttons
#define NDEFS_SMSSYS 2
static const char *defs_smssys[NDEFS_SMSSYS] = {
    "Reset", "Pause"
};

// Terebi Oekaki
#define NDEFS_TEREBIOEKAKI 1
static const char *defs_terebi[NDEFS_TEREBIOEKAKI] = {
    "Press"
};

static jg_inputinfo_t jg_sms_inputinfo(int index, int type) {
    jg_inputinfo_t ret;
    switch (type) {
        case JG_SMS_PAD: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name =  index == 0 ? "smspad1" : "smspad2";
            ret.fname = jg_sms_input_name[type];
            ret.defs = defs_smspad;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SMSPAD;
            return ret;
        }
        case JG_SMS_LIGHTPHASER: {
            ret.type = JG_INPUT_GUN;
            ret.index = index;
            ret.name = "lightphaser";
            ret.fname = jg_sms_input_name[type];
            ret.defs = defs_lightphaser;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_LIGHTPHASER;
            return ret;
        }
        case JG_SMS_PADDLE: {
            ret.type = JG_INPUT_CONTROLLER;
            ret.index = index;
            ret.name = index == 0 ? "smspaddle1" : "smspaddle2";
            ret.fname = jg_sms_input_name[type];
            ret.defs = defs_smspaddle;
            ret.numaxes = ret.numbuttons = 1;
            return ret;
        }
        case JG_SMS_TEREBIOEKAKI: {
            ret.type = JG_INPUT_POINTER;
            ret.index = index;
            ret.name = "terebi";
            ret.fname = jg_sms_input_name[type];
            ret.defs = defs_terebi;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_TEREBIOEKAKI;
            return ret;
        }
        case JG_SMS_SYS: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "smssystem";
            ret.fname = jg_sms_input_name[type];
            ret.defs = defs_smssys;
            ret.numaxes = 0;
            ret.numbuttons = NDEFS_SMSSYS;
            return ret;
        }
        default: {
            ret.type = JG_INPUT_EXTERNAL;
            ret.index = index;
            ret.name = "unconnected";
            ret.fname = jg_sms_input_name[0];
            ret.defs = NULL;
            ret.numaxes = ret.numbuttons = 0;
            return ret;
        }
    }
}

#endif
