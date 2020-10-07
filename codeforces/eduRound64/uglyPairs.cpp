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

void normalP(vector<ll> cnt)
{
	ll i;
	for(i=0;i<26;i++)
	{
		if(cnt[i]<=0)
			continue;
		while(cnt[i]--)
			cout<<char('a'+i);
	}
	cout<<endl;
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
		string s;
		cin>>s;
		vector<ll> cnt(26,0);
		ll i;
		ll length=0;
		bool cons=true;
		for(i=0;i<sz(s);i++)
			cnt[s[i]-'a']++;
		// cout<<cnt[3]<<endl;
		// return 0;
		for(i=0;i<26;i++)
		{
			if(cnt[i]!=0)
				length++;
			if((i!=0 && cnt[i]!=0 && cnt[i-1]!=0))
				continue;
			if(i!=0 && cnt[i]!=0)
				cons=false;
		}
		if(length==1)
			normalP(cnt);
		else if((length==2 || length==3) && cons)
			cout<<"No answer\n";
		else if(length==2)
			normalP(cnt);
		else if(length==3)
		{
			ll ind;
			for(i=0;i<26;i++)
			{
				if(i!=0 && cnt[i]!=0 && cnt[i-1]!=0)
				{
					ind=i;
					while(cnt[i]--)
						cout<<char('a'+i);
				}
			}
			for(i=0;i<26;i++)
			{
				if(abs(i-ind)!=1)
				{
					if(cnt[i]>0)
						while(cnt[i]--)
							cout<<char('a'+i);
				}
			}
			for(i=0;i<26;i++)
				if(cnt[i]>0)
					while(cnt[i]--)
						cout<<char('a'+i);
			cout<<endl;
		}
		else
		{
			ll cur=0;
			for(i=0;i<26;i++)
			{
				if(cnt[i]<=0)
					continue;
				cur++;
				if(cur%2==0)
					while(cnt[i]--)
						cout<<char('a'+i);
			}
			cur=0;
			for(i=0;i<26;i++)
			{
				if(cnt[i]<=0)
					continue;
				while(cnt[i]--)
					cout<<char('a'+i);
			}
			cout<<endl;
		}
	}
	return 0;
}