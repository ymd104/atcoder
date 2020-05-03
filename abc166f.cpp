#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;



void solve(){

    ll n;
    cin >> n;
    ll a,b,c;
    cin >> a >> b >> c;
    vector<char> v;
    vector<string> ve;
    rep(i,n){
        string st;
        cin >> st;
        ve.emplace_back(st);
    }
    for(ll i=0; i<ve.size()-1; i++){
        string st = ve[i];
        if(st=="AB") {

            if(a>b) {
                a--;
                b++;
                v.emplace_back('B');
            }
            else if(a<b){
                a++;
                b--;
                v.emplace_back('A');
            }
            else if(a==1&&b==1&&ve[i+1]=="BC"&&c==0){
                a--;
                b++;
                v.emplace_back('B');
            }
            else if(a==1&&b==1&&ve[i+1]=="AC"&&c==0){
                a++;
                b--;
                v.emplace_back('A');
            }
            else{
                a++;
                b--;
                v.emplace_back('A');
            }

        }

        else if(st=="BC"){
            if(b>c){
                b--;
                c++;
                v.emplace_back('C');
            }
            else if(b<c){
                b++;
                c--;
                v.emplace_back('B');
            }
            else if(b==1&&c==1&&ve[i+1]=="AC"&&a==0){
                b--;
                c++;
                v.emplace_back('C');
            }
            else if(a==1&&b==1&&ve[i+1]=="AB"&&a==0){
                b++;
                c--;
                v.emplace_back('B');
            }
            else{
                b++;
                c--;
                v.emplace_back('B');
            }

        }
        else{
            if(c>a){
                c--;
                a++;
                v.emplace_back('A');
            }
            else if(c<a){
                c++;
                a--;
                v.emplace_back('C');
            }
            else if(a==1&&c==1&&ve[i+1]=="BC"&&b==0){
                c++;
                a--;
                v.emplace_back('C');
            }
            else if(a==1&&c==1&&ve[i+1]=="AB"&&b==0){
                c--;
                a++;
                v.emplace_back('A');
            }
            else{
                c--;
                a++;
                v.emplace_back('A');
            }

        }

        if(a<0||b<0||c<0) {
            cout << "No" << endl;
            return;
        }
    }

    if(ve[n-1]=="AB"){
        if(a==0&&b==0) {
            cout << "No" << endl;
            return;
        }
        else{
            if(b>=1) v.emplace_back('A');
            else v.emplace_back('B');
        }
    }
    if(ve[n-1]=="BC"){
        if(c==0&&b==0) {
            cout << "No" << endl;
            return;
        }
        else{
            if(c>=1) v.emplace_back('B');
            else v.emplace_back('C');
        }
    }
    if(ve[n-1]=="AC"){
        if(a==0&&c==0) {
            cout << "No" << endl;
            return;
        }
        else{
            if(c>=1) v.emplace_back('A');
            else v.emplace_back('C');
        }
    }




    /*
    rep(i,n){
        string st;
        cin >> st;
        if(st=="AB") {
            if(a>b) {
                a--;
                b++;
                v.emplace_back('B');
            }
            else{
                a++;
                b--;
                v.emplace_back('A');
            }
        }
        else if(st=="BC"){
            if(b>c){
                b--;
                c++;
                v.emplace_back('C');
            }
            else{
                b++;
                c--;
                v.emplace_back('B');
            }
        }
        else{
            if(c>a){
                c--;
                a++;
                v.emplace_back('A');
            }
            else{
                c++;
                a--;
                v.emplace_back('C');
            }
        }
        if(a<0||b<0||c<0) {
            cout << "No" << endl;
            return;
        }
    }
    */

    if(a>=0&&b>=0&&c>=0){
        cout << "Yes" << endl;
        for(auto e:v){
            cout << e << endl;
        }
    }
    else{
        cout << "No" << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
