#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static constexpr int START_DIAL = 50;

int main() {
	string file_name = "input.txt";
	string line;
	ifstream fp(file_name);
	int dial = START_DIAL;
	int password1 = 0;
	int password2 = 0;
	while (getline(fp, line)) {
		int value = stoi(line.substr(1, line.length()));
		value = (line[0] == 'L') ? -value : value;
		int raw = dial + value;

		password2 += abs(raw) / 100;
		if (dial != 0 && raw <= 0) {
			password2 += 1;
		}

		dial = (dial + value) % 100;
		if (dial < 0)
			dial += 100;
		cout << dial << endl;
		if (dial == 0)
			++password1;
	}
	cout << password1 << endl;
	cout << password2 << endl;
	return 0;
}

