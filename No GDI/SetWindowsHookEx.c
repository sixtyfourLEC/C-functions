#include <Windows.h>

HHOOK hMsgHook = 0;

LRESULT
CALLBACK
WindowHook(
	_In_ INT nCode,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	if ( nCode == HCBT_ACTIVATE )
	{
		HWND hWnd = ( HWND )wParam;
		HWND hButtonWnd = GetDlgItem( hWnd, IDOK );

		EnableWindow( hButtonWnd, FALSE );
		Sleep( 10 );
	}
	return CallNextHookEx( hMsgHook, nCode, wParam, lParam );
}

VOID
WINAPI
MsgBoxThread( VOID )
{
	hMsgHook = SetWindowsHookExW( WH_CBT, &WindowHook, 0, GetCurrentThreadId( ) );
	MessageBoxW( NULL, L"Gaaaauhjfklhgijf49833le;rlt.;", L"It fucking hooks", MB_ICONERROR );
	UnhookWindowsHookEx( hMsgHook );
}

INT
WINAPI
wWinMain(
	_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     PWSTR     szCmdLine,
	_In_     INT       nShowCmd
)
{
	MsgBoxThread( );
	return TRUE;
}