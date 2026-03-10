/*
给定一个 n个点 m条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出 1号点到 n号点的最短距离，如果无法从 1号点走到 n号点，则输出 impossible。
数据保证不存在负权回路。
输入格式
第一行包含整数 n和 m。
接下来 m行每行包含三个整数 x,y,z，表示存在一条从点 x到点 y的有向边，边长为 z。

输出格式
输出一个整数，表示 1号点到 n号点的最短距离。
如果路径不存在，则输出 impossible。
数据范围
1≤n,m≤105,图中涉及边长绝对值均不超过 10000。
输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2
*/

//spfa bellman优化版
//bellman


#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N=120;
int dist[N];
int n,m,INF=0x3f3f3f3f;

struct Edges{
    int a;
    int b;
    int w;
}edges[N];

int spfa(){
    memset(dist,0x3f,sizeof dist);
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int t=Q.front();
        Q.pop();
        for(int i=1;i<=m;i++){
            int a=edges[i].a,b=edges[i].b,w=edges[i].w;
            if(a==t&&dist[b]>dist[a]+w) {
                dist[b]=dist[a]+w;
                Q.push(b);
            }
        }
    }
    return dist[n];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }
    int t=spfa();
    if(t==INF) puts("impossible");
    else cout<<t;
}