int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

ll n, m, walls; 

void dfs(ll x, ll y, vector<vector<char> >& grid, vvll & visited) {
    visited[x][y] = 1;
    
    fori(i,0,4) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
  
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
            if (!visited[nx][ny]) 
                dfs(nx, ny, grid, visited);
        }
    }
 
    if(walls > 0) {
        grid[x][y] = 'X';
        walls--;
    };

    return;
}

void solve(){
    cin >> n >> m >> walls;
    vector<vector<char> > grid(n,vector<char>(m,'a'));

    ll startx = -1, starty;
    
    fori(i,0,n) 
        fori(j,0,m) {
            cin >> grid[i][j];
            if(startx == -1)
                if(grid[i][j] == '.') 
                    startx = i, starty = j;
        }

    vvll visited(n,vll(m,0));
    dfs(startx, starty, grid, visited);

    fori(i,0,n) {
        fori(j,0,m) 
            cout << grid[i][j];
        cout << endl;
    }

}

