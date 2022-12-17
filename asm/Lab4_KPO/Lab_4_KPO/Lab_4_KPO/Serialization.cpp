#include "stdafx.h"

using namespace std;

void Serialization::Invoke()
{
	file = ofstream("D:\\BSTU\\Kurs_2_1\\KPO\\asm\\Lab4_KPO\\Lab_4_KPO\\Lab_4_KPO\\seriliz.txt");

	file.write(reinterpret_cast<char*>(&dataTypes.Char), sizeof(char));
	file.write(reinterpret_cast<char*>(&dataTypes.Int), sizeof(int));
}