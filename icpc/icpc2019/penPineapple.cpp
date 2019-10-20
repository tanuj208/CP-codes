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

vector<ll> arr(1100005, -1);

void rec(bitset<20> x, ll penNumber)
{
	// cout<<x<<" "<<penNumber<<endl;
	ll y = x.to_ulong();
	if(arr[y]!=-1)
		return;
	arr[y]=penNumber;
	ll i;
	for(i=0;i<sz(x);i++)
	{
		if(x.test(i))
		{
			x.reset(i);
			rec(x, penNumber);
			x.set(i);
		}
	}
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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll i;
		for(i=0;i<=1100000;i++)
			arr[i]=-1;
		for(i=0;i<k;i++)
		{
			string s2;
			cin>>s2;
			bitset<20> tmp;
			for(ll j=0;j<sz(s2);j++)
				tmp.set(s2[j]-'a');
			// cout<<tmp<<endl;
			rec(tmp, i+1);
		}
		bitset<20> cur;
		vector<ll> ans;
		ll curPen;
		for(i=0;i<sz(s);i++)
		{
			cur.set(s[i]-'a');
			// cout<<cur<<endl;
			// cout<<arr[cur.to_ulong()]<<endl;
			if(arr[cur.to_ulong()]==-1)
			{
				cur.reset();
				cur.set(s[i]-'a');
				while(sz(ans)<i)
					ans.pb(curPen);
				curPen=arr[cur.to_ulong()];
			}
			else
				curPen=arr[cur.to_ulong()];
		}
		while(sz(ans)<n)
			ans.pb(curPen);
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}