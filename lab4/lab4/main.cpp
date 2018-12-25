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


int main() 
{
    string str1, str;
	int n;
	getline(cin, str1);
	n=str1.length();
	for(int i=0; i<n; i+=3)
	{
		str+=p(str1.substr(i,3));
	}
	cout << str << endl;
    return 0;
}