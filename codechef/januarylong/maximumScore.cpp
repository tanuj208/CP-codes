#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void merge(ll l, ll r, ll mid, ll arr[])
{
	ll crr[1000];
	ll a=l;
	ll b=mid+1;
	ll c=0;
	while(a<=mid && b<=r)
	{
		if(arr[a]<arr[b])
		{
			crr[c]=arr[a];
			c++;
			a++;
		}
		else
		{
			crr[c]=arr[b];
			c++;
			b++;
		}
	}
	while(a<=mid)
	{
		crr[c]=arr[a];
		c++;
		a++;
	}
	while(b<=r)
	{
		crr[c]=arr[b];
		b++;
		c++;
	}
	ll i;
	for(i=0;i<c;i++)
	{
		arr[l+i]=crr[i];
	}
	return;
}

void sorte(ll l, ll r, ll arr[])
{
	if(l<r)
	{
		ll mid=(l+r)/2;
		sorte(l,mid,arr);
		sorte(mid+1,r,arr);
		merge(l,r,mid,arr);
	}
	return;
}

int main()
{
	ll t;
	cin>>t;
	ll n,mat[1000][1000];
	ll i,j;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>mat[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			sorte(0,n-1,mat[i]);
		}
		ll ans=0;
		ll max=mat[n-1][n-1];
		ans=max;
		if(n==1)
		{
			cout<<mat[n-1][n-1]<<endl;
			continue;
		}
		// cout<<max<<endl;
		ll flag=0;
		ll index=n;
		for(i=n-2;i>=0;i--)
		{
			flag=0;
			for(j=n-1;j>=0;j--)
			{
				if(mat[i][j]<max)
				{
					max=mat[i][j];
					ans+=max;
					flag=1;
					index=j;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"-1"<<endl;
				break;
			// 	i++;
			// 	if(i>=n)
			// 	{
			// 		cout<<"-1"<<endl;
			// 		return 0;
			// 	}
			// 	index--;
			// 	if(index<0)
			// 	{
			// 		cout<<"-1"<<endl;
			// 		return 0;
			// 	}
			// 	max=mat[i][index];
			 }
		}
		if(flag==0)
			continue;
		cout<<ans<<endl;
	}
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 	{
	// 		cout<<mat[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}