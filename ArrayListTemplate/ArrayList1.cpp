//============================================================================
// Name        : ArrayList2.cpp
// Version     : v1.0
// Copyright   : Your copyright notice
// Description : ArrayList implementation using template class
//============================================================================

#include <iostream>
#include "ArrayList.hpp"
using namespace std;

int main() {
	//set initial capacity to zero
	ArrayList<string> *list1 = new ArrayList<string>(0);

	// add elements
	list1->add("apple");  //0
	list1->add("orange"); //1
	list1->add("banana"); //2
	list1->add("kiwi");   //3
	list1->add("plum");   //4
	list1->add("cherry"); //5
	list1->print();

	//insert an item to specified location
	list1->insert(3, "blueberry");
	//remove the item at 5
	list1->remove(5);
	list1->print();

	//try catch block example
	try {
		cout << "list1->get(5)=" << list1->get(5) << endl;
		// this should produce exception
		cout << "list1->get(50)=" << list1->get(50) << endl;
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cout << "list1->length()=" << list1->length() << endl;
	list1->clear();
	return 0;
}
