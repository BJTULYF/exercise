mydata segment
	ary1 db 12,-35,0,126,-90,-5,68,120,1,-19
	ary2 db 24,25,0,-38,-89,99,68,100,2,-20
	len equ $-ary2
mydata ends

mycode segment
	assume cs:mycode,ds:mydata
start:
	mov ax,mydata
	mov ds,ax ; ds << data segment address

	mov bx,0 ; init i=0
lp:
	call exchange ; bx is parameter
	inc bx ; ++i
	cmp bx,len
	jnz lp

	mov ah,4ch
	int 21h

exchange proc
	mov ah,ary1[bx] ; ah << ary1[i]
	mov al,ary2[bx] ; al << ary2[i]
	cmp ah,al
	jnl noxchg ; ah>=al?
	xchg ah,al
	mov ary1[bx],ah
	mov ary2[bx],al
noxchg:
	ret
exchange endp

mycode ends
	end start