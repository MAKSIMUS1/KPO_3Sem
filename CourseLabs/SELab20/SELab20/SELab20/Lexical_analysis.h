#pragma once
#include "stdafx.h"

namespace Lex_analysis
{
	enum TYPEOFFST
	{
		_TYPEINT = 1, _TYPESTRING = 2, _TYPEFUNCTION = 3,
		_STRDECLARE = 4, _STRRETURN = 5, _STRMAIN = 6,
		_STRPRINT = 7, _LEFTBRACE = 8,
		_RIGHTBRACE = 9, _LEFTTHESIS = 10,
		_RIGHTTHESIS = 11, _SEMICOLON = 12, _COMMA = 13,
		_PLUS = 14, _MINUS = 15, _DEL = 16,
		_UMN = 17, _RAVNO = 18, _LITERAL_INT = 19, _LITERAL_STR = 20,
		_FSTIDENF = 21, _STANDART_LIBRARY = 22
	};
	struct LEX_FLAGS
	{
		bool __flag_int = false; // (���� ������ ��������������� ) ���� integer
		bool __flag_string = false; //  (���� ������ ��������������� ) ���� string

		bool __flag_function = false; // ( ���� ��������������� ) ���� �������
		bool __flag_function_external = false; // ( ���� ��������������� ) ���� �������
		bool __flag_parameter = false; // ( ���� ��������������� ) ���� ��������

		// ������� ���������� ����������
		//interger strlen (string) � ����� ������;
		//string substr(string, integer, integer) � ���������;
		bool __flag_standard_library = false;

		bool __flag_declare = false; // ���� declare
	};
	short Proverka_FST(char* c);
	void Add_To_LT(int line, char c);
	void Lexical_analysis(Parm::PARM parm, In::IN in);
};