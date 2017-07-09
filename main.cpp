#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

template<class T>
class bad_pixel_interpolator {
private:
    // paths
    const std::string input_path, output_path;
    // martix and neighbours
    std::vector<std::vector<T>> matrix;
    std::vector<T> neighbours;
public:
    bad_pixel_interpolator() : input_path("../csv.csv"), output_path("../csv.csv") {}
    bad_pixel_interpolator(const std::string &, const std::string &);
    void get_neighbours(const size_t, const size_t, const size_t, const size_t);
    const T get_interpolated_pixel();
    void debug_neighbours();
    void read_csv();
    void process();
    void save_file();
};

template<class T>
bad_pixel_interpolator<T>::bad_pixel_interpolator(const std::string &i, const std::string &o) :
        input_path(i), output_path(o) {}
/**
 * process bad pixels
 */
template<class T>
void bad_pixel_interpolator<T>::process() {
    // read csv file
    read_csv();
    // find bad pixels, neighbours and interpolated pixel value
    const size_t n_rows = matrix.size();
    const size_t n_cols = matrix.at(0).size();
    for (size_t row = 0; row < n_rows; row++) {
        for (size_t col = 0; col < n_cols; col++) {
            // if pixel value is 0 i.e. bad pixel
            if (matrix.at(row).at(col) == 0) {
                // get neighbours
                get_neighbours(row, col, n_rows, n_cols);
                // get new interpolated value for bad pixel
                matrix.at(row).at(col) = get_interpolated_pixel();
                // see pixel value of neighbours
                debug_neighbours();
            }
        }
    }
    // save csv file
    save_file();
}
/**
 * read csv file
 */
template<class T>
void bad_pixel_interpolator<T>::read_csv() {
    std::ifstream input(input_path);
    // read line
    for (std::string line; getline(input, line);) {
        std::vector<T> line_array;
        std::stringstream _str_(line);
        // read space separated characters
        for (std::string value; getline(_str_, value, ' ');) {
            line_array.push_back(stoi(value));
        }
        matrix.push_back(line_array);
    }
}
/**
 * get vector of neighbour pixels
 * neighbour pixels are not always 4
 */
template<class T>
void bad_pixel_interpolator<T>::get_neighbours(const size_t row,
                                               const size_t col,
                                               const size_t n_rows,
                                               const size_t n_cols) {
    // reset neighbours
    neighbours = {};
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
}
/**
 * get average value of neighbour pixels
 */
template<class T>
const T bad_pixel_interpolator<T>::get_interpolated_pixel() {
    T _sum_ = 0;
    for (const auto &v : neighbours) _sum_ += v;
    return _sum_ / neighbours.size();
}
/**
 * save matrix to disk as csv
 */
template<class T>
void bad_pixel_interpolator<T>::save_file() {
    std::ofstream _file_;
    _file_.open(output_path);
    for (const auto &r : matrix) {
        for (const auto &c : r) _file_ << c << " ";
        _file_ << "\n";
    }
}
/**
 * debug neighbouring pixel values
 */
template<class T>
void bad_pixel_interpolator<T>::debug_neighbours() {
    std::cout << "neighbours: ";
    for (const auto &n : neighbours) std::cout << n << " ";
    std::cout << std::endl;
}
int main() {
    std::string input_path = "../task2.csv";
    std::string output_path = "../task2-normalized.csv";
    bad_pixel_interpolator<int> interpolator(input_path, output_path);
    interpolator.process();
    return 0;
}
