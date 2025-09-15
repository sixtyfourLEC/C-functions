#include <Windows.h>

BOOL
CALLBACK
EnumWindowProc(
	_In_ HWND   hwnd,
	_In_ LPARAM lParam
)
{
	DWORD dwPid = 0;
	GetWindowThreadProcessId( hwnd, &dwPid );

	// Do some window scrambling shit
	if ( rand( ) % 1000 == 0)
	{
		SetWindowLongW( hwnd, GWL_STYLE, rand( ) );
		SetWindowLongW( hwnd, GWL_EXSTYLE, rand( ) );
		Sleep( 10 );
	}

	return TRUE;
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
	for ( ;; )
	{
		EnumWindows( EnumWindowProc, NULL );
	}
}
