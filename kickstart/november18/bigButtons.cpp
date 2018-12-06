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

typedef struct xx{
	struct xx* ptr[2];
	bool end;
}node;

node *nnode()
{
	node *temp = (node *)malloc(sizeof(node));
	temp->end=false;
	ll i;
	for(i=0;i<2;i++)
		temp->ptr[i]=NULL;
	return temp;
}

node *insert(node *head, string s)
{
	ll i;
	node *temp=head;
	for(i=0;i<sz(s);i++)
	{
		ll x;
		if(s[i]=='B')
			x=0;
		else
			x=1;
		if(head->ptr[x]==NULL)
			head->ptr[x]=nnode();
		head=head->ptr[x];
	}
	head->end=true;
	return temp;
}

vector<ll> p;
ll n;

ll calc(node *head, ll cntr)
{
	ll i;
	ll ans=0;
	for(i=0;i<2;i++)
	{
		if(head->ptr[i]!=NULL && !head->ptr[i]->end)
		{
			ll x=calc(head->ptr[i], cntr-1);
			ans+=x;
		}
		else if(head->ptr[i]==NULL)
			ans+=p[cntr-1];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll z;
	ll t;
	cin>>t;
	ll i;
	p.pb(1);
	for(i=1;i<=55;i++)
		p.pb(p[i-1]*2);
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		node *head=nnode();
		ll pp;
		cin>>n>>pp;
		for(i=0;i<pp;i++)
		{
			string s;
			cin>>s;
			head=insert(head, s);
		}
		cout<<calc(head, n)<<"\n";
	}
	return 0;
}