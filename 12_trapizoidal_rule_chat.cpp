#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    // Define the function to be integrated
    return x * x;
}

double trapezoidalRule(double a, double b, int n) {
    // Perform numerical integration using the Trapezoidal Rule
    double h = (b - a) / n;  // Step size
    double sum = 0.5 * (function(a) + function(b));  // Initialize sum

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += function(x);
    }

    return h * sum;
}

int main() {
    double a, b;  // Interval [a, b]
    int n;        // Number of subintervals

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the number of subintervals (n): ";
    cin >> n;

    // Perform numerical integration using the Trapezoidal Rule
    double result = trapezoidalRule(a, b, n);

    cout << "Numerical integration result: " << result << endl;

    return 0;
}
