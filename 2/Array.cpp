#include "Array.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;
Array::Array() {
	int count =0;
	int num = 0;
	while (count <= 0) {
		cout << "enter the length of an array" << endl;
		cin >> count;
	}
	cout << "enter the numbers " << endl;
	for (int i = 0; i < count; i++) {
		cin >> num;
		a.push_back(num);
	}
	cout << "array: ";

	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i != a.size() - 1)
			cout << "; ";
	}
	cout << endl;
}

bool Array::add() {
	cout << "adding the numbers" << endl;

	int count = 0;
	int num = 0;
	while (count <= 0) {
		cout << "enter the count of incoming numbers" << endl;
		cin >> count;
	}
	cout << "enter the numbers " << endl;
	for (int i = 0; i < count; i++) {
		cin >> num;
		a.push_back(num);
	}
	cout << "array: ";

	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i != a.size() - 1)
			cout << "; ";
	}
	cout << endl;
	return 0;
}


bool Array::remove(int index) {
	cout << "deleting the elements" << endl;
	try {
		if (index >= a.size()) {
			throw out_of_range("index out of range");
		}
		a.erase(a.begin() + index);
		cout << "number by index " << index << " has been deleted" << endl;
		return true;
	}
	catch (const out_of_range& e) {
		cerr << "error: " << e.what() << endl;
		return false;
	}
}

bool Array::show(int index) {
	cout << "showing current number by index" << endl;

	try {
		if (index >= a.size()) {
			throw out_of_range("index of range");
		}
		cout << "number by index " << index << " = " << a[index] << endl;
	}
	catch (const out_of_range& e) {
		cerr << "error: " << e.what() << endl;
	}
	return 0;
}