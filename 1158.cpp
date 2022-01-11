/***************************************************************
 *    Name:  KAZI NUR ALAM MASHRY                             *
 *  School:  MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY  *
 *           CSE (14TH BATCH)                                  *
 ***************************************************************/
#include<bits/stdc++.h>
#define INF           1e9
#define el            '\n'
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
    int n, x, ans = -1;
    cin >> n >> x;
    vector<vi> dp(n+1, vi(x+1, 0));
    vi price(n), pages(n);

    for(int i = 0; i < n; ++i) cin >> price[i];
    for(int i = 0; i < n; ++i) cin >> pages[i];
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= x; ++j) {
            if(j - price[i-1] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]] + pages[i-1]);
            }
            ans = max(ans, dp[i][j]);

        }
    }

    cout << ans << el;
    
    return 0;
}