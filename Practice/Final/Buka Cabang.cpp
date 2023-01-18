#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e,x,y,w;
    cin >> v >> e;
    int cab[v+1];
    while (e--){
        cin >> x >> y >> w;
        if(x == 0)
            cab[y] = w;
        else{
            cab[y] = w;
            cab[y] += cab[x];
        }
    }
    for (int i = 1; i < v; i++)
        cout << i << " " << cab[i] << "\n";

    return 0;
}
