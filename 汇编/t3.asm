mydata segment
	score db 56,78,67,40,87,99,63,51,74,100,90,80,68,88,55,66,84,96,45,73
	num equ $-score
	s5 db ?
	s6 db ?
	s7 db ?
	s8 db ?
	s9 db ?
	s10 db ?
mydata ends

mycode segment
	assume cs:mycode,ds:mydata
start:
	mov ax,mydata
	mov ds,ax

	mov s5,0
	mov s6,0
	mov s7,0
	mov s8,0
	mov s9,0
	mov s10,0

	mov bx,0
lp: cmp bx,num
	jz ld
	mov al,score[bx]
	cmp al,60d
	jb l1
	cmp al,70d
	jb l2
	cmp al,80d
	jb l3
	cmp al,90d
	jb l4
	cmp al,100d
	jb l5
	inc s10
	inc bx
	jmp lp

l1: inc s5
	inc bx
	jmp lp
l2: inc s6
	inc bx
	jmp lp
l3: inc s7
	inc bx
	jmp lp
l4: inc s8
	inc bx
	jmp lp
l5: inc s9
	inc bx
	jmp lp

ld: mov ah,4ch
	int 21h
mycode ends
end start