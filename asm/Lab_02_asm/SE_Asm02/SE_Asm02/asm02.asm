.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib user32.lib
ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD
.STACK 4096

.CONST
.DATA
ptra dword 3
ptrb dword 2

MB_OK EQU 0
STR1 DB "Моя первая программа", 0
STR2 DB "Результат сложения = ", 0
HW	 DD ?

.CODE
main PROC
	
START :
	mov	eax, ptra
	add	eax, ptrb 
	add eax, 30h
	add STR2 + 21, al

	INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK
	
	push 0
	call ExitProcess
main ENDP

end main