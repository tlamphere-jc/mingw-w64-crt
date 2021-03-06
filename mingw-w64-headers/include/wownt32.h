/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WOWNT32_
#define _WOWNT32_

LPVOID WINAPI WOWGetVDMPointer(DWORD vp,DWORD dwBytes,WINBOOL fProtectedMode);
LPVOID WINAPI WOWGetVDMPointerFix(DWORD vp,DWORD dwBytes,WINBOOL fProtectedMode);
VOID WINAPI WOWGetVDMPointerUnfix(DWORD vp);
WORD WINAPI WOWGlobalAlloc16(WORD wFlags,DWORD cb);
WORD WINAPI WOWGlobalFree16(WORD hMem);
DWORD WINAPI WOWGlobalLock16(WORD hMem);
WINBOOL WINAPI WOWGlobalUnlock16(WORD hMem);
DWORD WINAPI WOWGlobalAllocLock16(WORD wFlags,DWORD cb,WORD *phMem);
WORD WINAPI WOWGlobalUnlockFree16(DWORD vpMem);
DWORD WINAPI WOWGlobalLockSize16(WORD hMem,PDWORD pcb);
VOID WINAPI WOWYield16(VOID);
VOID WINAPI WOWDirectedYield16(WORD htask16);

typedef enum _WOW_HANDLE_TYPE {
  WOW_TYPE_HWND,WOW_TYPE_HMENU,WOW_TYPE_HDWP,WOW_TYPE_HDROP,WOW_TYPE_HDC,WOW_TYPE_HFONT,WOW_TYPE_HMETAFILE,WOW_TYPE_HRGN,WOW_TYPE_HBITMAP,
  WOW_TYPE_HBRUSH,WOW_TYPE_HPALETTE,WOW_TYPE_HPEN,WOW_TYPE_HACCEL,WOW_TYPE_HTASK,WOW_TYPE_FULLHWND
} WOW_HANDLE_TYPE;

HANDLE WINAPI WOWHandle32 (WORD,WOW_HANDLE_TYPE);
WORD WINAPI WOWHandle16 (HANDLE,WOW_HANDLE_TYPE);

#define HWND_32(h16) ((HWND) (WOWHandle32(h16,WOW_TYPE_HWND)))
#define HMENU_32(h16) ((HMENU) (WOWHandle32(h16,WOW_TYPE_HMENU)))
#define HDWP_32(h16) ((HDWP) (WOWHandle32(h16,WOW_TYPE_HDWP)))
#define HDROP_32(h16) ((HDROP) (WOWHandle32(h16,WOW_TYPE_HDROP)))
#define HDC_32(h16) ((HDC) (WOWHandle32(h16,WOW_TYPE_HDC)))
#define HFONT_32(h16) ((HFONT) (WOWHandle32(h16,WOW_TYPE_HFONT)))
#define HMETAFILE_32(h16) ((HMETAFILE) (WOWHandle32(h16,WOW_TYPE_HMETAFILE)))
#define HRGN_32(h16) ((HRGN) (WOWHandle32(h16,WOW_TYPE_HRGN)))
#define HBITMAP_32(h16) ((HBITMAP) (WOWHandle32(h16,WOW_TYPE_HBITMAP)))
#define HBRUSH_32(h16) ((HBRUSH) (WOWHandle32(h16,WOW_TYPE_HBRUSH)))
#define HPALETTE_32(h16) ((HPALETTE) (WOWHandle32(h16,WOW_TYPE_HPALETTE)))
#define HPEN_32(h16) ((HPEN) (WOWHandle32(h16,WOW_TYPE_HPEN)))
#define HACCEL_32(h16) ((HACCEL) (WOWHandle32(h16,WOW_TYPE_HACCEL)))
#define HTASK_32(h16) ((DWORD) (WOWHandle32(h16,WOW_TYPE_HTASK)))
#define FULLHWND_32(h16) ((HWND) (WOWHandle32(h16,WOW_TYPE_FULLHWND)))

#define HWND_16(h32) (WOWHandle16(h32,WOW_TYPE_HWND))
#define HMENU_16(h32) (WOWHandle16(h32,WOW_TYPE_HMENU))
#define HDWP_16(h32) (WOWHandle16(h32,WOW_TYPE_HDWP))
#define HDROP_16(h32) (WOWHandle16(h32,WOW_TYPE_HDROP))
#define HDC_16(h32) (WOWHandle16(h32,WOW_TYPE_HDC))
#define HFONT_16(h32) (WOWHandle16(h32,WOW_TYPE_HFONT))
#define HMETAFILE_16(h32) (WOWHandle16(h32,WOW_TYPE_HMETAFILE))
#define HRGN_16(h32) (WOWHandle16(h32,WOW_TYPE_HRGN))
#define HBITMAP_16(h32) (WOWHandle16(h32,WOW_TYPE_HBITMAP))
#define HBRUSH_16(h32) (WOWHandle16(h32,WOW_TYPE_HBRUSH))
#define HPALETTE_16(h32) (WOWHandle16(h32,WOW_TYPE_HPALETTE))
#define HPEN_16(h32) (WOWHandle16(h32,WOW_TYPE_HPEN))
#define HACCEL_16(h32) (WOWHandle16(h32,WOW_TYPE_HACCEL))
#define HTASK_16(h32) (WOWHandle16(h32,WOW_TYPE_HTASK))

DWORD WINAPI WOWCallback16(DWORD vpfn16,DWORD dwParam);

#define WCB16_MAX_CBARGS (16)

#define WCB16_PASCAL (0x0)
#define WCB16_CDECL (0x1)

WINBOOL WINAPI WOWCallback16Ex(DWORD vpfn16,DWORD dwFlags,DWORD cbArgs,PVOID pArgs,PDWORD pdwRetCode);
#endif
