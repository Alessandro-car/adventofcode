#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start)); // Add the last token

    return tokens;
}

bool invalid_id(string number) {
	int len = number.length();
	for (int i = 2; i <= len; ++i) {
		if (len % i == 0) {
			int part_size = number.length() / i;
			vector<string> parts;
			for (int j = 0; j < i; j++) {
				parts.push_back(number.substr(part_size * j, part_size));
			}

			if (!parts.empty() && std::all_of(parts.begin(), parts.end(), [&](const string& s) { return s == parts[0]; })) {
				return true;
			}
		}
	}
	return false;
}

vector<long long> invalid_range(const string& range) {
	string inf = split(range, "-")[0];
	string sup = split(range, "-")[1];
	vector<long long> invalid_ranges;
	for (long long i = stoll(inf); i <= stoll(sup); i++) {
		string number = to_string(i);
		if (invalid_id(number)) {
			invalid_ranges.push_back(i);
		}
	}
	return invalid_ranges;
}

int main() {
	string file_name = "input.txt";
	ifstream fp(file_name);
	string line;
	getline(fp, line);
	vector<string> ranges = split(line, ",");
	long long sum = 0;
	for (const auto& el : ranges) {
		vector<long long> invalid_ids = invalid_range(el);
		for (const auto& id : invalid_ids) {
			sum += id;
		}
	}

	cout << sum << endl;

	return 0;
}



