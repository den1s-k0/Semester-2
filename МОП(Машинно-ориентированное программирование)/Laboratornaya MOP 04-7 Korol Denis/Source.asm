.386
.model flat, C

extern xkub:proc 
extern xkvadr:proc 

.data
a dd 0
b dd 0
c1 dd 0
x dd 0
resultASM dd 0
perem dd 0

.code
Public main_asm
main_asm proc
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8] 
    mov a, eax
    mov eax, [ebp + 12]
    mov b, eax
    mov eax, [ebp + 16]
    mov c1, eax
    mov eax, [ebp + 20]
    mov x, eax
    mov ecx, [ebp + 24]
    
	mov eax, 12
    imul x
    jo per
    imul c1
    jo per
    mov resultASM, eax

    mov eax, b
    push eax
    call xkub
    add esp, 4
    add resultASM, eax
    jo per

    cmp c1, 0
    jz flazok

    mov eax, 4
    mov ebx, c1
    cdq
    idiv ebx
    add resultASM, eax
    jo per

    mov eax, x
    push eax
    call xkub
    add esp, 4
    imul a
    jo per
    mov perem, eax

    cmp x, 0
    jz flazok

    mov eax, 2
    imul x
    jo per
    mov ebx, eax
    mov eax, perem
    cdq
    idiv ebx
    add resultASM, eax
    jo per

    mov eax, x
    push eax
    call xkvadr
    add esp, 4
    imul eax,3
    jo per
    mov perem, eax

    cmp a, 0
    jz flazok

    mov eax, b
    cdq
    idiv a
    mov ebx, eax
    mov eax, perem
    sub eax, ebx
    jz flazok

    mov ebx, eax
    mov eax, resultASM
    cdq
    idiv ebx
    mov resultASM, eax

    jmp vihod
    flazok :
    mov dword ptr [ecx], 0
    jmp vihod
    per:
    mov dword ptr [ecx], 2
    vihod :
    mov esp, ebp
    pop ebp
    ret
main_asm endp
end