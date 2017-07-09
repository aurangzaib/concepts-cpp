/*
 int A::b(int c) { }    --> method b of class A with param c
 a->b                   --> a is a pointer to an instance, used to access method b
 class A: public B {};  --> A inherits B publicly
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template<class T>
class BadPixelInterpolator {
private:
    string inputPath, outputPath;
    vector<vector<T> > matrix;
    vector<T> neighbours;
public:
    BadPixelInterpolator() : inputPath("../csv.csv"), outputPath("../csv.csv") {}
    BadPixelInterpolator(const string &, const string &);
    vector<T> getNeighbours(size_t, size_t, const size_t, const size_t);
    const T getInterpolatedPixel();
    void debugNeighbours();
    void readCsv();
    void process();
    void saveFile();
};

template<class T>
BadPixelInterpolator<T>::BadPixelInterpolator(const string &i, const string &o) : inputPath(i), outputPath(o) {}
template<class T>
void BadPixelInterpolator<T>::process() {
    // read csv file
    readCsv();
    // find bad pixels, neighbours and interpolated pixel value
    const size_t n_rows = matrix.size();
    const size_t n_cols = matrix[0].size();
    for (size_t row = 0; row < n_rows; row++) {
        for (size_t col = 0; col < n_cols; col++) {
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
template<class T>
void BadPixelInterpolator<T>::readCsv() {
    ifstream input(inputPath);
    // read line
    for (string line; getline(input, line);) {
        vector<T> line_array;
        stringstream _str_(line);
        // read space separated characters
        for (string value; getline(_str_, value, ' ');) {
            line_array.push_back(stoi(value));
        }
        matrix.push_back(line_array);
    }
}
template<class T>
vector<T> BadPixelInterpolator<T>::getNeighbours(size_t row, size_t col, const size_t n_rows, const size_t n_cols) {
    vector<T> neighbours;
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
template<class T>
const T BadPixelInterpolator<T>::getInterpolatedPixel() {
    T _sum_ = 0;
    for (const auto &v : neighbours) _sum_ += v;
    return _sum_ / neighbours.size();
}
template<class T>
void BadPixelInterpolator<T>::saveFile() {
    ofstream _file_;
    _file_.open(outputPath);
    for (const auto &r : matrix) {
        for (const auto &c : r) _file_ << c << " ";
        _file_ << "\n";
    }
}
template<class T>
void BadPixelInterpolator<T>::debugNeighbours() {
    cout << "neighbours: ";
    for (const auto &n : neighbours) cout << n << " ";
    cout << endl;
}
int main() {
    string inputPath = "../task2.csv";
    string outputPath = "../task2-normalized.csv";
    BadPixelInterpolator<int> interpolator(inputPath, outputPath);
    interpolator.process();
    return 0;
}
