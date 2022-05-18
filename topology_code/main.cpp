#include <iostream>
#include "json-develop/single_include/nlohmann/json.hpp"
#include <string>
using json = nlohmann::json;
//#include "Api.h"
#include "topology.h"
using namespace std;
#include <fstream>
#include "test.h"
#include <unordered_map>
int main()
{
	cout << "Welcome to Api topology there is alot of functions"<<endl;
	char order;
	Api app;
	while (true) {
		cout << "Choose 1  to read a topology" << endl;
		cout << "Choose 2  to wright a topology" << endl;
		cout << "Choose 3  to get what topologies already stored in memeory" << endl;
		cout << "Choose 4  to delete a topology" << endl;
		cout << "Choose 5  to get devices in a topology" << endl;
		cout << "Choose 6  to get devices that is connected to a given nitlist node" << endl;
		cout << "Choose 7 for testing queries" << endl;
		cout << "Choose please :";
		cin >> order;
		if (order == '1') {
			string fileName;
			cout << "Please Enter the json file name without (.json) : ";
			cin >> fileName;
			cout << endl;
			bool x = app.ReadJSON(fileName);
			if (x)
				cout << "Done Reading & Adding to Memory" << endl;
			else
				cout << "Error Happened while reading & adding to memory or you entered wrong topology's id" << endl;
		}
		else if (order == '2')
		{
			cout << "Please enter the topology ID you want to wright :";
			string id;
			cin >> id;
			if (app.writeJSON(id))
				cout << "Sucssesful Wrighting" << endl;
			else
				cout << "Please enter valid id" << endl;
		}
		else if (order == '3')
		{
			vector<topology>ts = app.queryTopologies();
			for (int i = 0;i < ts.size();i++)
			{
				ts[i].Print_Topology();
			}
		}
		else if (order == '4')
		{
			cout << "please enter the topology id you want to delete";
			string s;
			cin >> s;
			if (app.deleteTopology(s))
			{
				cout << "Deleted Sucssesfully" << endl;
			}
			else
				cout << "please enter correct id" << endl;
		}
		
		else if (order == '5')
		{
			cout << "please enter the topology id you want to print its devices";
			string s;
			cin >> s;
			vector<DeviceClass*>dev = app.queryDevices(s);
			if (dev.size())
			{
				for (int i = 0;i < dev.size();i++)
					dev[i]->Print_Device();
			}
			else
				cout << "Please enter valid id" << endl;
		}
		else if (order == '6')
		{
			cout << "please enter the topology id and netlistnodeid : ";
			string s1, s2;
			cin >> s1 >> s2;
			vector<DeviceClass*>dev = app.queryDevicesWithNetlistNode(s1, s2);
			if (dev.size())
			{
				for (int i = 0;i < dev.size();i++)
					dev[i]->Print_Device();
			}
			else
				cout << "there is no connected devices with this node or enterd wrong topology id" << endl;
		}
		else if (order == '7')
		{
			test t;
			cout << "Test 1 :" << endl;
			t.testquery1();
			cout << "Test 2 :" << endl;
			t.testquery1();
			cout << "Test 3 :" << endl;
			t.testquery1();
			cout << "Test 4 :" << endl;
			t.testquery1();
			cout << "Test 5 :" << endl;
			t.testquery1();
			cout << "Test 6 :" << endl;
			t.testquery1();
		}
		cout << "**********************************************************************"<<endl;
	}

	
	
	return 0;
}
