#include <bits/stdc++.h>
using namespace std;

int main()
{
    list <int> x,y;
    array <int,2000> res;
    int n,m,p,digit;
    cin >> n >> m;
    if(n > m)
        digit = n;
    else
        digit = m;

    while(n--){
        cin >> p;
        x.push_back(p);
    }
    while(m--){
        cin >> p;
        y.push_back(p);
    }

    int a,b,sum = 0;
    int temp = 0;
    for(int i = 0; i < digit; i++){
        a = b = 0;
        if(!x.empty()){
            a = x.back();
            x.pop_back();
        }
        if(!y.empty()){
            b = y.back();
            y.pop_back();
        }

        sum = a + b + temp;
        temp = 0;
        if(sum > 9 && (i + 1 != digit)){
            temp = 1;
            sum -= 10;
        }

        res[i] = sum;
    }

    cout << "[";
    for(int i = digit - 1; i >= 0; i--){
        cout << res[i];
    }
    cout << "]";
    return 0;
}
