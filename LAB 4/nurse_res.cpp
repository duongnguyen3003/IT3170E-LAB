#include <bits/stdc++.h>
using namespace std;
#define maxN 1002

int n, K1, K2;
int S0[maxN], S1[maxN]; // S0[i] = so cach sap lich ma ngay i la nghi
                        // S1[i] = so cach sap lich ma ngay i di lam
                        // return S0[n] + S1[n]

int main(int argc, char const *argv[]) {
    cin >> n >> K1 >> K2;
    S0[1] = S1[K1] = S0[0] = 1;

    for (int i = K1+1; i<=n; i++) {
        S0[i] = S1[i-1]; // ngay i nghi: ngay i-1 di lam
        for (int j=K1; j<=K2 && i-j>=0; j++)
            S1[i] += S0[i-j]; // ngay i di lam: mot chuoi ngay lam viec
    }
    cout << S0[n] + S1[n];
    return 0;
}