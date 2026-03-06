/*
给定一个 n个点 m条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
请你求出 1号点到 n号点的最短距离，如果无法从 1号点走到 n号点，则输出 −1。

输入格式
第一行包含整数 n和 m。
接下来 m行每行包含三个整数 x,y,z，表示存在一条从点 x到点 y的有向边，边长为 z。

输出格式
输出一个整数，表示 1号点到 n号点的最短距离。
如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×105,图中涉及边长均不小于 0，且不超过 10000。
数据保证：如果最短路存在，则最短路的长度不超过 109。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

//初始化dis
//找出最小的没被找出的边
//更新边
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N=150010;
int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dis[N];
bool st[N];
typedef pair<int,int> PII;

void add(int a,int b,int x){
    e[idx]=b,ne[idx]=h[a],w[idx]=x,h[a]=idx++;
}

int dijktra(){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int distance=t.first;
        int point=t.second;
        if(st[point]) continue;
        st[point]=true;
        for(int i=h[point];i!=-1;i=ne[i]){
            if(w[i]+distance<dis[e[i]]){
                dis[e[i]]=w[i]+distance;
                heap.push({dis[e[i]],e[i]});
            }
        }
    }
    if(dis[n]==0x3f3f3f3f) return -1;
    return dis[n];
}

int main(){
    cin>>n>>m;
    memset(h, -1, sizeof h);
    while(m--){
        int a,b,x;
        cin>>a>>b>>x;
        add(a,b,x);
    }
    int ans=dijktra();
    cout<<ans;
}
//被长代码绕晕了，pair<int,int>的先后顺序要弄明白，排序有限first，所以距离要放在前面
//要记得初始化，一个是dis[N],一个是h[N]要全初始化成1
//在处理判断最短距离点是否已经算过是，直接continue，不然还会进行下面步骤，导致时间过长
//记得初始化时不用将st[1]赋值为true，不然后面无法进行下一步