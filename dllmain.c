#include <windows.h>

BOOL WINAPI __declspec(dllexport) DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        //Dune 2000 1.06 US
        if (memcmp((void *)0x00420000, (const char[]){0xFC,0xFF,0xFF,0x5F,0x5E,0x5D,0xB0,0x01,0x5B,0xC2}, 10) == 0)
        {    
            DWORD oldProtect = PAGE_EXECUTE_READ;
            
            // jump over DirectPlayLobbyCreateA code since the game doesn't check the return value and continues
            short *dplaylobbyjmp = (short *)0x0049FCB6;
            VirtualProtect(dplaylobbyjmp, 2, PAGE_EXECUTE_READWRITE, &oldProtect);
            *dplaylobbyjmp = 0x19EB;
            VirtualProtect(dplaylobbyjmp, 2, oldProtect, &oldProtect);
        }
    }
    return TRUE;
}

HRESULT WINAPI fake_DirectPlayCreate(int a, int b, int c) { return E_FAIL; }
HRESULT WINAPI fake_DirectPlayEnumerateA(int a, int b) { return E_FAIL; }
HRESULT WINAPI fake_DirectPlayEnumerateW(int a, int b) { return E_FAIL; }
HRESULT WINAPI fake_DirectPlayLobbyCreateA(int a, int b, int c, int d, int e) { return E_FAIL; }
HRESULT WINAPI fake_DirectPlayLobbyCreateW(int a, int b, int c, int d, int e) { return E_FAIL; }
HRESULT WINAPI fake_DirectPlayEnumerate(int a, int b) { return E_FAIL; }
