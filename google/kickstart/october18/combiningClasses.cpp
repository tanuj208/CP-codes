#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

vector<ll> X,Y,Z;
vector<pii> l,k;
multiset<ll> x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll zzz=1;
	ll i;
	for(zzz=1;zzz<=t;zzz++)
	{
		cout<<"Case #"<<zzz<<": ";
		ll n,q;
		cin>>n>>q;
		ll x1,x2,y1,y2,z1,z2,a1,a2,a3,b1,b2,b3,c1,c2,c3,m1,m2,m3;
		cin>>x1>>x2>>a1>>b1>>c1>>m1;
		cin>>y1>>y2>>a2>>b2>>c2>>m2;
		cin>>z1>>z2>>a3>>b3>>c3>>m3;
		X.clear();
		Y.clear();
		Z.clear();
		l.clear();
		k.clear();
		x.clear();

		X.pb(x1);
		X.pb(x2);
		Y.pb(y1);
		Y.pb(y2);
		Z.pb(z1);
		Z.pb(z2);
		for(i=2;i<n;i++)
		{
			X.pb(((X[i-1]*a1)%m1 + (X[i-2]*b1)%m1 +c1)%m1);
			Y.pb(((Y[i-1]*a2)%m2 + (Y[i-2]*b2)%m2 +c2)%m2);
		}
		for(i=2;i<q;i++)
			Z.pb(((Z[i-1]*a3)%m3 + (Z[i-2]*b3)%m3 +c3)%m3);
		for(i=0;i<n;i++)
			l.pb(mp(max(X[i],Y[i])+1, min(X[i],Y[i])+1));
		for(i=0;i<q;i++)
			k.pb(mp(Z[i]+1,i));
		sort(k.begin(),k.end());
		sort(l.begin(),l.end());
		reverse(l.begin(),l.end());
		ll curk=0;
		ll curRank=1;
		ll ans=0;
		x.insert(l[0].second);
		ll prevr=l[0].first;
		while(k[curk].first==1 && curk<sz(k))
		{
			ans+=(prevr)*(k[curk].second+1);
			curk++;
		}
		if(curk==sz(k))
		{
			cout<<ans<<"\n";
			continue;
		}
		for(i=1;i<n;i++)
		{
			ll curr=l[i].first;
			auto it=x.lower_bound(curr);
			ll flag=0;
			if(it==x.begin())
				flag=1;
			it--;
			auto it2=x.end();
			it2--;
			ll sizee=sz(x);
			for(;it2!=it;it2--)
			{
				ll tmp=curRank + sizee*(prevr-*it2);
				while(k[curk].first<=tmp && curk<sz(k))
				{
					ll tmpp=k[curk].first-curRank;
					ll xxxx=tmpp;
					tmpp/=sizee;
					if(xxxx%sizee==0)
						tmpp--;
					ans+=((prevr-tmpp-1)*(k[curk].second+1));
					curk++;
				}
				if(curk==sz(k))
					break;
				curRank = tmp;
				prevr=*it2;
				sizee--;
			}
			if(curk==sz(k))
				break;
			if(flag==1)
			{
				ll tmp=curRank + sizee*(prevr-*it2);
				while(k[curk].first<=tmp && curk<sz(k))
				{
					ll tmpp=k[curk].first-curRank;
					ll xxxx=tmpp;
					tmpp/=sizee;
					if(xxxx%sizee==0)
						tmpp--;
					ans+=((prevr-tmpp-1)*(k[curk].second+1));
					curk++;
				}
				if(curk==sz(k))
					break;
				curRank = tmp;
				prevr=*it2;
				sizee--;
			}
			if(curk==sz(k))
				break;
			it=x.lower_bound(curr);
			if(it!=x.end())
			{
				auto tmpit=x.end();
				tmpit--;
				while(*tmpit>=*it)
				{
					x.erase(tmpit);
					if(sz(x)==0)
						break;
					tmpit=x.end();
					tmpit--;
				}
			}
			ll tmp = curRank + sizee*(prevr-curr);
			while(k[curk].first<=tmp && curk<sz(k))
			{
				ll tmpp=k[curk].first-curRank;
				ll xxxx=tmpp;
				tmpp/=sizee;
				if(xxxx%sizee==0)
					tmpp--;
				ans+=((prevr-tmpp-1)*(k[curk].second+1));
				curk++;
			}
			if(curk==sz(k))
				break;
			curRank = tmp;
			curRank++;
			while(k[curk].first==curRank && curk<sz(k))
			{
				ans+=(curr)*(k[curk].second+1);
				curk++;
			}
			if(curk==sz(k))
				break;
			x.insert(l[i].second);
			prevr=l[i].first;
		}
		if(curk==sz(k))
		{
			cout<<ans<<"\n";
			continue;
		}
		// cout<<sz(x)<<endl;
		if(sz(x)!=0)
		{
			auto it2=x.end();
			it2--;
			auto it=x.begin();
			ll sizee=sz(x);
			for(;it2!=it;it2--)
			{
				ll tmp=curRank + sizee*(prevr-*it2);
				while(k[curk].first<=tmp && curk<sz(k))
				{
					ll tmpp=k[curk].first-curRank;
					ll xxxx=tmpp;
					tmpp/=sizee;
					if(xxxx%sizee==0)
						tmpp--;
					ans+=((prevr-tmpp-1)*(k[curk].second+1));
					curk++;
				}
				if(curk==sz(k))
					break;
				curRank = tmp;
				prevr=*it2;
				sizee--;
			}
			if(curk!=sz(k))
			{
				ll tmp=curRank + sizee*(prevr-*it2);
				while(k[curk].first<=tmp && curk<sz(k))
				{
					ll tmpp=k[curk].first-curRank;
					ll xxxx=tmpp;
					tmpp/=sizee;
					if(xxxx%sizee==0)
						tmpp--;
					ans+=((prevr-tmpp-1)*(k[curk].second+1));
					curk++;
				}
				curRank = tmp;
				prevr=*it2;
				sizee--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}