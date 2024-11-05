#include <iostream>
#include <cmath> // For mathematical functions

using namespace std;

// Function to be integrated
double f(double x) {
    // Example function: f(x) = x^2
    return x * x; // Change this function as needed
}

// Function to implement Simpson's 1/3 rule
double simpsonsRule(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Number of intervals (n) must be even." << endl;
        return 0; // Return 0 or handle error as necessary
    }

    double h = (b - a) / n; // Width of each interval
    double sum = f(a) + f(b); // Initial value with the endpoints

    // Apply Simpson's 1/3 rule
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h); // Even indexed terms
        } else {
            sum += 4 * f(a + i * h); // Odd indexed terms
        }
    }

    sum *= (h / 3); // Final result
    return sum;
}

int main() {
    double a, b; // Limits of integration
    int n; // Number of intervals

    // Input the limits and number of intervals
    cout << "Enter the lower limit of integration (a): ";
    cin >> a;
    cout << "Enter the upper limit of integration (b): ";
    cin >> b;
    cout << "Enter the number of intervals (n, must be even): ";
    cin >> n;

    // Calculate the integral using Simpson's 1/3 rule
    double result = simpsonsRule(a, b, n);
    if (n % 2 == 0) { // Ensure that n is even before printing result
        cout << "The approximate value of the integral is: " << result << endl;
    }

    return 0;
}
