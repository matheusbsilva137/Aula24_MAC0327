#include<bits/stdc++.h>
using namespace std;
int f[1100005];

int fib(int n){
    if (f[n-1] != -1) return f[n-1];
    else{
        f[n-1] = (fib(n-2) + fib(n-1))%100000;
        return f[n-1];
    }
}

int main(){
    int t, a, b;
    vector<int> fibP;
    cin >> t;

    memset(f, -1, sizeof(f));
    f[0] = 0;
    f[1] = 1;
    for (int i = 1; i <= t; i++){
        cin >> a >> b;
        int s = a;

        cout << "Case " << i << ": ";
        for (int j = 0; s <= a+b; s++, j++) fibP.push_back(fib(s));

        if (fibP.size() > 100){
            nth_element(fibP.begin(), fibP.begin() + 100,fibP.end());
            sort(fibP.begin(), fibP.begin() + 100);
        }else sort(fibP.begin(), fibP.end());
        
        for (int j = 0; j < 100 && j < fibP.size(); j++) cout << fibP[j] << " ";
        cout << endl;

        fibP.clear();
    }
    return 0;
}