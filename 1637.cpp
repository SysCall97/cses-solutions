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

int getMaxDigit(int val) {
    int maxDigit = -1;
    while(val) {
        int _digit = val % 10;
        maxDigit = _digit > maxDigit ? _digit : maxDigit;
        val /= 10;
    }
    return maxDigit;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if(n < 10) {
        cout << 1 << el;
        return 0;
    }
    vi dp(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        dp[i] = dp[i - getMaxDigit(i)] + 1;
    }
    cout << dp[n] << el;
    
    return 0;
}