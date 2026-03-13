int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n,m;

ll dfs(ll x, ll y, vvll& grid, vvll& visited){
    visited[x][y] = 1;
    ll c = grid[x][y];

    fori(i,0,4) {
        ll nx = x+ dx[i];
        ll ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > 0) {
            visited[nx][ny] = true;
            c += dfs(nx,ny,grid, visited);
        }
    }
    return c;
}











void solve() {
    cin >> n >> m;

    vvll grid(n,vll(m));
    fori(i,0,n)
        fori(j,0,m)
            cin >> grid[i][j];


    vvll visited(n,vll(m, 0));
    ll maxi = 0;
    fori(i,0,n)
        fori(j,0,m)
            if(grid[i][j]>0 && visited[i][j] != 1)
                maxi = max(maxi, dfs(i,j, grid, visited));
            
    cout << maxi << endl;
}
