#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[200100];

void solve(){

    ll n,k;
    cin >> n >> k;
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    set<ll> st;
    vector<ll> v;
    v.eb(0);
    st.insert(0);
    ll pointer = 0;
    ll t1=0;
    ll count1=1;
    while(true){
        //cout << pointer << endl;
        decltype(st)::iterator it = st.find(a[pointer]);
        if (it != st.end()) { // 見つかった
            //cout << "find" << *it << std::endl;
            t1 = *it;
            break;
        }
        st.insert(a[pointer]);
        pointer = a[pointer];
        count1++;
        v.eb(pointer);
    }

    ll count2=1;
    ll tm = 0;
    while(true){
        if(a[tm]!=t1){
            tm = a[tm];
            count2++;
        }
        else{
            break;
        }
    }

    /*
    for(auto e:v){
        cout << e << "!" << endl;
    }
    */

    //cout << count1 << " " << count2 << endl;

    ll y,x;
    if(count1==count2){
        y = count1;
        x=0;
    }
    else{
        y = count1-count2;
        x = count2;
    }
    
    if(k<x){
        cout << v[k]+1 << endl;
        return;
    }
    
    /*
    cout << v.size() << endl;
    cout << k << endl;
    cout << x << endl;
    cout << y << endl;
    
    cout << (k-x)%y+x << endl;
    */
    cout << v[(k-x)%y+x]+1 << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
