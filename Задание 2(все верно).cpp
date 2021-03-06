#include "pch.h"
#include <iostream>
#include "locale.h"
#include "string"
using namespace std;

void vse_posledovatelnost(string &s) {
	string dig;
	for (int i = 0; i < s.length() - 1; i++) {
		if (iswdigit(s[i]) && iswdigit(s[i + 1])) dig += s[i];
		else if (iswdigit(s[i]) && (iswalpha(s[i + 1]) || isspace(s[i + 1]) || ispunct(s[i + 1]))) {
			dig += s[i];
			int n = dig.length();
			if (n == 2) {
				s.erase((i - 1), 1);
				s[i - 1] = '*';
			}
			else if (n == 1) s[i] = '*';
			else if (n == 3 && stoi(dig) == 100) {
				s.erase((i - 2), 2);
				s[i - 2] = '*';
			}
			dig.clear();
		}
	}
}

void poslednia_posledovatelnost(string &s)
{
	string dig;
	dig.clear();
	int k = s.length();
	if (iswdigit(s[k - 1]) && iswdigit(s[k - 2]) && (iswalpha(s[k - 3]) || isspace(s[k - 3]) || ispunct(s[k - 3]))) {
		s.erase((k - 2), 1);
			s[k - 2] = '*';
	}
	if (iswdigit(s[k - 1]) && (iswalpha(s[k - 2]) || isspace(s[k - 2]) || ispunct(s[k - 2])))
		s[k - 1] = '*';
		if (iswdigit(s[k - 1]) && iswdigit(s[k - 2]) && iswdigit(s[k - 3]) && (s[k - 1] == 48) && (s[k - 2] == 48) && (s[k - 3] == 49) || (iswalpha(s[k - 4]) || isspace(s[k - 4]) || ispunct(s[k - 4]))) {
			s.erase((k - 3), 2);
				s[k - 3] = '*';
		}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	string s;
	cout << "Введите строку: " << endl;
	getline(cin, s);
	vse_posledovatelnost(s);
	poslednia_posledovatelnost(s);
	for (int i = 1; i < s.length(); i++) {
		if ((s[i] == 42) && (s[i - 1] == 45)) s.erase((i - 1, 1));
	}
	cout << s << endl;
	return 0;
}
