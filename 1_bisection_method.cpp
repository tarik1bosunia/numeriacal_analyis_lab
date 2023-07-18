#include <bits/stdc++.h>
using namespace std;

const double LIMIT  = 0.0000001;

double f(double x)
{
    return x*x*x - x*x + 2; // -1  interval(-200, 300)
    // return x * x - 3; // 1.73205 interval (1, 2)
}
/* ============== Recursive =============== */

// double bisection_root_of_polynomial(double a, double b)
// {
//     double t = (a + b) / 2.0;

//     // assume less than limit mean it is zero
//     if (abs(f(t))<= LIMIT) return t;

//     if (f(a) * f(t) < 0)
//     {
//         return bisection_root_of_polynomial(t, a);
//     }
//     else if (f(b) * f(t) < 0)
//     {
//         return bisection_root_of_polynomial(t, b);
//     }
//     return 0;
// }

/* ============== Iterative =============== */
void bisection_root_of_polynomial(double a , double b){

    if(f(a) * f(b) >= 0){
        cout << "You have not assumed right a & b." <<endl;
        return ;
    }

    double c = a;

    while (b-a >= LIMIT)
    {
        c = (a + b) / 2;

        if(f(c) == 0.0) 
            break;
        else if
            (f(c) * f(a) < 0) b = c;
        else 
            a = c;

    }
    cout << "The value of root is : " << c  << endl;

}


int main()
{
    double a =-200, b = 300;
    bisection_root_of_polynomial(a, b);
    return 0;
}
