/*
Part of the Enhanced Native Trainer project.
https://github.com/gtav-ent/GTAV-EnhancedNativeTrainer
(C) Rob Pridham and fellow contributors 2015
*/

#include "config_io.h"
#include "keyboard.h"
#include "..\debug\debuglog.h"
#include "..\ui_support\entcolor.h"
#include <sstream>
#include "..\features\script.h"
#include "..\features\fuel.h"

// 在文件开头添加新的函数
int get_game_button_from_name(const char* name) {
    // 从 INPUT_ 枚举定义中获取对应值
	if(strcmp(name, "INPUT_NEXT_CAMERA") == 0) return 0;
    if(strcmp(name, "INPUT_LOOK_LR") == 0) return 1;
    if(strcmp(name, "INPUT_LOOK_UD") == 0) return 2;
    if(strcmp(name, "INPUT_LOOK_UP_ONLY") == 0) return 3;
    if(strcmp(name, "INPUT_LOOK_DOWN_ONLY") == 0) return 4;
    if(strcmp(name, "INPUT_LOOK_LEFT_ONLY") == 0) return 5;
    if(strcmp(name, "INPUT_LOOK_RIGHT_ONLY") == 0) return 6;
    if(strcmp(name, "INPUT_CINEMATIC_SLOWMO") == 0) return 7;
    if(strcmp(name, "INPUT_SCRIPTED_FLY_UD") == 0) return 8;
    if(strcmp(name, "INPUT_SCRIPTED_FLY_LR") == 0) return 9;
    if(strcmp(name, "INPUT_SCRIPTED_FLY_ZUP") == 0) return 10;
    if(strcmp(name, "INPUT_SCRIPTED_FLY_ZDOWN") == 0) return 11;
    if(strcmp(name, "INPUT_WEAPON_WHEEL_UD") == 0) return 12;
    if(strcmp(name, "INPUT_WEAPON_WHEEL_LR") == 0) return 13;
    if(strcmp(name, "INPUT_WEAPON_WHEEL_NEXT") == 0) return 14;
    if(strcmp(name, "INPUT_WEAPON_WHEEL_PREV") == 0) return 15;
    if(strcmp(name, "INPUT_SELECT_NEXT_WEAPON") == 0) return 16;
    if(strcmp(name, "INPUT_SELECT_PREV_WEAPON") == 0) return 17;
    if(strcmp(name, "INPUT_SKIP_CUTSCENE") == 0) return 18;
    if(strcmp(name, "INPUT_CHARACTER_WHEEL") == 0) return 19;
    if(strcmp(name, "INPUT_MULTIPLAYER_INFO") == 0) return 20;
    if(strcmp(name, "INPUT_SPRINT") == 0) return 21;
    if(strcmp(name, "INPUT_JUMP") == 0) return 22;
    if(strcmp(name, "INPUT_ENTER") == 0) return 23;
    if(strcmp(name, "INPUT_ATTACK") == 0) return 24;
    if(strcmp(name, "INPUT_AIM") == 0) return 25;
    if(strcmp(name, "INPUT_LOOK_BEHIND") == 0) return 26;
    if(strcmp(name, "INPUT_PHONE") == 0) return 27;
    if(strcmp(name, "INPUT_SPECIAL_ABILITY") == 0) return 28;
    if(strcmp(name, "INPUT_SPECIAL_ABILITY_SECONDARY") == 0) return 29;
    if(strcmp(name, "INPUT_MOVE_LR") == 0) return 30;
    if(strcmp(name, "INPUT_MOVE_UD") == 0) return 31;
    if(strcmp(name, "INPUT_MOVE_UP_ONLY") == 0) return 32;
    if(strcmp(name, "INPUT_MOVE_DOWN_ONLY") == 0) return 33;
    if(strcmp(name, "INPUT_MOVE_LEFT_ONLY") == 0) return 34;
    if(strcmp(name, "INPUT_MOVE_RIGHT_ONLY") == 0) return 35;
    if(strcmp(name, "INPUT_DUCK") == 0) return 36;
    if(strcmp(name, "INPUT_SELECT_WEAPON") == 0) return 37;
    if(strcmp(name, "INPUT_PICKUP") == 0) return 38;
    if(strcmp(name, "INPUT_SNIPER_ZOOM") == 0) return 39;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_IN_ONLY") == 0) return 40;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_OUT_ONLY") == 0) return 41;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_IN_SECONDARY") == 0) return 42;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_OUT_SECONDARY") == 0) return 43;
    if(strcmp(name, "INPUT_COVER") == 0) return 44;
    if(strcmp(name, "INPUT_RELOAD") == 0) return 45;
    if(strcmp(name, "INPUT_TALK") == 0) return 46;
    if(strcmp(name, "INPUT_DETONATE") == 0) return 47;
    if(strcmp(name, "INPUT_HUD_SPECIAL") == 0) return 48;
    if(strcmp(name, "INPUT_ARREST") == 0) return 49;
    if(strcmp(name, "INPUT_ACCURATE_AIM") == 0) return 50;
    if(strcmp(name, "INPUT_CONTEXT") == 0) return 51;
    if(strcmp(name, "INPUT_CONTEXT_SECONDARY") == 0) return 52;
    if(strcmp(name, "INPUT_WEAPON_SPECIAL") == 0) return 53;
    if(strcmp(name, "INPUT_WEAPON_SPECIAL_TWO") == 0) return 54;
    if(strcmp(name, "INPUT_DIVE") == 0) return 55;
    if(strcmp(name, "INPUT_DROP_WEAPON") == 0) return 56;
    if(strcmp(name, "INPUT_DROP_AMMO") == 0) return 57;
    if(strcmp(name, "INPUT_THROW_GRENADE") == 0) return 58;
    if(strcmp(name, "INPUT_VEH_MOVE_LR") == 0) return 59;
    if(strcmp(name, "INPUT_VEH_MOVE_UD") == 0) return 60;
    if(strcmp(name, "INPUT_VEH_MOVE_UP_ONLY") == 0) return 61;
    if(strcmp(name, "INPUT_VEH_MOVE_DOWN_ONLY") == 0) return 62;
    if(strcmp(name, "INPUT_VEH_MOVE_LEFT_ONLY") == 0) return 63;
    if(strcmp(name, "INPUT_VEH_MOVE_RIGHT_ONLY") == 0) return 64;
    if(strcmp(name, "INPUT_VEH_SPECIAL") == 0) return 65;
    if(strcmp(name, "INPUT_VEH_GUN_LR") == 0) return 66;
    if(strcmp(name, "INPUT_VEH_GUN_UD") == 0) return 67;
    if(strcmp(name, "INPUT_VEH_AIM") == 0) return 68;
    if(strcmp(name, "INPUT_VEH_ATTACK") == 0) return 69;
    if(strcmp(name, "INPUT_VEH_ATTACK2") == 0) return 70;
    if(strcmp(name, "INPUT_VEH_ACCELERATE") == 0) return 71;
    if(strcmp(name, "INPUT_VEH_BRAKE") == 0) return 72;
    if(strcmp(name, "INPUT_VEH_DUCK") == 0) return 73;
    if(strcmp(name, "INPUT_VEH_HEADLIGHT") == 0) return 74;
    if(strcmp(name, "INPUT_VEH_EXIT") == 0) return 75;
    if(strcmp(name, "INPUT_VEH_HANDBRAKE") == 0) return 76;
    if(strcmp(name, "INPUT_VEH_HOTWIRE_LEFT") == 0) return 77;
    if(strcmp(name, "INPUT_VEH_HOTWIRE_RIGHT") == 0) return 78;
    if(strcmp(name, "INPUT_VEH_LOOK_BEHIND") == 0) return 79;
    if(strcmp(name, "INPUT_VEH_CIN_CAM") == 0) return 80;
    if(strcmp(name, "INPUT_VEH_NEXT_RADIO") == 0) return 81;
    if(strcmp(name, "INPUT_VEH_PREV_RADIO") == 0) return 82;
    if(strcmp(name, "INPUT_VEH_NEXT_RADIO_TRACK") == 0) return 83;
    if(strcmp(name, "INPUT_VEH_PREV_RADIO_TRACK") == 0) return 84;
    if(strcmp(name, "INPUT_VEH_RADIO_WHEEL") == 0) return 85;
    if(strcmp(name, "INPUT_VEH_HORN") == 0) return 86;
    if(strcmp(name, "INPUT_VEH_FLY_THROTTLE_UP") == 0) return 87;
    if(strcmp(name, "INPUT_VEH_FLY_THROTTLE_DOWN") == 0) return 88;
    if(strcmp(name, "INPUT_VEH_FLY_YAW_LEFT") == 0) return 89;
    if(strcmp(name, "INPUT_VEH_FLY_YAW_RIGHT") == 0) return 90;
    if(strcmp(name, "INPUT_VEH_PASSENGER_AIM") == 0) return 91;
    if(strcmp(name, "INPUT_VEH_PASSENGER_ATTACK") == 0) return 92;
    if(strcmp(name, "INPUT_VEH_SPECIAL_ABILITY_FRANKLIN") == 0) return 93;
    if(strcmp(name, "INPUT_VEH_STUNT_UD") == 0) return 94;
    if(strcmp(name, "INPUT_VEH_CINEMATIC_UD") == 0) return 95;
    if(strcmp(name, "INPUT_VEH_CINEMATIC_UP_ONLY") == 0) return 96;
    if(strcmp(name, "INPUT_VEH_CINEMATIC_DOWN_ONLY") == 0) return 97;
    if(strcmp(name, "INPUT_VEH_CINEMATIC_LR") == 0) return 98;
    if(strcmp(name, "INPUT_VEH_SELECT_NEXT_WEAPON") == 0) return 99;
    if(strcmp(name, "INPUT_VEH_SELECT_PREV_WEAPON") == 0) return 100;
    if(strcmp(name, "INPUT_VEH_ROOF") == 0) return 101;
    if(strcmp(name, "INPUT_VEH_JUMP") == 0) return 102;
    if(strcmp(name, "INPUT_VEH_GRAPPLING_HOOK") == 0) return 103;
    if(strcmp(name, "INPUT_VEH_SHUFFLE") == 0) return 104;
    if(strcmp(name, "INPUT_VEH_DROP_PROJECTILE") == 0) return 105;
    if(strcmp(name, "INPUT_VEH_MOUSE_CONTROL_OVERRIDE") == 0) return 106;
    if(strcmp(name, "INPUT_VEH_FLY_ROLL_LR") == 0) return 107;
    if(strcmp(name, "INPUT_VEH_FLY_ROLL_LEFT_ONLY") == 0) return 108;
    if(strcmp(name, "INPUT_VEH_FLY_ROLL_RIGHT_ONLY") == 0) return 109;
    if(strcmp(name, "INPUT_VEH_FLY_PITCH_UD") == 0) return 110;
    if(strcmp(name, "INPUT_VEH_FLY_PITCH_UP_ONLY") == 0) return 111;
    if(strcmp(name, "INPUT_VEH_FLY_PITCH_DOWN_ONLY") == 0) return 112;
    if(strcmp(name, "INPUT_VEH_FLY_UNDERCARRIAGE") == 0) return 113;
    if(strcmp(name, "INPUT_VEH_FLY_ATTACK") == 0) return 114;
    if(strcmp(name, "INPUT_VEH_FLY_SELECT_NEXT_WEAPON") == 0) return 115;
    if(strcmp(name, "INPUT_VEH_FLY_SELECT_PREV_WEAPON") == 0) return 116;
    if(strcmp(name, "INPUT_VEH_FLY_SELECT_TARGET_LEFT") == 0) return 117;
    if(strcmp(name, "INPUT_VEH_FLY_SELECT_TARGET_RIGHT") == 0) return 118;
    if(strcmp(name, "INPUT_VEH_FLY_VERTICAL_FLIGHT_MODE") == 0) return 119;
    if(strcmp(name, "INPUT_VEH_FLY_DUCK") == 0) return 120;
    if(strcmp(name, "INPUT_VEH_FLY_ATTACK_CAMERA") == 0) return 121;
    if(strcmp(name, "INPUT_VEH_FLY_MOUSE_CONTROL_OVERRIDE") == 0) return 122;
    if(strcmp(name, "INPUT_VEH_SUB_TURN_LR") == 0) return 123;
    if(strcmp(name, "INPUT_VEH_SUB_TURN_LEFT_ONLY") == 0) return 124;
    if(strcmp(name, "INPUT_VEH_SUB_TURN_RIGHT_ONLY") == 0) return 125;
    if(strcmp(name, "INPUT_VEH_SUB_PITCH_UD") == 0) return 126;
    if(strcmp(name, "INPUT_VEH_SUB_PITCH_UP_ONLY") == 0) return 127;
    if(strcmp(name, "INPUT_VEH_SUB_PITCH_DOWN_ONLY") == 0) return 128;
    if(strcmp(name, "INPUT_VEH_SUB_THROTTLE_UP") == 0) return 129;
    if(strcmp(name, "INPUT_VEH_SUB_THROTTLE_DOWN") == 0) return 130;
    if(strcmp(name, "INPUT_VEH_SUB_ASCEND") == 0) return 131;
    if(strcmp(name, "INPUT_VEH_SUB_DESCEND") == 0) return 132;
    if(strcmp(name, "INPUT_VEH_SUB_TURN_HARD_LEFT") == 0) return 133;
    if(strcmp(name, "INPUT_VEH_SUB_TURN_HARD_RIGHT") == 0) return 134;
    if(strcmp(name, "INPUT_VEH_SUB_MOUSE_CONTROL_OVERRIDE") == 0) return 135;
    if(strcmp(name, "INPUT_VEH_PUSHBIKE_PEDAL") == 0) return 136;
    if(strcmp(name, "INPUT_VEH_PUSHBIKE_SPRINT") == 0) return 137;
    if(strcmp(name, "INPUT_VEH_PUSHBIKE_FRONT_BRAKE") == 0) return 138;
    if(strcmp(name, "INPUT_VEH_PUSHBIKE_REAR_BRAKE") == 0) return 139;
    if(strcmp(name, "INPUT_MELEE_ATTACK_LIGHT") == 0) return 140;
    if(strcmp(name, "INPUT_MELEE_ATTACK_HEAVY") == 0) return 141;
    if(strcmp(name, "INPUT_MELEE_ATTACK_ALTERNATE") == 0) return 142;
    if(strcmp(name, "INPUT_MELEE_BLOCK") == 0) return 143;
    if(strcmp(name, "INPUT_PARACHUTE_DEPLOY") == 0) return 144;
    if(strcmp(name, "INPUT_PARACHUTE_DETACH") == 0) return 145;
    if(strcmp(name, "INPUT_PARACHUTE_TURN_LR") == 0) return 146;
    if(strcmp(name, "INPUT_PARACHUTE_TURN_LEFT_ONLY") == 0) return 147;
    if(strcmp(name, "INPUT_PARACHUTE_TURN_RIGHT_ONLY") == 0) return 148;
    if(strcmp(name, "INPUT_PARACHUTE_PITCH_UD") == 0) return 149;
    if(strcmp(name, "INPUT_PARACHUTE_PITCH_UP_ONLY") == 0) return 150;
    if(strcmp(name, "INPUT_PARACHUTE_PITCH_DOWN_ONLY") == 0) return 151;
    if(strcmp(name, "INPUT_PARACHUTE_BRAKE_LEFT") == 0) return 152;
    if(strcmp(name, "INPUT_PARACHUTE_BRAKE_RIGHT") == 0) return 153;
    if(strcmp(name, "INPUT_PARACHUTE_SMOKE") == 0) return 154;
    if(strcmp(name, "INPUT_PARACHUTE_PRECISION_LANDING") == 0) return 155;
    if(strcmp(name, "INPUT_MAP") == 0) return 156;
    if(strcmp(name, "INPUT_SELECT_WEAPON_UNARMED") == 0) return 157;
    if(strcmp(name, "INPUT_SELECT_WEAPON_MELEE") == 0) return 158;
    if(strcmp(name, "INPUT_SELECT_WEAPON_HANDGUN") == 0) return 159;
    if(strcmp(name, "INPUT_SELECT_WEAPON_SHOTGUN") == 0) return 160;
    if(strcmp(name, "INPUT_SELECT_WEAPON_SMG") == 0) return 161;
    if(strcmp(name, "INPUT_SELECT_WEAPON_AUTO_RIFLE") == 0) return 162;
    if(strcmp(name, "INPUT_SELECT_WEAPON_SNIPER") == 0) return 163;
    if(strcmp(name, "INPUT_SELECT_WEAPON_HEAVY") == 0) return 164;
    if(strcmp(name, "INPUT_SELECT_WEAPON_SPECIAL") == 0) return 165;
    if(strcmp(name, "INPUT_SELECT_CHARACTER_MICHAEL") == 0) return 166;
    if(strcmp(name, "INPUT_SELECT_CHARACTER_FRANKLIN") == 0) return 167;
    if(strcmp(name, "INPUT_SELECT_CHARACTER_TREVOR") == 0) return 168;
    if(strcmp(name, "INPUT_SELECT_CHARACTER_MULTIPLAYER") == 0) return 169;
    if(strcmp(name, "INPUT_SAVE_REPLAY_CLIP") == 0) return 170;
    if(strcmp(name, "INPUT_SPECIAL_ABILITY_PC") == 0) return 171;
    if(strcmp(name, "INPUT_CELLPHONE_UP") == 0) return 172;
    if(strcmp(name, "INPUT_CELLPHONE_DOWN") == 0) return 173;
    if(strcmp(name, "INPUT_CELLPHONE_LEFT") == 0) return 174;
    if(strcmp(name, "INPUT_CELLPHONE_RIGHT") == 0) return 175;
    if(strcmp(name, "INPUT_CELLPHONE_SELECT") == 0) return 176;
    if(strcmp(name, "INPUT_CELLPHONE_CANCEL") == 0) return 177;
    if(strcmp(name, "INPUT_CELLPHONE_OPTION") == 0) return 178;
    if(strcmp(name, "INPUT_CELLPHONE_EXTRA_OPTION") == 0) return 179;
    if(strcmp(name, "INPUT_CELLPHONE_SCROLL_FORWARD") == 0) return 180;
    if(strcmp(name, "INPUT_CELLPHONE_SCROLL_BACKWARD") == 0) return 181;
    if(strcmp(name, "INPUT_CELLPHONE_CAMERA_FOCUS_LOCK") == 0) return 182;
    if(strcmp(name, "INPUT_CELLPHONE_CAMERA_GRID") == 0) return 183;
    if(strcmp(name, "INPUT_CELLPHONE_CAMERA_SELFIE") == 0) return 184;
    if(strcmp(name, "INPUT_CELLPHONE_CAMERA_DOF") == 0) return 185;
    if(strcmp(name, "INPUT_CELLPHONE_CAMERA_EXPRESSION") == 0) return 186;
    if(strcmp(name, "INPUT_FRONTEND_DOWN") == 0) return 187;
    if(strcmp(name, "INPUT_FRONTEND_UP") == 0) return 188;
    if(strcmp(name, "INPUT_FRONTEND_LEFT") == 0) return 189;
    if(strcmp(name, "INPUT_FRONTEND_RIGHT") == 0) return 190;
    if(strcmp(name, "INPUT_FRONTEND_RDOWN") == 0) return 191;
    if(strcmp(name, "INPUT_FRONTEND_RUP") == 0) return 192;
    if(strcmp(name, "INPUT_FRONTEND_RLEFT") == 0) return 193;
    if(strcmp(name, "INPUT_FRONTEND_RRIGHT") == 0) return 194;
    if(strcmp(name, "INPUT_FRONTEND_AXIS_X") == 0) return 195;
    if(strcmp(name, "INPUT_FRONTEND_AXIS_Y") == 0) return 196;
    if(strcmp(name, "INPUT_FRONTEND_RIGHT_AXIS_X") == 0) return 197;
    if(strcmp(name, "INPUT_FRONTEND_RIGHT_AXIS_Y") == 0) return 198;
    if(strcmp(name, "INPUT_FRONTEND_PAUSE") == 0) return 199;
    if(strcmp(name, "INPUT_FRONTEND_PAUSE_ALTERNATE") == 0) return 200;
    if(strcmp(name, "INPUT_FRONTEND_ACCEPT") == 0) return 201;
    if(strcmp(name, "INPUT_FRONTEND_CANCEL") == 0) return 202;
    if(strcmp(name, "INPUT_FRONTEND_X") == 0) return 203;
    if(strcmp(name, "INPUT_FRONTEND_Y") == 0) return 204;
    if(strcmp(name, "INPUT_FRONTEND_LB") == 0) return 205;
    if(strcmp(name, "INPUT_FRONTEND_RB") == 0) return 206;
    if(strcmp(name, "INPUT_FRONTEND_LT") == 0) return 207;
    if(strcmp(name, "INPUT_FRONTEND_RT") == 0) return 208;
    if(strcmp(name, "INPUT_FRONTEND_LS") == 0) return 209;
    if(strcmp(name, "INPUT_FRONTEND_RS") == 0) return 210;
    if(strcmp(name, "INPUT_FRONTEND_LEADERBOARD") == 0) return 211;
    if(strcmp(name, "INPUT_FRONTEND_SOCIAL_CLUB") == 0) return 212;
    if(strcmp(name, "INPUT_FRONTEND_SOCIAL_CLUB_SECONDARY") == 0) return 213;
    if(strcmp(name, "INPUT_FRONTEND_DELETE") == 0) return 214;
    if(strcmp(name, "INPUT_FRONTEND_ENDSCREEN_ACCEPT") == 0) return 215;
    if(strcmp(name, "INPUT_FRONTEND_ENDSCREEN_EXPAND") == 0) return 216;
    if(strcmp(name, "INPUT_FRONTEND_SELECT") == 0) return 217;
    if(strcmp(name, "INPUT_SCRIPT_LEFT_AXIS_X") == 0) return 218;
    if(strcmp(name, "INPUT_SCRIPT_LEFT_AXIS_Y") == 0) return 219;
    if(strcmp(name, "INPUT_SCRIPT_RIGHT_AXIS_X") == 0) return 220;
    if(strcmp(name, "INPUT_SCRIPT_RIGHT_AXIS_Y") == 0) return 221;
    if(strcmp(name, "INPUT_SCRIPT_RUP") == 0) return 222;
    if(strcmp(name, "INPUT_SCRIPT_RDOWN") == 0) return 223;
    if(strcmp(name, "INPUT_SCRIPT_RLEFT") == 0) return 224;
    if(strcmp(name, "INPUT_SCRIPT_RRIGHT") == 0) return 225;
    if(strcmp(name, "INPUT_SCRIPT_LB") == 0) return 226;
    if(strcmp(name, "INPUT_SCRIPT_RB") == 0) return 227;
    if(strcmp(name, "INPUT_SCRIPT_LT") == 0) return 228;
    if(strcmp(name, "INPUT_SCRIPT_RT") == 0) return 229;
    if(strcmp(name, "INPUT_SCRIPT_LS") == 0) return 230;
    if(strcmp(name, "INPUT_SCRIPT_RS") == 0) return 231;
    if(strcmp(name, "INPUT_SCRIPT_PAD_UP") == 0) return 232;
    if(strcmp(name, "INPUT_SCRIPT_PAD_DOWN") == 0) return 233;
    if(strcmp(name, "INPUT_SCRIPT_PAD_LEFT") == 0) return 234;
    if(strcmp(name, "INPUT_SCRIPT_PAD_RIGHT") == 0) return 235;
    if(strcmp(name, "INPUT_SCRIPT_SELECT") == 0) return 236;
    if(strcmp(name, "INPUT_CURSOR_ACCEPT") == 0) return 237;
    if(strcmp(name, "INPUT_CURSOR_CANCEL") == 0) return 238;
    if(strcmp(name, "INPUT_CURSOR_X") == 0) return 239;
    if(strcmp(name, "INPUT_CURSOR_Y") == 0) return 240;
    if(strcmp(name, "INPUT_CURSOR_SCROLL_UP") == 0) return 241;
    if(strcmp(name, "INPUT_CURSOR_SCROLL_DOWN") == 0) return 242;
    if(strcmp(name, "INPUT_ENTER_CHEAT_CODE") == 0) return 243;
    if(strcmp(name, "INPUT_INTERACTION_MENU") == 0) return 244;
    if(strcmp(name, "INPUT_MP_TEXT_CHAT_ALL") == 0) return 245;
    if(strcmp(name, "INPUT_MP_TEXT_CHAT_TEAM") == 0) return 246;
    if(strcmp(name, "INPUT_MP_TEXT_CHAT_FRIENDS") == 0) return 247;
    if(strcmp(name, "INPUT_MP_TEXT_CHAT_CREW") == 0) return 248;
    if(strcmp(name, "INPUT_PUSH_TO_TALK") == 0) return 249;
    if(strcmp(name, "INPUT_CREATOR_LS") == 0) return 250;
    if(strcmp(name, "INPUT_CREATOR_RS") == 0) return 251;
    if(strcmp(name, "INPUT_CREATOR_LT") == 0) return 252;
    if(strcmp(name, "INPUT_CREATOR_RT") == 0) return 253;
    if(strcmp(name, "INPUT_CREATOR_MENU_TOGGLE") == 0) return 254;
    if(strcmp(name, "INPUT_CREATOR_ACCEPT") == 0) return 255;
    if(strcmp(name, "INPUT_CREATOR_DELETE") == 0) return 256;
    if(strcmp(name, "INPUT_ATTACK2") == 0) return 257;
    if(strcmp(name, "INPUT_RAPPEL_JUMP") == 0) return 258;
    if(strcmp(name, "INPUT_RAPPEL_LONG_JUMP") == 0) return 259;
    if(strcmp(name, "INPUT_RAPPEL_SMASH_WINDOW") == 0) return 260;
    if(strcmp(name, "INPUT_PREV_WEAPON") == 0) return 261;
    if(strcmp(name, "INPUT_NEXT_WEAPON") == 0) return 262;
    if(strcmp(name, "INPUT_MELEE_ATTACK1") == 0) return 263;
    if(strcmp(name, "INPUT_MELEE_ATTACK2") == 0) return 264;
    if(strcmp(name, "INPUT_WHISTLE") == 0) return 265;
    if(strcmp(name, "INPUT_MOVE_LEFT") == 0) return 266;
    if(strcmp(name, "INPUT_MOVE_RIGHT") == 0) return 267;
    if(strcmp(name, "INPUT_MOVE_UP") == 0) return 268;
    if(strcmp(name, "INPUT_MOVE_DOWN") == 0) return 269;
    if(strcmp(name, "INPUT_LOOK_LEFT") == 0) return 270;
    if(strcmp(name, "INPUT_LOOK_RIGHT") == 0) return 271;
    if(strcmp(name, "INPUT_LOOK_UP") == 0) return 272;
    if(strcmp(name, "INPUT_LOOK_DOWN") == 0) return 273;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_IN") == 0) return 274;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_OUT") == 0) return 275;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_IN_ALTERNATE") == 0) return 276;
    if(strcmp(name, "INPUT_SNIPER_ZOOM_OUT_ALTERNATE") == 0) return 277;
    if(strcmp(name, "INPUT_VEH_MOVE_LEFT") == 0) return 278;
    if(strcmp(name, "INPUT_VEH_MOVE_RIGHT") == 0) return 279;
    if(strcmp(name, "INPUT_VEH_MOVE_UP") == 0) return 280;
    if(strcmp(name, "INPUT_VEH_MOVE_DOWN") == 0) return 281;
    if(strcmp(name, "INPUT_VEH_GUN_LEFT") == 0) return 282;
    if(strcmp(name, "INPUT_VEH_GUN_RIGHT") == 0) return 283;
    if(strcmp(name, "INPUT_VEH_GUN_UP") == 0) return 284;
    if(strcmp(name, "INPUT_VEH_GUN_DOWN") == 0) return 285;
    if(strcmp(name, "INPUT_VEH_LOOK_LEFT") == 0) return 286;
    if(strcmp(name, "INPUT_VEH_LOOK_RIGHT") == 0) return 287;
    if(strcmp(name, "INPUT_REPLAY_START_STOP_RECORDING") == 0) return 288;
    if(strcmp(name, "INPUT_REPLAY_START_STOP_RECORDING_SECONDARY") == 0) return 289;
    if(strcmp(name, "INPUT_SCALED_LOOK_LR") == 0) return 290;
    if(strcmp(name, "INPUT_SCALED_LOOK_UD") == 0) return 291;
    if(strcmp(name, "INPUT_SCALED_LOOK_UP_ONLY") == 0) return 292;
    if(strcmp(name, "INPUT_SCALED_LOOK_DOWN_ONLY") == 0) return 293;
    if(strcmp(name, "INPUT_SCALED_LOOK_LEFT_ONLY") == 0) return 294;
    if(strcmp(name, "INPUT_SCALED_LOOK_RIGHT_ONLY") == 0) return 295;
    if(strcmp(name, "INPUT_REPLAY_MARKER_DELETE") == 0) return 296;
    if(strcmp(name, "INPUT_REPLAY_CLIP_DELETE") == 0) return 297;
    if(strcmp(name, "INPUT_REPLAY_PAUSE") == 0) return 298;
    if(strcmp(name, "INPUT_REPLAY_REWIND") == 0) return 299;
    if(strcmp(name, "INPUT_REPLAY_FFWD") == 0) return 300;
    if(strcmp(name, "INPUT_REPLAY_NEWMARKER") == 0) return 301;
    if(strcmp(name, "INPUT_REPLAY_RECORD") == 0) return 302;
    if(strcmp(name, "INPUT_REPLAY_SCREENSHOT") == 0) return 303;
    if(strcmp(name, "INPUT_REPLAY_HIDEHUD") == 0) return 304;
    if(strcmp(name, "INPUT_REPLAY_STARTPOINT") == 0) return 305;
    if(strcmp(name, "INPUT_REPLAY_ENDPOINT") == 0) return 306;
    if(strcmp(name, "INPUT_REPLAY_ADVANCE") == 0) return 307;
    if(strcmp(name, "INPUT_REPLAY_BACK") == 0) return 308;
    if(strcmp(name, "INPUT_REPLAY_TOOLS") == 0) return 309;
    if(strcmp(name, "INPUT_REPLAY_RESTART") == 0) return 310;
    if(strcmp(name, "INPUT_REPLAY_SHOWHOTKEY") == 0) return 311;
    if(strcmp(name, "INPUT_REPLAY_CYCLEMARKERLEFT") == 0) return 312;
    if(strcmp(name, "INPUT_REPLAY_CYCLEMARKERRIGHT") == 0) return 313;
    if(strcmp(name, "INPUT_REPLAY_FOVINCREASE") == 0) return 314;
    if(strcmp(name, "INPUT_REPLAY_FOVDECREASE") == 0) return 315;
    if(strcmp(name, "INPUT_REPLAY_CAMERAUP") == 0) return 316;
    if(strcmp(name, "INPUT_REPLAY_CAMERADOWN") == 0) return 317;
    if(strcmp(name, "INPUT_REPLAY_SAVE") == 0) return 318;
    if(strcmp(name, "INPUT_REPLAY_TOGGLETIME") == 0) return 319;
    if(strcmp(name, "INPUT_REPLAY_TOGGLETIPS") == 0) return 320;
    if(strcmp(name, "INPUT_REPLAY_PREVIEW") == 0) return 321;
    if(strcmp(name, "INPUT_REPLAY_TOGGLE_TIMELINE") == 0) return 322;
    if(strcmp(name, "INPUT_REPLAY_TIMELINE_PICKUP_CLIP") == 0) return 323;
    if(strcmp(name, "INPUT_REPLAY_TIMELINE_DUPLICATE_CLIP") == 0) return 324;
    if(strcmp(name, "INPUT_REPLAY_TIMELINE_PLACE_CLIP") == 0) return 325;
    if(strcmp(name, "INPUT_REPLAY_CTRL") == 0) return 326;
    if(strcmp(name, "INPUT_REPLAY_TIMELINE_SAVE") == 0) return 327;
    if(strcmp(name, "INPUT_REPLAY_PREVIEW_AUDIO") == 0) return 328;
    if(strcmp(name, "INPUT_VEH_DRIVE_LOOK") == 0) return 329;
    if(strcmp(name, "INPUT_VEH_DRIVE_LOOK2") == 0) return 330;
    if(strcmp(name, "INPUT_VEH_FLY_ATTACK2") == 0) return 331;
    if(strcmp(name, "INPUT_RADIO_WHEEL_UD") == 0) return 332;
    if(strcmp(name, "INPUT_RADIO_WHEEL_LR") == 0) return 333;
    if(strcmp(name, "INPUT_VEH_SLOWMO_UD") == 0) return 334;
    if(strcmp(name, "INPUT_VEH_SLOWMO_UP_ONLY") == 0) return 335;
    if(strcmp(name, "INPUT_VEH_SLOWMO_DOWN_ONLY") == 0) return 336;
    if(strcmp(name, "INPUT_MAP_POI") == 0) return 337;
    return -1; // 未找到映射返回-1
}

