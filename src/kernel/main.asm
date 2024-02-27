org 0x7C00
bits 16

%define ENDL 0x0D, 0x0A

start:
    jmp main

;
; Print a string to the screen
; Params: 
;   - ds:si points to the string
puts:
    ; Save register wi will modify
    push si
    push ax

.loop:
    ; LODSB, LODSW, LODSD
    ; These instruction load a byte/word/double-word from DS:SI into AL/AX/EAX, then increment SI by the number of bytes loaded
    
    lodsb           ; Load next character in AL
    or al, al       ; Verify if next characer is null?
    jz .done

    mov ah, 0x0e   ; maybe bh
    int 0x10

    jmp .loop


.done:
    pop ax
    pop si
    ret

main:

    ; setup data segments 
    mov ax, 0       ; can't write to ds/es directly
    mov ds, ax
    mov es, ax

    ; setup stack 
    mov ss, ax
    mov sp, 0x7C00  ; stack grows downwards from where we are loaded in memory

    ; Print message
    mov si, msg_hello
    call puts

    hlt

.halt:
    jmp .halt


msg_hello: db 'Hello World!', ENDL, 0


times 510 - ($ - $$) db 0
dw 0AA55h