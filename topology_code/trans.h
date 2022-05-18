#pragma once
#include <iostream>
#include <string>
#include "DeviceClass.h"
using namespace std;

class  trans : public DeviceClass
{
public:
	trans();
	trans(string name, float def, float max, float min);
	virtual void Print_Device();
	//~trans();
};

