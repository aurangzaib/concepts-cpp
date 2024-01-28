#include <iostream>

using namespace std;
#include <xtensor/xarray.hpp>

int main() {
    xt::xarray<double>::shape_type shape = {2, 3};
    xt::xarray<double> a0(shape);
    xt::xarray<double> a1(shape, 2.5);
    xt::xarray<double> a2 = {{1., 2., 3.}, {4., 5., 6.}};
    auto a3 = xt::xarray<double>::from_shape(shape);
    int d = 0;
}