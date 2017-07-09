#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BadPixelInterpolator {
private:
    string inputPath, outputPath;
    vector<vector<int> > matrix;
    vector<int> neighbours;
public:
    BadPixelInterpolator() : inputPath("../csv.csv"), outputPath("../csv.csv") {}
    BadPixelInterpolator(const string &, const string &);
    vector<int> getNeighbours(int, int, const size_t, const size_t);
    const int getInterpolatedPixel();
    void debugNeighbours();
    void readCsv();
    void process();
    void saveFile();
};

BadPixelInterpolator::BadPixelInterpolator(const string &i, const string &o) : inputPath(i), outputPath(o) {}
void BadPixelInterpolator::process() {
    // read csv file
    readCsv();
    // find bad pixels, neighbours and interpolated pixel value
    const size_t n_rows = matrix.size();
    const size_t n_cols = matrix[0].size();
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            if (matrix.at(row).at(col) == 0) {
                neighbours = getNeighbours(row, col, n_rows, n_cols);
                debugNeighbours();
                matrix[row][col] = getInterpolatedPixel();
            }
        }
    }
    // save csv file
    saveFile();
}
void BadPixelInterpolator::readCsv() {
    ifstream input(inputPath);
    // matrix for csv
    unsigned int col = 0;
    // read line
    for (string line; getline(input, line); col++) {
        vector<int> line_array;
        stringstream _str_(line);
        // read space separated characters
        for (string value; getline(_str_, value, ' ');) {
            line_array.push_back(stoi(value));
        }
        matrix.push_back(line_array);
    }
}
vector<int> BadPixelInterpolator::getNeighbours(int row, int col, const size_t n_rows, const size_t n_cols) {
    vector<int> neighbours;
    // top neighbour
    if ((row - 1) < n_rows && (row - 1) > 0)
        neighbours.push_back(matrix[row - 1][col]);
    // bottom neighbour
    if ((row + 1) < n_rows && (row + 1) > 0)
        neighbours.push_back(matrix[row + 1][col]);
    // left neighbour
    if (row < n_rows && (col - 1) < n_cols && (col - 1) > 0)
        neighbours.push_back(matrix[row][col - 1]);
    // right neighbour
    if (row < n_rows && (col + 1) < n_cols && (col + 1) > 0)
        neighbours.push_back(matrix[row][col + 1]);
    return neighbours;
}
const int BadPixelInterpolator::getInterpolatedPixel() {
    int _sum_ = 0;
    for (const auto &v : neighbours) _sum_ += v;
    return _sum_ / neighbours.size();
}
void BadPixelInterpolator::saveFile() {
    ofstream _file_;
    _file_.open(outputPath);
    for (const auto &r : matrix) {
        for (const auto &c : r) _file_ << c << " ";
        _file_ << "\n";
    }
}
void BadPixelInterpolator::debugNeighbours() {
    cout << "neighbours: ";
    for (const auto &n : neighbours) cout << n << " ";
    cout << endl;
}
int main() {
    string inputPath = "../task2.csv";
    string outputPath = "../task2-normalized.csv";
    BadPixelInterpolator interpolator(inputPath, outputPath);
    interpolator.process();
    return 0;
}
