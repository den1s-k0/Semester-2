.code
 ; a -> rcx, b -> rdx, c -> r8, x -> r9, prov -> r10, res -> r11
 ; Y=(12x*c+b3 +4/c +ax3 /2x)/ (3x2 –b/a )
main_asm PROC
    mov r13, rdx  
    mov r10, 1
    mov r11, 0
    mov rax, 12
        imul r9
        jo per
        imul r8
        jo per
        mov r11, rax

        mov rax, r13
        imul r13
        jo per
        imul r13
        jo per
        add r11, rax
        jo per

        cmp r8, 0
        jz flazok

        mov rax, 4
        mov rbx, r8
        cqo
        idiv rbx
        add r11, rax
        jo per

        mov rax, rcx
        imul r9
        jo per
        imul r9
        jo per
        imul r9
        jo per
        mov r12, rax

        cmp r9, 0
        jz flazok

        mov rax, 2
        imul r9
        jo per
        mov rbx, rax
        mov rax, r12
        cqo
        idiv rbx
        add r11, rax
        jo per

        mov rax, 3
        imul r9
        jo per
        imul r9
        jo per
        mov r12, rax

        cmp rcx, 0
        jz flazok

        mov rax, r13
        cqo
        idiv rcx
        mov rbx, rax
        mov rax, r12
        sub rax, rbx
        jz flazok

        mov rbx, rax
        mov rax, r11
        cqo
        idiv rbx
        mov r11, rax

        jmp vihod
        flazok :
        mov rax, [rsp+8+8]    
        mov rbx,0          
        mov [rax], rbx 
            jmp vihod
            per :
        mov rax, [rsp+8+8]    
        mov rbx,2          
        mov [rax], rbx 
            vihod :
    ret
main_asm ENDP

mainprov PROC
    mov r13, rdx  
    mov r10, 1
    mov r11, 0
    mov rax, 12
        imul r9
        jo per
        imul r8
        jo per
        mov r11, rax

        mov rax, r13
        imul r13
        jo per
        imul r13
        jo per
        add r11, rax
        jo per

        cmp r8, 0
        jz flazok

        mov rax, 4
        mov rbx, r8
        cqo
        idiv rbx
        add r11, rax
        jo per

        mov rax, rcx
        imul r9
        jo per
        imul r9
        jo per
        imul r9
        jo per
        mov r12, rax

        cmp r9, 0
        jz flazok

        mov rax, 2
        imul r9
        jo per
        mov rbx, rax
        mov rax, r12
        cqo
        idiv rbx
        add r11, rax
        jo per

        mov rax, 3
        imul r9
        jo per
        imul r9
        jo per
        mov r12, rax

        cmp rcx, 0
        jz flazok

        mov rax, r13
        cqo
        idiv rcx
        mov rbx, rax
        mov rax, r12
        sub rax, rbx
        jz flazok

        mov rbx, rax
        mov rax, r11
        cqo
        idiv rbx
        mov r11, rax
        mov rax, 1

        jmp vihod
        flazok :
        mov rax, 0
            jmp vihod
            per :
        mov rax, 2
            vihod :
    ret
mainprov ENDP
end
