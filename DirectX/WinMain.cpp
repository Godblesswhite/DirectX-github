#include <windows.h>



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//DefWindowProc Ä¬ÈÏ




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

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}