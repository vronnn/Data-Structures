#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin >> n;
    vector <int> v,a;
    while(n--){
        cin >> t;
        if(t < 0){
            auto it = find(v.begin(), v.end(), -t);
            if(it != v.end()){
                v.erase(it);
                while (find(v.begin(), v.end(), -t) != v.end()){
                    auto it2 = find(v.begin(), v.end(), -t);
                    v.erase(it2);
                }
            }
            else{
                a.push_back(-t);
            }
        }
        else{
            auto it1 = find(v.begin(), v.end(), t);
            if(it1 != v.end()){
                v.push_back(t);
                a.push_back(t);
            }
            else v.push_back(t);
        }
    }
    cout << a.size() << "\n";
    for(auto it : a){
        cout << it << "\n";
    }
}
