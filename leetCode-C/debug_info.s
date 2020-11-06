mov    -0x40(%rbp),%rax                                                                                                                                                                         │
mov    -0x64(%rbp),%edx                                                                                                                                                                         │
movslq %edx,%rdx                                                                                                                                                                                │
mov    (%rax,%rdx,4),%eax                                                                                                                                                                       │
mov    -0x60(%rbp),%rdx                                                                                                                                                                         │
movslq %eax,%rcx                                                                                                                                                                                │
mov    (%rdx,%rcx,4),%edx                                                                                                                                                                       │
lea    0x1(%rdx),%ecx                                                                                                                                                                           │
mov    -0x60(%rbp),%rdx                                                                                                                                                                         │
cltq                                                                                                                                                                                            │
mov    %ecx,(%rdx,%rax,4)