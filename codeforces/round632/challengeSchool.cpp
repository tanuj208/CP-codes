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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll mx_moves  = 0;
	ll i;
	ll cnt=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='R')
			cnt++;
		else
			mx_moves += cnt;
	}
	ll mn_moves=0;
	string t = s;
	while(true)
	{
		bool brk=true;
		bool r_enc=false;
		for(i=0;i<n;i++)
		{
			if(t[i] == 'R')
				r_enc = true;
			else if(t[i] == 'L' && r_enc)
				brk=false;
		}
		if(brk)
			break;
		for(i=0;i<n-1;i++)
		{
			if(t[i]=='R' && t[i+1]=='L')
			{
				swap(t[i], t[i+1]);
				i++;
			}
		}
		mn_moves++;
	}
	if(k<mn_moves || k>mx_moves)
	{
		cout<<-1<<endl;
		return 0;
	}
	t = s;
	bool flag=false;
	ll cur_rem = k;
	ll mx_rem = mx_moves;
	while(cur_rem != 0)
	{
		if(flag)
		{
			ll pp=-1;
			ll r_count = 0;
			for(i=0;i<n;i++)
			{
				if(t[i]=='R')
					r_count++;
				if(t[i]=='R' && pp==-1)
					pp=i;
				if(t[i]=='L' && pp != -1)
				{
					for(ll j=i-1;j>=pp;j--)
						cout<<1<<" "<<j+1<<endl;
					pp++;
				}
			}
			break;
		}
		else
		{
			ll possible_swaps = 0;
			for(i=0;i<n-1;i++)
			{
				if(t[i] == 'R' && t[i+1] == 'L')
				{
					possible_swaps ++;
					i++;
				}
			}
			ll swaps;
			if(mx_rem - possible_swaps > cur_rem - 1)
				swaps = possible_swaps;
			else
			{
				swaps = mx_rem - cur_rem + 1;
				flag = true;
			}
			cout<<swaps<<" ";
			mx_rem -= swaps;
			for(i=0;i<n-1;i++)
			{
				if(swaps==0)
					break;
				if(t[i]=='R' && t[i+1] =='L')
				{
					swaps--;
					cout<<i+1<<" ";
					swap(t[i], t[i+1]);
					i++;
				}
			}
			cout<<endl;
		}
		cur_rem--;
	}
	return 0;
}