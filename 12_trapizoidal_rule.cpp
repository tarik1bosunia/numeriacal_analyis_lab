#include<bits/stdc++.h>

using namespace std;

double delta_x(double a , double b, int n){
    return (b-a)/ n;
}

double fx(double x){
    return (1/x);
}

double trapizoidal_rule(){
    int a = 1;
    int b = 2;
    int n = 10;
    double dx = delta_x(a,b, n);

    // calculate the  values of x
    vector<double> x;
    for(int i = 0; i <= n; i++){
        x.push_back(a + i * dx);
    }

    // apply trapizoidal rule

    double result = 0;

    for(int i = 1; i < n; i++){
        
        result +=  fx(x[i]);

    }

    return dx * (result +(fx(x[0]) + fx(x[n])) / 2);

}


    
int main(){
 
    cout << trapizoidal_rule() << endl;
    
    return 0;
}

