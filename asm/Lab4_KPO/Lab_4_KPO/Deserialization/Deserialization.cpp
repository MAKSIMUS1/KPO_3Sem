#include "stdafx.h"

using namespace std;

void Deserialization::Invoke() {

	file = ifstream("D:\\BSTU\\Kurs_2_1\\KPO\\asm\\Lab4_KPO\\Lab_4_KPO\\Lab_4_KPO\\seriliz.txt");

	file.read(reinterpret_cast<char*>(&(dataTypes->Char)), sizeof(char));
	file.read(reinterpret_cast<char*>(&(dataTypes->Int)), sizeof(int));

	file.close();
}
