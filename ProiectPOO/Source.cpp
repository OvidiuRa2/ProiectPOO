#include <iostream>
#include"Meniu.h"
using namespace std;

int main() {

	try {
		Meniu meniu;
	}
	catch (exception e) {
		cout << e.what();
	}

}