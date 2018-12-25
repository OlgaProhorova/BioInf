#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

vector<string> aminoacids = { {'G'},{'A'},{'S'},{'P'},{'V'},{'T'},{'C'},{'I'},{'L'},{'N'},{'D'},{'K'},{'Q'},{'E'},{'M'},{'H'},{'F'},{'R'},{'Y'},{'W'} };

map<char, int> spectr = { { 'G', 57 },{ 'A', 71 },{ 'S', 87 },{ 'P', 97 },{ 'V', 99 },
{ 'T', 101 },{ 'C', 103 },{ 'I', 113 },{ 'L', 113 },{ 'N', 114 },
{ 'D', 115 },{ 'K', 128 },{ 'Q', 128 },{ 'E', 129 },{ 'M', 131 },
{ 'H', 137 },{ 'F', 147 },{ 'R', 156 },{ 'Y', 163 },{ 'W', 186 } };

int massPept(string peptide)
{
	int mass = 0;
	for (int i = 0; i < peptide.size(); i++)
		mass += spectr[peptide[i]];
	return mass;
};

vector<string> expand(vector<string> peptides)
{
	vector<string> tmp;
	for (int i = 0; i < peptides.size(); i++)
		for (int j = 0; j < aminoacids.size(); j++)
		{
			string newpep = peptides[i];
			newpep += aminoacids[j];
			tmp.push_back(newpep);
		}
	return tmp;
};

vector<int> cycloSpectrum(string peptide)
{
	vector<string> vs;
	vector<int> cycSpectrum;
	int size = peptide.size();
	vs.push_back("");
	for (int i = 1; i < size; i++)
				for (int l = 0; l < size; l++)
					if ((l + i) < size) vs.push_back(peptide.substr(l, i));
					else
					{
						int b = l + i - size;
						string tmp;
						tmp = peptide.substr(l, i);
						tmp += peptide.substr(0, b);
						vs.push_back(tmp);
					}
	vs.push_back(peptide);
	for (int i = 0; i < vs.size(); i++)
	{
		int tmpmass = 0;
		for (int j = 0; j < vs[i].size(); j++)
			tmpmass += spectr[vs[i][j]];
		cycSpectrum.push_back(tmpmass);
	}
	sort(cycSpectrum.begin(), cycSpectrum.end());
	return cycSpectrum;
};

vector<int> linarSpectrum(string peptide)
{
	vector<string> vs;
	vector<int> linSpectrum;
	int size = peptide.size();
	vs.push_back("");
	for (int i = 1; i < size; i++)
		for (int l = 0; l < size; l++)
			if ((l + i) <= size) vs.push_back(peptide.substr(l, i));
	vs.push_back(peptide);
	for (int i = 0; i < vs.size(); i++)
	{
		int tmpmass = 0;
		for (int j = 0; j < vs[i].size(); j++)
			tmpmass += spectr[vs[i][j]];
		linSpectrum.push_back(tmpmass);
	}
	sort(linSpectrum.begin(), linSpectrum.end());
	return linSpectrum;
};

vector<string> remove(vector<string> peptides, string pept)
{
	vector<string> tmp;
	for (int i = 0; i < peptides.size(); i++)
		if (peptides[i] != pept) tmp.push_back(peptides[i]);
	return tmp;
};

bool isConsistedWithSpectrum(vector<int> spec, vector<int> pept)
{
	bool f = false;
	for (int i = 0; i < pept.size(); i++)
	{
		for(int j=0;j<spec.size();j++)
			if (spec[j] == pept[i]) f = true;
		if (!f) return f;
		f = false;
	}
	return true;	
};

vector<string> cycloPeptideSequencing(vector<int> spec)
{
	int parMass = spec[spec.size() - 1];
	vector<string> result;
	vector<string> peptides = { "" };
	while (peptides.size() > 0)
	{
		peptides = expand(peptides);
		vector<string> tmp;
		tmp = peptides;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (massPept(tmp[i]) == parMass)
			{
				if (cycloSpectrum(tmp[i]) == spec)
				{
					result.push_back(tmp[i]);
				}
				peptides = remove(peptides, tmp[i]);
			}
			else if (!isConsistedWithSpectrum(spec, linarSpectrum(tmp[i])))
			{
				peptides = remove(peptides, tmp[i]);
			}
		}
	}
	return result;
};

vector<int> strToVec(string str)
{
	vector<int> res;
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		while((str[i] != ' ')&&(i<str.size()))
		{
			tmp += str[i];
			i++;
		}
		char *p = &tmp[0];
		res.push_back(atoi(p));
		tmp = "";
	}
	return res;
};

int main()
{
	string inspectr;
	getline(cin, inspectr);
	vector<int> spec = strToVec(inspectr);
	vector<string> peptides;
	peptides.push_back("");
	peptides=expand(peptides);
	peptides = expand(peptides);
	cycloSpectrum("PVT");
	linarSpectrum("PVT");
	peptides = cycloPeptideSequencing(spec);
	string res;
	for (int i = 0; i < peptides.size(); i++) 
	{
		string tmp;
		for (int j = 0; j < peptides[i].length(); j++) 
		{
			tmp += to_string(spectr[peptides[i][j]]);
			tmp += "-";
		}
		tmp = tmp.substr(0, tmp.length() - 1);
		if (res.find(tmp) > res.length() || res.find(tmp) < 0) 
		{
			res += tmp;
			res += " ";
		}
	}
	res = res.substr(0, res.length() - 1);
	cout << res;
	return 0;
}