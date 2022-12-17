#pragma once

#include "stdafx.h"

#define ASMHEADER \
\
<< ".586P" << endl \
<< ".MODEL FLAT, STDCALL" << endl \
<< "includelib kernel32.lib\n" << endl \
<< "ExitProcess PROTO : DWORD" << endl \
<< "MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD\n" << endl \
<< ".STACK 4096\n" << endl \
<< ".CONST\n" << endl \
<< ".DATA\n" << endl \
<< "OK			EQU	0" << endl \
<< "TEXT_MESSAGE		DB \"test\", 0" << endl \
<< "HW			DD ?\n" << endl

#define ASMFOOTER \
\
<< ".CODE\n" << endl \
<< "main PROC\n" << endl \
<< "push OK" << endl \
<< "push offset TEXT_MESSAGE" << endl \
<< "push offset FILESTR" << endl \
<< "push HW" << endl \
<< "call MessageBoxA\n" << endl \
<< "mov eax, FILEINT" << endl \
<< "mov ebx, offset INTSTR" << endl \
<< "add ebx, sizeof INTSTR" << endl \
<< "dec ebx" << endl \
<< "dec ebx" << endl \
<< "mov[ebx], eax" << endl \
<< "push OK" << endl \
<< "push offset TEXT_MESSAGE" << endl \
<< "push offset INTSTR" << endl \
<< "push HW" << endl \
<< "call MessageBoxA\n" << endl \
<< "push - 1\n" << endl \
<< "call ExitProcess" << endl \
<< "main ENDP\n" << endl \
<< "end main" << endl			

class AsmConvenrter
{
public:
	DataTypes dataTypes;

	AsmConvenrter(DataTypes dataTypes) {
		this->dataTypes = dataTypes;
	}

	void Invoke();

private:

	std::ofstream file;
};