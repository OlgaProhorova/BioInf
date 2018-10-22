#include <string>
#include <iostream>

using namespace std;

int main()
{
	string str1, str2, str;
	int n1, n2, ch=0;
	getline(cin, str1);
	getline(cin, str2);
	n1=str1.length();
	n2=str2.length();
	for(int i=0; i<=(n2-n1); i++)
	{
		str=str2.substr(i, n1);
		if(str==str1) ch++;
	}
	cout << ch << endl;
	return 0;
}
