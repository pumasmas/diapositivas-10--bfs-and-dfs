ll bfs(ll x, ll y, vvll& grid, vvll& visited){
    queue<ll> qx, qy;
    visited[x][y] = 1;

    ll c = 0;
    qx.push(x);
    qy.push(y);

    while (!qx.empty()){   
        ll cx = qx.front();
        ll cy = qy.front();

        c += grid[cx][cy];

        qx.pop();
        qy.pop();
        
        fori(i,0,4) {
            ll nx = cx + dx[i];
            ll ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                qx.push(nx);
                qy.push(ny);
            }
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
                maxi = max(maxi, bfs(i,j, grid, visited));
            
    cout << maxi << endl;
}
