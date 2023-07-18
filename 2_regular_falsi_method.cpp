#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int
#define MAX_ITER 1000000

using namespace std;

double func(double x){
    return x*x*x - x*x + 2; //Output::The value of root is : -1
}

void regular_falsi(double a, double b){
    if(func(a) * func(b) >= 0){
        cout << "you have not assumed right a and b" << endl;
        return;
    }
    double c = a; // initialize result

    for(int i = 0; i < MAX_ITER; i++){
        c = (a * func(b) - b * func(a) ) / (func(b) - func(a));
        if (func(c) == 0) break;
        else if(func(c) * func(a) < 0)  b = c;
        else a = c;
    }
    cout << "The value of root is : " << c << endl;
}

int main(){

    double a =-200, b = 300;
    regular_falsi(a, b);

    
    return 0;
}

