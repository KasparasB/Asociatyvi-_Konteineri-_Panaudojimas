#pragma once

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <ctype.h>
#include <cctype>
#include <stdlib.h>
#include <sstream>
#include <chrono>
#include <iterator>
#include <map>
#include <iomanip>
#include <functional>
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::ifstream;
using std::ofstream;
using std::multiset;
using std::remove_if;
using std::map;
using std::vector;


bool Url(string word);
int wordLength(map<string, size_t>& wordsNumbers);
int repeatingLength(map<string, vector<int>> &reference);
void readUrl();
void read(map<string, vector<int>> &reference);
void print(map<string, vector<int>> &reference);


