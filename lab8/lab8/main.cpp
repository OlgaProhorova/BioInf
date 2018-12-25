#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int s[18] = {57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186};
	int m;
	cin >> m;
	vector <long long int> vec(m+1);
	vec[0]=1;
	for (int i=57; i<=m; i++)
	{
		vec[i]=0;
		for (int j=0; j<18; j++)
			if (i-s[j]>=0) vec[i]+=vec[i-s[j]];
	}
	cout << vec[m];
	return 0;
}