#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

ll n;
vector<ll> a;
vector<ll> ind[25];
vector<ll> op_cnt(25, 0);
vector<vector<ll>> otPr(25, vector<ll> (25));
vector<vector<ll>> stPr(400005, vector<ll> (25)); // till i-1, how many colors j present
vector<ll> dp(3000000,LLONG_MAX);
vector<ll> pp(22, 0);

ll rearrange(vector<ll>& bin, ll clr)
{
	ll i;
	if(sz(ind[clr])==0)
		return 0;
	vector<ll> done, left;
	for(i=0;i<sz(bin);i++)
	{
		if(i==clr-1)
			continue;
		if(bin[i]==1)
			left.pb(i+1);
		else
			done.pb(i+1);
	}
	ll inBw=0;
	ll atSt=0;
	ll curClrStrt = ind[clr][0];
	for(i=0;i<sz(done);i++)
	{
		inBw+=otPr[clr][done[i]];
		atSt+=stPr[curClrStrt][done[i]];
	}
	ll clrCnt = sz(ind[clr]);
	ll ans=op_cnt[clr]-inBw;
	ans+=(clrCnt)*(curClrStrt - atSt);
	return ans;
}

void rec(ll x)
{
	if(dp[x]!=LLONG_MAX)
		return;
	bool allZeros=true;
	vector<ll> bin;
	ll tmpx=x;
	while(tmpx!=0)
	{
		if(tmpx%2==1)
			allZeros=false;
		bin.pb(tmpx%2);
		tmpx/=2;
	}
	if(allZeros)
	{
		dp[x]=0;
		return;
	}
	ll i;
	for(i=0;i<sz(bin);i++)
	{
		if(bin[i]==1)
		{
			rec(x-pp[i]);
			dp[x]=min(dp[x], rearrange(bin, i) + dp[x-pp[i]]);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,j;
	pp[0]=1;
	for(i=1;i<=21;i++)
		pp[i]=2*pp[i-1];
	// vector<ll> firstInd(25, LLONG_MAX);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		ind[val].pb(i);
		// firstInd[val] = min(firstInd[val], i);
	}
	for(i=1;i<=20;i++)
	{
		if(sz(ind[i])==0)
			continue;
		ll cnt=0;
		for(j=1;j<sz(ind[i]);j++)
			cnt+=ind[i][j]-ind[i][0]-j;
		op_cnt[i]=cnt;
	}
	for(i=1;i<=20;i++)
	{
		if(sz(ind[i])==0)
			continue;
		vector<ll> cnt_arr(25, 0);
		ll bacheHue=sz(ind[i])-1;
		for(j=ind[i][0]+1;j<ind[i][sz(ind[i])-1];j++)
		{
			if(a[j]==i)
				bacheHue--;
			else
				cnt_arr[a[j]]+=bacheHue;
		}
		otPr[i]=cnt_arr;
	}
	vector<ll> cnt_arr(25, 0);
	stPr[0]=cnt_arr;
	cnt_arr[a[0]]++;
	for(i=1;i<n;i++)
	{
		stPr[i]=cnt_arr;
		cnt_arr[a[i]]++;
	}
	stPr[n]=cnt_arr;
	rec(pp[20]-1);
	cout<<dp[pp[20]-1]<<endl;
	return 0;
}