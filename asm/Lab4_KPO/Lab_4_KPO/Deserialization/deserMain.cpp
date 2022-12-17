#include "stdafx.h"

using namespace std;

int main() {
	DataTypes dataTypes = DataTypes();
	Deserialization deserializer(&dataTypes);
	deserializer.Invoke();
	AsmConvenrter assembler(dataTypes);
	assembler.Invoke();
}