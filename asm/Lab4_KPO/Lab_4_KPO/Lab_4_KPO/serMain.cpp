#include "stdafx.h"

using namespace std;

void main()
{
	DataTypes dataTypes = DataTypes();

	cout << "Char: ";
	cin >> dataTypes.Char;
	cout << "Int: ";
	cin >> dataTypes.Int;

	Serialization serialization(dataTypes);
	serialization.Invoke();
}