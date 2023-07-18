#include <iostream>
#include <vector>
#include <cmath>

// Structure to represent a 2D point
struct Point {
    double x;
    double y;
};

// Function to calculate the best-fit line using the Least Squares Method
void leastSquaresMethod(const std::vector<Point>& points, double& slope, double& intercept) {
    double sumX = 0.0;
    double sumY = 0.0;
    double sumXY = 0.0;
    double sumXX = 0.0;

    for (const Point& p : points) {
        sumX += p.x;
        sumY += p.y;
        sumXY += p.x * p.y;
        sumXX += p.x * p.x;
    }

    double n = static_cast<double>(points.size());

    double denominator = (n * sumXX) - (sumX * sumX);
    if (std::abs(denominator) < 1e-10) {
        // Handle the case when the denominator is close to zero to avoid division by zero
        slope = 0.0;
        intercept = 0.0;
        return;
    }

    slope = ((n * sumXY) - (sumX * sumY)) / denominator;
    intercept = (sumY - (slope * sumX)) / n;
}

int main() {
    std::vector<Point> dataPoints = { {1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {5.0, 6.0} };

    double slope, intercept;
    leastSquaresMethod(dataPoints, slope, intercept);

    std::cout << "Best-fit line equation: y = " << slope << "x + " << intercept << std::endl;

    return 0;
}
