// --- Imports y todo lo que necesitamos ---

vector<int> adj[N];
bool visited[N];

void dfs(int s) {
  if (visited[s])
    return;
  // process node s
  for (auto u : adj[s]) {
    dfs[u];
  }
}

// --- Un main ---
