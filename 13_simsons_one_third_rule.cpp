#include<bits/stdc++.h>

using namespace std;

double delta_x(double a , double b, int n){
    return (b-a)/ n;
}

double fx(double x){
    return (1/x);
}

double simsons_one_third(){
    int a = 1;
    int b = 2;
    int n = 10;
    double dx = delta_x(a,b, n);

    // calculate the  values of x
    vector<double> x;
    for(int i = 0; i <= n; i++){
        x.push_back(a + i * dx);
    }

    // apply simsomes one third

    double result = fx(x[0]) + fx(x[n]);

    for(int i = 1; i < n; i++){
        if(i % 2){
            result += (4 * fx(x[i]));
        }else{
            result += (2 * fx(x[i]));
        }
    }

    return dx * result / 3.0;

}


    
int main(){
 
    cout << simsons_one_third() << endl;
    
    return 0;
}

