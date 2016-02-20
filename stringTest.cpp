#include <iostream>
#include <string>

using namespace std;

int main(){

	string string1 = "abcdefghijklmnop";
	cout << string1[10] << endl;
	cout << string1.substr(10-4,4) << endl;
	cout << string1 << endl;

	return 0;

}
