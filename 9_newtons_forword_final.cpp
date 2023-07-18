#include <iostream>
#include <vector>

// Function to calculate the forward differences
void calculateForwardDifferences(const std::vector<double>& y, std::vector<double>& forwardDiff)
{
    int n = y.size();

    forwardDiff = y;

    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            forwardDiff[i] = forwardDiff[i] - forwardDiff[i - 1];
        }
    }
}

// Function to perform Newton's forward difference interpolation
// double newtonsForwardInterpolation(const std::vector<double>& x, const std::vector<double>& forwardDiff, double xValue)
// {
//     int n = x.size();

//     double result = forwardDiff[0];
//     double term = 1.0;

//     for (int i = 1; i < n; i++)
//     {
//         term *= (xValue - x[i - 1]) / (x[i] - x[i - 1]);
//         result += term * forwardDiff[i];
//     }

//     return result;
// }

// Function to perform Newton's forward difference interpolation
double newtonsForwardInterpolation(const std::vector<double>& x, const std::vector<double>& forwardDiff, double xValue)
{
    int n = x.size();

    double result = forwardDiff[0];
    double term = 1.0;
    double u = (xValue-x[0]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++)
    {
        term = term * i;
        result += u * forwardDiff[i] / term;
        u = u * (u-i);
    }

    return result;
}
int main()
{
    // Sample data points
    std::vector<double> x = {0, 1, 2, 3, 4};
    std::vector<double> y = {1, 3, 9, 27, 81};

    // Calculate forward differences
    std::vector<double> forwardDiff;
    calculateForwardDifferences(y, forwardDiff);

    // Perform interpolation at x = 2.5
    double xValue = 2.5;
    double interpolatedValue = newtonsForwardInterpolation(x, forwardDiff, xValue);

    // Output the interpolated value
    std::cout << "Interpolated value at x = " << xValue << ": " << interpolatedValue << std::endl;

    return 0;
}
