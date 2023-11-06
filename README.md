# ISZ_H
- Enables Hotkeys for Laptops without a Middle Click.
- Requires [UMU](https://illusory.dev/index.html#) (**UnrealModLoader**) and it's Plugins Folder Specifically "UnrealModPlugins" Folder at the game's root Directory.

## Download(s):
- Download the [AutoLoader Here](https://github.com/Cracko298/ISZ_H/releases/download/v1/iszhLoad.dll).
- Download the [Hotkey App Here](https://github.com/Cracko298/ISZ_H/releases/download/v1/iszhotkeys.exe).

## Building:
### Hotkeys Application:
```
> g++ -o iszhotkeys.exe -O3 -s hotkeys.cpp -luser32
```
### ISZ_H AutoLoader:
```
> g++ -shared -o iszhLoad.dll -O3 -s iszh_loader.cpp
```

## AutoLoader Code:
```cpp
#include <windows.h>
#include <string>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    static bool initialized = false;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (!initialized)
        {
            initialized = true;

            HANDLE hMutex = CreateMutexW(NULL, TRUE, L"iszhLoader");
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                CloseHandle(hMutex);
                return FALSE; 
            }

            Sleep(2000);
            wchar_t dllPath[MAX_PATH];
            GetModuleFileNameW(hModule, dllPath, MAX_PATH);

            wcsrchr(dllPath, L'\\')[1] = L'\0';

            wchar_t batchFilePath[MAX_PATH];
            wcscpy_s(batchFilePath, dllPath);
            wcscat_s(batchFilePath, L"iszhotkeys.exe");

            _wsystem((L"cmd.exe /C start \"\" \"" + std::wstring(batchFilePath) + L"\"").c_str());

            CloseHandle(hMutex);
            return FALSE;
        }
        break;
    case DLL_PROCESS_DETACH:
        return FALSE;
    }

    return FALSE;
}
```

## Hotkeys Application Code:
```cpp
#include <Windows.h>
#include <cstdlib>
#include <TlHelp32.h>

void Selection();

extern "C"
{
int printf(const char *format, ...);
}

bool TerminateSecondInstance(const wchar_t* processName) {
    bool foundFirstInstance = false;

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe32)) {
        do {
            // Converts the process name to wide char string
            wchar_t wProcessName[MAX_PATH];
            if (MultiByteToWideChar(CP_ACP, 0, pe32.szExeFile, -1, wProcessName, MAX_PATH) > 0) {
                if (wcscmp(wProcessName, processName) == 0) {
                    if (foundFirstInstance) {
                        // Terminate the second instance
                        HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
                        if (hProcess != nullptr) {
                            TerminateProcess(hProcess, 0);
                            CloseHandle(hProcess);
                            CloseHandle(hSnapshot);
                            return true; // Terminated the second instance (successful termanation)
                        }
                    }
                    foundFirstInstance = true;
                }
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return false; // Second instance not found or couldn't be terminated
}

void Map(){
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
    keybd_event(0x53, 0, 0, 0);
    Sleep(50);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
    Selection();
}

void Inv(){
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
    keybd_event(0x57, 0, 0, 0);
    Sleep(50);
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
    Selection();
}

void cloth(){
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
    keybd_event(0x41, 0, 0, 0);
    Sleep(50);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
    Selection();
}

void people(){
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
    keybd_event(0x44, 0, 0, 0);
    Sleep(50);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
    Selection();
}

void text(){
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
    keybd_event(0x44, 0, 0, 0);
    keybd_event(0x57, 0, 0, 0);
    Sleep(50);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
    Selection();
}

void Selection(){
    while (1==1){
        if (GetAsyncKeyState(0x4D) & 0x8000){
            Sleep(100);
            Map();
        }

        if (GetAsyncKeyState(0x49) & 0x8000){
            Sleep(100);
            Inv();
        }
        
        if (GetAsyncKeyState(0x58) & 0x8000){
            Sleep(100);
            cloth();
        }
        
        if (GetAsyncKeyState(0x56) & 0x8000){
            Sleep(100);
            people();
        }
        
        if (GetAsyncKeyState(0x54) & 0x8000){
            Sleep(100);
            text();
        }
        
        if ((GetAsyncKeyState(0xBA) & 0x8000) && (GetAsyncKeyState(0xDE) & 0x8000)) {
            break;
        }
    }
    
    MessageBoxW(NULL, L"Unloaded/Closed 'ISZ_H (ISZ-Hotkeys)'.", L"ISZ_H (ISZ-Hotkeys)", MB_OK | MB_ICONINFORMATION);
    exit(0);
}

int main(){
    const wchar_t* processName = L"iszhotkeys.exe";
    TerminateSecondInstance(processName);
    MessageBoxW(NULL, L"Loaded ISZ_H Successfully!", L"ISZ_H (ISZ-Hotkeys)", MB_OK | MB_ICONINFORMATION);
    printf("Access Inventory   = 'I'.\n");
    printf("Access Map         = 'M'.\n");
    printf("Access Apparel     = 'X'.\n");
    printf("Access People      = 'V'.\n");
    printf("Access Messages    = 'T'.\n");
    printf("Close Application  = 'Semi-Colon' + 'Quotation Mark'.");
    Selection();
}
```
