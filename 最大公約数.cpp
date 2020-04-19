ll gcd( ll a, ll b )
{
    ll temp;

    if( a < b ) { temp = a; a = b; b = temp; }
    if( b < 1 ) return -1;

    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}