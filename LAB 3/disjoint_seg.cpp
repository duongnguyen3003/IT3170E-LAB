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
    vector<pii> a(n);

    for(auto &x : a)
    {
        cin >> x.fi >> x.se;
    }

    sort(bend(a), [](pii a, pii b)
    {
        return a.se < b.se;
    });

    for(auto x : a)
    {
        cout << x.fi << ' ' << s.se << '\n';
    }

    int last = -1, res = 0;

    for(auto x : a)
    {
        if(x.fi > last)
        {
            last = x.se;
            res++;
        }
    }

    cout << res;

    return 0;
}

/*
6
0 10
3 7
6 14
9 11
12 15
17 19
*/