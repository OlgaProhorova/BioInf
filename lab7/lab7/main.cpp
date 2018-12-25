#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ch(string s)
{
	int a=0;
	if(s=="G") a=57;
	if(s=="A") a=71;
	if(s=="S") a=87;
	if(s=="P") a=97;
	if(s=="V") a=99;
	if(s=="T") a=101;
	if(s=="C") a=103;
	if((s=="I")||(s=="L")) a=113;
	if(s=="N") a=114;
	if(s=="D") a=115;
	if((s=="K")||(s=="Q")) a=128;
	if(s=="E") a=129;
	if(s=="M") a=131;
	if(s=="H") a=137;
	if(s=="F") a=147;
	if(s=="R") a=156;
	if(s=="Y") a=163;
	if(s=="W") a=186;
	return a;
};

int main()
{
	string str;
	int n,l,a;
	getline(cin,str);
	n=str.length();
	l=(n-1)*n+2;
	vector <int> spector(l);
	spector[0]=0;
	for(int i=0; i<n; i++)
		spector[i+1]=ch(str.substr(i, 1));
	for(int i=n+1; i<l; i++)
	{
		if(i%n!=0) a=(i/n)+1;
		else a=i/n;
		for(int j=1; j<=a; j++)
		{
			if(i%n+j-1==0) spector[i]+=spector[n];
			else if(i%n+j-1<=n) spector[i]+=spector[i%n+j-1];
				else spector[i]+=spector[i%n+j-1-n];
		}
	}
	sort(spector.begin(), spector.end());
	for(int i=0; i<l; i++)
		cout << spector[i]	<< ' ';
	return 0;
}