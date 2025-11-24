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
int dp[N];

int getMaxGold(int n, int l1, int l2, const vector<int>& a) {
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of the valid range [i - l2, i - l1]
        if (!dq.empty() && dq.front() < i - l2) {
            dq.pop_front();
        }

        // Calculate dp[i]
        if (i >= l1) {
            dp[i] = dp[dq.front()] + a[i];
        } else {
            dp[i] = a[i];
        }

        // Maintain deque in decreasing order of dp values
        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);
    }

    // Return the maximum value in dp array
    return *max_element(dp, dp + n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    int n, l1, l2; cin >> n >> l1 >> l2;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }

    for(int i = l1; i < n - 1; i++)
    {
        int tmp = -1;
        for(int j = i - l2; j <= i - l1; j++)
        {
            tmp = max(tmp, dp[j] + a[i]);
        }
        dp[i] = tmp;
    }

    int res = -1;
    for(int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }

    cout << res << '\n';
    //for(int i = 0; i < n; i++) dp[i] = a[i];
    //cout << getMaxGold(n,l1,l2,a);


    return 0;
}

/*
6 2 3
3 5 9 6 7 4
*/