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

const int N = 2e3+7;


int m, n;
bool teach[N][N], conflict[N][N];
int solution[N], load[N];
int res;

bool check(int teacher, int course) {
    if (!teach[teacher][course]) {
        return false;
    }

    for (int i = 1; i < course; ++i) {
        if (solution[i] == teacher) {
            if (conflict[i][course]) {
                return false;
            }
        }
    }
    
    return true;
}

void solve(int k) {
    if (k > n) {
        int current_max_load = 0;
        for (int i = 1; i <= m; ++i) {
            current_max_load = max(current_max_load, load[i]);
        }
        
        res = min(res, current_max_load);
        return;
    }

    for (int v = 1; v <= m; v++) {
        if (check(v, k)) {
            solution[k] = v;
            load[v]++;

            if (load[v] < res) {
                solve(k + 1);
            }

            load[v]--;
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

    cin >> m >> n;
    res = n + 1;

    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int id;
            cin >> id;
            teach[i][id] = true;
        }
    }

    int conflicts;
    cin >> conflicts;
    for (int i = 0; i < conflicts; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        conflict[c1][c2] = true;
        conflict[c2][c1] = true;
    }

    solve(1);

    if (res == n + 1) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}


/*

*/