// A global Windows "basic string". Actual memory is allocated by the
// COM methods used by MSXML which take &keyconf_bstr. We must use SysFreeString() 
// to free this memory before subsequent uses, to prevent a leak.
BSTR keyconf_bstr;

TrainerConfig *config = NULL;

/**Read the XML config file. Currently contains keyboard choices.*/
void read_config_file(){
	TrainerConfig *result = new TrainerConfig();

	CoInitialize(NULL);

	//read XML
	MSXML2::IXMLDOMDocumentPtr spXMLDoc;
	spXMLDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60));
	if(!spXMLDoc->load("Enhanced Native Trainer/ent-config.xml")){
		write_text_to_log_file("No config found, using defaults");
		config = result; //the default config
	}

	// keyboard binds
	IXMLDOMNodeListPtr nodes = spXMLDoc->selectNodes(L"//ent-config/keys/key");
	long length;
	nodes->get_length(&length);
	for(int i = 0; i < length; i++){
		IXMLDOMNode *node;
		nodes->get_item(i, &node);
		IXMLDOMNamedNodeMap *attribs;
		node->get_attributes(&attribs);

		long length_attribs;
		attribs->get_length(&length_attribs);

		char *attrib_key_func = NULL;
		char *attrib_key_value = NULL;
		bool modCtrl = false;
		bool modAlt = false;
		bool modShift = false;

		for(long j = 0; j < length_attribs; j++){
			IXMLDOMNode *attribNode;
			attribs->get_item(j, &attribNode);
			attribNode->get_nodeName(&keyconf_bstr);
			if(wcscmp(keyconf_bstr, L"function") == 0){
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_key_func = _com_util::ConvertBSTRToString(V_BSTR(&var));
			}
			else if(wcscmp(keyconf_bstr, L"value") == 0){
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_key_value = _com_util::ConvertBSTRToString(V_BSTR(&var));
			}
			else if(wcscmp(keyconf_bstr, L"modCtrl") == 0){
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				char* value = _com_util::ConvertBSTRToString(V_BSTR(&var));
				if(value != 0 && _strcmpi(value, "true") == 0){
					modCtrl = true;
				}
			}
			else if(wcscmp(keyconf_bstr, L"modAlt") == 0){
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				char* value = _com_util::ConvertBSTRToString(V_BSTR(&var));
				if(value != 0 && _strcmpi(value, "true") == 0){
					modAlt = true;
				}
			}
			else if(wcscmp(keyconf_bstr, L"modShift") == 0){
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				char* value = _com_util::ConvertBSTRToString(V_BSTR(&var));
				if(value != 0 && _strcmpi(value, "true") == 0){
					modShift = true;
				}
			}

			SysFreeString(keyconf_bstr);
			attribNode->Release();
		}

		if(attrib_key_func != NULL && attrib_key_value != NULL){
			result->get_key_config()->set_key(attrib_key_func, attrib_key_value, modCtrl, modAlt, modShift);
		}

		delete attrib_key_func;
		delete attrib_key_value;

		attribs->Release();
		node->Release();
	}

	// controller binds
	nodes = spXMLDoc->selectNodes(L"//ent-config/controller_keys/controller");
	nodes->get_length(&length);
	for (int i = 0; i < length; i++) {
		IXMLDOMNode* node;
		nodes->get_item(i, &node);
		IXMLDOMNamedNodeMap* attribs;
		node->get_attributes(&attribs);

		long length_attribs;
		attribs->get_length(&length_attribs);

		char* attrib_controller_func = NULL;
		int attrib_button1_v = NULL;
		int attrib_button2_v = NULL;

		for (long j = 0; j < length_attribs; j++) {
			IXMLDOMNode* attribNode;
			attribs->get_item(j, &attribNode);
			attribNode->get_nodeName(&keyconf_bstr);
			if (wcscmp(keyconf_bstr, L"function") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_controller_func = _com_util::ConvertBSTRToString(V_BSTR(&var));
			}
			else if (wcscmp(keyconf_bstr, L"button1") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_button1_v = std::stoi(_com_util::ConvertBSTRToString(V_BSTR(&var)));
			}
			else if (wcscmp(keyconf_bstr, L"button2") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_button2_v = std::stoi(_com_util::ConvertBSTRToString(V_BSTR(&var)));
			}

			SysFreeString(keyconf_bstr);
			attribNode->Release();
		}

		// here must be a code to store keybinds somewhere.
		if (attrib_controller_func != NULL) {
 
			if (attrib_button1_v == NULL)
			{
				std::stringstream ss;
				ss << "[ERROR] Problem reading " << attrib_controller_func << "'s function. Button1's value was NULL! Skipping and the default value(s) will be used instead.";
				write_text_to_log_file(ss.str());
				continue;
			}

			if (controller_binds.find(attrib_controller_func) != controller_binds.end())
			{
				std::stringstream ss;
				ss << "Controller function " << attrib_controller_func << " given value: " << attrib_button1_v << " and " << attrib_button2_v;
				write_text_to_log_file(ss.str());
				controller_binds.at(attrib_controller_func) = std::pair(attrib_button1_v, attrib_button2_v);
			}
			else 
			{
				std::stringstream ss;
				ss << "[ERROR] Could not find controller function " << attrib_controller_func << " in controller bind map. Skipping.";
				write_text_to_log_file(ss.str());
				continue;
			}
		}
		else
		{
			std::stringstream ss;
			ss << "[ERROR] Controller function with button IDs " << attrib_button1_v << " and " << attrib_button2_v << " was NULL! Skipping.";
			write_text_to_log_file(ss.str());
			continue;
		}

		delete attrib_controller_func;
	
		attribs->Release();
		node->Release();
	}

	// extra map stuff list
	nodes = spXMLDoc->selectNodes(L"//ent-config/map_stuff_list/stuff");
	nodes->get_length(&length);
	for (int i = 0; i < length; i++) {
		IXMLDOMNode* node;
		nodes->get_item(i, &node);
		IXMLDOMNamedNodeMap* attribs;
		node->get_attributes(&attribs);

		long length_attribs;
		attribs->get_length(&length_attribs);

		char* map_stuff = NULL;
		
		for (long j = 0; j < length_attribs; j++) {
			IXMLDOMNode* attribNode;
			attribs->get_item(j, &attribNode);
			attribNode->get_nodeName(&keyconf_bstr);
			if (wcscmp(keyconf_bstr, L"sname") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				map_stuff = _com_util::ConvertBSTRToString(V_BSTR(&var));
				MAP_STUFF = MAP_STUFF + map_stuff + " ";
			}
			SysFreeString(keyconf_bstr);
			attribNode->Release();
		}

		delete map_stuff;
		
		attribs->Release();
		node->Release();
	}

	// weather list
	nodes = spXMLDoc->selectNodes(L"//ent-config/weather_list/weather");
	nodes->get_length(&length);
	for (int i = 0; i < length; i++) {
		IXMLDOMNode* node;
		nodes->get_item(i, &node);
		IXMLDOMNamedNodeMap* attribs;
		node->get_attributes(&attribs);

		long length_attribs;
		attribs->get_length(&length_attribs);

		char* attrib_weather = NULL;

		for (long j = 0; j < length_attribs; j++) {
			IXMLDOMNode* attribNode;
			attribs->get_item(j, &attribNode);
			attribNode->get_nodeName(&keyconf_bstr);
			if (wcscmp(keyconf_bstr, L"name") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_weather = _com_util::ConvertBSTRToString(V_BSTR(&var));
				if (i == 0) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 1) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 2) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 3) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 4) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 5) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 6) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 7) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 8) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 9) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 10) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 11) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 12) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 13) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var)) + " ";
				if (i == 14) C_WEATHER_C = C_WEATHER_C + _com_util::ConvertBSTRToString(V_BSTR(&var));
			}

			SysFreeString(keyconf_bstr);
			attribNode->Release();
		}

		delete attrib_weather;

		attribs->Release();
		node->Release();
	}

	// gas stations
	nodes = spXMLDoc->selectNodes(L"//ent-config/gas_stations/station");
	nodes->get_length(&length);
	for (int i = 0; i < length; i++) {
		IXMLDOMNode* node;
		nodes->get_item(i, &node);
		IXMLDOMNamedNodeMap* attribs;
		node->get_attributes(&attribs);

		long length_attribs;
		attribs->get_length(&length_attribs);

		char* attrib_station_x_coord = NULL;
		char* attrib_station_y_coord = NULL;
		char* attrib_station_z_coord = NULL;

		for (long j = 0; j < length_attribs; j++) {
			IXMLDOMNode* attribNode;
			attribs->get_item(j, &attribNode);
			attribNode->get_nodeName(&keyconf_bstr);
			if (wcscmp(keyconf_bstr, L"x_coord") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_station_x_coord = _com_util::ConvertBSTRToString(V_BSTR(&var));
				GAS_X.push_back(std::stoi(attrib_station_x_coord));
			}
			else if (wcscmp(keyconf_bstr, L"y_coord") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_station_y_coord = _com_util::ConvertBSTRToString(V_BSTR(&var));
				GAS_Y.push_back(std::stoi(attrib_station_y_coord));
			}
			else if (wcscmp(keyconf_bstr, L"z_coord") == 0) {
				VARIANT var;
				VariantInit(&var);
				attribNode->get_nodeValue(&var);
				attrib_station_z_coord = _com_util::ConvertBSTRToString(V_BSTR(&var));
				GAS_Z.push_back(std::stoi(attrib_station_z_coord));
			}

			SysFreeString(keyconf_bstr);
			attribNode->Release();
		}

		delete attrib_station_x_coord;
		delete attrib_station_y_coord;
		delete attrib_station_z_coord;

		attribs->Release();
		node->Release();
	}

	//nodes->Release(); //don't do this, it crashes on exit
	spXMLDoc.Release();
	CoUninitialize();

	config = result;
}

