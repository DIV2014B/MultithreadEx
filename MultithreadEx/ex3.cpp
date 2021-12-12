#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <chrono>
#include <cmath>
#include <sstream>
#include <iostream>
#include <tchar.h>


void thread_function2();

ULONG CALLBACK DummyThread(PVOID)
{
    //SetThreadAffinityMask(GetCurrentThread(), 1);

    for (;;)
    {
        thread_function2();
    }

    return 0;
}

int main()
{
    if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS))
    {
        _tprintf(TEXT("Failed to end background mode (%d)\n"), GetLastError());
    }

    HANDLE thread = CreateThread(NULL, 0, DummyThread, NULL, 0, NULL);
    if (!SetThreadPriority(thread, THREAD_PRIORITY_TIME_CRITICAL))
    {
        _tprintf(TEXT("Failed to end background mode (%d)\n"), GetLastError());
    }
    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);
    return 0;

}  
