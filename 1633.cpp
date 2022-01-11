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
const int mx = 1e9 + 7;
ll n;

ll calculate(int target, vi& dp) {
    if(target < 0) return 0;
    if(dp[target] > 0) return dp[target];
    if(target == 0) return 1;

    int ans = 0;
    for(int i = 1; i <= 6; ++i) {
        ans = (ans + calculate(target - i, dp)) % mx;
    }
    dp[target] = ans%mx;
    return dp[target];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    vi dp(n+1, 0);
    cout << calculate(n, dp) << el;
    
    return 0;
}