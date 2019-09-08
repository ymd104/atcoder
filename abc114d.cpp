#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
七五数
75=3*5*5

a^74
a^24 * b^2
a^15 * b^4
a^4 * b^4 * c^2
のどれか。
1.a^74
 a=2がギリギリありそう。実際、100なら50+25+12+6+3+1>75。
 74を超えるのは、n=78 39+19+9+4+2+1 以上の場合。
2.a^24 * b^2
 例えばn=100まで行くと、a=2,3,5まで届く。
 a=2はn>=28
 a=3はn>=54
 a=5はn>=100
 bについては大体の素数がそう
 n/2以下の素数の数を数える。ただし、aと同じ数になってはいけない。
3.a^14 * b^4
 n=7もギリギリ届く
 a=2はn>=16
 a=3はn>=30
 a=5はn>=60
 a=7はn>=91
 bについては、n/4以下の素数の数を数えればいい。
4.a^4 * b^4 * c^2
 約数が4つ以上の素数の数をp
 n/2以下の素数をq個とする。
 pC2 * (q-2)が答え。
*/

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

void solve(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i=2; i<=n/2; i++){
        if(IsPrime(i)) v.emplace_back(i);
    }

    ll ans = 0;

    //1
    if(n>=78) ans++;

    //2
    //a=2
    if(n>=28) ans += v.size()-1;
    //a=3
    if(n>=54) ans += v.size()-1;
    //a=5
    if(n>=100) ans += v.size()-1;

    //3
    //n/4以下の素数の数を数える
    int limit = n/4;
    int count = 0;
    for(int i=11; i<=limit; i++){
        if(IsPrime(i)) count++;
    }
    //2,3,5,7は個別に数える
    if(n>=6) count++;
    if(n>=9) count++;
    if(n>=20) count++;
    if(n>=28) count++;

    //a=2はn>=16
    if(n>=16) ans += count-1;
    //a=3はn>=30
    if(n>=30) ans += count-1;
    //a=5はn>=60
    if(n>=60) ans += count-1;
    //a=7はn>=91
    if(n>=91) ans += count-1;

    //4
    ll p=count;
    ll q=v.size();
    ans += p*(p-1)/2 * (q-2);

    cout << ans << endl;

    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
