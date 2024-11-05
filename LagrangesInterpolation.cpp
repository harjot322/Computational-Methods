#include <iostream>
#include <vector>

double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double x_interp) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x_interp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;

    // Input number of data points
    std::cout << "Enter the number of data points: ";
    std::cin >> n;

    std::vector<double> x(n);
    std::vector<double> y(n);

    // Input data points
    std::cout << "Enter the data points (x and y values):" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i + 1 << " (x, y): ";
        std::cin >> x[i] >> y[i];
    }

    double x_interp;
    // Input interpolation point
    std::cout << "Enter the interpolation point: ";
    std::cin >> x_interp;

    // Calculate the interpolated value
    double interpolated_value = lagrangeInterpolation(x, y, x_interp);
    std::cout << "Interpolated value at x = " << x_interp << " is: " << interpolated_value << std::endl;

    return 0;
}
