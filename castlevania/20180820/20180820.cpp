// 20180814.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "20180820.h"// 헤더파일 포함
#include "mainGame.h"

HINSTANCE	g_hInstance;	// 프로그램 인스턴스 핸들
HWND		g_hWnd;			// 윈도우 핸들
LPTSTR		g_lpszClass = (LPTSTR)TEXT("윈메인의 시작");
char		g_szText[128] = "";

mainGame	g_mainGame;

SAVE_DATA	g_saveData;
//전역 변수로 옮기기 > 구조체로 옮기기 

//싱글 톤으로 옮기기

//g_maingame 안에서 만들어서 거기서 접근

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void SetWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstacne,
	LPSTR _lpszCmdParam, int nCmdShow)
{
	g_hInstance = _hInstance;

	MSG message;

	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;		// 클래스 여분 메모리
	wndClass.cbWndExtra = 0;		// 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// 백그라운드 색상
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 아이콘
	wndClass.hInstance = _hInstance;								// 인스턴스 핸들
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						// 윈도우 프로시저
	wndClass.lpszClassName = g_lpszClass;							// 클래스 이름
	wndClass.lpszMenuName = NULL;									// 메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우 스타일

																	// 윈도우 클래스 등록
	RegisterClass(&wndClass);

	// 윈도우 생성
	g_hWnd = CreateWindow(g_lpszClass,
		g_lpszClass,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		_hInstance,
		NULL);

	// 화면 작업 사이즈 영역 계산
	SetWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	// 윈도우 출력
	ShowWindow(g_hWnd, nCmdShow);

	if (FAILED(g_mainGame.init())) //여기서 메인게임 이니셜라이즈
	{
		return 0;
	}

	// 메시지큐에 있는 메시지 처리
	// 메시지가 발생할 때까지 기다린다 (대기)
	//while (GetMessage(&message, 0, 0, 0))
	//{
	//	TranslateMessage(&message);
	//	DispatchMessage(&message);
	//}

	while (true)
	{
		// 메시지가 발생할 때만 반응한다
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)	break;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			TIMEMANAGER->update(60.0f);

			g_mainGame.update();	//업데이트 렌더
			g_mainGame.render();
		}
	}

	g_mainGame.release();

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return g_mainGame.MainProc(hWnd, iMessage, wParam, lParam);
}

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(g_hWnd, NULL,
		x, y,
		(rc.right - rc.left), (rc.bottom - rc.top),
		SWP_NOZORDER | SWP_NOMOVE);
}