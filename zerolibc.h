// Assuming 32-bit

#ifndef ZEROLIBC_H
#define ZEROLIBC_H

#define f32 float
#define f64 double
#define i16 short
#define i32 int
#define i64 long long
#define i8 char
#define u16 unsigned i16
#define u32 unsigned i32
#define u64 unsigned i64
#define u8 unsigned i8

#if 0
#define int16_t i16
#define int32_t i32
#define int64_t i64
#define int8_t i8
#define isize i64
#define uint16_t u16
#define uint32_t u32
#define uint64_t u64
#define uint8_t u8
#define usize u64

#define __forceinline
#define __int16 i16
#define __int32 i32
#define __int3264 i32
#define __int64 i64
#define __int8 i8
#define ATOM unsigned short
#define BOOL int
#define BOOL int
#define BYTE unsigned char
#define CALLBACK
#define CHAR uint8_t
#define DIB_RGB_COLORS 0
#define DWORD unsigned long
#define ENABLE_ECHO_INPUT 0x0004
#define ENABLE_LINE_INPUT 0x0002
#define ENABLE_MOUSE_INPUT 0x0010
#define ENABLE_QUICK_EDIT_MODE 0x0040
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define ENABLE_WINDOW_INPUT 0x0008
#define HANDLE void *
#define HBRUSH HANDLE
#define HCURSOR HICON
#define HDC HANDLE
#define HICON HANDLE
#define HICON HANDLE
#define HINSTANCE HANDLE
#define HINSTANCE HANDLE
#define HMENU HANDLE
#define HMODULE HINSTANCE
#define HWND void *
#define intptr_t i64
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR) - 1)
#define KEY_EVENT 0x0001
#define LONG long
#define LONG_PTR int64_t
#define LONGLONG i64
#define LPARAM LONG_PTR
#define LPCSTR const char *
#define LPCTSTR LPCSTR
#define LPCWSTR const char *
#define LPVOID void *
#define LRESULT LONG_PTR
#define NULL 0
#define PeekMessage PeekMessageA
#define PM_REMOVE 0x0001
#define SHORT short
#define SRCCOPY (DWORD)0x00CC0020
#define STD_INPUT_HANDLE ((DWORD) - 10)
#define STD_OUTPUT_HANDLE ((DWORD) - 11)
#define UINT unsigned int
#define UINT16 u16
#define UINT32 u32
#define UINT8 u8
#define UINT_PTR u32
#define uintptr_t u64
#define ULONG_PTR __int3264
#define VOID void
#define WCHAR uint16_t
#define WINAPI
#define WINDOWS_CALL(cond_, format_) do {if (UUNLIKELY(cond_)) winError(format_);} while (0)
#define winError printf
#define WM_CLOSE 0x0010
#define WM_DESTROY 0x0002
#define WM_QUIT 0x0012
#define WM_SIZE 0x0005
#define WORD unsigned short
#define WPARAM UINT_PTR
#define WS_BORDER 0x00800000L
#define WS_CAPTION 0x00C00000L
#define WS_CHILD 0x40000000L
#define WS_CHILDWINDOW 0x40000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_DISABLED 0x08000000L
#define WS_DLGFRAME 0x00400000L
#define Ws_group 0x00020000L
#define WS_HSCROLL
#define WS_ICONIC 0x20000000L
#define WS_MAXIMIZE 0x01000000L
#define WS_MAXIMIZEBOX 0x00010000L
#define WS_MINIMIZE 0x20000000L
#define WS_MINIMIZEBOX 0x00020000L
#define WS_OVERLAPPED 0x00000000L
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUP 0x80000000L
#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_SIZEBOX 0x00040000L
#define WS_SYSMENU 0x00080000L
#define WS_TABSTOP 0x00010000L
#define WS_THICKFRAME 0x00040000L
#define WS_VISIBLE 0x10000000L
//#define __stdcall
//#define CALLBACK __stdcall
//typedef __nullterminated CONST CHAR *LPCSTR;
//typedef const wchar_t *LPCWSTR;

