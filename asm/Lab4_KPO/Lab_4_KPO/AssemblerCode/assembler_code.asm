.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

OK			EQU	0
TEXT_MESSAGE		DB "test", 0
HW			DD ?

FILESTR	 DB "b", 0

FILEINT	 DD 55

INTSTR		DB "num: ", 0
.CODE

main PROC

push OK
push offset TEXT_MESSAGE
push offset FILESTR
push HW
call MessageBoxA

mov eax, FILEINT
mov ebx, offset INTSTR
add ebx, sizeof INTSTR
dec ebx
dec ebx
mov[ebx], eax
push OK
push offset TEXT_MESSAGE
push offset INTSTR
push HW
call MessageBoxA

push - 1

call ExitProcess
main ENDP

end main