void read_config_ini_file(){
	int tmpv[12][4];
	const char *sectionMenuColor = "MenuColor", *file = "Enhanced Native Trainer/ent_customization.ini";
	const std::string tmpk[] = {"r", "g", "b", "a"};
	std::ifstream tmp(file);
	bool notexist = !((bool) tmp);
	tmp.close();

	if(notexist){
		write_text_to_log_file("INI file does not exist.\nUsing default settings.\nINI file will be created upon saving in-game.");
		return;
	}

	for(int a = 0; a < ENTColor::colsVarsNum; a++){
		for(int b = 0; b < 4; b++){
			tmpv[a][b] = GetPrivateProfileInt(sectionMenuColor, (ENTColor::colsVarsReverse.at(a) + tmpk[b]).c_str(), -1, file);
		}
		if(!(tmpv[a][0] < 0 || tmpv[a][1] < 0 || tmpv[a][2] < 0 || tmpv[a][3] < 0) || !(tmpv[a][0] > 255 || tmpv[a][1] > 255 || tmpv[a][2] > 255 || tmpv[a][3] > 255)){
			for(int b = 0; b < 4; b++){
				ENTColor::colsMenu[a].rgba[b] = tmpv[a][b];
			}
		}
	}
}

void write_config_ini_file(){
	const char *sectionMenuColor = "MenuColor", *file = "Enhanced Native Trainer/ent_customization.ini";
	const std::string tmpk[] = {"r", "g", "b", "a"};
	std::ofstream ini;
	std::ifstream tmp(file);
	bool notexist = !((bool) tmp);
	tmp.close();

	for(int a = 0; a < ENTColor::colsVarsNum; a++){
		for(int b = 0; b < 4; b++){
			WritePrivateProfileString(sectionMenuColor, (ENTColor::colsVarsReverse.at(a) + tmpk[b]).c_str(), std::to_string(ENTColor::colsMenu[a].rgba[b]).c_str(), file);
		}
	}

	if(notexist){
		tmp.open(file);
		if(tmp.is_open()){
			std::vector<std::string> lines, result;
			for(std::string line; std::getline(tmp, line); ){
				lines.push_back(line);
			}
			tmp.close();

			result.push_back(std::string(";;;; Enhanced Native Trainer: Configuration INI File (Begin) ;;;;\n\n;;; (Delete this file to revert to defaults) ;;;\n"));

			result.push_back(std::string(";; Menu Colors (Begin) ;;\n;\tFollows the RGBA color system, 0 ~ 255 for each component of a color;"));
			for(auto a : lines){
				for(int b = 0; b < ENTColor::colsVarsNum; b++){
					if(a.compare(0, ENTColor::colsVarsReverse.at(b).length() + 1, (ENTColor::colsVarsReverse.at(b) + tmpk[0])) == 0){
						result.push_back(std::string("; ") + ENTColor::colsCaptions[b] + std::string(" ;"));
						break;
					}
				}
				result.push_back(a);
			}
			result.push_back(std::string(";; Menu Colors (End) ;;"));

			result.push_back(std::string("\n;;;; Enhanced Native Trainer: Configuration INI File (End) ;;;;"));

			ini.open(file, std::ofstream::out | std::ofstream::trunc);
			if(ini.is_open()){
				for(auto a : result){
					ini << a << std::endl;
				}

				ini.close();
			}
		}
	}
}

