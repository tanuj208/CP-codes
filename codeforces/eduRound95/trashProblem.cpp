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

set<ll> cor;
set<pair<ll,pii>> diff;

ll get_ans()
{
	if(sz(cor) <= 2)
		return 0;
	ll min_cor = *(cor.begin());
	ll max_cor = *(cor.rbegin());
	auto it = diff.rbegin();
	ll x = (it->ss).ff;
	ll y = (it->ss).ss;
	return x - min_cor + max_cor - y;
}

void insert(ll x)
{
	if(sz(cor) == 0)
	{
		cor.insert(x);
		return;
	}
	if(sz(cor) == 1)
	{
		cor.insert(x);
		auto it = cor.begin();
		ll tmp = *it;
		it++;
		ll tmp2 = *it;
		diff.insert(mp(tmp2-tmp, mp(tmp, tmp2)));
		return;
	}
	ll min_cor = *(cor.begin());
	ll max_cor = *(cor.rbegin());
	if(x < min_cor)
	{
		cor.insert(x);
		diff.insert(mp(min_cor-x, mp(x, min_cor)));
		return;
	}
	else if(x > max_cor)
	{
		cor.insert(x);
		diff.insert(mp(x-max_cor, mp(max_cor, x)));
		return;
	}
	auto it = cor.lower_bound(x);
	ll tmp2 = *it;
	it--;
	ll tmp1 = *it;
	cor.insert(x);
	diff.erase(mp(tmp2-tmp1, mp(tmp1, tmp2)));
	diff.insert(mp(x - tmp1, mp(tmp1, x)));
	diff.insert(mp(tmp2-x, mp(x, tmp2)));
	return;
}

void erase(ll x)
{
	if(sz(cor) == 1)
	{
		cor.erase(x);
		return;
	}
	else if(sz(cor) == 2)
	{
		cor.erase(x);
		diff.clear();
		return;
	}
	ll min_cor = *(cor.begin());
	ll max_cor = *(cor.rbegin());
	if(x == min_cor)
	{
		cor.erase(x);
		ll tmp = *(cor.begin());
		diff.erase(mp(tmp-x, mp(x, tmp)));
		return;
	}
	else if(x == max_cor)
	{
		cor.erase(x);
		ll tmp = *(cor.rbegin());
		diff.erase(mp(x-tmp, mp(tmp, x)));
		return;
	}
	auto it = cor.find(x);
	it--;
	ll tmp1 = *it;
	it++;
	it++;
	ll tmp2 = *it;
	diff.erase(mp(x-tmp1, mp(tmp1, x)));
	diff.erase(mp(tmp2-x, mp(x, tmp2)));
	diff.insert(mp(tmp2-tmp1, mp(tmp1, tmp2)));
	cor.erase(x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		cor.insert(val);
	}
	auto it = cor.begin();
	ll cur = *it;
	it++;
	for(;it != cor.end();it++)
	{
		ll d = (*it - cur);
		diff.insert(mp(d, mp(cur, *it)));
		cur = *it;
	}
	cout<<get_ans()<<endl;
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		if(x==0)
			erase(y);
		else
			insert(y);
		cout<<get_ans()<<endl;
	}
	return 0;
}
