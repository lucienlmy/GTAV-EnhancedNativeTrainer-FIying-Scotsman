/*
		THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
					http://dev-c.com
				(C) Alexander Blade 2015
*/

#include "..\io\keyboard.h"
#include "..\features\script.h"
#include "..\debug\debuglog.h"

#include <sstream>

const int KEYS_SIZE = 255;

struct {
	DWORD time;
	BOOL isWithAlt;
	BOOL wasDownBefore;
	BOOL isUpNow;
} keyStates[KEYS_SIZE];

void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow)
{
	if (key < KEYS_SIZE)
	{
		keyStates[key].time = GetTickCount();
		keyStates[key].isWithAlt = isWithAlt;
		keyStates[key].wasDownBefore = wasDownBefore;
		keyStates[key].isUpNow = isUpNow;
	}
}

const int NOW_PERIOD = 100, MAX_DOWN = 5000; // ms

// 函数实现时不要包含默认参数
bool IsKeyDown(DWORD key, bool isGameButton) 
{
    if(key == 0) {
        return false;
    }

    if(isGameButton) {
        return CONTROLS::IS_CONTROL_PRESSED(2, key);
    } else {
        return (GetAsyncKeyState(key) & 0x8000) != 0;
    }
}

bool IsKeyDown(std::string keyName) {
    KeyConfig* key = get_config()->get_key_config()->get_key(keyName);
    if(key == NULL || (key->keyCode == 0 && key->gameButton == -1)) {
        return false;
    }
    
    bool result;
    if(key->useGameButton) {
        result = CONTROLS::IS_CONTROL_PRESSED(2, key->gameButton);
    } else {
        result = (GetAsyncKeyState(key->keyCode) & 0x8000) != 0;
    }

    // 检查修饰键
    if(result && key->modAlt) {
        result = (GetKeyState(VK_MENU) & 0x8000) != 0;
    }
    if(result && key->modShift) {
        result = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
    }
    if(result && key->modCtrl) {
        result = (GetKeyState(VK_LCONTROL) & 0x8000 || GetKeyState(VK_RCONTROL) & 0x8000);
    }
    
    return result;
}

// 添加单参数版本
bool IsKeyJustUp(DWORD key)
{
    return IsKeyJustUp(key, false, true); // 默认non-game button, exclusive=true
}

// 实现双参数版本(带默认exclusive参数)  
bool IsKeyJustUp(DWORD key, bool exclusive)
{
    return IsKeyJustUp(key, false, exclusive);
}

// 保持三参数版本不变
bool IsKeyJustUp(DWORD key, bool isGameButton, bool exclusive)
{
    if(key == 0) {
        return false;
    }

    if(isGameButton) {
        return CONTROLS::IS_CONTROL_JUST_RELEASED(2, key); 
    }

    bool b = (key < KEYS_SIZE) ? (GetTickCount() < keyStates[key].time + NOW_PERIOD && keyStates[key].isUpNow) : false;
    if(b && exclusive) {
        ResetKeyState(key);
    }
    return b;
}

bool IsKeyJustUp(std::string keyName, bool exclusive) 
{
    KeyConfig* key = get_config()->get_key_config()->get_key(keyName);
    if(key == NULL || (key->keyCode == 0 && key->gameButton == -1)) {
        return false;
    }

    bool result;
    if(key->useGameButton) {
        result = IsKeyJustUp(key->gameButton, true, exclusive);
    } else {
        result = IsKeyJustUp(key->keyCode, false, exclusive); 
    }

    // 检查修饰键
    if(result && key->modAlt) {
        result = (GetKeyState(VK_MENU) & 0x8000) != 0;
    }
    if(result && key->modShift) {
        result = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
    } 
    if(result && key->modCtrl) {
        result = (GetKeyState(VK_LCONTROL) & 0x8000 || GetKeyState(VK_RCONTROL) & 0x8000);
    }

    return result;
}

void ResetKeyState(DWORD key)
{
	if (key < KEYS_SIZE)
		memset(&keyStates[key], 0, sizeof(keyStates[0]));
}

int keyNameToVal(char * input)
{
	for (int i = 0; i < (sizeof ALL_KEYS / sizeof ALL_KEYS[0]); i++)
	{
		if (strcmp(input, ALL_KEYS[i].name) == 0)
		{
			return ALL_KEYS[i].keyCode;
		}
	}
	return -1;
}