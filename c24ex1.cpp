#include<bits/stdc++.h>
using namespace std;
int p[200020];
int c;
int l[200020][2]; //l[i][0] é o maior lucro possível entre os dias [i..n-1] tendo uma ação e l[i][1] é o lucro máximo não tendo uma ação

int solve(int n){
    //devolve o lucro máximo entre os dias [0...n-1] (top-down)
    l[n-1][0] = 0;
    l[n-1][1] = p[n-1];
    for (int j = n-2; j >= 0; j--){
        l[j][0] = max(0, max(l[j+1][0], l[j+1][1] - c - p[j]));
        l[j][1] = max(0, max(l[j+1][1], l[j+1][0] + p[j]));
    }
    return l[0][0];
}

int main(){
    int n, v;
    
    while (scanf("%d %d", &n, &c) != EOF){
        int i;
        for (i = 0; i < n; i++) scanf("%d", &(p[i]));
        printf("%lld\n", solve(n));
    }
    return 0;
}