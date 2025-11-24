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

const int INF = 1e9 + 9;
const int N = 2e6 + 7;
int dp[N][2];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    for(int i = 0; i < n; ++i) 
    {
        dp[i][0] = -INF;
        dp[i][1] =  -INF;
    }

    if (abs(a[0]) % 2 == 0) dp[0][0] = a[0];
    else dp[0][1] = a[0];
    
    int res = dp[0][0];

    for (int i = 1; i < n; i++) 
    {
        int val = a[i];
        if (abs(val) % 2 == 0) 
        {
            dp[i][0] = max(val, (dp[i - 1][0] ==  - INF) ?  - INF : dp[i - 1][0] + val);
            dp[i][1] = (dp[i - 1][1] ==  - INF) ?  - INF : dp[i - 1][1] + val;
        } 
        else 
        {
            dp[i][0] = (dp[i - 1][1] ==  - INF) ?  - INF : dp[i - 1][1] + val;
            dp[i][1] = max(val, (dp[i - 1][0] ==  - INF) ?  - INF : dp[i - 1][0] + val);
        }
        
        if (dp[i][0] !=  - INF) {
            res = max(res, dp[i][0]);
        }
    }

    cout << res;
    
    return 0;
}