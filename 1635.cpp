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
ll n, val, dp[mx];

int calculate(vi& coins) {
    mem(dp, 0);
    for(int coin: coins) if(coin <= val) dp[coin] = 1;

    for(int i = 1; i <= val; ++i) {
        if(dp[i] != 0) {
            for(int coin: coins) {
                if(i + coin <= val) {
                    dp[i + coin] = (dp[i + coin] + dp[i]) % mod;
                }
            }
        }
    }

    return dp[val];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> val;
    vi coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];
    cout << calculate(coins) << el;
    return 0;
}