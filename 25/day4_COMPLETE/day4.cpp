#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> string_to_matrix(const vector<string>& pattern) {
	vector<vector<int>> matrix;
	for (const auto& line : pattern) {
		vector<int> row;
		for (char c : line) {
			row.push_back(c == '@' ? 1 : 0);
		}
		matrix.push_back(row);
	}
	return matrix;
}

bool check_surrounding(const vector<vector<int>>& matrix, size_t row, size_t col) {
	int count = 0;
	int cols = static_cast<int>(matrix[0].size());
	int rows = static_cast<int>(matrix.size());
	for (int offset_row = -1; offset_row <= 1; ++offset_row) {
		for (int offset_col = -1; offset_col <= 1; ++offset_col) {
			int nrow = static_cast<int>(row) + offset_row;
			int ncol = static_cast<int>(col) + offset_col;

			if (offset_row == 0 && offset_col == 0)
				continue;
			if (ncol < 0 || nrow < 0)
				continue;
			else if (ncol >= cols || nrow >= rows)
				continue;

			if (matrix[nrow][ncol] == 1)
				count++;
		}
	}
	return count < 4;
}



int main() {
	string file_name = "input.txt";
	string line;
	ifstream fp(file_name);
	vector<string> input;
	while (getline(fp, line)) {
		input.push_back(line);
	}
	vector<vector<int>> matrix = string_to_matrix(input);

	vector<vector<int>> tmp_m;
	int rolls = 0;
	while (tmp_m != matrix) {
		tmp_m = matrix;
		for (size_t i = 0; i < matrix.size(); ++i) {
			for (size_t j = 0; j < matrix[i].size(); ++j) {
				if (matrix[i][j] == 1 && check_surrounding(matrix, i, j)) {
					matrix[i][j] = 0;
					++rolls;
				}
			}
		}
	}

	cout << rolls << endl;
	return 0;
}
