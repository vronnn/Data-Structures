#include <bits/stdc++.h>
using namespace std;
#define N 100200

vector<int> gr[N];

void Add_edge(int x, int y)
{
    gr[x].push_back(y);
    gr[y].push_back(x);
}

int shortest_cycle(int n)
{
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {

        vector<int> dist(n, (int)(1e9));

        vector<int> par(n, -1);

        dist[i] = 0;
        queue<int> q;

        q.push(i);

        while (!q.empty()) {

            int x = q.front();
            q.pop();

            for (int child : gr[x]) {

                if (dist[child] == (int)(1e9)) {

                    dist[child] = 1 + dist[x];

                    par[child] = x;

                    q.push(child);
                }

                else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }

    if (ans == INT_MAX)
        return -1;

    else
        return ans;
}

int main()
{
    int x,y,a,b;
    cin >> x;
    cin >> y;
    while(y--){
        cin >> a;
        cin >> b;
        Add_edge(a, b);
    }

    if(shortest_cycle(x) == -1)
        cout << "gamau gasuka gelay";
    else
        cout << shortest_cycle(x);

    return 0;
}
