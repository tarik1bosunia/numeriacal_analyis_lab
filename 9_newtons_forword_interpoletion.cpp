#include<bits/stdc++.h>


using namespace std;

double dfx(int d, ){
    
    
}
    
int main(){
    freopen("input_newtons_forword.txt", "r", stdin);
    
    
    int n, a, b, target;
    vector<pair<int, int>> year_population;

    cin >> n >> target;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        year_population.push_back({a, b});
    }

    int base = year_population[0].first;
    int h = year_population[1].first - year_population[0].first;
    int u = (target  - a) / h;



    

    
    return 0;
}

