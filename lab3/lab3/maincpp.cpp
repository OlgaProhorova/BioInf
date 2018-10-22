#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str, str1, str0;
	int n;
	getline(cin, str);
	n=str.length();
	str1=str;
	for(int i=0; i<n; i++)
	{
		if(str[i]=='A') str1[i]='T';
		if(str[i]=='T') str1[i]='A';
		if(str[i]=='C') str1[i]='G';
		if(str[i]=='G') str1[i]='C';
	}
	for(int i=n-1; i>=0; i--) str0+=str1[i];
	cout << str0 << endl;
    return 0;
}