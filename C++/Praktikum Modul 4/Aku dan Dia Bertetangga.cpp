#include <bits/stdc++.h>
using namespace std;

int encrypt(string a, vector <string> b)
{
    int i
    for(i = 0; i < b.size(); i++){
        if(a == b[i])
            return i;
    }
    return i;
}

string decrypt(int a, vector <string> b)
{
    return b[a];
}

void print(vector<pair <int, int>> a[], int b, vector <string> c)
{
    if(a[b].size() > 0){
        for(int i = 0; i < a[b].size(); i++){
            string t = decrypt(a[b][i].first, c);
            cout << "(" << t << ", " << a[b][i].second << ") ";
        }
    }
    else cout << "TIDAK TERSEDIA\n";
}

int main()
{
    vector <string> s;
    string tmp;
    int n;
    cin >> n;
    vector <pair<int, int>> v[n];
    for(int i = 0; i < n; i++){
        cin >> tmp;
        s.push_back(tmp);
    }
    int x,y,e,w;
    for(x = 0; x < n; x++){
        cin >> e;
        while(e--){
            cin >> tmp;
            y = encrypt(tmp, s);
            cin >> w;
            v[x].push_back(make_pair(y,w));
        }
    }
    cin >> tmp;
    int t = encrypt(tmp, s);
    if(t <= n)
        print(v, t, s);
    else
        cout << "TIDAK TERSEDIA\n";
    return 0;
}
