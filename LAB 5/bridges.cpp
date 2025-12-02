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

int n, m;
vector<int> adj[N];
int num[N], low[N];
int timeDfs = 0;
int bridges = 0;
bool joint[N];

void dfs(int u, int p) {
    num[u] = low[u] = ++timeDfs;
    int child = 0;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > num[u]) {
                bridges++;
            }
            
            if (p != -1) {
                if (low[v] >= num[u]) {
                    joint[u] = true;
                }
            }
        }
    }
    
    if (p == -1 && child > 1) {
        joint[u] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for (int i = 1; i <= n; ++i) 
    {
        if (!num[i]) 
        {
            dfs(i, -1);
        }
    }
    
    int cntJoint = 0;
    for (int i = 1; i <= n; ++i) 
    {
        if (joint[i]) cntJoint++;
    }
    
    cout << cntJoint << " " << bridges << "\n";

    return 0;
}

/*
10 12
1 10
10 2
10 3
2 4
4 5
5 2
3 6
6 7
7 3
7 8
8 9
9 7
*/