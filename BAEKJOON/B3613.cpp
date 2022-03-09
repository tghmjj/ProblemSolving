#include "../header.h"
/*
https://www.acmicpc.net/problem/3613
*/

#include <string>

bool checkJava(string str) {
	if (str[0] > 'z' || str[0] < 'a')
		return false;
	for (int i = 0; i < str.length(); i++) {
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			return false;
		}
	}
	return true;
}

bool checkCpp(string str) {
	if (str[0] == '_' || str[str.length() - 1] == '_')
		return false;
	for (int i = 0; i < str.length(); i++) {
		if (i > 0) {
			if (str[i - 1] == '_' && str[i] == '_')
				return false;
		}

		if ((str[i] > 'z' || str[i] < 'a') && str[i] != '_') {
			return false;
		}
	}
	return true;
}

string CppToJava(string str) {
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == '_') {
			str[i + 1] = (char)str[i + 1] - 32;
			str.erase(i,1);
		}
			
	}
	
	return str;
}

void JavaToCpp(string str) {
	cout << str[0];
	for (int i = 1; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << "_" << (char)(str[i] + 32);
		}
		else {
			cout << str[i];
		}
	}
	
}

//'a' = 97 'A' = 65 gap = 32
void ProblemSolved() {
	string str;
	cin >> str;
	if (checkJava(str)) {
		JavaToCpp(str);
	}
	else if (checkCpp(str)) {
		cout << CppToJava(str);
	}
	else {
		cout << "Error!";
	}

	return;
}