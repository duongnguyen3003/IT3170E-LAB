/**
*   ^~^  ,
*  ('Y') )
*  /   / 
* (||/)
**/
#include <bits/stdc++.h>
#define TASK "bus"

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
const int N = 5005;

int n, m;
int c[N], d[N];
vector<int> adj[N];
vector<pii> adj_cost[N];
ll dist[N];
bool vis[N];
void bfs() {
    for (int i = 1; i <= n; ++i) {
        queue<pii> q;
        q.push({i, 0});
        
        vis[i] = true;
        
        while (!q.empty()) 
        {
            int u = q.front().fi;
            int depth = q.front().se;
            q.pop();
            
            if(u != i) 
            {
                adj_cost[i].pb({u, c[i]});
            }
            
            if(depth < d[i]) 
            {
                for (int v : adj[u]) 
                {
                    if (!vis[v]) 
                    {
                        vis[v] = true;
                        q.push({v, depth + 1});
                    }
                }
            }
        }
    }
}

void dijkstra() {
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[1] = 0;
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    
    while(!pq.empty()) 
    {
        ll d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto edge : adj_cost[u]) 
        { 
            int v = edge.fi;
            int w = edge.se;
            
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
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
    for (int i = 1; i <= n; ++i) 
    {
        cin >> c[i] >> d[i];
    }
    
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    bfs();
    
    dijkstra();
    
    cout << dist[n] << "\n";

    return 0;
}