#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

//各マスのRLの境目に密集する。
//RRLRLのような文字列を、(2,1),(1,1)のように表す。例えば、
//RRRLLRLLRRRLLLLLは(3,2),(1,2),(3,5)となる
//各ペア(i,j)について、i,jの偶奇で場合分け。
//共に偶数の場合、例えばRRLLLLなどなので、111111 022110 023100 033000 のようにして半々になる
//共に奇数の場合、偶数の場合と同じ
//iが奇数、jが偶数の時、RRRLLなど。11111 01220 00320 00230 というように振動。
//10^100は偶数だから、00320のように、( (i+j+1)/2 , (i+j-1)/2 )のようになる。
//偶奇が逆の場合、RRLなど。111 021 012というように振動。
//( (i+j-1)/2 , (i+j+1)/2 )のようになる


void solve(){
    string s;
    cin >> s;
    vector<pair<int,int>> v;
    //sを削っていく。２つのモードx,yを用意し、
    //モードxの時はs[0]=Lになるまでa++
    //モードyの時はs[0]=Rになるまでb++
    //モードは順番に実行される
    int a=0;
    int b=0;
    while(s.size()!=0){
        while(s[0]=='R'){
                a++;
                s = s.substr(1, s.size());
            }
        while(s[0]=='L'){
                b++;
                s = s.substr(1, s.size());
            }
        
        v.emplace_back(make_pair(a,b));
        a=0;
        b=0;
    }
    //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;

    //各ペア(p,q)について、
    //pとqの偶奇が一致している時、0 0 ... 0 (p+q)/2 [i個] (p+q)/2 0 0 ... 0 [j個] となる

    for(int i = 0; i < v.size(); i++){
        int p = v[i].first;
        int q = v[i].second;

        if((p-q)%2==0){
        for(int j=0; j<p-1; j++){
            cout << "0 ";
        }
        cout << (p+q)/2 << " " << (p+q)/2 << " ";
        for(int j=0; j<q-1; j++){
            cout << "0 ";
        }
        }
        else if(p%2==1){
        for(int j=0; j<p-1; j++){
            cout << "0 ";
        }
        cout << (p+q+1)/2 << " " << (p+q-1)/2 << " ";
        for(int j=0; j<q-1; j++){
            cout << "0 ";
        }
        }
        else{
        for(int j=0; j<p-1; j++){
            cout << "0 ";
        }
        cout << (p+q-1)/2 << " " << (p+q+1)/2 << " ";
        for(int j=0; j<q-1; j++){
            cout << "0 ";
        }
        }
    }

    cout << endl;
}

int main(){
  solve();
  return 0;
}
