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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	vector<pii> del;
	vector<pair<pair<ll,char>,ll> > ins;
	cin>>s;
	ll i;
	ll cntr=0;
	while(s!="E")
	{
		ll x;
		cin>>x;
		if(s=="D")
			del.pb(mp(x,cntr));
		else
		{
			char c;
			cin>>c;
			ins.pb(mp(mp(x,c),cntr));
		}
		cntr++;
		cin>>s;
	}

	vector<ll> deleted;
	map<ll,char> ans;
	ll j=0;

	pbds tobeinserted;
	for(i=0;i<sz(ins);i++)
	{
		ll cntrr=0;
		for(ll kk=i+1;kk<sz(ins);kk++)
			if(ins[kk].first.first<=ins[i].first.first)
				cntrr++;

		ins[i].first.first+=cntrr;
		tobeinserted.insert(ins[i].first.first);
	}


	i=0;
	while(i!=sz(ins) || j!=sz(del))
	{
		if(i==sz(ins))
		{
			ll ind=del[j].first;
			ll xx=tobeinserted.order_of_key(ind);
			ll yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			ll oldxx=0;
			ll oldyy=0;
			while(xx!=oldxx || yy!=oldyy)
			{
				ind+=xx+yy;
				oldyy=yy;
				oldxx=xx;
				xx=tobeinserted.order_of_key(ind);
				yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			}
			ans[ind]='0';
			deleted.pb(ind);
			j++;
			continue;
		}
		if(j==sz(del) || ins[i].second<del[j].second)
		{
			ll ind=ins[i].first.first;

			ans[ind]=ins[i].first.second;
			tobeinserted.erase(ind);
			i++;
		}
		else if(i==sz(ins) || ins[i].second > del[j].second)
		{
			ll ind=del[j].first;
			ll xx=tobeinserted.order_of_key(ind);
			ll yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			ll oldxx=0;
			ll oldyy=0;
			while(xx!=oldxx || yy!=oldyy)
			{
				ind+=xx+yy;
				oldyy=yy;
				oldxx=xx;
				xx=tobeinserted.order_of_key(ind);
				yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			}
			ans[ind]='0';
			deleted.pb(ind);
			j++;
		}
	}

	for(i=0;i<sz(ins);i++)
		if(ans[ins[i].first.first]=='0')
			ans.erase(ins[i].first.first);








	del.clear();
	ins.clear();
	cin>>s;
	cntr=0;
	while(s!="E")
	{
		ll x;
		cin>>x;
		if(s=="D")
			del.pb(mp(x,cntr));
		else
		{
			char c;
			cin>>c;
			ins.pb(mp(mp(x,c),cntr));
		}
		cntr++;
		cin>>s;
	}

	deleted.clear();
	map<ll,char> ans2;
	j=0;

	tobeinserted.clear();
	for(i=0;i<sz(ins);i++)
	{
		ll cntrr=0;
		for(ll kk=i+1;kk<sz(ins);kk++)
			if(ins[kk].first.first<=ins[i].first.first)
				cntrr++;
			
		ins[i].first.first+=cntrr;
		tobeinserted.insert(ins[i].first.first);
	}
	i=0;
	while(i!=sz(ins) || j!=sz(del))
	{
		if(i==sz(ins))
		{
			ll ind=del[j].first;
			ll xx=tobeinserted.order_of_key(ind);
			ll yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			ll oldxx=0;
			ll oldyy=0;
			while(xx!=oldxx || yy!=oldyy)
			{
				ind+=xx+yy;
				oldyy=yy;
				oldxx=xx;
				xx=tobeinserted.order_of_key(ind);
				yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			}
			ans2[ind]='0';
			deleted.pb(ind);
			j++;
			continue;
		}
		if(j==sz(del) || ins[i].second<del[j].second)
		{
			ll ind=ins[i].first.first;

			ans2[ind]=ins[i].first.second;
			tobeinserted.erase(ind);
			i++;
		}
		else if(i==sz(ins) || ins[i].second > del[j].second)
		{
			ll ind=del[j].first;
			ll xx=tobeinserted.order_of_key(ind);
			ll yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			ll oldxx=0;
			ll oldyy=0;
			while(xx!=oldxx || yy!=oldyy)
			{
				ind+=xx+yy;
				oldyy=yy;
				oldxx=xx;
				xx=tobeinserted.order_of_key(ind);
				yy=lower_bound(deleted.begin(),deleted.end(), ind)-deleted.begin();
			}
			ans2[ind]='0';
			deleted.pb(ind);
			j++;
		}
	}

	for(i=0;i<sz(ins);i++)
		if(ans2[ins[i].first.first]=='0')
			ans2.erase(ins[i].first.first);


	if(ans==ans2)
		cout<<0<<endl;
	else
		cout<<1<<endl;


	return 0;
}