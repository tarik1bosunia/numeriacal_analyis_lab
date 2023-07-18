#include <iostream>
#include <vector>

void gaussElimination(std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x) {
    int n = A.size();

    for (int k = 0; k < n; ++k) {
        // Find the pivot row
        int pivotRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (std::abs(A[i][k]) > std::abs(A[pivotRow][k])) {
                pivotRow = i;
            }
        }

        // Swap rows if necessary
        if (pivotRow != k) {
            std::swap(A[k], A[pivotRow]);
            std::swap(b[k], b[pivotRow]);
        }

        // Perform row operations to eliminate variables
        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main() {
    int n;  // Size of the system

    std::cout << "Enter the size of the system: ";
    std::cin >> n;

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<double> b(n);
    std::vector<double> x(n);

    // Input the matrix A and vector b
    std::cout << "Enter the coefficients of the matrix A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Enter the values of the vector b:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // Solve the system using Gauss elimination
    gaussElimination(A, b, x);

    // Output the solution
    std::cout << "Solution: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}
