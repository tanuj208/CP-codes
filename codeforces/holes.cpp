#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int n,m;
vector<int> power(1000005);
vector<pair<int,int> > x(1000005);
vector<int> l(1000005);
vector<int> r(1000005);
int xx;

//update from ll to rr excluding r
void update(int ll, int rr)
{
	int i;
	for(i=rr-1;i>=ll;i--)
	{
		if(power[i]>(rr-1-i))
		{
			x[i].first=i+power[i];
			x[i].second=1;
		}
		else
		{
			x[i].first=x[i+power[i]].first;
			x[i].second=1+x[i+power[i]].second;
		}
	}
	return;
}

void ans(int p)
{
	int jumps=0;
	int temp;
	while(x[p].first<=n)
	{
		jumps+=x[p].second;
		temp=x[p].first;
		p=temp;
	}
	while(power[p]+p<=n)
	{
		p=power[p]+p;
		jumps++;
	}
	cout<<p<<" "<<jumps+1<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	int i,val;
	for(i=1;i<=n;++i)
		cin>>power[i];
	xx=sqrt(n);
	int temp=1;
	for(i=1;i<=(n/xx);++i)
	{
		l[i]=temp;
		temp+=xx;
		r[i]=temp;
		update(l[i],r[i]);
	}
	l[1+(n/xx)]=temp;
	r[1+(n/xx)]=n+1;
	update(temp,n+1);
	while(m--)
	{
		cin>>val;
		if(val==0)
		{
			int g,h;
			cin>>g>>h;
			power[g]=h;
			int hi=((g-1)/xx)+1;
			update(l[hi],r[hi]);
		}
		if(val==1)
		{
			int g;
			cin>>g;
			ans(g);
		}
	}

	return 0;
}