void KeyInputConfig::set_key(char* function, char* keyName, bool modCtrl, bool modAlt, bool modShift)
{
    // 判断是否为游戏按键名称
    if(strncmp(keyName, "INPUT_", 6) == 0) {
        // 从eButton枚举获取游戏按键值
        int gameButton = get_game_button_from_name(keyName);
        if(gameButton != -1) {
            auto match = keyConfigs.find(function);
            if(match != keyConfigs.end()) {
                KeyConfig* oldConfig = match->second;
                match->second = new KeyConfig(0, gameButton); // 使用游戏按键
                match->second->modCtrl = modCtrl;
                match->second->modAlt = modAlt;
                match->second->modShift = modShift;
                delete oldConfig;
                return;
            }
        }
    }

    // 原有的VK键值处理
    int vkID = keyNameToVal(keyName);
    // ...原有代码...
}

bool KeyInputConfig::is_hotkey_assigned(int i){

	std::string target;
	switch(i){
		case 1:
			target = KeyConfig::KEY_HOT_1;
			break;
		case 2:
			target = KeyConfig::KEY_HOT_2;
			break;
		case 3:
			target = KeyConfig::KEY_HOT_3;
			break;
		case 4:
			target = KeyConfig::KEY_HOT_4;
			break;
		case 5:
			target = KeyConfig::KEY_HOT_5;
			break;
		case 6:
			target = KeyConfig::KEY_HOT_6;
			break;
		case 7:
			target = KeyConfig::KEY_HOT_7;
			break;
		case 8:
			target = KeyConfig::KEY_HOT_8;
			break;
		case 9:
			target = KeyConfig::KEY_HOT_9;
			break;
		default:
			return false;
	}

	KeyConfig* conf = this->keyConfigs[target];
	if(conf == NULL || conf->keyCode == 0){
		return false;
	}
	return true;
}

