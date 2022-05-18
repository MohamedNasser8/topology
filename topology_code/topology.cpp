#include"topology.h"

topology::topology(string id)
{
	this->set_id(id);
}

topology::topology()
{
}

topology::topology(string id, vector<component>comp)
{
	this->set_id(id);
	this->set_ComponentArray(comp);
}

void topology::set_id(string id)
{
	this->id = id;
}



void topology::set_ComponentArray(vector<component> comp)
{
	this->comp = comp;
}




void topology::Add_Component(component c)
{
	this->comp.push_back(c);
}

string topology::get_id()
{
	return this->id;
}

vector<component>  topology::get_Components()
{
	return this->comp;
}

void topology::Print_Topology()
{
	cout << "Topology's ID: " << this->get_id() << endl;
	for (int i = 0; i < comp.size(); i++) {
		comp[i].Print_Component();
		cout << endl << endl;
	}
}