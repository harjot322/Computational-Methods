#include <iostream>
#include <cmath> // For mathematical functions

using namespace std;

// Function to be integrated
double f(double x) {
    // Example function: f(x) = x^2
    return x * x; // Change this function as needed
}

// Function to implement Simpson's 3/8 rule
double simpsons38Rule(double a, double b, int n) {
    if (n % 3 != 0) {
        cout << "Number of intervals (n) must be a multiple of 3." << endl;
        return 0; // Return 0 or handle error as necessary
    }

    double h = (b - a) / n; // Width of each interval
    double sum = f(a) + f(b); // Initial value with the endpoints

    // Apply Simpson's 3/8 rule
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h); // Terms at multiples of 3
        } else {
            sum += 3 * f(a + i * h); // Other terms
        }
    }

    sum *= (3 * h / 8); // Final result
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
    cout << "Enter the number of intervals (n, must be a multiple of 3): ";
    cin >> n;

    // Calculate the integral using Simpson's 3/8 rule
    double result = simpsons38Rule(a, b, n);
    if (n % 3 == 0) { // Ensure that n is a multiple of 3 before printing result
        cout << "The approximate value of the integral is: " << result << endl;
    }

    return 0;
}
