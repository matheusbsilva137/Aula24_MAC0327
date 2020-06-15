#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int dist[10005];
vector<pair<int, int>> adj[10005];
int a, b;

void dijkstra(int a){
    //executa o algoritmo de dijkstra partindo de a com custo 0
    memset(dist, INF, sizeof(dist));
    set<pair<int, int>> Q;

    dist[a] = 0;
    Q.insert(make_pair(0, a));

    while (!Q.empty()){
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        for (int i = 0; i < adj[u].size(); i++){
            pair<int, int> e = adj[u][i];
            int v = e.first, p = e.second;
            if (dist[u] + p < dist[v]){
                if (Q.find(make_pair(dist[v], v)) != Q.end()) Q.erase(make_pair(dist[v], v));
                dist[v] = dist[u] + p;
                Q.insert(make_pair(dist[v], v));
            }
        }
    }
}

int main(){
    int t, v, k, ai, bi, ci;
    cin >> t;

    while (t--){
        cin >> v >> k;
        for (int i = 0; i < k; i++){
            cin >> ai >> bi >> ci;
            adj[ai].push_back(make_pair(bi, ci));
        }

        cin >> a >> b;
        dijkstra(a);
        if (dist[b] == INF) cout << "NO" << endl;
        else cout << dist[b] << endl;
        for(int i = 0; i < v; i++) adj[i].clear();
    }
    return 0;
}