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