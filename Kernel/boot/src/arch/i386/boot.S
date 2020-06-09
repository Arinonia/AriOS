# sephira-os : boot - https://gitlab.com/Sephira/operating-system/sephira-os.git

.set FLAGS, 0
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot

.long MAGIC
.long FLAGS
.long CHECKSUM

stack_bottom:
    .skip 4096

stack_top:
    .section .text
    .global start
    .type start, @function

start:
    mov $stack_top, %esp

    call init
    cli

hlt_loop:
    hlt
    jmp hlt_loop

.size start, . - start
