#pragma once

#include "stdafx.h"


struct DataTypes
{
	char Char;
	int Int;
};

class Deserialization
{
public:

	DataTypes* dataTypes;


	Deserialization(DataTypes *dataTypes) {
		this->dataTypes = dataTypes;
	}

	void Invoke();

private:

	std::ifstream file;
};