TrainerConfig::TrainerConfig(){
	this->keyConfig = new KeyInputConfig();
}

KeyInputConfig::KeyInputConfig(){
	this->keyConfigs[KeyConfig::KEY_TOGGLE_MAIN_MENU] = new KeyConfig(VK_F4);

	this->keyConfigs[KeyConfig::KEY_MENU_UP] = new KeyConfig(VK_NUMPAD8);
	this->keyConfigs[KeyConfig::KEY_MENU_DOWN] = new KeyConfig(VK_NUMPAD2);
	this->keyConfigs[KeyConfig::KEY_MENU_LEFT] = new KeyConfig(VK_NUMPAD4);
	this->keyConfigs[KeyConfig::KEY_MENU_RIGHT] = new KeyConfig(VK_NUMPAD6);
	this->keyConfigs[KeyConfig::KEY_MENU_SELECT] = new KeyConfig(VK_NUMPAD5);
	this->keyConfigs[KeyConfig::KEY_MENU_BACK] = new KeyConfig(VK_NUMPAD0);

	this->keyConfigs[KeyConfig::KEY_VEH_BOOST] = new KeyConfig(VK_NUMPAD9);
	this->keyConfigs[KeyConfig::KEY_VEH_STOP] = new KeyConfig(VK_NUMPAD3);
	this->keyConfigs[KeyConfig::KEY_VEH_ROCKETS] = new KeyConfig(VK_ADD);
	this->keyConfigs[KeyConfig::KEY_VEH_LEFTBLINK] = new KeyConfig(VK_LEFT);
	this->keyConfigs[KeyConfig::KEY_VEH_RIGHTBLINK] = new KeyConfig(VK_RIGHT);
	this->keyConfigs[KeyConfig::KEY_VEH_EMERGENCYBLINK] = new KeyConfig(VK_DECIMAL);
	this->keyConfigs[KeyConfig::KEY_VEH_STARTREFUELING] = new KeyConfig(VK_KEY_E);
	this->keyConfigs[KeyConfig::KEY_VEH_STOPREFUELING] = new KeyConfig(VK_KEY_S);
	
	this->keyConfigs[KeyConfig::KEY_TOGGLE_AIRBRAKE] = new KeyConfig(VK_F6);

	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_UP] = new KeyConfig(VK_KEY_Q);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_DOWN] = new KeyConfig(VK_KEY_Z);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_FORWARD] = new KeyConfig(VK_KEY_W);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_BACK] = new KeyConfig(VK_KEY_S);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_ROTATE_LEFT] = new KeyConfig(VK_KEY_A);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_ROTATE_RIGHT] = new KeyConfig(VK_KEY_D);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_SPEED] = new KeyConfig(VK_SHIFT);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_FREEZE_TIME] = new KeyConfig(VK_KEY_T);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_HELP] = new KeyConfig(VK_KEY_H);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_SPACE] = new KeyConfig(VK_SPACE);
	this->keyConfigs[KeyConfig::KEY_AIRBRAKE_MOUSE_CONTROL] = new KeyConfig(VK_KEY_M);

	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_UP] = new KeyConfig(VK_KEY_Q);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_DOWN] = new KeyConfig(VK_KEY_Z);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_FORWARD] = new KeyConfig(VK_KEY_W);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_BACK] = new KeyConfig(VK_KEY_S);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_ROTATE_LEFT] = new KeyConfig(VK_KEY_A);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_ROTATE_RIGHT] = new KeyConfig(VK_KEY_D);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_SPEED_UP] = new KeyConfig(VK_OEM_6);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_SPEED_DOWN] = new KeyConfig(VK_OEM_4);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_FREEZE_TIME] = new KeyConfig(VK_KEY_T);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_HELP] = new KeyConfig(VK_KEY_H);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_FREEZE_POSITION] = new KeyConfig(VK_KEY_G);
	this->keyConfigs[KeyConfig::KEY_OBJECTPLACER_ALT_MOVE] = new KeyConfig(VK_MENU);

	this->keyConfigs[KeyConfig::KEY_HOT_1] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_2] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_3] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_4] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_5] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_6] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_7] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_8] = new KeyConfig(0);
	this->keyConfigs[KeyConfig::KEY_HOT_9] = new KeyConfig(0);

}

