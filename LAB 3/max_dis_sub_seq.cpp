/**
* ^~^  ,
* ('Y') )
* /   / 
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

int n, c;
vector<int> a;

bool check(int dist) {
    int count = 1;
    int last_picked_pos = a[0];
    
    for (int i = 1; i < n; i++) {
        if (a[i] - last_picked_pos >= dist) {
            count++;
            last_picked_pos = a[i];
        }
    }
    
    return count >= c;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(bend(a));
        
        int lo = 0;
        int hi = a[n-1] - a[0];
        int res = 0;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        cout << res << '\n';
    }

    return 0;
}