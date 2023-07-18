#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int
#define EPSILON 0.001

using namespace std;

double func(double x)
{
    return x*x*x + x - 1;
}


void secant(double x1, double x2, double E){
    if(func(x1) * func(x2) >= 0){
        cout << "Can't find a root in the given interval." << endl;
        return;
    }

    double n = 0, xm, x0, c;


    do{
        x0 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

                   // check if x0 is root of equation or not
            c = func(x1) * func(x0);
 
            // update the value of interval
            x1 = x2;
            x2 = x0;
 
            // update number of iteration
            n++;
 
            // if x0 is the root of equation then break the loop
            if (c == 0)
                break;
            xm = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

    }while (fabs(xm - x0 >= E));
       cout << "Root of the given equation=" << x0 << endl;
        cout << "No. of iterations = " << n << endl;

    
}

int main(){

    // initializing the values
    double x1 = 0, x2 = 1, E = 0.0001;
    secant(x1, x2, E);
    

    return 0;
}
