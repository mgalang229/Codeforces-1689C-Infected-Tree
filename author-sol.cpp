#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 3e5 + 1;
vector<int> adj[maxN];
int childVertices[maxN], dp[maxN];

void Dfs(int u, int parent) {
	childVertices[u] = 1;
	dp[u] = 0;
	int s = 0;
	for (int& v : adj[u]) {
		if (v != parent) {
			Dfs(v, u);
			s += dp[v];
			childVertices[u] += childVertices[v];
		}
	}
	for (int& v : adj[u]) {
		if (v != parent) {
			dp[u] = max(dp[u], s - dp[v] + childVertices[v] - 1);
		}
	}
}

void TestCase(int& tc) {
	int n;
	cin >> n;
	for (int u = 0; u < n; u++) {
		adj[u].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(childVertices, 0, sizeof(childVertices));
	memset(dp, 0, sizeof(dp));
	Dfs(0, -1);
	cout << dp[0] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		TestCase(tc);
	}
	return 0;
}
