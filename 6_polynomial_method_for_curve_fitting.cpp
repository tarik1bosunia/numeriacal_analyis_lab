#include <iostream>
#include <vector>
#include <cmath>

void polynomialCurveFit(const std::vector<double>& x, const std::vector<double>& y, int degree, std::vector<double>& coefficients) {
    int n = x.size();

    // Create the Vandermonde matrix
    std::vector<std::vector<double>> A(n, std::vector<double>(degree + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= degree; ++j) {
            A[i][j] = std::pow(x[i], j);
        }
    }

    // Create the right-hand side vector
    std::vector<double> b(y.begin(), y.end());

    // Solve the system of equations using least squares
    coefficients.resize(degree + 1);
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = 0.0;
        for (int j = 0; j < n; ++j) {
            coefficients[i] += A[j][i] * b[j];
        }
    }
}

double evaluatePolynomial(const std::vector<double>& coefficients, double x) {
    int degree = coefficients.size() - 1;
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

int main() {
    int n;  // Number of data points
    int degree;  // Degree of the polynomial

    std::cout << "Enter the number of data points: ";
    std::cin >> n;

    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;

    std::vector<double> x(n);
    std::vector<double> y(n);

    // Input the data points
    std::cout << "Enter the x-coordinates of the data points:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    std::cout << "Enter the y-coordinates of the data points:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> y[i];
    }

    std::vector<double> coefficients;

    // Perform polynomial curve fitting
    polynomialCurveFit(x, y, degree, coefficients);

    // Output the polynomial equation
    std::cout << "Polynomial Equation: ";
    for (int i = degree; i >= 0; --i) {
        std::cout << coefficients[i] << "x^" << i;
        if (i > 0) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;

    // Evaluate the fitted polynomial at a specific value
    double evalX;
    std::cout << "Enter the value of x to evaluate the fitted polynomial: ";
    std::cin >> evalX;

    double result = evaluatePolynomial(coefficients, evalX);
    std::cout << "Fitted Polynomial Value at x = " << evalX << ": " << result << std::endl;

    return 0;
}
