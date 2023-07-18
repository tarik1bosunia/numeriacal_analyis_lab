#include <bits/stdc++.h>
using namespace std;

#define e 1e-9

double f(double x)
{
    return x * x - 3;
}



double false_position_method(double a, double b){
        double x = (a * f(b) - b * f(a)) / (f(b) - f(a));

    if(abs(f(x) <= e)){
        return x;
    }else{
        return false_position_method(a, sqrt(x));
    }
}

int main()
{
    cout << false_position_method(1, 2) << endl;
    
    return 0;
}
