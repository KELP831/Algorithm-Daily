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

const int N=100010;
int dist[N];
int n,m,INF=0x3f3f3f3f;
bool st[N];
int h[N],e[N],ne[N],w[N],idx;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> Q;
    Q.push(1);
    st[1]=true;
    while(!Q.empty()){
        int t=Q.front();
        Q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            if(dist[e[i]]>dist[t]+w[i]){
                dist[e[i]]=dist[t]+w[i];
                if(!st[e[i]]){
                    Q.push(e[i]);
                    st[e[i]]=true;
                }
            }
        }
    }
    return dist[n];
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
    }
    int t=spfa();
    if(t==INF) puts("impossible");
    else cout<<t;
}
//只能使用邻接表存储

//判断有无负环
//增添数组cnt[N]来记录路径中边的数量
//如果某个cnt[i]>=n，则说明有负环
//所以一开始我们要将所有的顶点都加入队列
/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N=100010;
int dist[N];
int n,m,INF=0x3f3f3f3f,cnt[N];
bool st[N];
int h[N],e[N],ne[N],w[N],idx;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool spfa(){
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    dist[1]=0;
    queue<int> Q;
    for (int i = 1; i <= n; i ++ )
    {
        st[i] = true;
        Q.push(i);
    }
    while(!Q.empty()){
        int t=Q.front();
        Q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            if(dist[e[i]]>dist[t]+w[i]){
                dist[e[i]]=dist[t]+w[i];
                cnt[e[i]]=cnt[t]+1;
                if (cnt[e[i]] >= n) return true;
                if (!st[e[i]])
                {
                    Q.push(e[i]);
                    st[e[i]] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
    }
    
    bool flag=spfa();
    
    if(!flag)cout<<"No";
    else cout<<"Yes";
}
*/