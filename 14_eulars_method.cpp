#include <iostream>
#include <vector>

// Function representing the ODE: dy/dx = f(x, y)
double f(double x, double y) {
    return x - y;
}

// Euler's method for solving ODE
void eulerMethod(double x0, double y0, double h, double xn) {
    std::vector<double> xVals;
    std::vector<double> yVals;

    double x = x0;
    double y = y0;

    xVals.push_back(x);
    yVals.push_back(y);

    while (x < xn) {
        y = y + h * f(x, y);
        x = x + h;

        xVals.push_back(x);
        yVals.push_back(y);
    }

    // Print the values
    std::cout << "Euler's Method Solution:" << std::endl;
    for (size_t i = 0; i < xVals.size(); ++i) {
        std::cout << "x = " << xVals[i] << ", y = " << yVals[i] << std::endl;
    }
}

int main() {
    double x0, y0;  // Initial conditions: x0, y0
    double h;       // Step size
    double xn;      // Upper limit of x

    std::cout << "Enter the initial condition x0: ";
    std::cin >> x0;

    std::cout << "Enter the initial condition y0: ";
    std::cin >> y0;

    std::cout << "Enter the step size h: ";
    std::cin >> h;

    std::cout << "Enter the upper limit of x (xn): ";
    std::cin >> xn;

    // Solve the ODE using Euler's method
    eulerMethod(x0, y0, h, xn);

    return 0;
}
