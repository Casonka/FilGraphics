#include "Projects.h"

LRESULT CALLBACK SoftProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

WNDCLASS MainFormClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hprevInstance, LPSTR args, int nCmdShow) {

	WNDCLASS SoftFormClass = MainFormClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, (HICON)LoadImage(NULL, L"RCR.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE), L"[FIL] Project Class", SoftProcedure);

	if (!RegisterClassW(&SoftFormClass)) { return -1; }
	MSG SoftFormPage = { 0 };

	CreateWindow(L"[FIL] Project Class", L"Fil Graphics", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);

	while (GetMessage(&SoftFormPage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftFormPage);
		DispatchMessage(&SoftFormPage);
	}
	return 0;
}

	WNDCLASS MainFormClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
		WNDCLASS NWC = { 0 };

		NWC.hCursor = Cursor;
		NWC.hIcon = Icon;
		NWC.hInstance = hInst;
		NWC.lpszClassName = Name;
		NWC.hbrBackground = BGColor;
		NWC.lpfnWndProc = Procedure;

		return NWC;
	}

	LRESULT CALLBACK SoftProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

		switch (msg) {
		case WM_CREATE: break;
		case WM_DESTROY: PostQuitMessage(0); break;

		default: return DefWindowProc(hWnd, msg, wp, lp);
		}

	}
	