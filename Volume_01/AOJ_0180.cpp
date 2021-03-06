#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4
#define ALL(v) v.begin(),v.end()
#define func [&]
#define MAX_V 101

int n,m;

// Union-Find
int par[MAX_V];
int rrank[MAX_V];

void init(int n){
  rep(i,n){
    par[i] = i;
    rrank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);

  if(x == y) return;

  if(rrank[x] < rrank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rrank[x] == rrank[y]) rrank[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

// Union-Find

struct Edge{
  int u;
  int v;
  int cost;
};

bool comp(const Edge&e1, const Edge&e2){
  return e1.cost < e2.cost;
}

Edge es[10000];


int kruskal(){
  sort(es, es+m, comp);
  init(n);
  int res = 0;
  rep(i,m){
    Edge e = es[i];
    if(!same(e.u, e.v)){
      unite(e.u,e.v);
      res += e.cost;
    }
  }

  return res;
}

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    rep(i,m){
      cin >> es[i].u >> es[i].v >> es[i].cost;
    }
    cout << kruskal() << endl;
  }

  return 0;
}
