#include <iostream>
#include <cmath>

double f(double x) {
    return std::sin(x) - 0.5;
}

void secantMethod(double x0, double x1, double tolerance, int max_iterations) {
    double x2;
    int iteration = 0;

    while (iteration < max_iterations) {
        double f_x0 = f(x0);
        double f_x1 = f(x1);

        if (std::abs(f_x1 - f_x0) < 1e-10) {
            std::cerr << "Error: Division by zero in Secant method." << std::endl;
            return;
        }

        // Secant formula
        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

        if (std::abs(x2 - x1) < tolerance) {
            std::cout << "Root: " << x2 << std::endl;
            return;
        }

        x0 = x1;
        x1 = x2;
        iteration++;
    }

    // If max iterations are reached, print the approximation
    std::cout << "Root: " << x2 << std::endl;
}

int main() {
    double x0 = 0.0;
    double x1 = 1.0;
    double tolerance = 0.001;
    int max_iterations = 100;

    secantMethod(x0, x1, tolerance, max_iterations);

    return 0;
}
