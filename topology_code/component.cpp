#include "component.h"


component::component(string typ, string id, DeviceClass* d, unordered_map<string, string> netlist)
{
	this->set_Device(d);
	this->set_id(id);
	this->set_type(typ);
	this->set_netList(netlist);
}

component::component()
{

}

void component::set_type(string type)
{
	this->type = type;
}

void component::set_id(string id)
{
	this->id = id;
}

void component::set_Device(DeviceClass* d)
{
	this->Device = d;
}

void component::set_netList(unordered_map<string, string> netlist)
{
	this->netlist = netlist;
}

string component::get_type()
{
	return this->type;
}

string component::get_id()
{
	return this->id;
}

DeviceClass* component::get_Comp_Device()
{
	return this->Device;
}

unordered_map<string, string> component::get_netList()
{
	return this->netlist;
}

void component::Print_Component()
{
	cout << "Component: " << endl;
	Device->Print_Device();
	cout << "NetList: " << endl;
	for (auto it : this->netlist) {
		cout << it.first << " : " << it.second << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

