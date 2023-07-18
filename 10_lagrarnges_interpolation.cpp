#include <iostream>
#include <vector>

// Function to calculate the Lagrange basis polynomial at a specific index
double lagrangeBasis(const std::vector<double>& x, int index, double xValue)
{
    int n = x.size();
    double result = 1.0;

    for (int i = 0; i < n; i++)
    {
        if (i != index)
        {
            result *= (xValue - x[i]) / (x[index] - x[i]);
        }
    }

    return result;
}

// Function to perform Lagrange's interpolation
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xValue)
{
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        double basis = lagrangeBasis(x, i, xValue);
        result += basis * y[i];
    }

    return result;
}

int main()
{
    // Sample data points
    std::vector<double> x = {0, 1, 2, 3, 4};
    std::vector<double> y = {1, 3, 9, 27, 81};

    // Interpolate at x = 2.5
    double xValue = 2.5;
    double interpolatedValue = lagrangeInterpolation(x, y, xValue);

    // Output the interpolated value
    std::cout << "Interpolated value at x = " << xValue << ": " << interpolatedValue << std::endl;

    return 0;
}
