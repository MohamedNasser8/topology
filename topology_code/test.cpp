#include "test.h"
void test::testquery1() {

	string s = "topology";
	string r = "ree";
	bool x;
	try
	{
		x = a.ReadJSON(s);

		cout << "PASSED" << endl;
	}
	catch (const std::exception&) {
		cout << "DIDN'T PASS" << endl;
	}
	try
	{
		x = a.ReadJSON(r);

		cout << "PASSED" << endl;
	}
	catch (const std::exception&) {
		cout << "DIDN'T PASS" << endl;
	}
	try
	{
		x = a.ReadJSON("topo");
		if (x == false)
			cout << "PASS" << endl;
	}
	catch (const std::exception&) {
		cout << "DIDN'T PASS" << endl;
	}
}
void test::testquery2() {
	bool f = false;
	try
	{
		string fileName = "";

		f = a.writeJSON(fileName);
		if (f ==false)
			cout << "PASSED" << endl;
	}
	catch (const std::exception&) {
		cout << "DIDN'T PASS" << endl;
	}
	try
	{
		bool x = a.writeJSON("top1");
		if (x == true)
			cout << "PASSED" << endl;
	}
	catch (const std::exception&) {
		cout << "DIDN'T PASS" << endl;
	}

}

void test::testquery3() {
	vector<topology>list = a.queryTopologies();
	if (list.size() != 0) {
		cout << "PASSED" << endl;
	}
	else {
		cout << "DIDN'T PASS"<<endl;
	}

}
void test::testquery4() {
	bool f = a.deleteTopology("top1");
	if (f) {
		cout << "PASSED" << endl;
	}
	else {
		cout << "DIDN'T PASS"<<endl;
	}

}
void test::testquery5(){
	vector<DeviceClass*>de = a.queryDevices("top1");
	if(de.size()!=2)
		cout << "DIDN'T PASS"<<endl;
	else
		cout << "PASSED" << endl;
}
void test::testquery6() {
	vector<DeviceClass*>de = a.queryDevicesWithNetlistNode("top1", "n1");
	if (de.size() != 2)
		cout << "DIDN'T PASS" << endl;
	else
		cout << "PASSED" << endl;
}
