.intel_syntax noprefix

.LC0:
	.string "%d"
	.text
	.globl main
	.type main, @function

main:
.LFB0:
   endbr64
   push   rbp
   mov    rbp,rsp
   sub    rsp,0x10
   mov    DWORD PTR [rbp-0x8],0x12
   mov    DWORD PTR [rbp-0x4],0x0

.J2:
   mov    eax,DWORD PTR [rbp-0x4]
   mov    edx,0x1
   mov    ecx,eax
   shl    edx,cl
   mov    eax,edx
   mov    DWORD PTR [rbp-0xc],eax
   mov    eax,DWORD PTR [rbp-0xc]
   cmp    eax,DWORD PTR [rbp-0x8]
   jg     .J1
   mov    eax,DWORD PTR [rbp-0x8]
   and    eax,DWORD PTR [rbp-0xc]
   mov    edx,eax
   mov    eax,DWORD PTR [rbp-0x4]
   mov    ecx,eax
   sar    edx,cl
   mov    eax,edx
   mov    esi,eax
   mov    edi, OFFSET FLAT:.LC0
   mov    eax,0x0
   call   printf
   add    DWORD PTR [rbp-0x4],0x1
   jmp    .J2


.J1:
   nop
   nop
   leave
   ret
