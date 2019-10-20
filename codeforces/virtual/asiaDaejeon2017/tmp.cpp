#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"
const ll N=1e6+5,inf=1e10;

ll z[N];
void zalgo(vll s)
{
	ll l=-1,r=-1,n=s.size();
	lp(i,1,n)
	{
		if(r<i)
		{
			l=r=i;
			while(r<n && s[r-l] == s[r])r++;
			r--; 
			z[i]=r-l+1;
		}
		else
		{
			ll k=i-l;
			if(z[k]<r-i+1)	z[i]=z[k];
			else
			{
				l = i;
				while(r<n && s[r-l]==s[r]) r++;
				r--;
				z[i]=r-i+1;
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n;
	cin >> n;
	vll s;
	lp(i,0,n)
	{
		ll a;
		cin >> a;
		s.pb(a);
	}
	reverse(s.begin(),s.end());
	zalgo(s);
	ll ans=inf,p=1,k=n-1;
	lp(i,0,n)
	{
		if(ans>n-z[i])
		{
			ans=n-z[i];
			p=i;
			k=n-z[i]-i;
		}
	}
	cout<<k<<" "<<p<<endl;
	return 0;
}