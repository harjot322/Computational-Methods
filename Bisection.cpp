#include <iostream>
#include <cmath>

void bisection(double (*func)(double), double a, double b, double tolerance) {
    if (func(a) * func(b) >= 0) {
        std::cerr << "Error: f(a) and f(b) must have opposite signs." << std::endl;
        return; // No root exists in this interval
    }

    double mid = a;
    while ((b - a) / 2 > tolerance) {
        mid = (a + b) / 2;
        if (func(mid) == 0.0) {
            break; // We've found the root
        } else if (func(mid) * func(a) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }

    std::cout << "Root found at: " << mid << std::endl;
}

// Define the function f(x) = x^2-4
double func(double x) {
    return x*x - 4;
}

int main() {
    double a = 0, b = 5, tolerance = 0.001;
    bisection(func, a, b, tolerance);

    return 0;
}
