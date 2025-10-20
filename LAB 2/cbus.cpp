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
int n, k;
int c[25][25];
bool picked[25], dropped[25];
int ans = 1e9;
int curCost = 0, onBus = 0;

void backtrack(int u, int done) 
{
    if (curCost + c[u][0] >= ans) return;
    
    if (done == 2*n) 
    {
        ans = min(ans, curCost + c[u][0]); 
        return;
    }

    for (int v = 1; v <= 2*n; ++v) {
        if (v <= n) 
        {
            if (!picked[v] && onBus < k) {
                picked[v] = true;
                onBus++;
                curCost += c[u][v];
                backtrack(v, done + 1);
                curCost -= c[u][v];
                onBus--;
                picked[v] = false;
            }
        } 
        else 
        {
            int i = v - n;
            if (picked[i] && !dropped[i]) {
                dropped[i] = true;
                onBus--;
                curCost += c[u][v];
                backtrack(v, done + 1);
                curCost -= c[u][v];
                onBus++;
                dropped[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen(TASK".inp","r"))  
    {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    cin >> n >> k;
    for (int i = 0; i <= 2*n; ++i)
        for (int j = 0; j <= 2*n; ++j)
            cin >> c[i][j];

    backtrack(0, 0);
    cout << ans << "\n";
    return 0;
}
