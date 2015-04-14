#include <windows.h>
#define PBTN1 0x1
#define PBTN2 0x2

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
bool InitMainWindow(HINSTANCE,int);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, int iCmdShow)
{
   if ( InitMainWindow(hInstance, iCmdShow)==false ) return 0;

	MSG                 msg;
   while(GetMessage(&msg, NULL, 0, 0)!=0)
   {      
      DispatchMessage(&msg);
   }
   
   return msg.wParam;
}  // WinMain

bool InitMainWindow(HINSTANCE hInstance, int iCmdShow)
{
	HWND                hWnd;

	WNDCLASSEX          wndClass;
   
   wndClass.cbSize			= sizeof(WNDCLASSEX);
   wndClass.style          = CS_HREDRAW | CS_VREDRAW;
   wndClass.lpfnWndProc    = WndProc;
   wndClass.cbClsExtra     = 0;
   wndClass.cbWndExtra     = 0;
   wndClass.hInstance      = hInstance;
   wndClass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
   wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
	//wndClass.hCursor        = LoadCursor(NULL, IDC_SIZE);	
   wndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
   wndClass.lpszMenuName   = NULL;
   wndClass.lpszClassName  = "WinEx1";
	wndClass.hIconSm			= NULL;
   
	if (RegisterClassEx(&wndClass)== 0 ) return false;	
	
	hWnd = CreateWindow(
      "WinEx1",					   // window class name
      "Пример №2",			 				// window caption
      WS_OVERLAPPEDWINDOW,			// window style
//		WS_OVERLAPPED,					// window style
      CW_USEDEFAULT,					// initial x position
      CW_USEDEFAULT,					// initial y position
      CW_USEDEFAULT,					// initial x size
      CW_USEDEFAULT,					// initial y size
      NULL,								// parent window handle
      NULL,								// window menu handle
      hInstance,						// program instance handle
      NULL);							// creation parameters	
	if (hWnd==NULL) return false;
////////////////////////////////////////////////////////////////
	HWND                hBtn1;
	
	hBtn1 = CreateWindow(
      "button",					   // window class name
      "Кнопка №1",			 		// window caption
      WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,			// window style
      50,								// initial x position
      50,					// initial y position
      80,					// initial x size
      40,					// initial y size
      hWnd,								// parent window handle
      (HMENU) PBTN1,					// window menu handle
      hInstance,						// program instance handle
      NULL);							// creation parameters	
	if (hBtn1==NULL) return false;
////////////////////////////////////////////////////////////////
	HWND                hBtn2;
	
	hBtn2 = CreateWindow(
      "button",					   // window class name
      "Кнопка №2",			 		// window caption
      WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,			// window style
      50,								// initial x position
      100,					// initial y position
      80,					// initial x size
      40,					// initial y size
      hWnd,								// parent window handle
      (HMENU) PBTN2,								// window menu handle
      hInstance,						// program instance handle
      NULL);							// creation parameters	
	if (hBtn2==NULL) return false;

	ShowWindow(hWnd, iCmdShow);

	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
						 WPARAM wParam, LPARAM lParam)
{	
	char s1[]="Нажата кнопка 1";
	char s2[]="Нажата кнопка 2";
	char *s;
	LPCSTR s;
	switch(message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam)==PBTN1) 
			s=s1;
		else
			s=s2;
      MessageBox(NULL,
      s,
      "Сообщение", MB_OK | MB_ICONINFORMATION);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc
