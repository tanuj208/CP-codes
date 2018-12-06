#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll l[1005],r[1005];
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
		}
		ll time;
		ll queue=0;
		for(i=0;i<n;i++)
		{
			time=l[i];
			if(i!=0)
			{
				if(l[i]!=l[i-1])
					queue-=l[i]-l[i-1];
			}	
			if(queue<0)
				queue=0;
			time+=queue;
			queue++;
			if(time>r[i])
				queue--;
			if(time<=r[i])
			{
				cout<<time<<" ";
			}
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	return 0;
}