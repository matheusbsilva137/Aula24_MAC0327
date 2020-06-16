#include<bits/stdc++.h>
using namespace std;
vector<int> p;
int c;
int l[200000]; //l[i] é o maior lucro possível entre os dias [i..n-1]

int maxLucro(int i, int n){
    //retorna o maior lucro possível usando a ação i em [i...n]
    if (p[n] - p[i] - c < 0) return 0;
    else return (p[n] - p[i] - c + l[n+1]);
}

int solve(int n){
    //devolve o lucro máximo entre os dias [0...n-1] (top-down)
    l[n] = 0;
    l[n-1] = 0;
    for (int j = n-2; j >= 0; j--){
        l[j] = 0;
        for (int k = n-1; k > j; k--) l[j] = max(l[j+1], max(l[j], maxLucro(j, k)));
    }
    return l[0];
}

int main(){
    int n, v;

    memset(l, -1, sizeof(l));
    while (cin >> n){
        cin >> c;
        for (int i = 0; i < n; i++) {
            cin >> v;
            p.push_back(v);
        }
        cout << solve(n) << endl;
        p.clear();
    }
    return 0;
}