typedef LRESULT (CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagWNDCLASSA {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	LPCSTR lpszMenuName;
	LPCSTR lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;

typedef struct _FOCUS_EVENT_RECORD {
	BOOL bSetFocus;
} FOCUS_EVENT_RECORD;

typedef struct _MENU_EVENT_RECORD {
	UINT dwCommandId;
} MENU_EVENT_RECORD, *PMENU_EVENT_RECORD;

typedef struct _COORD {
	SHORT X;
	SHORT Y;
} COORD, *PCOORD;

typedef struct _WINDOW_BUFFER_SIZE_RECORD {
	COORD dwSize;
} WINDOW_BUFFER_SIZE_RECORD;

typedef struct _MOUSE_EVENT_RECORD {
	COORD dwMousePosition;
	DWORD dwButtonState;
	DWORD dwControlKeyState;
	DWORD dwEventFlags;
} MOUSE_EVENT_RECORD;

typedef struct _KEY_EVENT_RECORD {
	BOOL bKeyDown;
	WORD wRepeatCount;
	WORD wVirtualKeyCode;
	WORD wVirtualScanCode;
	union {
		WCHAR UnicodeChar;
		CHAR AsciiChar;
	} uChar;
	DWORD dwControlKeyState;
} KEY_EVENT_RECORD;

typedef struct _INPUT_RECORD {
	WORD EventType;
	union {
		KEY_EVENT_RECORD KeyEvent;
		MOUSE_EVENT_RECORD MouseEvent;
		WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
		MENU_EVENT_RECORD MenuEvent;
		FOCUS_EVENT_RECORD FocusEvent;
	} Event;
} INPUT_RECORD;

typedef struct tagRECT {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef struct tagPAINTSTRUCT {
	HDC hdc;
	BOOL fErase;
	RECT rcPaint;
	BOOL fRestore;
	BOOL fIncUpdate;
	BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagRGBQUAD {
	BYTE rgbBlue;
	BYTE rgbGreen;
	BYTE rgbRed;
	BYTE rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
	BITMAPINFOHEADER bmiHeader;
	RGBQUAD bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;

typedef union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG HighPart;
	} DUMMYSTRUCTNAME;
	struct {
		DWORD LowPart;
		LONG HighPart;
	} u;
	LONGLONG QuadPart;
} LARGE_INTEGER;

typedef struct tagPOINT {
	LONG x;
	LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct tagMSG {
	HWND hwnd;
	UINT message;
	WPARAM wParam;
	LPARAM lParam;
	DWORD time;
	POINT pt;
	DWORD lPrivate;
} MSG, *PMSG, *NPMSG, *LPMSG;

typedef ATOM(WINAPI *RegisterClassAFunc)(const WNDCLASSA *);
typedef BOOL(WINAPI *DestroyWindowFunc)(HWND);
typedef BOOL(WINAPI *PeekMessageAFunc)(LPMSG, HWND, UINT, UINT, UINT);
typedef BOOL(WINAPI *StretchDIBitsFunc)(HDC, int, int, int, int, int, int, int, int, const void *, const BITMAPINFO *, UINT, DWORD);
typedef BOOL(WINAPI *TranslateMessageFunc)(const MSG *);
typedef HANDLE(WINAPI *GetStdHandleFunc)(DWORD);
typedef HDC(WINAPI *GetDCFunc)(HWND);
typedef HWND(WINAPI *CreateWindowExAFunc)(DWORD, LPCSTR, LPCSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);
typedef int( *FARPROC)();
typedef LRESULT(WINAPI *DefWindowProcAFunc)(HWND, UINT, WPARAM, LPARAM);
typedef LRESULT(WINAPI *DispatchMessageAFunc)(const MSG *);
typedef VOID(WINAPI *ExitProcessFunc)(UINT);
typedef VOID(WINAPI *PostQuitMessageFunc)(int);

ATOM RegisterClassA(const WNDCLASSA *lpWndClass);
BOOL DestroyWindow(HWND hWnd);
BOOL PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);
BOOL TranslateMessage(const MSG *lpMsg);
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
HANDLE get_std_handle(DWORD nStdHandle);
HDC GetDC(HWND hWnd);
HMODULE GetModuleHandleA(LPCSTR lpModuleName);
HMODULE LoadLibrary(LPCTSTR lpFileName);
HWND CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
int StretchDIBits(HDC hdc, int xDest, int yDest, int DestWidth, int DestHeight, int xSrc, int ySrc, int SrcWidth, int SrcHeight, const VOID *lpBits, const BITMAPINFO *lpbmi, UINT iUsage, DWORD rop);
LRESULT DefWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT DefWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT DispatchMessage(const MSG *lpMsg);
void exit_process(UINT uExitCode);
void PostQuitMessage(int nExitCode);
#endif

/*
#define char 0
#define double 0
#define float 0
#define int 0
#define long 0
#define short 0
#define signed 0
#define unsigned 0
*/

typedef enum {
	false,
	true
} bool;

#define SHOULD(expression, block)\
do {\
	if (expression) {\
		printf("Line %d expected '%s' in function '%s'\n", __LINE__, #expression, __FUNCTION__);\
		block\
		exit_process(EXIT_FAILURE);\
	}\
}\
while (0)

/*
static void fflush() {
	HANDLE hStdOut = get_std_handle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) {
		// Handle error, cannot get standard output handle
		return;
	}

	// Flush the console output buffer
	if (!FlushConsoleInputBuffer(hStdOut)) {
		// Handle error, failed to flush console output buffer
		return;
	}
}

static void print_char(char c) {
	DWORD bytesWritten;
	WriteConsole(get_std_handle(STD_OUTPUT_HANDLE), &c, 1, &bytesWritten, NULL);
}

static void print_string(char *s) {
	while (*s) print_char(*s++);
}

static void print_int(i32 v) {
	char buf[20];
	i32 i = 0;
	bool unm = false;

	if (v < 0) {
		unm = true;
		v = -v;
	}

	do {
		buf[i++] = '0' + (v % 10);
		v /= 10;
	} while (v > 0);

	if (unm) {
		buf[i++] = '-';
	}

	while (i > 0) {
		i--;
		print_char(buf[i]);
	}
}

static void print_f32(f32 n) {
	if (n < 0) {
		print_char('-');
		n = -n;
	}

	i32 i = (i32)n;

	print_int(i);

	f32 f = n - (f32)i;

	print_char('.');

	while (f > 0) {
		f *= 10;
		i32 digit = (i32)f;
		print_char((char)('0' + digit));
		f -= (f32)digit;
	}
}

static i32 print_pattern(char *fmt, ...) {
	va_list args;
	va_start(args, fmt);

	i32 r = 0;
	bool has_fmt = false;

	while (*fmt) {

		if (*fmt == '%') {
			has_fmt = true;
		}
		else if (has_fmt) {
			has_fmt = false;

			switch (*fmt) {
				case 'd': {
 print_int(va_arg(args, i32));
 break;
				}
				case 's': {
 print_string(va_arg(args, char *));
 break;
				}
				case 'c': {
 print_char((char)va_arg(args, i32));
 break;
				}
				case 'f': {
 print_f32(va_arg(args, f32));
 break;
				}
				default:
 print_char(*fmt);
 break;
				}
			}

		else {
			print_char(*fmt);
		}

		++fmt;
	}

	va_end(args);

	return r;
}

static void *mem_cpy(void *out, const void *src, usize n) {
	char *d = (char *)out;
	const char *s = (const char *)src;
	usize i = 0;
	while (i < n) d[i] = s[i++];
	return out;
}

static char *str_cpy(char *out, const char *src) {
	usize i = 0;
	while (src[i]) {
		out[i] = src[i];
		++i;
	}
	out[i] = 0;
	return out;
}

static usize str_get_len(const char *str) {
	usize len = 0;
	while (str[++len]);
	return len;
}

static char *str_cat(char *out, const char *src) {
	usize out_len = str_get_len(out);
	usize i = 0;
	while (src[i]) {
		out[out_len + i] = src[i];
		++i;
	}
	out[out_len + i] = 0;
	return out;
}
*/

#endif