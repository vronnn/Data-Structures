#include <bits/stdc++.h>
using namespace std;

int main()
{
    set <long long unsigned> num;
    long long unsigned a, b, ans;
    while(scanf("%llu", &a) != EOF){
        num.insert(a);
        if(num.count(a)) b = a;
    }
    b %= 10001;
    ans = 7312;
    if(b < ans) printf("<\n");
    if(b == ans) printf("==\n");
    if(b > ans) printf(">\n");

    return 0;
}
