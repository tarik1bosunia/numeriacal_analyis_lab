#include <iostream>
#include <vector>

// Function to calculate the divided differences
std::vector<double> calculateDividedDifferences(const std::vector<double>& x, const std::vector<double>& y)
{
    int n = x.size();
    std::vector<double> dividedDiff(y.begin(), y.end());

    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            dividedDiff[i] = (dividedDiff[i] - dividedDiff[i - 1]) / (x[i] - x[i - j]);
        }
    }

    return dividedDiff;
}

// Function to perform Newton's divided difference interpolation
double newtonDividedDifferenceInterpolation(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& dividedDiff, double xValue)
{
    int n = x.size();
    double result = 0.0;
    double term = 1.0;

    for (int i = 0; i < n; i++)
    {
        result += dividedDiff[i] * term;
        term *= (xValue - x[i]);
    }

    return result;
}

int main()
{
    // Sample data points
    std::vector<double> x = {0, 1, 2, 3, 4};
    std::vector<double> y = {1, 3, 9, 27, 81};

    // Calculate the divided differences
    std::vector<double> dividedDiff = calculateDividedDifferences(x, y);

    // Interpolate at x = 2.5
    double xValue = 2.5;
    double interpolatedValue = newtonDividedDifferenceInterpolation(x, y, dividedDiff, xValue);

    // Output the interpolated value
    std::cout << "Interpolated value at x = " << xValue << ": " << interpolatedValue << std::endl;

    return 0;
}
