#include <iostream>
#include <Windows.h>

int main() {
    HANDLE hFile = CreateFileA(
        "test.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "Failed to create file\n";
        return 1;
    }

    std::cout << "File created\n";

    CloseHandle(hFile);
    return 0;
}