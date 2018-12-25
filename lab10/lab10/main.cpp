#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chs(string s)
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

vector<int> stringtovector(string str)
{
	int j,n,k=0;
	for(int i=0; i<str.length(); i++)
	{
		if(str[i]==' ') k++;
	}
	k++;
	vector<int> vec(k);
	n=0;
	for(int i=0; i<str.length(); i++)
	{
		if(isdigit(str[i]))
		{
			j=0;
			while(isdigit(str[i+j])) j++;
			vec[n]=stoi(str.substr(i,j));
			n++;
			i+=j;
		}
	}	
	return vec;
};

vector<int> cyclospectrum(string str)
{
	int l,n,a;
	n=str.length();
	l=(n-1)*n+2;
	vector <int> spector(l);
	spector[0]=0;
	for(int i=0; i<n; i++)
		spector[i+1]=chs(str.substr(i, 1));
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
	return spector;
};

int main()
{
	string s1,s2;
	int ch=0,n1,n2;
	getline(cin,s1);
	getline(cin,s2);
	vector<int> v1, v2;
	v1=cyclospectrum(s1);
	v2=stringtovector(s2);
	n1=v1.size();
	n2=v2.size();
	for(int i=0; i<n1; i++)
		for(int j=0; j<n2; j++)
			if(v1[i]==v2[j])
			{
				ch++;
				v2[j]=1;
				v1[i]=1;
			}
	cout << ch << endl;
	return 0;
}