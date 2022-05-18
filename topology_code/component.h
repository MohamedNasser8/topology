#pragma once
#include<unordered_map>
#include<string>
#include"DeviceClass.h"
using namespace std;



class component {
private:
	string id, type;
	unordered_map<string, string>netlist;
	DeviceClass* Device;

public:
	component(string typ, string id, DeviceClass* d, unordered_map<string, string>netlist);
	component();
	void set_type(string type);
	void set_id(string id);
	void set_Device(DeviceClass* d);
	void set_netList(unordered_map<string, string>netlist);
	string get_type();
	string get_id();
	DeviceClass* get_Comp_Device();
	unordered_map<string, string> get_netList();
	void Print_Component();

};

