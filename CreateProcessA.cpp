#include <Windows.h>
#include <iostream>

int main() {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    char cmd[] = "C:\\Windows\\System32\\notepad.exe";

    BOOL success = CreateProcessA(
        NULL,
        cmd,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    if (success) {
        std::cout << "Process started\n";

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        std::cout << "CreateProcess failed: "
            << GetLastError() << "\n";
    }

    return 0;
}
