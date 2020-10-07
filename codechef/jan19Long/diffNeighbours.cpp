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
	ll t,i,j;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		if(n==1 && m==1)
		{
			cout<<1<<endl;
			cout<<1<<endl;
		}
		else if(n==1 && m==2)
		{
			cout<<1<<endl;
			cout<<1<<" "<<1<<endl;
		}
		else if(n==2 && m==1)
		{
			cout<<1<<endl;
			cout<<1<<endl;
			cout<<1<<endl;
		}
		else if(n==1)
		{
			cout<<2<<endl;
			for(i=0;i<m;i++)
			{
				if(i%4==1 || i%4==0)
					cout<<1<<" ";
				else
					cout<<2<<" ";
			}
			cout<<"\n";
		}
		else if(m==1)
		{
			cout<<2<<endl;
			for(i=0;i<n;i++)
			{
				if(i%4==1 || i%4==0)
					cout<<1<<"\n";
				else
					cout<<2<<"\n";
			}
		}
		else if(n==2 && m==2)
		{
			cout<<2<<endl;
			cout<<1<<" "<<2<<endl;
			cout<<1<<" "<<2<<endl;
		}
		else if(n==2)
		{
			cout<<3<<endl;
			for(i=0;i<m;i++)
			{
				if(i%3==0)
					cout<<1<<" ";
				else if(i%3==1)
					cout<<2<<" ";
				else
					cout<<3<<" ";
			}
			cout<<"\n";
			for(i=0;i<m;i++)
			{
				if(i%3==0)
					cout<<1<<" ";
				else if(i%3==1)
					cout<<2<<" ";
				else
					cout<<3<<" ";
			}
			cout<<"\n";
		}
		else if(m==2)
		{
			cout<<3<<endl;
			for(i=0;i<n;i++)
			{
				if(i%3==0)
					cout<<1<<" "<<1<<"\n";
				else if(i%3==1)
					cout<<2<<" "<<2<<"\n";
				else
					cout<<3<<" "<<3<<"\n";
			}
		}
		else
		{
			cout<<4<<endl;
			for(i=0;i<n;i++)
			{
				ll cnt;
				if(i%4==0)
					cnt=1;
				else if(i%4==1)
					cnt=2;
				else if(i%4==2)
					cnt=3;
				else
					cnt=4;
				for(j=0;j<m;j++)
				{
					if(j%4==0 || j%4==1)
						cout<<cnt<<" ";
					else
					{
						if(cnt+2==4)
							cout<<4<<" ";
						else
							cout<<(cnt+2)%4<<" ";
					}
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}