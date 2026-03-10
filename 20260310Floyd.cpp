//Floyd,多源汇最短路问题

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=210,INF=0x3f3f3f3f;
int g[N][N],n,m,k;

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }    
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)g[i][j]=0;
            else g[i][j]=INF;
        }
    }
    while(m--){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=min(w,g[a][b]);
    }
    floyd();
    while(k--){
        int i,j;
        scanf("%d%d",&i,&j);
        int t=g[i][j];
        if(t>INF/2) puts("impossible");
        else cout<<t<<endl;
    }
}