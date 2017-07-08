#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

// declarations
void task2(string, string);

vector<vector<int> > readCsv(const string);

vector<int> getNeighbours(vector<vector<int> >, size_t, size_t,
                          const size_t, const size_t);

int getInterpolatedPixel(vector<int>);

void saveFile(vector<vector<int> >, string);

void debugNeighbours(vector<int>);

// implementations
void task2(string input_path, string output_path) {
    // read csv file
    vector<vector<int> > _matrix_ = readCsv(input_path);

    const size_t n_rows = _matrix_.size();
    const size_t n_cols = _matrix_.at(0).size();

    for (size_t row = 0; row < n_rows; row++) {
        for (size_t col = 0; col < n_cols; col++) {
            if (_matrix_.at(row).at(col) == 0) {
                vector<int> neighbours =
                        getNeighbours(_matrix_, row, col, n_rows, n_cols);
                debugNeighbours(neighbours);
                _matrix_.at(row).at(col) = getInterpolatedPixel(neighbours);
            }
        }
    }
    saveFile(_matrix_, output_path);
}

vector<vector<int> > readCsv(const string file_name) {
    ifstream input(file_name);
    // matrix for csv
    vector<vector<int> > _matrix_;
    unsigned int col = 0;
    // read line
    for (string line; getline(input, line); col++) {
        vector<int> line_array;
        stringstream _str_(line);
        // read space seperated characters
        for (string value; getline(_str_, value, ' ');) {
            line_array.push_back(stoi(value));
        }
        _matrix_.push_back(line_array);
    }
    return _matrix_;
}

vector<int> getNeighbours(vector<vector<int> > csv_matrix,
                          size_t row, size_t col,
                          const size_t n_rows, const size_t n_cols) {
    vector<int> neighbours;
    // top neighbour
    if ((row - 1) < n_rows && (row - 1) > 0)
        neighbours.push_back(csv_matrix[row - 1][col]);
    // bottom neighbour
    if ((row + 1) < n_rows && (row + 1) > 0)
        neighbours.push_back(csv_matrix[row + 1][col]);
    // left neighbour
    if (row < n_rows && (col - 1) < n_cols && (col - 1) > 0)
        neighbours.push_back(csv_matrix[row][col - 1]);
    // right neighbour
    if (row < n_rows && (col + 1) < n_cols && (col + 1) > 0)
        neighbours.push_back(csv_matrix[row][col + 1]);

    return neighbours;
}

int getInterpolatedPixel(vector<int> neighbours) {
    int _sum_ = 0;
    for (const auto &v : neighbours) _sum_ += v;
    return _sum_ / neighbours.size();
}

inline void saveFile(vector<vector<int> > csv_matrix, string output_path) {
    ofstream _file_;
    _file_.open(output_path);
    for (const auto &r : csv_matrix) {
        for (const auto &c : r) _file_ << c << " ";
        _file_ << "\n";
    }
}

inline void debugNeighbours(vector<int> neighbours) {
    cout << "neighbours: ";
    for (const auto &n : neighbours) cout << n << " ";
    cout << endl;
}

//int main() {
//    task2("../task2.csv", "../task2-normalized.csv");
//    return 0;
//}

template<typename T>
T Max(T const &a, T const &b) {
    return a > b ? a : b;
}

int Max(int a, int b) {
    return a < b ? b : a;
}

template<class T>
class aClass {

private :
    T _member_;
public:
    aClass(T a) : _member_(a) {}

    ~aClass() {
        cout << "dtor called" << endl;
    }

    void print();

    void increment(T value) {
        _member_ = _member_ + value;
    }

    void decrement(T value) {
        _member_ = _member_ - value;
    }

    T operator+(T value) {
        _member_ += value;
        return _member_;
    }

    T operator-(T value);
};

template<class T>
void aClass<T>::print() {
    cout << "member value: " << _member_ << endl;
}

template<class T>
T aClass<T>::operator-(T value) {
    _member_ -= value;
    return _member_;
}

void a_func(int a[]) {
    cout << a[1];
}


int main() {
    aClass<float> anInstance(23);
    anInstance.increment(1.4);
    anInstance.decrement(1.4);
    anInstance.print();
    cout << "+ operator: " << anInstance + 1 << endl;
    cout << "- operator: " << anInstance - 1 << endl;
    cout << (uint64_t) (int64_t) -1 << endl;
}
