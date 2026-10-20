#include <stdio.h>
#include <windows.h>
int main()
{
    printf("Process ID: %lu\n", GetCurrentProcessId());
    printf("Parent Process ID: %lu\n", GetCurrentProcessId());
    return 0;
}