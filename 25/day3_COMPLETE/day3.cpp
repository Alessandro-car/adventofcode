#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string max_n_digit(const string& s, int n) {
	string result;
	int to_remove = s.length() - n;
	for (char digit : s) {
		while (!result.empty() && result.back()  < digit && to_remove > 0) {
			result.pop_back();
			to_remove--;
		}
		result.push_back(digit);
	}
	return result.substr(0, n);
}

int main() {
	string file_name = "input.txt";
	ifstream fp(file_name);
	string line;
	long long total_joltage = 0;
	while (getline(fp, line)) {
		string joltage = max_n_digit(line, 12);
		total_joltage += stoll(joltage);
	}
	cout << total_joltage << endl;
	return 0;
}
