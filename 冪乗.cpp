ll l[35];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<35; i++){
        l[i] = (l[i-1]*l[i-1]) % MOD;
    }
    /*
    rep(i,35){
        cout << l[i] << " ";
    }
    cout << endl;
    */

    ll tmp = n;
    ll ans = 1;
    rep(i,35){
        if(tmp%2==1){
            ans = (ans*l[i]) % MOD;
        }
        tmp /= 2;
        //cout << ans << " ";
    }
    //cout << endl;
    return ans%MOD;

}