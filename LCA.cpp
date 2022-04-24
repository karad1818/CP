vector<bool> vis(n + 2, 0);
vector<vector<int>> sparse(n + 2, vector<int>(19, 0));
vector<int> depth(n + 2, 0);

function<void(int, int)> dfs = [&](int node, int p) -> void {
    vis[node] = 1;
    sparse[node][0] = p;
    for (int i = 1; i < 19; i++) {
        sparse[node][i] = (sparse[node][i - 1] >= 0 ? sparse[sparse[node][i - 1]][i - 1] : -1);
    }
    for (auto i : adj[node]) {
        if (!vis[i]) {
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
};

auto LCA = [&](int u, int v) -> int {
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 18; i >= 0; i--) {
        if (depth[v] + (1 << i) <= depth[u]) {
            u = sparse[u][i];
        }
    }

    if (u == v)
        return u;

    for (int i = 18; i >= 0; i--) {
        if (sparse[u][i] != sparse[v][i]) {
            u = sparse[u][i];
            v = sparse[v][i];
        }
    }
    return sparse[u][0];
};
