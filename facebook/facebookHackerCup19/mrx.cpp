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
string s;
map<ll,ll> allot;

ll calc(ll f, ll s, char o)
{
	if((f==0 || f==1) && (s==0 || s==1))
	{
		if(o=='|')
			return f|s;
		else if(o=='&')
			return f&s;
		else
			return f^s;
	}
	if((f==2 || f==3) && (s==2 || s==3))
	{
		if(o=='^' && f!=s)
			return 1;
		else if(o=='^')
			return 0;
		else if(o=='&' && f!=s)
			return 0;
		else if(o=='&')
			return f;
		else if(o=='|' && f!=s)
			return 1;
		else
			return f;
	}
	if(s==2 || s==3)
		swap(f, s);
	if(o=='&')
	{
		if(s==0)
			return 0;
		else
			return f;
	}
	else if(o=='|')
	{
		if(s==1)
			return 1;
		else
			return f;
	}
	else
	{
		if(s==0)
			return f;
		else if(f==2)
			return 3;
		else
			return 2;
	}
}

ll rec(ll st, ll en)
{
	if(s[st]=='(')
	{
		ll tmp=rec(st+1, allot[st]-1);
		ll tmp2=rec(allot[st]+1, en-1);
		ll tmp3=calc(tmp, tmp2, s[allot[st]]);
		return tmp3;
	}
	else
	{
		if(s[st]=='x')
			return 2;
		else if(s[st]=='X')
			return 3;
		else if(s[st]=='0')
			return 0;
		else
			return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll z;
	for(z=1;z<=t;z++)
	{
		allot.clear();
		cout<<"Case #"<<z<<": ";
		cin>>s;
		if(sz(s)==1)
		{
			if(s[0]=='x' || s[0]=='X')
				cout<<1<<endl;
			else
				cout<<0<<endl;
			continue;
		}
		ll i;
		stack<ll> st;
		for(i=0;i<sz(s);i++)
		{
			if(s[i]=='(')
				st.push(i);
			else if(s[i]=='|' || s[i]=='&' || s[i]=='^')
			{
				allot[st.top()]=i;
				st.pop();
			}
		}
		ll x1=rec(1, allot[0]-1);
		ll x2=rec(allot[0]+1, sz(s)-1);
		char op=s[allot[0]];
		if((x1==0 || x1==1) && (x2==0 || x2==1))
		{
			cout<<0<<endl;
			continue;
		}
		if((x1==2 || x1==3) && (x2==2 || x2==3))
		{
			if(op=='^')
				cout<<0<<endl;
			else if(x1!=x2)
				cout<<0<<endl;
			else
				cout<<1<<endl;
			continue;
		}
		if(x2==2 || x2==3)
			swap(x1, x2);
		if(x2==0)
		{
			if(op=='&')
				cout<<0<<endl;
			else
				cout<<1<<endl;
		}
		else if(x2==1)
		{
			if(op=='|')
				cout<<0<<endl;
			else
				cout<<1<<endl;
		}
	}
	return 0;
}