#pragma once

struct DataTypes
{
	char Char;
	int Int;
};

class Serialization
{

public:

	DataTypes dataTypes;


	Serialization(DataTypes dataTypes) : dataTypes(dataTypes) { }

	void Invoke();

private:

	std::ofstream file;

};
