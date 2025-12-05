#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

pair<long long, long long> splitRange(const string& range) {
    size_t dashPos = range.find('-');

    long long start = stoll(range.substr(0, dashPos));
  	long long end = stoll(range.substr(dashPos + 1));

    return make_pair(start, end);
}

bool is_in_range(long long id, const vector<pair<long long, long long>>& ranges) {
    for (const auto& range : ranges) {
        if (id >= range.first && id <= range.second) {
            return true;
        }
    }
    return false;
}

void print128(__int128 x) {
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    if (x > 9) print128(x / 10);
    cout << (int)(x % 10);
}


int main() {
	string file_name = "input.txt";
	ifstream fp(file_name);
	string line;
	vector<long long> ids;

	// Part 1
	/*while (getline(fp, line)) {
		if (line.empty()) continue;
		auto range = find(line.begin(), line.end(), '-');
		if (range != line.end()) {
			ranges_id.push_back(splitRange(line));
		} else {
			ids.push_back(stoll(line));
		}
	}

	int n_fresh = 0;
	for (long long id : ids) {
		if (is_in_range(id, ranges_id))
			++n_fresh;
	}

	cout << n_fresh << endl;*/
	// Part 2
	vector<pair<long long, long long>> ranges_id;

	while (getline(fp, line)) {
		if (line.empty()) break;
		auto range = find(line.begin(), line.end(), '-');
		if (range != line.end()) {
			ranges_id.push_back(splitRange(line));
		}
	}
	sort(ranges_id.begin(), ranges_id.end());
	vector<pair<long long, long long>> merged;
	for (auto& range: ranges_id) {
		if (merged.empty() || range.first > merged.back().second + 1)
			merged.push_back(range);
		else
			merged.back().second = max(merged.back().second, range.second);
	}

	__int128 n_fresh2 = 0;
	for (auto& pair : merged)
		n_fresh2 += ((__int128)pair.second - pair.first + 1);
	print128(n_fresh2);
	cout << endl;
	return 0;
}
