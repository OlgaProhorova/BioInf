using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_33
{
	class Program
	{
		static Dictionary<char, int> aminoacid = new Dictionary<char, int>()
		{ {'G', 57}, { 'A', 71 }, { 'S', 87 }, { 'P', 97 }, { 'V', 99 }, { 'T', 101 }, { 'C', 103 }, { 'I', 113 }, { 'L', 113 }, { 'N', 114 }, { 'D', 115 }, { 'K', 128 },
		{ 'Q', 128 }, { 'E', 129 }, { 'M', 131 }, { 'H', 137 }, { 'F', 147 }, { 'R', 156 }, { 'Y', 163 }, { 'W', 186 }
		};
		static int massPept(string peptide)
		{
			int mass = 0;
			for (int i = 0; i < peptide.Length; i++)
				mass += aminoacid[peptide[i]];
			return mass;
		}
		static List<string> expand(List<string> peptides)
		{
			List<string> newPeptides = new List<string>();
			foreach(var peptide in peptides)
			{
				foreach(var key in aminoacid.Keys)
				{
					newPeptides.Add(peptide + key);
				}
			}
			return newPeptides;
		}
		static string LinearSpectrum(string peptide)
		{
			List<int> Linearspectrum = new List<int>();
			string subpeptide = " ";
			int mass = 0;
			if (peptide.Length == 1)
				return aminoacid[peptide[0]].ToString();
			Linearspectrum.Add(0);
			for (int i = 1; i < peptide.Length; i++)
			{
				for (int j = 0; j < peptide.Length; j++)
				{
					if ((i + j) <= peptide.Length)
					{
						subpeptide = peptide.Substring(j, i);
						Linearspectrum.Add(massPept(subpeptide));
					}
				}
			}
			Linearspectrum.Add(massPept(peptide));
			Linearspectrum.Sort();
			return string.Join(" ", Linearspectrum);
		}
		static int Score(string peptide, string spectrum)
		{
			List<string> peptideMass = LinearSpectrum(peptide).Split(' ').ToList();
			List<string> spectrumMass = spectrum.Split(' ').ToList();
			int score = 0;
			foreach(var mass in peptideMass)
			{
				if (spectrumMass.Contains(mass))
				{
					spectrumMass.Remove(mass);
					score++;
				}
			}
			return score;
		}
		static List<string> Trim(List<string> leaderboard, string spectrum, int n)
		{
			leaderboard.Sort((a, b) => Score(b, spectrum).CompareTo(Score(a, spectrum)));
			if (leaderboard.Count > n)
			{
				int last = n;
				for (int i = n; i < leaderboard.Count; i++)
				{
					if (Score(leaderboard[n - 1], spectrum) == Score(leaderboard[i], spectrum))
					{
						last = i;
					}
					else break;
				}
				leaderboard = leaderboard.Take(last + 1).ToList();
			}
			return leaderboard;
		}
		static int ParentMass(string spectrum)
		{
			int parentMass = int.Parse(spectrum.Split(' ').Last());
			return parentMass;
		}
		static string leaderboardCyclopeptideSequencing(string spectrum, int N)
		{
			List<string> leaderboard = new List<string>() { "" };
			string leaderPeptide = "";
			while (leaderboard.Count() > 0)
			{
				leaderboard = expand(leaderboard);
				List<string> leaderboardExemple = new List<string>(leaderboard);
				foreach(var Peptide in leaderboardExemple)
				{
					if (massPept(Peptide) == ParentMass(spectrum))
					{
						if (Score(Peptide, spectrum) > Score(leaderPeptide, spectrum))
						{
							leaderPeptide = Peptide;
						}
					}
					else if (massPept(Peptide) > ParentMass(spectrum))
					{
						leaderboard.Remove(Peptide);
					}
				}
				leaderboard = Trim(leaderboard, spectrum, N);
			}
			return leaderPeptide;
		}
		static void Main(string[] args)
		{
			int N = int.Parse(Console.ReadLine());
			string spectrum = Console.ReadLine();

			string leaderPeptide = leaderboardCyclopeptideSequencing(spectrum, N);

			List<string> Mass = new List<string>();
			foreach(var Peptide in leaderPeptide)
			{
				Mass.Add(aminoacid[Peptide].ToString());
			}
			Console.WriteLine(string.Join("-", Mass));
		}
}
}