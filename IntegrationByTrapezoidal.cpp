#include <iostream>
#include <cmath> // For mathematical functions

using namespace std;

// Function to be integrated
double f(double x) {
    // Example function: f(x) = x^2
    return x * x; // Change this function as needed
}

// Function to implement the trapezoidal rule
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; // Width of each trapezoid
    double sum = 0.5 * (f(a) + f(b)); // Initial value with the endpoints

    // Summing the values of f(x) at each segment
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    sum *= h; // Final result
    return sum;
}

int main() {
    double a, b; // Limits of integration
    int n; // Number of trapezoids

    // Input the limits and number of trapezoids
    cout << "Enter the lower limit of integration (a): ";
    cin >> a;
    cout << "Enter the upper limit of integration (b): ";
    cin >> b;
    cout << "Enter the number of trapezoids (n): ";
    cin >> n;

    // Calculate the integral using the trapezoidal rule
    double result = trapezoidalRule(a, b, n);
    cout << "The approximate value of the integral is: " << result << endl;

    return 0;
}
