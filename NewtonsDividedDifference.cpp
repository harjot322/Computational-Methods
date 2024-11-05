#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the divided difference coefficients
void dividedDifference(const vector<double>& x, const vector<double>& y, vector<vector<double>>& coeff) {
    int n = x.size();
    for (int i = 0; i < n; i++)
        coeff[i][0] = y[i]; // First column is y values

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            coeff[i][j] = (coeff[i + 1][j - 1] - coeff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to evaluate the interpolated value using Newton's divided difference formula
double newtonInterpolation(const vector<double>& x, const vector<vector<double>>& coeff, double value) {
    double result = coeff[0][0]; // Starting with the first term
    double term = 1.0; // This will store the product of (value - x[i]) terms

    for (int i = 1; i < x.size(); i++) {
        term *= (value - x[i - 1]);
        result += coeff[0][i] * term; // Add the next term
    }

    return result;
}

int main() {
    int n;

    // Input number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);
    vector<vector<double>> coeff(n, vector<double>(n));

    // Input data points
    cout << "Enter the data points (x and y values):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i + 1 << " (x, y): ";
        cin >> x[i] >> y[i];
    }

    double x_interp;
    // Input interpolation point
    cout << "Enter the interpolation point: ";
    cin >> x_interp;

    // Calculate divided differences
    dividedDifference(x, y, coeff);

    // Calculate the interpolated value
    double interpolated_value = newtonInterpolation(x, coeff, x_interp);
    cout << "Interpolated value at x = " << x_interp << " is: " << interpolated_value << endl;

    return 0;
}
