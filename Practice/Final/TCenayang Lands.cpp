#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y,tag = 1;
    vector <pair<int,int> > v;
    vector <double> tri;
    pair<int,int> p;
    cin >> n;
    while(n--){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    double temp;
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            for(int k = i + 2; k < v.size(); k++){
                temp = abs(0.5*((v[i].first - v[k].first)*(v[j].second - v[i].second) - (v[i].first - v[j].first)*(v[k].second - v[i].second)));
                tri.push_back(temp);
            }
        }
    }

    double minim = numeric_limits<double>::max();
    for(int i = 0; i < tri.size(); i++){
        if(tri[v.size()] != 0) tag = 0;
        if(tri[i] < minim && tri[i] != 0)
            minim = tri[i];
    }
    if(tag)
        cout << "-1.00";
    else
        printf("%.2f", minim);

    return 0;
}