KeyInputConfig::~KeyInputConfig(){
	for each (std::pair<std::string, KeyConfig*> conf in this->keyConfigs){
		delete conf.second;
	}
	keyConfigs.clear();
}

KeyConfig* KeyInputConfig::get_key(std::string function){
	auto match = keyConfigs.find(function);
	if(match != keyConfigs.end()){
		return match->second;
	}
	return NULL;
}

const std::string KeyConfig::KEY_TOGGLE_MAIN_MENU = std::string("toggle_main_menu");
const std::string KeyConfig::KEY_TOGGLE_AIRBRAKE = std::string("toggle_airbrake");

const std::string KeyConfig::KEY_MENU_UP = std::string("menu_up");
const std::string KeyConfig::KEY_MENU_DOWN = std::string("menu_down");
const std::string KeyConfig::KEY_MENU_LEFT = std::string("menu_left");
const std::string KeyConfig::KEY_MENU_RIGHT = std::string("menu_right");
const std::string KeyConfig::KEY_MENU_SELECT = std::string("menu_select");
const std::string KeyConfig::KEY_MENU_BACK = std::string("menu_back");

const std::string KeyConfig::KEY_VEH_BOOST = std::string("veh_boost");
const std::string KeyConfig::KEY_VEH_STOP = std::string("veh_stop");
const std::string KeyConfig::KEY_VEH_ROCKETS = std::string("veh_rockets");
const std::string KeyConfig::KEY_VEH_LEFTBLINK = std::string("veh_leftblink");
const std::string KeyConfig::KEY_VEH_RIGHTBLINK = std::string("veh_rightblink");
const std::string KeyConfig::KEY_VEH_EMERGENCYBLINK = std::string("veh_emergencyblink");
const std::string KeyConfig::KEY_VEH_STARTREFUELING = std::string("veh_startrefueling");
const std::string KeyConfig::KEY_VEH_STOPREFUELING = std::string("veh_stoprefueling");

