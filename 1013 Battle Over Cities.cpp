#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n; // ��������
bool visit[1010];   // ��¼��ǰ�����Ƿ񱻷��ʹ�
int v[1010][1010];  // ��ͨͼ

/* ͳ�Ƶ�ǰ�ڵ��ܷ��ʵ����нڵ� */
void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; ++i) {
        if (visit[i] == false && v[node][i] == 1) {
            dfs(i); /* �����ǰ�ڵ�û�����ʹ�������node������ͨ */
        }
    }
}

int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);

    /* ��¼����֮�以ͨ����Ϣ */
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }

    /* ��Ҫͳ�Ƶĳ��и��� */
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
        printf("%d\n", count - 1); /* ��count������������������Ҫcount-1��·�� */
    }
    return 0;
}
