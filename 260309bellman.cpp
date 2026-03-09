/*
给定一个n个点 m条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出从 1号点到 n号点的最多经过 k条边的最短距离，如果无法从 1号点走到 n号点，输出 impossible。
注意：图中可能 存在负权回路 。

输入格式
第一行包含三个整数 n,m,k。
接下来 m行，每行包含三个整数 x,y,z，表示存在一条从点 x到点 y的有向边，边长为 z。
点的编号为 1∼n。
输出格式
输出一个整数，表示从 1号点到 n号点的最多经过 k条边的最短距离。
如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500,
1≤m≤10000,
1≤x,y≤n，
任意边长的绝对值不超过 10000。
输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/

//用结构体{a,b,w}存边
//迭代k次，每次更新


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=510,M=10010,INT=1e9;
int dist[N],backup[N];
int n,m,k;

struct Edge{
    int a,b,w;
}edge[M];

int bellman(){
    
    for(int i=1;i<=n;i++){
        dist[i]=INT;
    }
    dist[1]=0;
    for(int i=1;i<=k;i++){
        memcpy(backup,dist,sizeof dist);
        for(int j=1;j<=m;j++){
            int a=edge[j].a,b=edge[j].b,w=edge[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    return dist[n];
}


int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge[i]={a,b,w};
    }
    int ans=bellman();
    if(ans>=1e9/2) cout<<"impossible";
    else cout<<ans;
}
