#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

vector<int> g[N];
bool vis[N];
void dfs(int u) {
	vis[u] = true;
	for (int v : g[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