const std::string KeyConfig::KEY_AIRBRAKE_UP = std::string("airbrake_up");
const std::string KeyConfig::KEY_AIRBRAKE_DOWN = std::string("airbrake_down");
const std::string KeyConfig::KEY_AIRBRAKE_FORWARD = std::string("airbrake_forward");
const std::string KeyConfig::KEY_AIRBRAKE_BACK = std::string("airbrake_back");
const std::string KeyConfig::KEY_AIRBRAKE_ROTATE_LEFT = std::string("airbrake_rotate_left");
const std::string KeyConfig::KEY_AIRBRAKE_ROTATE_RIGHT = std::string("airbrake_rotate_right");
const std::string KeyConfig::KEY_AIRBRAKE_SPEED = std::string("airbrake_speed");
const std::string KeyConfig::KEY_AIRBRAKE_FREEZE_TIME = std::string("airbrake_freeze_time");
const std::string KeyConfig::KEY_AIRBRAKE_HELP = std::string("airbrake_help");
const std::string KeyConfig::KEY_AIRBRAKE_SPACE = std::string("airbrake_move_aside");
const std::string KeyConfig::KEY_AIRBRAKE_MOUSE_CONTROL = std::string("airbrake_mouse_control");

const std::string KeyConfig::KEY_OBJECTPLACER_UP = std::string("objectplacer_up");
const std::string KeyConfig::KEY_OBJECTPLACER_DOWN = std::string("objectplacer_down");
const std::string KeyConfig::KEY_OBJECTPLACER_FORWARD = std::string("objectplacer_forward");
const std::string KeyConfig::KEY_OBJECTPLACER_BACK = std::string("objectplacer_back");
const std::string KeyConfig::KEY_OBJECTPLACER_ROTATE_LEFT = std::string("objectplacer_rotate_left");
const std::string KeyConfig::KEY_OBJECTPLACER_ROTATE_RIGHT = std::string("objectplacer_rotate_right");
const std::string KeyConfig::KEY_OBJECTPLACER_SPEED_CYCLE = std::string("objectplacer_speed_cycle");
const std::string KeyConfig::KEY_OBJECTPLACER_SPEED_UP = std::string("objectplacer_speed_up");
const std::string KeyConfig::KEY_OBJECTPLACER_SPEED_DOWN = std::string("objectplacer_speed_down");
const std::string KeyConfig::KEY_OBJECTPLACER_FREEZE_TIME = std::string("objectplacer_freeze_time");
const std::string KeyConfig::KEY_OBJECTPLACER_FREEZE_POSITION = std::string("objectplacer_freeze_position");
const std::string KeyConfig::KEY_OBJECTPLACER_HELP = std::string("objectplacer_help");
const std::string KeyConfig::KEY_OBJECTPLACER_ALT_MOVE = std::string("objectplacer_alt_move");

