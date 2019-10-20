#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


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

vector<ll> fac[1000005];

vector<ll> divid(ll x)
{
	vector<ll> tmp;
	while(x!=0)
	{
		tmp.pb(x%10);
		x/=10;
	}
	return tmp;
}

ll form(vector<ll> num)
{
	ll i;
	ll ans=0;
	ll cntr=1;
	for(i=0;i<sz(num);i++)
	{
		ans+=(cntr*num[i]);
		cntr*=10;
	}
	return ans;
}

ll formNumber(ll a,ll b, ll digits)
{
	ll fac=1;
	while(digits!=0)
	{
		fac*=10;
		digits--;
	}
	return b+fac*a;
}

bool perfectPower(ll x)
{
	while(x!=1)
	{
		if(x%10!=0)
			return false;
		x/=10;
	}
	return true;
}

ll maxNumber(ll x)
{
	ll ans=0;
	while(x!=0)
	{
		ans*=10;
		ans+=9;
		x--;
	}
	return ans;
}

ll allnine(ll x)
{
	ll ans=0;
	while(x!=0)
	{
		x/=10;
		if(x==0)
			break;
		ans*=10;
		ans+=9;
	}
	return ans;
}

ll prime[1000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("halfnice.in", "r", stdin);
	ll t;
	cin>>t;
	ll i,j;
	for(i=2;i<=1000000;i++)
	{
		if(prime[i]==0)
		{
			for(j=i;j<=1000000;j+=i)
			{
				prime[j]=1;
				fac[j].pb(i);
			}
		}
	}
	for(ll xx=1;xx<=t;xx++)
	{
		ll dgta=0;
		ll digitCnt=0;
		cout<<"Case "<<xx<<": ";
		ll a,b;
		cin>>a>>b;

		vector<ll> tmp=divid(a);
		vector<ll> tmp1;

		for(i=0;i<sz(tmp)/2;i++)
			tmp1.pb(tmp[i]);

		if(sz(tmp)%2==1)
		{
			tmp1.pb(tmp[i]);
			i++;
		}
		dgta=sz(tmp1);

		ll r1=form(tmp1);
		tmp1.clear();

		for(;i<sz(tmp);i++)
			tmp1.pb(tmp[i]);
		ll l1=form(tmp1);

		tmp=divid(b);
		tmp1.clear();
		for(i=0;i<sz(tmp)/2;i++)
			tmp1.pb(tmp[i]);

		if(sz(tmp)%2==1)
		{
			tmp1.pb(tmp[i]);
			i++;
		}
		digitCnt=sz(tmp1);
		ll r2=form(tmp1);


		tmp1.clear();
		for(;i<sz(tmp);i++)
			tmp1.pb(tmp[i]);
		ll l2=form(tmp1);

		ll minRem=1e15;
		// cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
		for(i=0;i<sz(fac[l2]);i++)
		{
			ll x=fac[l2][i];
			minRem=min(r2%x,minRem);
		}
	
		if(r2-minRem>0)
		{
			ll ans=formNumber(l2,r2-minRem, digitCnt);
			if(ans<a)
				cout<<"impossible\n";
			else
				cout<<ans<<"\n";
			continue;
		}
		// else if(r2-minRem<=0 && l1==l2 && dgta == digitCnt)
		// {
		// 	cout<<"impossible\n";
		// 	continue;
		// }
		if(!perfectPower(l2))
		{
			l2--;
			r2=maxNumber(digitCnt);
			if(l2==1)
			{
				ll anss=allnine(b);
				if(anss>a)
					cout<<allnine(b)<<"\n";
				else
					cout<<"impossible\n";
				continue;
			}
			minRem=1e15;
			for(i=0;i<sz(fac[l2]);i++)
			{
				ll x=fac[l2][i];
				minRem=min(r2%x,minRem);
			}
			ll ans=formNumber(l2,r2-minRem, digitCnt);
			if(ans<a || ans>b)
				cout<<"impossible\n";
			else
				cout<<formNumber(l2,r2-minRem, digitCnt)<<"\n";
		}
		else
		{
			ll ans=allnine(b);
			if(ans>=a)
				cout<<allnine(b)<<"\n";
			else
				cout<<"impossible\n";
		}
	}
	return 0;
}