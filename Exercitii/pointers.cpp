#include <iostream>

using namespace std;

int main() {
	string name = "geasdsa";
	string* pName = &name;

	int age = 20;
	int* pAge = &age;
	string pizzas[5] = { "1","2" ,"3" ,"4" ,"5" };
	string* pPizzas = pizzas;

	for (string pizza : pizzas) {
		cout << pizza << "\n";
	}

	cout << "my pointer points at " << pName << '\n'; //memory address itself
	cout << "my pointer points at " << *pName << '\n'; //the value stored at this memory address
	cout << " my age is " << *pAge << '\n';
	cout << "i have # pizzas " << *pPizzas << '\n';

	return 0;
}