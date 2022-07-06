from __future__ import print_function
from random import randint
from time import sleep
import hashlib
from colorama import init
from colorama import Fore, Back, Style
import ctypes


def doStuff():
    while True:
        value = randint(-10000, 100000)
        my_string_bits1 = str(value).encode('utf-8')
        secret_thing1 = hashlib.sha256(my_string_bits1)
        wallet_try_address1 = secret_thing1.hexdigest()

        value = randint(-10000, 10000)
        my_string_bits2 = str(value).encode('utf-8')
        secret_thing2 = hashlib.sha256(my_string_bits1)
        wallet_try_address2 = secret_thing1.hexdigest()
        print(Fore.RED + '[TRYING] ' + wallet_try_address1 + wallet_try_address2)
        sleep(0.01)

def sendSlowmessage():
    init()
    print(r'.  ..__ .__     __ .__ .__. __ .  ..___.__ ')
    print(r'|\/|[__)[__)   /  `[__)[__]/  `|_/ [__ [__)')
    print(r'|  ||   |  \   \__.|  \|  |\__.|  \[___|  \ ')
          
          
    print('CRYPTO WALLET CRACKER'); sleep(0.1)
    print(Fore.YELLOW + 'This crypto wallet miner does not use as much CPU as bitcoin miners, as they use a different hashing '
          'algorithm. Feel free to work normally on your PC. \n'); sleep(2)
    print(Fore.GREEN + 'Searching for pools...'); sleep(2)
    print('Found pool!'); sleep(0.5)
    print('Connection to pool...'); sleep(1)
    print('Connected!')
    sleep(0.5)
    print("Starting search")
    sleep(1)
    doStuff()

def debuggingFastMessage():
    print('CRYPTO WALLET CRACKER')
    print('Searching for pools...')
    print('Found pool!')
    print('Connection to pool...')
    print('Connected!')
    print("Starting search")
    sleep(1)
    doStuff()
    
ctypes.windll.kernel32.SetConsoleTitleA("Cracker")
sendSlowmessage()



