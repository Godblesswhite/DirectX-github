

#include <windows.h>
#include "WindowsMessageMap.h"
#include <sstream> 


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugStringA(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE://once click exit ,msg will in this case
		PostQuitMessage(69);//asign msg.wParam 69
		break;
	case WM_KEYDOWN:
		if (wParam == 'F') {
			SetWindowText(hWnd, L"Fujii Kaze");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F') {
			SetWindowText(hWnd, L"kirari");

		}
		break;

	case WM_CHAR:
	{
		static std::string title;
		title.push_back((char)wParam);
		SetWindowTextA(hWnd, title.c_str());
	}
	break;
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);


		std::ostringstream oss;
		oss << "Mouse Click at: (" << pt.x << ", " << pt.y << ")";

		SetWindowTextA(hWnd, oss.str().c_str());


	}
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//DefWindowProc д╛хо




int CALLBACK WinMain(
	HINSTANCE hPrevInstance,
	HINSTANCE hInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{

	const auto pClassName = L"hw3dbutts";
	// register window class

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = (LPCWSTR)pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	// create window instance
	HWND hWnd = CreateWindowEx(
		0, (LPCWSTR)pClassName,
		L"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);
	// show the damn window
	ShowWindow(hWnd, SW_SHOW);

	MSG msg;//Receive mouse interaction
	BOOL gresult;
	while ((gresult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gresult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}