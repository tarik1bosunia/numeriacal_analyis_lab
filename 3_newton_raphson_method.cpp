#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int
#define EPSILON 0.001

using namespace std;

double func(double x)
{
    return x*x*x - x*x + 2;
}

double derivFunc(double x)
{
    return 3*x*x - 2*x;
}

void newtonRaphson(double x){
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x) / derivFunc(x);

         // x(i+1) = x(i) - f(x) / f'(x) 
        x = x - h;
    }
    cout << "The value of the root is : " << x << endl;
    
}

int main(){
    
    double x0 = -20; // Initial values assumed
    newtonRaphson(x0);
    
    
    return 0;
}
