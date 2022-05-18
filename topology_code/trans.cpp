#include"trans.h"

trans::trans() {}
trans::trans(string name, float def, float max, float min) :DeviceClass(name, def, max, min) {}
void trans::Print_Device()
{

	cout << "Transistor : " << this->get_name() << endl;
	DeviceClass::Print_Device();
	cout << endl;
}
//trans::~trans(){}