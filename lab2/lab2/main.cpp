#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str, str1, str2, str0;
	int n, k, ch1=0, ch2;
	getline(cin, str);
	cin >> k;
	n=str.length();
	for(int i=0; i<=(n-k); i++)
	{
		ch2=0;
		str1=str.substr(i,k);
		if(str0.find(str1)==string::npos)
		{
			for(int j=0; j<=(n-k); j++)
			{
				str2=str.substr(j,k);
				if(str2==str1) ch2++;
			}
			if(ch2==ch1)
			{
				str0+=' ';
				str0+=str1;
			}
			if(ch2>ch1) 
			{
				str0=str1;
				ch1=ch2;
			}
		}
	}
	cout << str0 << endl;
    return 0;
}