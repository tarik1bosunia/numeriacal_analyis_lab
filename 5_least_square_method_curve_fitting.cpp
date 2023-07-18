#include <iostream>
#include <vector>
#include <cmath>

void leastSquareFit(const std::vector<double>& x, const std::vector<double>& y, int degree, std::vector<double>& coefficients) {
    int n = x.size();

    // Build the Vandermonde matrix
    std::vector<std::vector<double>> A(degree + 1, std::vector<double>(degree + 1));
    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= degree; ++j) {
            double sum = 0.0;
            for (int k = 0; k < n; ++k) {
                sum += std::pow(x[k], i + j);
            }
            A[i][j] = sum;
        }
    }

    // Build the right-hand side vector
    std::vector<double> b(degree + 1);
    for (int i = 0; i <= degree; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            sum += y[j] * std::pow(x[j], i);
        }
        b[i] = sum;
    }

    // Solve the system of equations using Gauss-Jordan elimination
    for (int k = 0; k <= degree; ++k) {
        int pivotRow = k;
        for (int i = k + 1; i <= degree; ++i) {
            if (std::abs(A[i][k]) > std::abs(A[pivotRow][k])) {
                pivotRow = i;
            }
        }

        if (pivotRow != k) {
            std::swap(A[k], A[pivotRow]);
            std::swap(b[k], b[pivotRow]);
        }

        double pivot = A[k][k];
        for (int j = k; j <= degree; ++j) {
            A[k][j] /= pivot;
        }
        b[k] /= pivot;

        for (int i = 0; i <= degree; ++i) {
            if (i != k) {
                double factor = A[i][k];
                for (int j = k; j <= degree; ++j) {
                    A[i][j] -= factor * A[k][j];
                }
                b[i] -= factor * b[k];
            }
        }
    }

    // Extract the coefficients
    coefficients.resize(degree + 1);
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = b[i];
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

    // Perform curve fitting using the Least Square Method
    leastSquareFit(x, y, degree, coefficients);

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
