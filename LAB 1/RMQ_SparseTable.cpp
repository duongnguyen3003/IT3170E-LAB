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
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> lg(n + 1);
    for(int i = 2; i <= n; i++)
    {
        lg[i] = lg[i/2] + 1;
    }

    int k = lg[n];
    vector<vector<int> > st(n, vector<int>(k + 1));

    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q; 
    cin >> q;
    int res = 0;
    while(q--) 
    {
        int l, r; cin >> l >> r;
        int j = lg[r - l + 1];
        int mn = min(st[l][j], st[r - (1 << j) + 1][j]);
        res += mn;
    }
    cout << res;

    return 0;
}


