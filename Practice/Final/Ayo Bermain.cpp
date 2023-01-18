#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> p1,p2,p3,p4,s;
    map <int, string> ptag, found;
    map <string, int> pname;
    string name;
    int n;
    for(int i = 1; i <= 4; i++){
        cin >> name;
        ptag[i] = name;
        pname[name] = i;
    }
    cin >> n >> name;
    int seeker = pname[name];
    int p, pos;

    if(seeker == 1){
        while(n--){
            cin >> p >> pos;
            if(p == seeker)
                s.push(pos);
            else if(p == 2)
                p2.push(pos);
            else if(p == 3)
                p3.push(pos);
            else if(p == 4)
                p4.push(pos);
        }
        while(!s.empty()){
            int hide;
            int seek = s.front();
            s.pop();

            if(!p2.empty()){
                hide = p2.front();
                p2.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[2]], ptag[2]));
            }
            if(!p3.empty()){
                hide = p3.front();
                p3.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[3]], ptag[3]));
            }
            if(!p4.empty()){
                hide = p4.front();
                p4.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[4]], ptag[4]));
            }

        }
    }
    if(seeker == 2){
        while(n--){
            cin >> p >> pos;
            if(p == 1)
                p1.push(pos);
            else if(p == seeker)
                s.push(pos);
            else if(p == 3)
                p3.push(pos);
            else if(p == 4)
                p4.push(pos);
        }
        while(!s.empty()){
            int hide;
            int seek = s.front();
            s.pop();

            if(!p1.empty()){
                hide = p1.front();
                p1.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[1]], ptag[1]));
            }
            if(!p3.empty()){
                hide = p3.front();
                p3.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[3]], ptag[3]));
            }
            if(!p4.empty()){
                hide = p4.front();
                p4.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[4]], ptag[4]));
            }

        }
    }
    if(seeker == 3){
        while(n--){
            cin >> p >> pos;
            if(p == 1)
                p1.push(pos);
            else if(p == 2)
                p2.push(pos);
            else if(p == seeker)
                s.push(pos);
            else if(p == 4)
                p4.push(pos);
        }
        while(!s.empty()){
            int hide;
            int seek = s.front();
            s.pop();

            if(!p1.empty()){
                hide = p1.front();
                p1.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[1]], ptag[1]));
            }
            if(!p2.empty()){
                hide = p2.front();
                p2.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[2]], ptag[2]));
            }
            if(!p4.empty()){
                hide = p4.front();
                p4.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[4]], ptag[4]));
            }

        }
    }
    if(seeker == 4){
        while(n--){
            cin >> p >> pos;
            if(p == 1)
                p1.push(pos);
            else if(p == 2)
                p2.push(pos);
            else if(p == 3)
                p3.push(pos);
            else if(p == seeker)
                s.push(pos);
        }
        while(!s.empty()){
            int hide;
            int seek = s.front();
            s.pop();

            if(!p1.empty()){
                hide = p1.front();
                p1.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[1]], ptag[1]));
            }
            if(!p2.empty()){
                hide = p2.front();
                p2.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[2]], ptag[2]));
            }
            if(!p3.empty()){
                hide = p3.front();
                p3.pop();
                if(hide == seek)
                    found.insert(make_pair(pname[ptag[3]], ptag[3]));
            }

        }
    }
    if(!found.empty()){
        int i = 0;
        for(auto it = found.begin(); it != found.end(); ++it, ++i){
            if(i == found.size()-1 && i != 0)
                cout << "dan ";
            cout << it->second;
            if(i < found.size()-1)
                cout << ",";
            cout << " ";
        }
        cout << "ditangkap oleh " << name;
    }
    else
        cout << name << " jaga lagi";
}
