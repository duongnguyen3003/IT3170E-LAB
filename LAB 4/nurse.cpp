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
const int N = 2e3 + 7;
ll dp[N][N]; //* dp[i][j]: làm đến ngày i và đã làm đc j ngày liên tiếp

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    int n, k1, k2; cin >> n >> k1 >> k2;

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        ll tmp = 0;
        for(int k = k1; k <= k2; k++)
        {
            if (i - 1 >= 0) {
                tmp += dp[i-1][k];
            }
        }
        dp[i][0] = tmp;

        if (i - 1 >= 0) {
            dp[i][1] = dp[i-1][0];
        }
        for(int j = 2; j <= k2; j++)
        {
            if (i - 1 >= 0) {
               dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    ll res1 = dp[n][0];
    for(int k = k1; k <= k2; k++)
    {
        res1 += dp[n][k];
    }

    ll res0 = 0;
    if (n > 0) {
        res0 = dp[n-1][0];
        for (int k = k1; k <= k2; k++) {
            res0 += dp[n-1][k];
        }
    } else {
        res0 = 1;
    }

    cout << res1 + res0;

    return  0;
}