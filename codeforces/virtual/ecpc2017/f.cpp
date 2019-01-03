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
#define pdd pair<ld,ld>
const ll M=5e4+4;
pdd pt[M],p1,p2;
ld X,Y,ansx,ansy;
ld getdist(ld x,ld y,pdd p)
{
	return sqrt((p.ff-x)*(p.ff-x)+(p.ss-y)*(p.ss-y));
}
ld func(ld x,ld y)
{
	return getdist(x,y,p1)+getdist(x,y,p2);
}
ld check(ll p,ll q)
{
	ll i;
	ld l,r,l1,l2;
	if(pt[p].ff==pt[q].ff)
	{
		l=min(pt[p].ss,pt[q].ss);
		r=pt[p].ss+pt[q].ss-l;
		for(i=0;i<200;i++)
		{
			l1=(2*l+r)/3;
			l2=(l+2*r)/3;
			if(func(pt[p].ff,l1)>func(pt[p].ff,l2))
				l=l1;
			else
				r=l2;
		}
		X=pt[p].ff;
		Y=l1;
		return func(pt[p].ff,l1);
	}
	else
	{
		ld m=(pt[p].ss-pt[q].ss)/(pt[p].ff-pt[q].ss);
		ld c=pt[p].ss-pt[p].ff*m;
		l=min(pt[p].ff,pt[q].ff);
		r=pt[p].ff+pt[q].ff-l;
		for(i=0;i<200;i++)
		{
			l1=(2*l+r)/3;
			l2=(l+2*r)/3;
			if(func(l1,m*l1+c)>func(l2,m*l2+c))
				l=l1;
			else
				r=l2;
		}
		X=l1;
		Y=l1*m+c;
		return func(l1,l1*m+c);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("flags.in", "r", stdin);
	ll test,tt,i,j,n;
	cin>>test;
	for(tt=1;tt<=test;tt++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>pt[i].ff>>pt[i].ss;
		}
		ld ans=1e18;
		ll Q;
		cin>>Q;
		cout<<"Case "<<tt<<":\n";
		for(i=0;i<Q;i++)
		{
			cin>>p1.ff>>p1.ss>>p2.ff>>p2.ss;
			ld ans=1e18;
			for(ll j=0;j<n;j++)
			{
				ld vl=check(j,(j+1)%n);
				if(ans>vl)
				{
					ans=vl;
					ansx=X;
					ansy=Y;
				}
			}
			cout<<fixed<<setprecision(7)<<ans;
			cout<<" ";
			cout<<fixed<<setprecision(7)<<ansx;
			cout<<" ";
			cout<<fixed<<setprecision(7)<<ansy;
			cout<<"\n";
		}
	}
}