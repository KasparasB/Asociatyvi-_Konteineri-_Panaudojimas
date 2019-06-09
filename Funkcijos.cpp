#include "Header.h"

bool Url(string word)
{
	string test1 = "https://";
	string test2 = "www";
	string test3 = "http://";

	string blankWord = "";
	int commaCount = 0;
	int trues = 0;

	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == '.') commaCount++;

		blankWord += word[i];

		if (i == 6 && blankWord == test3) trues++;
	
		if (i == 2 && blankWord == test2) trues++;
		
		if (i == 7 && blankWord == test1) trues++;
		
	}
	if (commaCount == 2 && trues == 1) return true;
	return false;
}

int wordLength(map<string, vector<int>>& wordsNumbers)
{
	int maxLength = 0;

	for (auto a : wordsNumbers)
	{
		if (maxLength < a.first.length()) maxLength = a.first.length();
	}

	return maxLength;
}

int repeatingLength(map<string, vector<int>> &reference)
{
	int maxLength = 0;

	for (auto a : reference)
	{
		if (maxLength < a.second.size()) maxLength = a.second.size();
	}

	return maxLength;
}

void readUrl()
{
	ifstream in("Text.txt");
	ofstream out("results.txt");
	string s1;
	string tmp;

	vector<string> words;
	vector<string> urls;
	out << "Rasti url adresai:" << endl;

	while (in.peek() != EOF)
	{
		while (getline(in, s1))
		{
			std::istringstream eil(s1);
			while (eil.peek() != EOF)
			{
				eil >> tmp;
				words.push_back(tmp);
				if (Url(tmp))
				{
					urls.push_back(tmp);
					out << tmp << endl;
				}
			}
		}
	}
	out << endl;
	in.close();

	ofstream ofs("Text.txt", std::ofstream::out | std::ofstream::trunc);

	int guard = 0;
	int jj = 1;
	
	for (int i = 0; i < words.size()-1; i++)
	{
		guard = 0;
		if(urls.size()!=0)
		{
			for (int y = 0; y < urls.size()-1; i++)
			{
				if (urls[y] == words[i]) guard++;
			}
		}
		if (guard == 0)
		{
			if (jj % 10 == 1)
			{
				ofs << words[i];
			}
			else
			{
				ofs << " " << words[i];
				if (jj % 10 == 0) ofs << endl;
			}
			jj++;
			
		}
	}
	
	ofs.close();
	out.close();
}

void read(map<string, vector<int>> &reference)
{
	ifstream in("Text.txt");
	string s1;
	string tmp;

	int lineCount = 1;

	while (in.peek() != EOF)
	{
		while (getline(in, s1))
		{
			//s1.erase(remove_if(s1.begin(), s1.end(), Url));
			//s1.erase(s1[0]);
			s1.erase(remove_if(s1.begin(), s1.end(), [](char s) { return s == ',' || s == '-' || s == '.' || s == '!' || s == '?' || s == '(' || s == ')' || s == '„' || s == '–' || s == '“'; }),
				s1.end());
			std::istringstream eil(s1);
			while (eil.peek() != EOF)
			{
				eil >> tmp;
				std::transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);
				reference[tmp].push_back(lineCount);

			}
			lineCount++;
		}
		
	}

	in.close();
}

void print(map<string, vector<int>> &reference)
{
	std::ofstream out("results.txt", std::ios::app);
	
	typedef std::function<bool(std::pair<std::string, vector<int>> , std::pair<std::string, vector<int>>)> Comparator;

	Comparator compFunctor = [](std::pair<std::string, vector<int>>elem1 , std::pair<std::string, vector<int>>elem2)
	{
		return elem1.second.size() > elem2.second.size();
	};

	std::multiset <std::pair<std::string, vector<int>>, Comparator> setOfWords(reference.begin(), reference.end(), compFunctor);

	int maxLength = wordLength(reference);
	int maxSize = repeatingLength(reference);

	out << std::left << std::setw(maxLength) << "Zodziai" << std::right<<"|"<<std::left << std::setw(23) << "Pasikartojimu skaicius"<<std::right<<"|"<< std::left << std::setw(maxSize * 2 + maxSize - 1)<<"Eilutes"<< std::right<<"|"<<endl;
	for (int i = 0; i < maxLength + 23 +  maxSize*2 + maxSize; i++) out << "-";
	out << endl;

	for (auto a : setOfWords)
	{
		if (a.second.size() > 1)
		{
			string test = "";
			out << std::left << std::setw(maxLength) << a.first << std::right<<"|"<<std::left << std::setw(23) << a.second.size()<<std::right<<"|";
			out <<std::left<<std::setw(maxSize * 2 + maxSize - 1);
			for (int i = 0; i < a.second.size(); i++)
			{
				test += std::to_string(a.second[i]) + " ";
			}
			out << test << std::right << "|" << endl;
		}
	}
	out.close();
}
