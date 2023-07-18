#include <iostream>

double function(double x) {
    // Define the function to be integrated
    return x * x;
}

double simpsonsRule(double a, double b, int n) {
    // Perform numerical integration using Simpson's 1/3 Rule
    double h = (b - a) / n;  // Step size
    double sum = function(a) + function(b);  // Initialize sum

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2 * function(x) : 4 * function(x);
    }

    return (h / 3.0) * sum;
}

int main() {
    double a, b;  // Interval [a, b]
    int n;        // Number of subintervals

    std::cout << "Enter the interval [a, b]: ";
    std::cin >> a >> b;

    std::cout << "Enter the number of subintervals (n): ";
    std::cin >> n;

    // Perform numerical integration using Simpson's 1/3 Rule
    double result = simpsonsRule(a, b, n);

    std::cout << "Numerical integration result: " << result << std::endl;

    return 0;
}
