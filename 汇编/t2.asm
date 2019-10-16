mydata segment
	buff db -37,28,-115,-2,98,-100,93,120,56,-99
	max db ?
	min db ?
mydata ends

mycode segment
	assume cs:mycode,ds:mydata
start:
	mov ax,mydata
	mov ds,ax
	mov bx,1
	mov ah,buff[0]
	mov al,buff[1]
	cmp ah,al
	jnl l1
	mov ah,buff[1] ; <
	mov al,buff[0]
l1: inc bx ; at start bx=1
	cmp bx,10d
	jz l4 ; end
	cmp al,buff[bx]
	jnle l2
	cmp ah,buff[bx]
	jl l3
l2: mov al,buff[bx]
	jmp l1
l3: mov ah,buff[bx]
	jmp l1
l4: mov max,ah
	mov min,al
	mov ah,4ch
	int 21h
mycode ends
end start