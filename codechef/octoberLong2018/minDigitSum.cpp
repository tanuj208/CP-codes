#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll digitSum(ll x)
{
	if(x<10)
		return x;
	ll w=0;
	while(x!=0)
	{
		w+=x%10;
		x/=10;
	}
	return w;
}

pii absDigitSum(ll x, ll op)
{
	if(x<10)
		return mp(x,op);
	ll w=0;
	while(x!=0)
	{
		w+=x%10;
		x/=10;
	}
	if(w<10)
		return mp(w,op+1);
	else
		return absDigitSum(w,op+1);
}

ll ans=INT_MAX;
ll op=0;

void func(ll n,ll d,ll cntr)
{
	pii tmp=absDigitSum(n,0);
	if(ans>tmp.first)
	{
		ans=tmp.first;
		op=cntr+tmp.second;
	}
	else if(ans==n)
		op=min(op,cntr);
	if(cntr>10)
		return;
	if(n!=digitSum(n))
		func(digitSum(n),d,cntr+1);
	func(n+d,d,cntr+1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		ans=n;
		op=0;
		func(n,d,0);
		cout<<ans<<" "<<op<<endl;
	}
	return 0;
}