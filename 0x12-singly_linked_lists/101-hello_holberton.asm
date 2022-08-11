  section .data
  msg db  "Hello, Holberton", 0Ah, 0

  global main
  section .text

  extern printf

main:
  push rbp
  mov rdi, msg
  mov rax, 0
  call printf
  pop rbp

  xor rax, rax
  ret
