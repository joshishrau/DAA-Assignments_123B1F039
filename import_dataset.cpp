#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string &line, char delimiter) {
    vector<string> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

int main() {
    string filename = "/home/nisl19/Desktop/123B1F039/dataset.csv";  // full path
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    string line;
    vector<vector<string>> records;

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        records.push_back(row);
    }

    file.close();

    cout << "CSV Records:\n";
    for (const auto &row : records) {
        for (const auto &col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }

    return 0;
}
