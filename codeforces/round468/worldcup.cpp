#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,a,b;
	cin>>n>>a>>b;
	ll totalrounds=0;
	ll temp=n;
	while(temp!=1)
	{
		temp/=2;
		totalrounds++;
	}
	ll rounds=0;
	ll i;
	vector<ll> r(300,-1);
	ll j;
	while(1)
	{
		rounds++;
		for(i=1;i<=n;i++)
		{
			if(r[i]==-1)
			{
				j=i;
				i++;
				while(r[i]!=-1 && i<=n)
					i++;
				if((i==a || i==b) && (j==a || j==b))
				{
					if(rounds==totalrounds)
					{
						cout<<"Final!"<<endl;
						return 0;
					}
					cout<<rounds<<endl;
					return 0;
				}
				if(i==a || i==b)
					r[j]=0;
				else
					r[i]=0;
			}
		}
	}
	return 0;
}