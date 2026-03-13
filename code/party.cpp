#include<bits/stdc++.h>
using namespace std;

vector<int> v[2001];
int c = 1;

void dfs(int x, int d) {
  c = max(c,d);
  for(int i = 0; i < v[x].size(); i++) {
    dfs(v[x][i] , d + 1);
  }
}

int main() {
  int t;

  cin>>t;
  for(int i = 1; i <= t; i++) {
    int x;
    cin >> x;
    if(x == -1)
      continue;
    v[x].push_back(i);
  }
  for(int i = 1; i <= t; i++) {
    dfs(i,1);
  }
  cout << c << endl;
  // this is for academic purposes and is not part of the (bad) solution
  for (int i = 1; i <= t; i++) {
    printf("%d): ", i);
    for (int n : v[i]) {
      printf("%d\t", n);
    }
    printf("\n");
  }
}
