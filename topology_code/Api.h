///thsi is
#include<vector>
#include<map>
#include<iostream>
#include"topology.h"
#include"DeviceClass.h"
#include"component.h"
#include<fstream>
#include"res.h"
#include"trans.h"
#include "json-develop/single_include/nlohmann/json.hpp"
using namespace std;
using nlohmann::json;


class Api{
private:
	
	vector<topology>topologies;
public:
	Api() {

	}

	bool ReadJSON(string FileName) {
		ifstream file(FileName + ".json");

		try {

			json jas = json::parse(file);
			topology to;
			vector<component>comps;
			string s;
			s = jas["id"];
			to.set_id(jas["id"]);
			for (int i = 0;i < jas["components"].size(); i++)
			{
				component comp;
				comp.set_id(jas["components"][i]["id"]);
				comp.set_type(jas["components"][i]["type"]);
				if (comp.get_type() == "resistor") {
					res* r = new res();
					r->set_name("resistance");
					json R = jas["components"][i]["resistance"];
					r->set_Default(R["default"]);
					r->set_Min(R["min"]);
					r->set_Max(R["max"]);
					comp.set_Device(r);
					comp.set_netList(jas["components"][i]["netlist"]);
					comps.push_back(comp);
				}
				else if (comp.get_type() == "nmos" || comp.get_type() == "pmos") {
					trans* tr = new trans();
					tr->set_name("m(l)");
					json R = jas["components"][i]["m(l)"];
					tr->set_Default(R["default"]);
					tr->set_Min(R["min"]);
					tr->set_Max(R["max"]);
					comp.set_Device(tr);
					comp.set_netList(jas["components"][i]["netlist"]);
					comps.push_back(comp);
				}
			}
			to.set_ComponentArray(comps);
			topologies.push_back(to);

		}
		catch (const std::exception&) {

			return false;
		}
	}
	bool writeJSON(string TopologyID) {
		string jname;
		cout << "Please enter the file name :";
		cin >> jname;
		if (jname == "")
			return false;
		cout << endl;
		topology t;
		ofstream o(jname + ".json");
		for (int i = 0; i < topologies.size(); i++) {
			if (topologies[i].get_id() == TopologyID) {
				t = topologies[i];
				break;
			}
		}
		if (t.get_id() == "") {

			return false;
		}
		o << '{' << endl;
		o << "\"id\": \"" + t.get_id() + "\"," << endl;
		o << "\"components\": [" << endl;
		vector<component>cs = t.get_Components();
		for (int i = 0;i < cs.size();i++)
		{
			o << '{' << endl;
			o << "\"type\": ";
			if (cs[i].get_type() == "resistor")
			{
				o << "\"resistor\"," << endl;
				o << "\"id\": " << "\"" << cs[i].get_id() << "\"" <<',' << endl;
				o << "\"resistance\" : {" << endl;
				o << "\"default\" :" << cs[i].get_Comp_Device()->get_Default() << "," << endl;
				o << "\"min\" :" << cs[i].get_Comp_Device()->get_min() << "," << endl;;
				o << "\"max\" :" << cs[i].get_Comp_Device()->get_max()<<endl;
				o << "},"<<endl;
				o << "\"netlist\": {"<<endl;
				unordered_map<string, string> netL = cs[i].get_netList();
				int count = 0;
				for (auto it = netL.begin(); it != netL.end(); it++)
				{
					count++;
					o << "\"" << it->first << " \" : \""
						<< it->second << "\"";
					if (count != 2)
						o << "," << endl;

				}
				o << "}" << endl;
				o << "}," << endl;
			}
			else if (cs[i].get_type() == "nmos" || cs[i].get_type() == "pmos")
			{
				o << "\"" << cs[i].get_type() << "\"" <<","<< endl;
				o << "\"id\": " << "\"" << cs[i].get_id() << "\"" <<',' << endl;
				o << "\"m(l)\" : {"<<endl;
				o << "\"default\" :" << cs[i].get_Comp_Device()->get_Default() << "," << endl;
				o << "\"min\" :" << cs[i].get_Comp_Device()->get_min() << ","<<endl;
				o << "\"max\" :" << cs[i].get_Comp_Device()->get_max()<<endl;
				o << "},"<<endl;
				o << "\"netlist\": {" << endl;
				unordered_map<string, string> netL = cs[i].get_netList();
				int count = 0;
				for (auto it = netL.begin(); it != netL.end(); it++)
				{
					count++;
					o << "\"" << it->first << " \" : \""
						<< it->second << "\"";
					if (count != 3)
						o << "," << endl;

				}
				o << '}' << endl;
				o << "}" << endl;
			}
		}
		o << "]" << endl;
		o << "}" << endl;


		return true;
	}

	vector<topology> queryTopologies() {
		return topologies;
	}

	bool deleteTopology(string TopologyID) {
		for (int i = 0;i < topologies.size();i++)
		{
			if (topologies[i].get_id() == TopologyID)
			{
				topologies[i] = topologies[topologies.size() - 1];
				topologies.pop_back();
				return true;
			}
		}
		return false;
	}
	vector<DeviceClass*> queryDevices(string TopologyID)
	{
		topology t;
		string a = "";
		vector<DeviceClass*>dev;
		for (int i = 0;i < topologies.size();i++)
		{
			if (topologies[i].get_id() == TopologyID)
			{
				a = TopologyID;
				t = topologies[i];
				break;
			}
		}
		if (a == "")
			return vector<DeviceClass*>();
		else
		{
			vector<component>comp = t.get_Components();
			for (int i = 0;i < comp.size();i++)
			{
				dev.push_back(comp[i].get_Comp_Device());
			}
			return dev;
		}
	}

	vector<DeviceClass*> queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID) 
	{
		topology t;
		bool found = false;
		vector<DeviceClass*>dev;
		for (int i = 0;i < topologies.size();i++)
		{
			if (topologies[i].get_id() == TopologyID)
			{
				t = topologies[i];
				found = true;
				break;
			}
		}
		if (!found)
			return dev;
		vector<component>comps = t.get_Components();
		for (int i = 0;i < comps.size();i++)
		{
			unordered_map<string, string>nl = comps[i].get_netList();
			bool connected = false;
			for (auto j : nl)
			{
				if (j.second == NetlistNodeID)
				{
					dev.push_back(comps[i].get_Comp_Device());
				}
			}

			return dev;
		}
		

	}

};