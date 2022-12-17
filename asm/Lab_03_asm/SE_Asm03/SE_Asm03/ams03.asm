.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
ExitProcess PROTO : DWORD
.STACK 4096

.CONST
.DATA
myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles

myArray DWORD 1, 2, 33, 45, 52, 65, 7
sum DWORD 0

.CODE
main PROC
	
START :
	mov ESI, OFFSET myWords
	mov AX, [ESI + 0]
	mov BX, [ESI + 2]

	mov ESI, OFFSET myArray
	mov ECX, LENGTHOF myArray
	TURBOLOOP:
		mov EAX, [ESI]
		add sum, EAX
		add ESI, type myArray
		cmp EAX, 0
		jz EXIT
	loop TURBOLOOP

	mov EBX, 1
		jmp DARKEXIT

	EXIT:
		mov EBX, 0

	DARKEXIT:
		mov EAX, sum

	push 0
	call ExitProcess
main ENDP

end main