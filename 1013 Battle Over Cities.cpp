#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n; // 城市总数
bool visit[1010];   // 记录当前城市是否被访问过
int v[1010][1010];  // 连通图

/* 统计当前节点能访问的所有节点 */
void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; ++i) {
        if (visit[i] == false && v[node][i] == 1) {
            dfs(i); /* 如果当前节点没被访问过，且与node可以连通 */
        }
    }
}

int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);

    /* 记录城市之间互通的信息 */
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }

    /* 需要统计的城市个数 */
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a);
        fill(visit, visit + 1010, false);
        visit[a] = true;

        int count = 0;
        for (int k = 1; k <= n; ++k) {
            if (visit[k] == false) {
                dfs(k);
                ++count;
            }
        }
        printf("%d\n", count - 1); /* 将count个城市连接起来，需要count-1条路线 */
    }
    return 0;
}
