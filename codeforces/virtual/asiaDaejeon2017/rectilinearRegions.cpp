#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ll> xl,yl,xu,yu;
	ll i;
	for(i=0;i<2*n+1;i++)
	{
		ll val;
		cin>>val;
		if(i%2==0)
			yl.pb(val);
		else
			xl.pb(val);		
	}
	for(i=0;i<2*m+1;i++)
	{
		ll val;
		cin>>val;
		if(i%2==0)
			yu.pb(val);
		else
			xu.pb(val);		
	}
	ll j=0;
	i=0;
	ll curArea=0;
	ll ans=0;
	ll areas=-1;
	ll flag=0;
	ll anFlag=0;
	ll lastX;
	while(i<n+1 && j<m+1)
	{
		// cout<<i<<" "<<j<<endl;
		// cout<<flag<<endl;
		// cout<<xl[i]<<" "<<xu[i]<<" "<<yl[i]<<" "<<yu[i]<<endl;
		// cout<<yl[i]<<" "<<yu[j]<<" "<<flag<<endl;
		if(yl[i]<yu[j] && flag!=0)
		{
			anFlag=0;
			if(j==m)
			{
				// cout<<i<<" "<<j<<endl;
				if(i==n && j==m+1)
					break;
				if(j==m+1)
				{
					i++;
					continue;
				}
				else if(i==n)
				{
					j++;
					continue;
				}
				// cout<<xl[i]<<" "<<xl[i-1]<<endl;
				curArea+=(yu[j]-yl[i])*(xl[i]-lastX);
				lastX=xl[i];
				i++;
				continue;
			}
			else
			{				
				// cout<<i<<" "<<j<<endl;
				if(i==n+1 && j==m)
					break;
				if(j==m)
				{
					i++;
					continue;
				}
				else if(i==n+1)
				{
					j++;
					continue;
				}
				curArea+=(yu[j]-yl[i])*(xu[j]-lastX);
				lastX=xu[j];
				j++;
				continue;
			}
			if(xl[i]<=xu[j])
			{
				// cout<<i<<" "<<j<<endl;
				if(i==n && j==m+1)
					break;
				if(j==m+1)
				{
					i++;
					continue;
				}
				else if(i==n)
				{
					j++;
					continue;
				}
				curArea+=(yu[j]-yl[i])*(xl[i]-xl[i-1]);
				i++;
			}
			else
			{
				if(i==n+1 && j==m)
					break;
				if(j==m)
				{
					i++;
					continue;
				}
				else if(i==n+1)
				{
					j++;
					continue;
				}
				curArea+=(yu[j]-yl[i])*(xu[j]-xu[j-1]);
				j++;
			}
		}
		else if(yu[j]<=yl[i])
		{
			if(i==n && j==m)
				break;
			if(j==m)
			{
				i++;
				continue;
			}
			else if(i==n)
			{
				j++;
				continue;
			}
			if(xl[i]<=xu[j])
				i++;
			else
				j++;
		}
		else if(yu[j]>yl[i] && flag==0)
		{
			// cout<<"DKJFDLF\n";
			lastX=xl[i-1];
			ans+=curArea;
			areas++;
			curArea=0;
			flag=1;
			anFlag=1;
			if(i==n && j==m)
				break;
			if(j==m)
			{
				i++;
				continue;
			}
			else if(i==n)
			{
				j++;
				continue;
			}
			if(xl[i]<=xu[j])
				i++;
			else
				j++;
		}
	}
	cout<<areas<<" "<<ans<<endl;
	return 0;
}