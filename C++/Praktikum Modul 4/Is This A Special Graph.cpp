#include <bits/stdc++.h>
using namespace std;

void dfs(vector <int> a[], int cur, int prev, bool vis[], bool &flag)
{
    if(vis[cur]){
        flag = true;
        return;
    }
    vis[cur] = 1;
    for(int i = 0; i < a[cur]. size(); i++){
        if(a[cur][i] == prev)
            continue;
        dfs(a, a[cur][i], cur, vis, flag);
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        int v,e,a,b, c = 0;
        cin >> v >> e;
        vector <int> g[v];
        while(e--){
            cin >> a >> b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        for(int i = 0; i < v; i++){
            if(g[i].size() > 2){
                c = 1;
            }
        }
        if(c == 0) cout << "Graf ini adalah linked list\n";
        else{
            bool cek = false;
            bool vis[1000];
            fill(vis, vis+900, 0);
            for(int i = 0; i < v; i++){
                if(!vis[i]){
                    dfs(g, i, i, vis, cek);
                }
            }
            if(cek)
                cout << "Graf ini adalah graf biasa\n";
            else
                cout << "Graf ini adalah tree\n";
        }
    }
    return 0;
}
