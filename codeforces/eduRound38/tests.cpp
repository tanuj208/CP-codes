#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)

ll square[100004];

ll search(ll x)
{
	ll i;
	lp(i,1,100000)
	{
		if(square[i]>x)
			return i;
	}
}

ll isperfect(ll x)
{
	ll m=sqrt(x);
	if(m*m==x)
		return 1;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	ll i;
	for(i=1;i<=100000;i++)
		square[i]=i*i;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		if(x==0)
		{
			cout<<"1 1\n";
			continue;
		}
		// if(isperfect(x)==1)
		// {
		// 	cout<<"-1\n";
		// 	continue;
		// }
		i=search(x);
		ll a,b;
		ll j;
		ll c;
		ll flag=0;
		for(j=i;j<=100000;j++)
		{
			if(isperfect(square[j]-x)==1)
			{
				a=sqrt(square[j]);
				b=sqrt(square[j]-x);
				c=a/b;
				if(a/c==b)
				{
					cout<<a<<" "<<c<<endl;
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			cout<<"-1\n";
	}
	return 0;
}
		