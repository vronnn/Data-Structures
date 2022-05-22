#include <cstdio>
using namespace std;

int main(){
    int t,n,m,ans,pos,print;
    int priority[100];
    bool printed[100];

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);

        for(int j = 0; j < n; j++){
            scanf("%d",&priority[j]);
            printed[j] = false;
        }
        pos = 0;
        ans = 0;

        while(!printed[m]){
            print=-1;
            ans++;

            for(int i=0;i<n;i++){
                if(!printed[(pos+i)%n] && (print == -1 || priority[(pos+i)%n] > priority[print]))
                    print = (pos+i)%n;
            }

            printed[print] = true;
            pos = print;
        }

        printf("%d\n",ans);
    }

    return 0;
}
