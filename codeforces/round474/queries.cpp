#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

ll level(ll x)
{
	ll l=0;
	while(x!=0)
	{
		x=x/2;
		l++;
	}
	return l;
}

ll arr[100]={0};
ll two[100]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin>>q;
	two[0]=1;
	ll i;
	for(i=1;i<=60;i++)
		two[i]=two[i-1]*2;
	while(q--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll x,k;
			cin>>x>>k;
			ll l=level(x);
			ll mod=two[l-1];
			arr[l]+=k;
			ll xx=abs(arr[l])/mod;
			arr[l]=(arr[l]+mod*xx+mod)%mod;
		}
		if(t==2)
		{
			ll x,k;
			cin>>x>>k;
			ll l=level(x);
			for(i=l;i<=60;i++)
			{
				ll mod=two[i-1];
				arr[i]+=k;
				ll xx=abs(arr[i])/mod;
				arr[i]=(arr[i]+mod+mod*xx)%mod;
				k*=2;
			}
		}
		if(t==3)
		{
			ll x;
			cin>>x;
			cout<<x<<" ";
			ll l=level(x);
			x+=arr[l];
			if(x>=two[l])
				x=x%two[l]+two[l-1];
			while(x>1)
			{
				x=x/2;
				l--;
				ll temp=x;
				ll temp1=-arr[l];
				temp1=(temp1+two[l-1])%two[l-1];
				temp+=temp1;
				if(temp>=two[l])
					temp=temp%two[l]+two[l-1];
				cout<<temp<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}