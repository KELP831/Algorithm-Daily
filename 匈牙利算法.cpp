//匈牙利算法
//用match[]来记录当前右位是否被匹配上
//find()函数用来判断能否找到匹配的点
#include <iostream>
#include <cstring>

using namespace std;

const int N=510,M=100010;
int n1,n2,m,res,match[N];
int h[N],e[M],ne[M],idx;
bool st[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]) {
            st[j]=true;
            if(match[j]==0||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d%d",&n1,&n2,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for(int i=1;i<=n1;i++){
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }
    cout<<res<<endl;
    return 0;
}
//注意ne[],e[]是和边一块记录的，所以开数组大小应该和边数量一致
//st[]用来记录已经查询过的右位，防止二次查询浪费时间