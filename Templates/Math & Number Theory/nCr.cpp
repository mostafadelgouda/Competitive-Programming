ll powmod(ll a,ll  b) { if(b==0)return 1;ll cnt=powmod(a,b/2);(cnt*=cnt) %=mod;if(b&1){(cnt*=a) %= mod;}return cnt;}
ll f[MX], inv[MX];
ll ncr(int n, int r)
{
    if(r > n)
        return 0;
    if(n == r)
        return 1;
    return f[n] * (inv[n - r] * inv[r] % mod) % mod;
}
void load(){
    f[0] = 1;
	inv[0] = 1;
	for(int i = 1 ; i < MX ; i++){
		f[i] = f[i - 1] * i % mod;
		inv[i] = powmod(f[i], mod - 2);
	}
}
