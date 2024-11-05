#include <iostream>
#include <cmath>

double f(double x) {
    return x * x - 2;
}

double f_derivative(double x) {
    return 2 * x;
}

void newtonRaphson(double initial_guess, double tolerance, int max_iterations) {
    double x = initial_guess;
    int iteration = 0;

    while (iteration < max_iterations) {
        double fx = f(x);
        double f_prime_x = f_derivative(x);

        if (std::abs(f_prime_x) < 1e-10) {
            std::cerr << "Error: Derivative is too close to zero, stopping iteration." << std::endl;
            return;
        }

        double x_next = x - fx / f_prime_x;

        std::cout << "Iteration " << iteration + 1 << ": x = " << x_next << std::endl;

        if (std::abs(x_next - x) < tolerance) {
            std::cout << "Root found at: " << x_next << " after " << iteration + 1 << " iterations." << std::endl;
            return;
        }

        x = x_next;
        iteration++;
    }

    std::cout << "Maximum iterations reached. Approximate root: " << x << std::endl;
}

int main() {
    double initial_guess = 1.0;
    double tolerance = 1e-6;
    int max_iterations = 100;

    newtonRaphson(initial_guess, tolerance, max_iterations);

    return 0;
}
