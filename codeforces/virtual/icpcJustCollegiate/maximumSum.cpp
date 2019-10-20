#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n;
ll a[20][20];

ll func(ll i,ll j, vector<pii> last, vector<pii> seclast, vector<pii> cur, ll diag)
{
	if(i<0 || j>=n || diag>=2*n-1 || i>=n || j<0)
		return 0;
	// cout<<i<<" "<<j<<" "<<diag<<endl;
	// for(ll iii=0;iii<sz(cur);iii++)
	// 	cout<<cur[iii].first<<" "<<cur[iii].second<<endl;
	// cout<<"DFLKJ\n";
	vector<pii> tmpa=last,tmpb=seclast,tmpc=cur;
	ll x;
	ll a1=0,a2=0;
	ll ii=i;
	ll jj=j;
	ll flag=0;
	while(true)
	{
		ii--;
		jj++;
		if(ii<0 || jj>=n)
			break;
		if(binary_search(last.begin(),last.end(),mp(ii-1,jj)) || binary_search(last.begin(),last.end(),mp(ii,jj-1)))
			continue;
		if(binary_search(seclast.begin(),seclast.end(),mp(ii-1,jj-1)))
			continue;
		flag=1;
		a1=func(ii,jj,last,seclast,cur,diag);
		break;
	}
	if(flag==0)
	{
		if(i==n-1)
		{
			ii=i;
			jj=1;
		}
		else
		{
			ii=diag+1;
			jj=0;
		}
		seclast=last;
		last=cur;
		cur.clear();
		while(true)
		{
			if(ii<0 || jj>=n)
				break;
			if(binary_search(last.begin(),last.end(),mp(ii-1,jj)) || binary_search(last.begin(),last.end(),mp(ii,jj-1)))
			{
				ii--;
				jj++;
				continue;
			}
			if(binary_search(seclast.begin(),seclast.end(),mp(ii-1,jj-1)))
			{
				ii--;
				jj++;
				continue;
			}
			flag=1;
			a1=func(ii,jj,last,seclast,cur,diag+1);
			break;
		}
		if(flag==0)
		{
			if(i==n-1)
			{
				ii=i;
				jj=2;
			}
			else if(i==n-2)
			{
				ii=n-1;
				jj=1;
			}
			else
			{
				ii=diag+2;
				jj=0;
			}
			seclast=last;
			last=cur;
			cur.clear();
			a1=func(ii,jj,last,seclast,cur,diag+2);
		}
	}
	else
		flag=0;
	last=tmpa;
	seclast=tmpb;
	cur=tmpc;
	cur.pb(mp(i,j));
	ii--;
	jj++;
	a2=a[i][j];
	while(true)
	{
		ii--;
		jj++;
		if(ii<0 || jj>=n)
			break;
		if(binary_search(last.begin(),last.end(),mp(ii-1,jj)) || binary_search(last.begin(),last.end(),mp(ii,jj-1)))
			continue;
		if(binary_search(seclast.begin(),seclast.end(),mp(ii-1,jj-1)))
			continue;
		flag=1;
		a2+=func(ii,jj,last,seclast,cur,diag);
		break;
	}
	if(flag==0)
	{
		if(i==n-1)
		{
			ii=i;
			jj=1;
		}
		else
		{
			ii=diag+1;
			jj=0;
		}
		seclast=last;
		last=cur;
		cur.clear();
		while(true)
		{
			if(ii<0 || jj>=n)
				break;
			if(binary_search(last.begin(),last.end(),mp(ii-1,jj)) || binary_search(last.begin(),last.end(),mp(ii,jj-1)))
			{
				ii--;
				jj++;
				continue;
			}
			if(binary_search(seclast.begin(),seclast.end(),mp(ii-1,jj-1)))
			{
				ii--;
				jj++;
				continue;
			}
			flag=1;
			a2+=func(ii,jj,last,seclast,cur,diag+1);
			break;
		}
		if(flag==0)
		{
			if(i==n-1)
			{
				ii=i;
				jj=2;
			}
			else if(i==n-2)
			{
				ii=n-1;
				jj=1;
			}
			else
			{
				ii=diag+2;
				jj=0;
			}
			seclast=last;
			last=cur;
			cur.clear();
			a2+=func(ii,jj,last,seclast,cur,diag+2);
		}
	}
	return max(a1,a2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,j;
		for(i=0;i<=16;i++)
			for(j=0;j<=16;j++)
				a[i][j]=0;
		cin>>n;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>a[i][j];
		vector<pii> tmp1,tmp2,tmp3;
		cout<<func(0,0,tmp1,tmp2,tmp3,0)<<"\n";
	}
	return 0;
}