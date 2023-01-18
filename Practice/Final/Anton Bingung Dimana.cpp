#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <string> v;
    v.push_back("home");
    v.push_back("anton");
    string s;
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "goto"){
            cin >> s;
            v.push_back(s);
        }
        else if(s == "goback"){
            if(v.size() == 0)
                cout << "cannot go back\n";
            else
                v.pop_back();
        }
        else if(s == "whereami"){
            if(v.size() == 0)
                cout << "i am nowhere\n";
            else{
                cout << v[0];
                for(int i = 1; i < v.size(); i++){
                    cout << "/" << v[i];
                }
                cout << "\n";
            }
        }
        else{
            cout << "Query not found\n";
        }
    }
    return 0;
}
