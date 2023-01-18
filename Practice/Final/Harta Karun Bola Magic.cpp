#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> s;
    int n,b,tag;
    cin >> n;
    while(n--){
        cin >> b;
        s.push_back(b);
        auto it = s.begin() + s.size() - 1;
        tag = 0;
        for(int i = 1; i < b; i++){
            if(i == s.size()){
                tag = 1;
                break;
            }
            if(*(it-i) != b){
                tag = 1;
                break;
            }
        }
        if(!tag){
            while(b--)
                s.pop_back();
        }
        cout << s.size() << "\n";
    }
    return 0;
}
