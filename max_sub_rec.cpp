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

    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }

    vector<int> h(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
         {
            if (a[i][j] == 1) h[j]++;
            else h[j] = 0;
        }

        int size = h.size();
        stack<int> s;
        int res = 0;

        for (int k = 0; k < size; k++) 
        {
            while (!s.empty() && h[s.top()] >= h[k]) 
            {
                int tp = s.top();
                s.pop();
                int width = s.empty() ? k : k - s.top() - 1;
                res = max(res, h[tp] * width);
            }
            s.push(k);
        }

        while (!s.empty()) 
        {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? size : size - s.top() - 1;
            res = max(res, h[tp] * width);
        }

        ans = max(ans, res);
    }

    cout << ans;

    return 0;
}
