.intel_syntax noprefix
.text
.globl main

main:
   endbr64
   push   rbp
   mov    rbp,rsp
   sub    rsp,0x40
   movabs rax,0x54454d4f434c4557
   movabs rdx,0x414e4f5a4952414f
   mov    QWORD PTR [rbp-0x40],rax
   mov    QWORD PTR [rbp-0x38],rdx
   movabs rax,0x494e554554415453
   movabs rdx,0x59544953524556
   mov    QWORD PTR [rbp-0x30],rax
   mov    QWORD PTR [rbp-0x28],rdx
   mov    QWORD PTR [rbp-0x20],0x0
   lea    rax,[rbp-0x40]
   mov    rdi,rax
   call   strlen 
   mov    DWORD PTR [rbp-0xc],eax
   mov    DWORD PTR [rbp-0x8],0x0
   jmp    .L1   
.L3:
   mov    eax,DWORD PTR [rbp-0x8]
   cdqe
   movzx  eax,BYTE PTR [rbp+rax*1-0x40]
   add    eax,0x19
   mov    BYTE PTR [rbp-0x1],al
   cmp    BYTE PTR [rbp-0x1],0x5a
   jle    .L2
   movzx  eax,BYTE PTR [rbp-0x1]
   sub    eax,0x1a
   mov    BYTE PTR [rbp-0x1],al
.L2:
   mov    eax,DWORD PTR [rbp-0x8]
   cdqe
   movzx  edx,BYTE PTR [rbp-0x1]
   mov    BYTE PTR [rbp+rax*1-0x40],dl
   add    DWORD PTR [rbp-0x8],0x1
.L1:
   mov    eax,DWORD PTR [rbp-0x8]
   cmp    eax,DWORD PTR [rbp-0xc]
   jl     .L3
   lea    rax,[rbp-0x40]
   mov    rdi,rax
   call   puts 
   nop
   leave
   ret
