#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND                hWnd;
	MSG                 msg;
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
	//wndClass.hbrBackground  = GetSysColorBrush(COLOR_BTNFACE); 
	wndClass.lpszMenuName   = NULL;
	wndClass.lpszClassName  = "WinEx1";
	wndClass.hIconSm			= NULL;

	if (!RegisterClassEx(&wndClass)) return 0;

	hWnd = CreateWindow(
		"WinEx1",					   // window class name
		"������ �1",			 				// window caption
		WS_OVERLAPPEDWINDOW,			// window style
		//		WS_OVERLAPPED,					// window style
		/*
		WS_BORDER // ���� � ������ ������
		WS_CAPTION //���� � ���������� (� � ������)
		WS_CHILD //����� ��������� ����  (����� ��� �������� ��������� ����������)
		WS_CHILDWINDOW // ��� �� �����
		WS_DISABLED // ���������� ���� (!!! �� ������������ ���� ������������)
		WS_DLGFRAME //Creates a window that has a border of a style typically used with dialog boxes. A window with this style cannot have a title bar.
		WS_HSCROLL //���� � �������������� ������� ���������
		WS_ICONIC //����, ���������������� ��� ��������, �� �� WS_MINIMIZE
		WS_MAXIMIZE //�������� ��������
		WS_SYSMENU //���� � ��������� ����
		WS_VISIBLE //����, ������� ��� �������� (��. ShowWindow or SetWindowPos)
		WS_VSCROLL //���� � ������������ ������� ���������
		*/
		CW_USEDEFAULT,					// initial x position
		CW_USEDEFAULT,					// initial y position
		CW_USEDEFAULT,					// initial x size
		CW_USEDEFAULT,					// initial y size
		NULL,								// parent window handle
		NULL,								// window menu handle
		hInstance,						// program instance handle
		NULL);							// creation parameters

	ShowWindow(hWnd, iCmdShow);   

	while(GetMessage(&msg, NULL, 0, 0)!=0)
	{
		DispatchMessage(&msg);
	}
	return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
						 WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		//DestroyWindow(hWnd);
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc
