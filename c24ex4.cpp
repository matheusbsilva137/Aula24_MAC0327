#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
vector<int> adj[MAX];
vector<int> ans;
bool mrk[MAX];
int sum[MAX];
int temp[MAX];
int r;

int dfs(int u, int part){
    sum[u] = temp[u];
    for (int i = 0; i < adj[u].size(); i++) 
        sum[u] += dfs(adj[u][i], part);
    if (sum[u] == part && u != r){
        ans.push_back(u);
        return 0; //caso especial, usado quando uma partição encontrada é filha de outra partião válida
    }
    return sum[u];
}

int main(){
    int n, a, t, st = 0;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++){
        scanf("%d %d", &a, &t);
        st += t;
        if (a == 0) r = i;
        else adj[a].push_back(i);

        temp[i] = t;
    }

    if (st%3 != 0) printf("-1\n");
    else{
        dfs(r, st/3);
        if (ans.size() < 2) printf("-1\n");
        else{
            for (int i = 0; i < 2; i++) printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}