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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    int n, m; cin >> n >> m;
    vector<int> a(n), dp(n);

    int sum = 0;
    for(auto &x : a)
    {
        cin >> x; 
        sum += x;
    }

    int M = m - sum;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int s = a[i]; s <= M; s++) {
            dp[s] += dp[s - a[i]];
        }
    }

    cout << dp[M];
    return 0;
}
