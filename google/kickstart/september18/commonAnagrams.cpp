#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll cnt[26] = {0};
ll cntt[26];

void resett()
{
	ll i;
	for(i=0;i<26;i++)
		cnt[i]=0;
	return;
}

void ee()
{
	ll i;
	for(i=0;i<26;i++)
		cntt[i]=cnt[i];
	return;
}

bool cc()
{
	ll i;
	for(i=0;i<26;i++)
	{
		if(cntt[i]!=0)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll z=1;
	for(z=1;z<=t;z++)
	{
		ll l;
		cin>>l;
		string a,b;
		cin>>a>>b;
		ll i,j,k,m;
		ll ans=0;
		cout<<"Case #"<<z<<": ";
		for(i=0;i<sz(a);i++)
		{
			resett();
			for(j=i;j<sz(a);j++)
			{
				cnt[a[j]-'A']++;
				for(k=0;k<sz(b);k++)
				{
					ee();
					for(m=k;m<sz(b);m++)
					{
						cntt[b[m]-'A']--;
						if(cc()==true)
						{
							ans++;
							break;
						}
						if(cntt[b[m]-'A']<0)
							break;
					}
					if(cc()==true)
						break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}