#pragma once
#include <iostream>
#include <string>
#include "DeviceClass.h"
using namespace std;
class  res : public DeviceClass
{
public:
	res();
	res(string name, float def, float max, float min);
	virtual void Print_Device();
	//~res();
};
