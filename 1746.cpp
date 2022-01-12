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
    int n, m, _x, ans = 0;
    cin >> n >> m;
    vector<vi> dp(n+1, vi(m+1, 0));

    for(int i = 1; i <= n; ++i) {
        cin >> _x;
        if(_x == 0) {
            if(i == 1) {
                for(int j = 1; j <= m; ++j) dp[i][j] = 1;
            }
            else {
                for(int j = 1; j <= m; ++j) {
                    vi arr;
                    arr.pb(j-1), arr.pb(j);
                    if(j != m) arr.pb(j+1);
                    for(int k: arr) {
                        (dp[i][j] += dp[i-1][k]) %= mod;
                    }
                }
            }
        } else {
            if(i == 1) dp[i][_x] = 1;
            else {
                vi arr;
                arr.pb(_x-1), arr.pb(_x);
                if(_x != m) arr.pb(_x+1);
                for(int k: arr) {
                    (dp[i][_x] += dp[i-1][k]) %= mod;
                }
            }
        }
    }

    // for(vi v: dp) {
    //     for(int i: v) cout << i << " "; cout << el;
    // }

    for(int v: dp[n]) (ans += v) %= mod;
    cout << ans << el;
    
    return 0;
}