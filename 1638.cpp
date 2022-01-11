/***************************************************************
 *    Name:  KAZI NUR ALAM MASHRY                             *
 *  School:  MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY  *
 *           CSE (14TH BATCH)                                  *
 ***************************************************************/
#include<bits/stdc++.h>
#define INF           1e9
#define el            '\n'
#define x             first
#define y             second
#define pi            acos(-1.0)
#define pb            push_back
#define mp            make_pair
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vi> dp(n+1, vi(n+1, -1));
    char ch;
    for(int i = n; i >= 1; --i) {
        for(int j = n; j >= 1; --j) {
            cin >> ch;
            if(ch == '*') dp[i][j] = 0;
        }
    }
    cout << el <<el;
    bool flag1 = true, flag2 = true;
    for(int i = 1; i <= n; ++i) {
        if(dp[i][1] == 0 || !flag1) {
            dp[i][1] = 0;
            flag1 = false;
        } else {
            dp[i][1] = 1;
        }
        if(dp[1][i] == 0 || !flag2) {
            dp[1][i] = 0;
            flag2 = false;
        } else {
            dp[1][i] = 1;
        }
    }

    for(int i = 2; i <=n; ++i) {
        for(int j = 2; j <= n; ++j) {
            if(dp[i][j] == -1) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n][n] << el;
    
    return 0;
}