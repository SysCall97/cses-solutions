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
const int mx = 1e6 + 7;
const int mod = 1e9 + 7;
ll n, val;

int calculate(vi& coins) {
    vector<vi> dp(n+1,vi(val+1,0));
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= val; ++j) {
            dp[i][j] += dp[i-1][j];
            int _left = j - coins[i];
            if(_left >= 0) dp[i][j] += dp[i][_left];
            dp[i][j] %= mod;
        }
    }
    return dp[n][val];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> val;
    vi coins(n+1);
    for(int i = 1; i <= n; ++i) cin >> coins[i];
    sort(all(coins));
    cout << calculate(coins) << el;
    return 0;
}