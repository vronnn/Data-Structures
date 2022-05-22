#include <bits/stdc++.h>
using namespace std;

vector<int> ver[100000];
bool vis[100000];

int connecting(int node)
{
    vis[node] = 1;
    for(int child : ver[node]){
        if(vis[child] == 0)
            connecting(child);
    }
    return 1;
}

int main()
{
    int v, e, bridge = 0;
    int a, b;
    cin >> v >> e;
    while(e--){
        cin >> a >> b;
        if(a != b){
            ver[a].push_back(b);
            ver[b].push_back(a);
        }
    }
    for(int i = 1; i < v; i++){
        if(vis[i] == 0)
            bridge += connecting(i);
    }
    cout << bridge - 1;
    return 0;
}
