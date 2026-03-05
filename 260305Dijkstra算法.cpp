//Dijkstra算法-单源最短路


/*
给定一个 n个点 m条边的有向图，图中可能存在重边和自环，所有边权均为正值。
请你求出 1 号点到 n号点的最短距离，如果无法从 1号点走到 n号点，则输出 −1。
输入格式
第一行包含整数 n和m。
接下来 m行每行包含三个整数 x,y,z，表示存在一条从点 x到点 y的有向边，边长为 z。

输出格式
输出一个整数，表示 1号点到 n号点的最短距离。
如果路径不存在，则输出 −1。
数据范围
1≤n≤500,
1≤m≤105,
图中涉及边长均不超过10000。
输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

//1.初始化，遍历1-n，将dis[i]除了源点为0，都初始化为∞（即一个极大数）
//2.遍历1-n，找到最短边，将该点存入s
//3.更新所有的dis



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 510;
int n, m;
int dis[N];
int g[N][N];
bool st[N];

int dijkstra() {
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	for (int i = 1; i <= n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dis[j] < dis[t])) {
				t = j;
			}
			
		}
		st[t] = true;
		for (int j = 1; j <= n; j++) {
			if (dis[t] + g[t][j] < dis[j]) {
				dis[j] = dis[t] + g[t][j];
			}
		}
	}
	return dis[n];
}
int main() {
	scanf("%d %d", &n, &m);
	
	memset(g, 0x3f, sizeof g);
	while (m--) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		g[a][b] = min(g[a][b], x);
	}
	int ans = dijkstra();
	if (ans == 0x3f3f3f3f) ans = -1;
	printf("%d", ans);
}
/*
memset 这个函数的工作原理是“按字节（Byte）赋值”的。
在 C++ 中，一个 int 类型的整数占用 4 个字节。
当你写 memset(dis, 0x3f, sizeof dis); 时，编译器会把 dis 数组里的每一个 int 的 4 个字节都填上 0x3f。
所以，拼凑起来后，这个 int 实际的值变成了 0x3f3f3f3f（十进制大约是 $10^9$）。
*/