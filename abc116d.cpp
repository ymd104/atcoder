#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
各寿司には、ネタと美味しさのパラメータがある
満足ポイント：美味しさの総和＋ネタの種類の二乗
N個の寿司の中からK個の寿司を選ぶとき、満足ポイントの最大値を求めよ。

k個のお寿司について、p種類のネタを選んだ時の美味しさの総和の最大値をf(p)とする。
求める最大値は、f(p)+p*p
美味しさの高いものからK個お寿司を選ぶとする。(このお寿司の集合をSとする)
この時、このK個のお寿司の種類をxとする。
この場合の美味しさの総和はf(x)となる。

xより小さいiについて、美味しさの総和だけでなく種類も少ないので、i<xなるiについては考えなくていい。
xより大きいiについて、美味しさの総和は確実に減る(または等しいまま)。しかし種類が多くなれば、
満足ポイントは逆転しうる。
x+1,x+2,...,Nまで、以下の手続きで計算できる。
1. Sから、取り除いてもネタの種類が減らないお寿司の中でもっとも美味しさの小さいものを取り出す。
2. Sに存在しないネタを持つ、もっとも美味しさの大きいお寿司を加える。
この操作をNまで繰り返す。

値の挿入および最小値の取り出しは、プライオリティキューを用いる。
プライオリティキューには、取り除いてもネタの種類が減らないお寿司の、美味しさが2番目以降の
お寿司を入れていく。

*/

void solve(){
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> v;
  rep(i,n){
    ll t,d;
    cin >> t >> d;
    v.emplace_back(make_pair(d,t));
  }
  sort(v.rbegin(),v.rend());
  ll sum = 0;
  
  
  
  priority_queue<ll, vector<ll>, greater<ll>> sushi;
  set<ll> sushitabetai;

  rep(i,k){
    sum += v[i].first;
    if(sushitabetai.find(v[i].second) != sushitabetai.end()){
      sushi.push(v[i].first);
    }
    else{
      sushitabetai.insert(v[i].second);
    }
  }
  ll siz = sushitabetai.size();
  //sum += siz*siz;

  ll ans = sum + siz*siz;
  for(int i = k; i<n; i++){
    //cout << "queue top:" << sushi.top() << endl;
    //cout << "v[i]:" << v[i].first << " " << v[i].second << endl;
    //各お寿司v[k],v[k+1],...,v[n-1]について、
    //ネタが同じならsumには加えない、
    //ネタが同じ出ない時に、プライオリティキューの先頭要素qと比較し、
    //sum-q-siz*siz+(siz+1)*(siz+1)+v[i].first>sumならキューからポップしてsumを更新。
    //ちなみにこの不等式は、2*siz+1+v[i].first>qの時に成立する
    if(sushitabetai.find(v[i].second) == sushitabetai.end() && sushitabetai.size() != k){
      ll q = sushi.top();
      //if(2*siz+1+v[i].first>q){
      //上の評価は実は要らない。なぜなら道中で得られた全てのsumの最大値を計算するため
        sushitabetai.insert(v[i].second);
        sushi.pop();
        sum -= q;
        sum += v[i].first;
        ll t = sushitabetai.size();
        ans = max(ans,sum + t*t);
      //}
    }
  }
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}