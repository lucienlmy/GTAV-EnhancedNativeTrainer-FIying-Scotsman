/*
Some of this code began its life as a part of GTA V SCRIPT HOOK SDK.
http://dev-c.com
(C) Alexander Blade 2015

It is now part of the Enhanced Native Trainer project.
https://github.com/gtav-ent/GTAV-EnhancedNativeTrainer
(C) Rob Pridham and fellow contributors 2015
*/

#include "io.h"
#include "config_io.h"
#include "..\features\script.h"
#include <string>
#include <sstream>
#include "../io/controller.h"

DWORD trainerResetTime = 0;

bool gameInputDisabledByUs = false;
bool gameInputBlockedByUs = false;

bool trainer_switch_pressed()
{
	/*std::stringstream ss;
	ss << "Map first: " << controller_binds["KEY_TOGGLE_MAIN_MENU"].first << " Map second: " << controller_binds["KEY_TOGGLE_MAIN_MENU"].second;
	set_status_text_centre_screen(ss.str());*/

	bool result = IsKeyJustUp(KeyConfig::KEY_TOGGLE_MAIN_MENU) || (CONTROLS::IS_CONTROL_PRESSED(2, controller_binds["KEY_TOGGLE_MAIN_MENU"].first) && CONTROLS::IS_CONTROL_JUST_PRESSED(2, controller_binds["KEY_TOGGLE_MAIN_MENU"].second)); //INPUT_FRONTEND_RB + INPUT_ENTER (Y)
	if (result)
	{
		//avoid repeat of key press
		DWORD maxTickCount = GetTickCount() + 200;
		do
		{
			make_periodic_feature_call();
			WAIT(0);
		} while (GetTickCount() < maxTickCount);
	}
	return result;
}

void get_button_state(bool* a, bool* b, bool* up, bool* down, bool* l, bool* r)
{
	KeyInputConfig* keyConf = config->get_key_config();
	// 确认键 - 数字键盘5和游戏按键
	if (a) *a = IsKeyJustUp(KeyConfig::KEY_MENU_SELECT) ||
		IsKeyJustUp(VK_NUMPAD5) ||
		CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_ACCEPT); //A //IS_DISABLED_CONTROL_PRESSED

	// 返回键 - 数字键盘0和游戏按键
	if (b) *b = (is_menu_showing() && !IsKeyJustUp(VK_ESCAPE) &&
		(IsKeyJustUp(KeyConfig::KEY_MENU_BACK) || IsKeyJustUp(VK_NUMPAD0))) ||
		(is_menu_showing() && (CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_CANCEL) ||
			CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_PAUSE))); //B

	if (MISC_TRAINERCONTROL_VALUES[TrainerControlIndex] == 1)
	{ // press
		// 同时检查配置的按键、固定的数字键盘和游戏按键
		if (up) *up = IsKeyDown(KeyConfig::KEY_MENU_UP) ||
			IsKeyDown(VK_NUMPAD8) ||
			CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_UP); //Dpad up

		if (down) *down = IsKeyDown(KeyConfig::KEY_MENU_DOWN) ||
			IsKeyDown(VK_NUMPAD2) ||
			CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_DOWN); //Dpad down

		if (r) *r = IsKeyDown(KeyConfig::KEY_MENU_RIGHT) ||
			IsKeyDown(VK_NUMPAD6) ||
			CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RIGHT); //Dpad right

		if (l) *l = IsKeyDown(KeyConfig::KEY_MENU_LEFT) ||
			IsKeyDown(VK_NUMPAD4) ||
			CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LEFT); //Dpad left
	}
	if (MISC_TRAINERCONTROL_VALUES[TrainerControlIndex] == 0)
	{ // release
		if (up) *up = IsKeyJustUp(KeyConfig::KEY_MENU_UP) ||
			IsKeyJustUp(VK_NUMPAD8) ||
			CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_UP);

		if (down) *down = IsKeyJustUp(KeyConfig::KEY_MENU_DOWN) ||
			IsKeyJustUp(VK_NUMPAD2) ||
			CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_DOWN);

		if (r) *r = IsKeyJustUp(KeyConfig::KEY_MENU_RIGHT) ||
			IsKeyJustUp(VK_NUMPAD6) ||
			CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_RIGHT);

		if (l) *l = IsKeyJustUp(KeyConfig::KEY_MENU_LEFT) ||
			IsKeyJustUp(VK_NUMPAD4) ||
			CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_LEFT);
	}
}

bool get_key_pressed(int nVirtKey)
{
	//return (GetKeyState(nVirtKey) & 0x8000) != 0;
	return (GetAsyncKeyState(nVirtKey) & 0x8000) != 0;
}

bool airbrake_switch_pressed()
{
	bool result = IsKeyJustUp(KeyConfig::KEY_TOGGLE_AIRBRAKE) || (CONTROLS::IS_CONTROL_PRESSED(2, controller_binds["KEY_TOGGLE_AIRBRAKE"].first) && CONTROLS::IS_CONTROL_JUST_PRESSED(2, controller_binds["KEY_TOGGLE_AIRBRAKE"].second)); //INPUT_FRONTEND_ACCEPT (A) + INPUT_FRONTEND_RB (RB)
	if (result)
	{
		//avoid repeat of key press
		DWORD maxTickCount = GetTickCount() + 200;
		do
		{
			make_periodic_feature_call();
			WAIT(0);
		} while (GetTickCount() < maxTickCount);
	}
	return result;
}

void reset_trainer_switch()
{
	trainerResetTime = GetTickCount();
}

void setGameInputToEnabled(bool enabled, bool force)
{
	if (enabled && (gameInputDisabledByUs || force))
	{
		PLAYER::SET_PLAYER_CONTROL(0, 1, 0);
		gameInputDisabledByUs = false;
	}
	else if (!enabled)
	{
		PLAYER::SET_PLAYER_CONTROL(0, 0, 256);
		gameInputDisabledByUs = true;
	}
}

void setAirbrakeRelatedInputToBlocked(bool blocked, bool force)
{
	if (blocked || force || (!blocked && gameInputBlockedByUs))
	{
		void(*function)(int index, int control, BOOL enable);
		if (blocked)
		{
			function = CONTROLS::DISABLE_CONTROL_ACTION;
		}
		else
		{
			function = CONTROLS::ENABLE_CONTROL_ACTION;
		}
		
		function(2, 332, 1); //radio wheel up
		function(2, 333, 1); //radio wheel down

		for (int i = 81; i <= 85; i++)
		{
			function(2, i, 1); //radio stuff
		}

		gameInputBlockedByUs = blocked;
	}
}