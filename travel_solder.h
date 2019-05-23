#include <iostream>
#include <cstring>
#include <algorithm>

#define cin std::cin
#define cout std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
const static int maxn = 1000;
int N, G[maxn][maxn], min_value = inf, begin_pos;
bool vis[maxn];

void dfs(int now_pos = begin_pos, int now_value = 0, int index = 0) {
    if (index == (N - 2)) {
        for (int i = 0; i < N; ++i) {
            if (!vis[i]) {
                min_value = std::min(
                        min_value, now_value + G[now_pos][i] + G[i][begin_pos]
                );
                return;
            }
        }
    } else {
        for (int i = 0; i < N; ++i) {
            if (vis[i])continue;
            vis[i] = true;
            dfs(i, G[now_pos][i] + now_value, index + 1);
            vis[i] = false;
        }
    }
}

int main(int argc, char **argv) {
    cin >> N;
    for (int i = 0, a, b, v; i < N * (N - 1) / 2; ++i) {
        cin >> a >> b >> v;
        G[a][b] = v, G[b][a] = v, G[a][a] = 0;
    }
    cin >> begin_pos;
    memset(vis, false, sizeof(vis));
    vis[begin_pos] = true;
    dfs();
    cout << min_value << endl;
    return 0;
}
