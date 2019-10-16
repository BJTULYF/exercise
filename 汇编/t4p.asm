mydata segment
	n dw 0
	table db 100 dup(?)
	string db 'please enter:$'
	kmp db 'CHAR'
	kmplen equ $-kmp
mydata ends

mycode segment
	assume cs:mycode,ds:mydata
start:
	mov ax,mydata
	mov ds,ax

	mov bx,0 ; bx is the num of input string

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

	add dl,'0'
	mov ah,02h
	int 21h
	mov ah,4ch
	int 21h

ctn proc near
	mov cx,n
	sub cx,kmplen
	inc cx ; bx = n-kmplen+1
	mov dl,0 ; dl is result
	mov si,0 ; string ptr
lop:mov di,0 ; kmp ptr
	cmp si,cx
	jz cend

	mov al,table[si]
	mov bx,si
	inc si

lp1:cmp di,kmplen
	jz cty
	mov al,table[bx][di]
	mov ah,kmp[di]
	inc di
	cmp ah,al
	jnz lop
	jmp lp1

cty:inc dl
	jmp lop

cend:ret
ctn endp

mycode ends
end start