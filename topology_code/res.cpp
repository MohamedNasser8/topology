#include"res.h"
res::res() {}
res::res(string name, float def, float max, float min) :DeviceClass(name, def, max, min){}
void res::Print_Device()
{
	cout << "Resistance : " << this->get_name() << endl;
	DeviceClass::Print_Device();
}
