mydata segment
	string db 7fh,5bh,6dh,6dh,40h,77h ; 8255-A
	strlen equ $-string
mydata ends

mycode segment
	assume cs:mycode,ds:mydata
start:
	mov ax,mydata
	mov ds,ax ; use data segment
	
	mov dx,213h
	mov al,10010000b
	out dx,al ; init

myloop:
	mov dx,210h
	in al,dx
	cmp ah,al
	jz continue1 ; no change
	mov ah,al
	mov bl,al
continue1:
	mov al,bl
	mov dx,211h
	out dx,al
	ror bl,1
	call mydelay ; for delay
	jmp myloop ; endless loop
	
	mov ah,4ch ; end process,but can't reach here
	int 21h
	
mydelay proc
	mov cx,0fffh
minedelay:
	dec cx
	call shumaguan ; show 8255-A
	cmp cx,0
	jnz minedelay
	ret
mydelay endp

shumaguan proc
	push bx
	push cx ; protect

	mov bx,0
	mov cl,00100000b
loop1:
	mov ch,string[bx]
	call show ; cl,ch are parameters
	inc bx
	cmp bx,strlen
	jnz loop1

	pop cx ; release
	pop bx
	
	ret
shumaguan endp

show proc
	mov dx,220h
	mov al,0
	out dx,al ; clear character

	mov dx,221h
	mov al,cl ; cl is parameter
	out dx,al ; select position
	shr cl,1
	
	mov dx,220h
	mov al,ch ; ch is parameter
	out dx,al ; select character

	ret
show endp

mycode ends
	end start
	