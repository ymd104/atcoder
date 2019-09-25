#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

struct edge{
    int num;
    int v1;
    int v2;
};

void solve(){
    int n;
    int q;
    cin >> n >> q;
    vector<edge> v;
    vector<int> vr[n+10];
    rep(i,n-1){
        edge s;
        s.num=i;
        cin >> s.v1 >> s.v2;
        v.emplace_back(s);
        vr[s.v1].emplace_back(s.v2);
        vr[s.v2].emplace_back(s.v1);
    }
    //cout << v[0].num << v[0].v1 << v[0].v2 << endl;
    int p[q+10];
    int x[q+10];
    rep(i,q){
        cin >> p[i] >> x[i];
    }

    //各クエリp,xについて、配列cを用意し、頂点pにxを加算
    //頂点番号iを、根に近いものから順に並び替えた番号へと写像

    //各頂点の、根からの距離を計算
    int d[n+10];
    d[1]=0;
    vector<pair<int,int>> vp;
    //vp:(子, 親)のペア

    /*
    愚直にやるとO(n^2)となり間に合わない
    各頂点を走査したかどうかを判定するbool配列を保持し、
    スタックに入った時点でtrue
    辺はあらかじめ(順番が逆のものも含めた上で)保持しておく
    */
    bool b[n+10];
    rep(i,n){
        b[i+1] = false;
    }
    
    stack<int> st;
    st.push(1);
    b[1]=true;
    while(!st.empty()){
        int tmp = st.top();
        st.pop();
        //rep(i,n-1){
            /*
            if(v[i].v1==tmp){
                d[v[i].v2]=d[tmp]+1;
                //cout << v[i].v2 << endl;
                st.push(v[i].v2);
                vp.emplace_back(make_pair(v[i].v2, tmp));
                v[i].v1=-1;
                v[i].v2=-1;
            }
            if(v[i].v2==tmp){
                d[v[i].v1]=d[tmp]+1;
                st.push(v[i].v1);
                vp.emplace_back(make_pair(v[i].v1, tmp));
                v[i].v1=-1;
                v[i].v2=-1;
            }
            */
            int siz = vr[tmp].size();
            auto k = vr[tmp];
            rep(i,siz){
                if(!b[k[i]]){
                    d[k[i]]=d[tmp]+1;
                    //cout << v[i].v2 << endl;
                    st.push(k[i]);
                    vp.emplace_back(make_pair(k[i], tmp));
                    b[k[i]]=true;
                }
            }
        //}
    }
    /*
    この時点で、d[i]には頂点iの根からの距離が格納されている
    vp:(親,子)のリスト
    d[i]の小さい順に、(d[i]=1のものから)子に親のcを足していく
    */
    /*
    rep(i,n){
        cout << "d[" << i+1 << "]:" << d[i+1] << endl;
    }
    */
    vector<pair<int,int>> m;
    for(int i=1; i<=n; i++){
        m.emplace_back(d[i],i);
    }
    /*
    rep(i,n){
        cout << "m[" << i << "]:" << m[i].first << "," << m[i].second << endl;
    }
    */
    sort(m.begin(), m.end());
    sort(vp.begin(), vp.end());
    //ある頂点iが与えられた時、その親の頂点はvp[i-2].secondで計算できる
    /*
    rep(i,n-1){
        cout << "vp[" << i << "]:" << vp[i].first << "," << vp[i].second << endl;
    }
    */
    int c[n+10];
    rep(i,n){
        c[i+1]=0;
    }
    rep(i,q){
        c[p[i]] += x[i];
    }
    for(int i=1; i<n; i++){
        int ver = m[i].second;
        //cout << "ver:" << ver << endl;
        //ver:着目している頂点の番号
        int parent = vp[ver-2].second;
        //cout << "parent:" << parent << endl;
        c[ver] += c[parent];
    }

    rep(i,n){
        cout << c[i+1] << " ";
    }
    cout << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

