/**
*   ^~^  ,
*  ('Y') )
*  /   / 
* (||/)
**/
#include <bits/stdc++.h>
#define TASK ""

using ll = long long;
using ld = long double;
#define pii pair<int,int>
#define bend(a) a.begin(), a.end()
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

const ll INF = 1e17 + 9;
const int N = 2e6 + 7;

vector<int> adj[N], radj[N];
bool vis[N];
vector<int> order;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v]) dfs1(v);
    order.pb(u);
}

void dfs2(int u) {
    vis[u] = true;
    for (int v : radj[u])
        if (!vis[v]) dfs2(v);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    //freopen("a.in","r",stdin);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }

    for(int i = 1; i <= n; i++)
        if (!vis[i]) dfs1(i);
    
    memset(vis, 0, sizeof vis);
    int scc = 0;

    reverse(bend(order));
    // for(auto u : order) cout << u << ' ';
    // cout << endl;
    for (int u : order) {
        if (!vis[u]) {
            dfs2(u);
            scc++;
        }
    }
    cout << scc << '\n';
    return 0;
}