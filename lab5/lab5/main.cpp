#include <string>
#include <iostream>

using namespace std;

string p(string s)
{
	string a;
	if ((s=="AAC")||(s=="AAU")) a='N';
	if ((s=="AAA")||(s=="AAG")) a='K';
	if ((s=="UAC")||(s=="UAU")) a='Y';
	if ((s=="UUC")||(s=="UUU")) a='F';
	if ((s=="UGC")||(s=="UGU")) a='C';
	if (s=="UGG") a='W';
	if ((s=="ACA")||(s=="ACU")||(s=="ACC")||(s=="ACG")) a='T';
	if ((s=="UCA")||(s=="UCC")||(s=="UCG")||(s=="UCU")||(s=="AGC")||(s=="AGU")) a='S';
	if ((s=="AUA")||(s=="AUC")||(s=="AUU")) a='I';
	if (s=="AUG") a='M';
	if ((s=="CAC")||(s=="CAU")) a='H';
	if ((s=="CAA")||(s=="CAG")) a='Q';
	if ((s=="CCA")||(s=="CCC")||(s=="CCG")||(s=="CCU")) a='P';
	if ((s=="AGA")||(s=="AGG")||(s=="CGA")||(s=="CGC")||(s=="CGG")||(s=="CGU")) a='R';
	if ((s=="CUA")||(s=="CUC")||(s=="CUG")||(s=="CUU")||(s=="UUA")||(s=="UUG")) a='L';
	if ((s=="GAC")||(s=="GAU")) a='D';
	if ((s=="GAA")||(s=="GAG")) a='E';
	if ((s=="GCA")||(s=="GCC")||(s=="GCG")||(s=="GCU")) a='A';
	if ((s=="GGA")||(s=="GGC")||(s=="GGG")||(s=="GGU")) a='G';
	if ((s=="GUA")||(s=="GUC")||(s=="GUG")||(s=="GUU")) a='V';
	if ((s=="UAA")||(s=="UAG")||(s=="UGA")) a="\0";
	return a;
};

string r(string s)
{
    string a, str0;
    int n;
    n=s.length();
    str0=s;
    for(int i=0; i<n; i++)
	{
		if(s[i]=='A') str0[i]='U';
		if(s[i]=='U') str0[i]='A';
		if(s[i]=='C') str0[i]='G';
		if(s[i]=='G') str0[i]='C';
	}
	for(int i=n-1; i>=0; i--) a+=str0[i];
    return a;
};

int main()
{
	string strna, stra, str;
	int n1, n2;
	getline(cin, strna);
	getline(cin, stra);
	n1=strna.length();
	n2=stra.length();
	for(int i=0; i<n1; i++)
		if(strna[i]=='T') strna[i]='U';
	for(int i=0; i<(n1-3*n2+1); i++)
	{
		for(int j=i; j<(i+3*n2); j+=3)
			str+=p(strna.substr(j,3));
		if(str==stra)
        {
            str=strna.substr(i, 3*n2);
            for(int i=0; i<3*n2; i++)
		        if(str[i]=='U') str[i]='T';
            cout << str << endl;
        }
        str.clear();
	}
    strna=r(strna);
	for(int i=0; i<(n1-3*n2+1); i++)
	{
		for(int j=i; j<(i+3*n2); j+=3)
			str+=p(strna.substr(j,3));
		if(str==stra)
        {
            str=strna.substr(i, 3*n2);
            str=r(str);          
            for(int i=0; i<3*n2; i++)
		        if(str[i]=='U') str[i]='T';
            cout << str << endl;
        }
        str.clear();
	}
	return 0;
}