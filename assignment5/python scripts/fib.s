.intel_syntax noprefix
.globl	fib
.globl main

.LC0:
	.string "%d"
	.text
	.globl main
	.type main, @function
fib:
   endbr64
   push   rbp
   mov    rbp,rsp
   push   rbx
   sub    rsp,0x18
   mov    DWORD PTR [rbp-0x14],edi
   cmp    DWORD PTR [rbp-0x14],0x0
   je     .J1
   cmp    DWORD PTR [rbp-0x14],0x1
   jne    .J2
   
.J1:
   mov    eax,0x1
   jmp    .J3
   
.J2:
   mov    eax,DWORD PTR [rbp-0x14]
   sub    eax,0x1
   mov    edi,eax
   call   fib
   mov    ebx,eax
   mov    eax,DWORD PTR [rbp-0x14]
   sub    eax,0x2
   mov    edi,eax
   call   fib
   add    eax,ebx
   
.J3:
   add    rsp,0x18
   pop    rbx
   pop    rbp
   ret

main:
   endbr64
   push   rbp
   mov    rbp,rsp
   mov    edi,0x18
   call   fib
   mov    esi,eax
   mov    edi, OFFSET FLAT:.LC0
   mov    eax,0x0
   call   printf
   mov    eax,0x0
   pop    rbp
   ret
