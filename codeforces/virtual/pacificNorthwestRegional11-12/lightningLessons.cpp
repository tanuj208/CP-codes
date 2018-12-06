#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,i,a[100];
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		ll p=0;
		while(1)
		{
			bool f=0;
			for(i=m;i>=1;i--)
			{
				if(a[i])
					f=1;
			}
			if(f==0)
			{
				for(i=0;i<p;i++)
					cout<<"z";
				cout<<"ap!\n";
				break;
			}
			for(i=m;i>1;i--)
			{
				a[i]=a[i]-a[i-1];
			}
			p++;
			a[p]=0;
			if(p==m-1)
			{
				if(a[m]>0)
				{
					cout<<"*fizzle*\n";
					break;
				}
				if(a[m]<0)
				{
					cout<<"*bunny*\n";
					break;
				}
			}				
		}
	}
	return 0;
}
