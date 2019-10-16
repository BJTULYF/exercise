mydata segment
	n dw 0
	table db 100 dup(?)
	string db 'please enter:$'
mydata ends

mycode segment
	assume cs:mycode,ds:mydata
start:
	mov ax,mydata
	mov ds,ax

	mov bx,0

	lea dx,string
	mov ah,09h
	int 21h

inp:mov ah,01h
	int 21h
	mov table[bx],al
	inc bx
	cmp al,0dh
	jnz inp
	mov n,bx

	call ctn

	add bx,'0'
	mov dl,bl
	mov ah,02h
	int 21h
	mov ah,4ch
	int 21h

ctn proc near
	mov bx,0
	mov si,0
lop:cmp si,n
	jz cend

	mov al,table[si]
	cmp al,'C'
	jz cty
	cmp al,'H'
	jz cty
	cmp al,'A'
	jz cty
	cmp al,'R'
	jz cty
	inc si
	jmp lop
cty:
	inc bx
	inc si
	jmp lop

cend:ret
ctn endp
mycode ends
end start
