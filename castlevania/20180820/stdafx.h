// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>
#include <map>

using namespace std;

typedef struct tagSaveData
{
	int selected_player_id;
	int maxHP;
	int score;
}SAVE_DATA;


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#define SYNTHESIZE(varType, varName, funcName)\
protected: varType varName;\
public: varType get##funcName() { return varName; }\
public: void set##funcName(varType var) { varName = var; }

#include "txtData.h"
#include "timeManager.h"
#include "keyManager.h"
#include "imageManager.h"
#include "effectManager.h"
#include "roomManager.h"
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "utils.h"
#include "sceneManager.h"
#include "mainGame.h"

#define WINSTARTX 50
#define WINSTARTY 50
#define WINSIZEX 640
#define WINSIZEY 480

#define PI 3.141592f

#define SAFE_DELETE(p)	{ if (p) delete p; p = NULL; }

#define RANDOM randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define ROOMMANAGER roomManager::getSingleton()


extern HINSTANCE	g_hInstance;
extern HWND			g_hWnd;
extern mainGame		g_mainGame;
extern SAVE_DATA	g_saveData;
