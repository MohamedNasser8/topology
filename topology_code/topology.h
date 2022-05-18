#pragma once
#include <vector>
#include <iostream>
#include <string>
#include"component.h"
using namespace std;

class topology
{

private:
	string id;
	vector<component>comp;

public:
	topology();
	topology(string id);
	topology(string id, vector<component>comp);
	void set_id(string id);
	void set_ComponentArray(vector<component>comp);
	void Add_Component(component c);
	string get_id();
	vector<component> get_Components();
	void Print_Topology();
	//~topology();
};