const std::string KeyConfig::KEY_HOT_1 = std::string("hotkey_1");
const std::string KeyConfig::KEY_HOT_2 = std::string("hotkey_2");
const std::string KeyConfig::KEY_HOT_3 = std::string("hotkey_3");
const std::string KeyConfig::KEY_HOT_4 = std::string("hotkey_4");
const std::string KeyConfig::KEY_HOT_5 = std::string("hotkey_5");
const std::string KeyConfig::KEY_HOT_6 = std::string("hotkey_6");
const std::string KeyConfig::KEY_HOT_7 = std::string("hotkey_7");
const std::string KeyConfig::KEY_HOT_8 = std::string("hotkey_8");
const std::string KeyConfig::KEY_HOT_9 = std::string("hotkey_9");

//Bind name -> button ID 1 and button ID 2. For keys with only 1 button ID - use -1 as a "no bind" value.
std::map<std::string, std::pair<int, int>> controller_binds =
{
	{ "KEY_TOGGLE_MAIN_MENU", {206, 192} },
	{ "KEY_TOGGLE_AIRBRAKE", {201, 206} },
	{ "KEY_MENU_UP", {188, -1} },
	{ "KEY_MENU_DOWN", {187, -1} },
	{ "KEY_MENU_LEFT", {189, -1} },
	{ "KEY_MENU_RIGHT", {190, -1} },
	{ "KEY_MENU_SELECT", {201, 1} },
	{ "KEY_MENU_BACK", {202, -1} },
	{ "KEY_VEH_BOOST", {206, 24} },
	{ "KEY_VEH_STOP", {205, 25} },
	{ "KEY_VEH_ROCKETS", {205, 206} },
	{ "KEY_VEH_LEFTBLINK", {25, -1} },
	{ "KEY_VEH_RIGHTBLINK", {24, -1} },
	{ "KEY_VEH_EMERGENCYBLINK", {202, -1} },
	{ "KEY_VEH_STARTREFUELING", {201, -1} },
	{ "KEY_VEH_STOPREFUELING", {202, -1} },
	{ "KEY_AIRBRAKE_UP", {25, -1} },
	{ "KEY_AIRBRAKE_DOWN", {24, -1} },
	{ "KEY_AIRBRAKE_FORWARD", {32, -1} },
	{ "KEY_AIRBRAKE_BACK", {33, -1} },
	{ "KEY_AIRBRAKE_ROTATE_LEFT", {205, -1} },
	{ "KEY_AIRBRAKE_ROTATE_RIGHT", {206, -1} },
	{ "KEY_AIRBRAKE_SPEED", {201, -1} },
	{ "KEY_AIRBRAKE_FREEZE_TIME", {202, -1} },
	{ "KEY_AIRBRAKE_HELP", {-1, -1} }, //No bind in the XML?
	{ "KEY_AIRBRAKE_SPACE", {-1, -1} }, //No bind in the XML?
	{ "KEY_AIRBRAKE_MOUSE_CONTROL", {-1, -1} }, //No bind in the XML?
	{ "KEY_OBJECTPLACER_UP", {25, -1} },
	{ "KEY_OBJECTPLACER_DOWN", {24, -1} },
	{ "KEY_OBJECTPLACER_FORWARD", {32, -1} },
	{ "KEY_OBJECTPLACER_BACK", {33, -1} },
	{ "KEY_OBJECTPLACER_ROTATE_LEFT", {205, -1} },
	{ "KEY_OBJECTPLACER_ROTATE_RIGHT", {206, -1} },
	{ "KEY_OBJECTPLACER_SPEED_CYCLE", {201, -1} },
	{ "KEY_OBJECTPLACER_SPEED_UP", {-1, -1} },  //No bind in the XML?
	{ "KEY_OBJECTPLACER_SPEED_DOWN", {-1, -1} }, //No bind in the XML?
	{ "KEY_OBJECTPLACER_FREEZE_TIME", {202, -1} },
	{ "KEY_OBJECTPLACER_FREEZE_POSITION", {192, -1} },
	{ "KEY_OBJECTPLACER_HELP", {-1, -1} },  //No bind in the XML?
	{ "KEY_OBJECTPLACER_ALT_MOVE", {-1, -1} }, //No bind in the XML?
};