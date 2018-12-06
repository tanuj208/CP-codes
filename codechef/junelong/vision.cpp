#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		long double p1,p2,p3,q1,q2,q3,v1,v2,v3,c1,c2,c3,r;
		cin>>p1>>p2>>p3>>q1>>q2>>q3>>v1>>v2>>v3>>c1>>c2>>c3>>r;
		p1-=c1;
		p2-=c2;
		p3-=c3;
		q1-=c1;
		q2-=c2;
		q3-=c3;
		long double a1=(p2*v3)-(p3*v2);
		long double a2=(p1*v2)-(p2*v1);
		long double a3=(p3*v1)-(p1*v3);

		long double cc1=(p2*q3)-(p3*q2);
		long double cc2=(p1*q2)-(p2*q1);
		long double cc3=(p3*q1)-(p1*q3);

		long double w1=q1-p1;
		long double w2=q2-p2;
		long double w3=q3-p3;

		long double v=v1*v1+v2*v2+v3*v3;
		
		long double a=(a1*a1+a2*a2+a3*a3)-(r*r*v);
		long double b=2*((a1*cc1+a2*cc2+a3*cc3)-(r*r*(w1*v1+w2*v2+w3*v3)));
		long double c=(cc1*cc1+cc2*cc2+cc3*cc3)-((r*r)*(w1*w1+w2*w2+w3*w3));
		if(a==0)
		{
			long double ans=-c/b;
			printf("%0.10Lf\n",ans);
			return 0;
		}
		if(c==0)
		{
			printf("0\n");
			return 0;
		}
		long double tmp=sqrt(b*b-(4*a*c));
		long double tmp1=-b+tmp;
		long double tmp2=-b-tmp;
		long double tt;
		if(tmp1<0 || tmp1>1000000000)
			tt=tmp2/(2*a);
		else if(tmp2<0 || tmp2>1000000000)
			tt=tmp1/(2*a);		
		else
			tt=min(tmp1,tmp2)/(2*a);
		printf("%0.10Lf\n",tt);
	}
	return 0;
}