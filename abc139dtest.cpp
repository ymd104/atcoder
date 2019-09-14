#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
例えば2 3 1 4をそれぞれ1 2 3 4で割り、割った余りの総和の最大値を計算する
2 3 4 ... n-1 n 1とすると、余りの総和は1+2+...+(n-1)となり、これが最大？
*/

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
    int ans = 0;
    do {
        //for(auto x : v) cout << x << " ";    // v の要素を表示
        int i=1;
        int sum=0;
        for(auto x : v) {
            sum += i%x;
            i++;
        }
        //cout << sum << endl;
        ans = max(sum,ans);
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成
    cout << "maximum:" << ans << endl;
    cout << n*(n-1)/2 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
