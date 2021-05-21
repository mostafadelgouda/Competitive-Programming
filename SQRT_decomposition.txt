#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define IO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
using namespace std;

const ll mod = 1000000007;
const ll inf = 1e18 + 5;
const ll N = 1e5 + 5;
const ll LG = 21;




int t, n, arr[N], q, sq, pre[N];
int sol(int st, int en){
	int stb = st/sq, enb = en/sq;
	if(stb == enb) return *min_element(arr + st, arr + en + 1);
	int ret = min(*min_element(arr + st, arr + ((stb + 1) * sq)), *min_element(arr + enb*sq, arr + en + 1));
	if(stb + 1 != enb) ret = min(ret, *min_element(pre + stb + 1, pre + enb));
	return ret;
}

int main()
{IO
#ifndef ONLINE_JUDGE
	freopen("out.txt","w",stdout);
	freopen("in.txt","r",stdin);
#else
#endif
	int idx = 0;
	scanf("%d", &n);
	sq = sqrt(n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", arr+i);


	for(int i = 0 ; i < n ; i += sq){
		int sum = INT_MAX;
		for(int j = 0 ; j < sq && i + j < n ; j++){
			sum = min(sum, arr[i + j]);
		}
		pre[idx++] = sum;
	}
	scanf("%d", &q);
	while(q--){
		int x,y;
		scanf("%d%d", &x, &y);
		int ans = sol(x, y);

		printf("%d\n", ans);
	}





    return 0;
}
