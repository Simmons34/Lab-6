#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
	cout << "Hello Heap" << endl;
	Heap<int>myData;
	myData.Add(5);
	myData.Add(9);
	myData.Add(15);
	myData.Add(20);
	myData.Add(7);
	myData.Add(13);
	myData.Add(19);
	myData.Add(25);
	myData.PrintHeap();

	//fix search
	// test remove 
	myData.Remove(3);
	myData.Remove(25);
	return 0;
}
