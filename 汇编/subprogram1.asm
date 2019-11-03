mydata segment
    tishi db 'Please input a string: $'
    num dw 0
    string db ?
mydata ends

mycode segment
    assume cs:mycode,ds:mydata
start:
    mov ax,mydata
    mov ds,ax ; ds << data segment address
lp:
    lea dx,tishi
    mov ah,09h ; tishi
    int 21h
    mov bx,0 ; init i=0
lp0:
    mov ah,01h ; input >> al
    int 21h
    cmp al,0dh
    jz endinput ; al='\r'?
    mov string[bx],al ; string[i] << input
    inc bx ; ++i
    jmp lp0
endinput:
    mov num,bx ; store string length
    call transform ; call subprogram
    mov ah,4ch ; end program
    int 21h

transform proc
    push bx
    push dx
    mov bx,0 ; init i=0
lp1:
    mov dl,string[bx] ; dl << string[i]
    cmp dl,'a'
    jb notin ; dl<'a'?
    cmp dl,'z'
    jnbe notin ; dl>'z'?
    sub dl,20h ; 'a'-'A'=20h
notin:
    mov ah,02h
    int 21h
    inc bx
    cmp bx,num
    jnz lp1
    pop dx
    pop bx
    ret
transform endp

mycode ends
    end start