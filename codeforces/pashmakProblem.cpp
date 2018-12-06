#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

vector<int> segTree[4000055];
vector<int> en(1000000);
vector<int> st(1000000);

vector<int> merge(vector<int> a1, vector<int> a2)
{
	int i,j;
	vector<int> temp;
	i=j=0;
	int n1,n2;
	n1=sz(a1);
	n2=sz(a2);
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			temp.pb(a1[i]);
			i++;
		}
		else
		{
			temp.pb(a2[j]);
			j++;
		}
	}
	while(i<n1)
	{
		temp.pb(a1[i]);
		i++;
	}
	while(j<n2)
	{
		temp.pb(a2[j]);
		j++;
	}
	return temp;
}

void make_segTree(int s,int e,int i)
{
	if(s==e)
	{
		segTree[i].pb(en[s]);
		return;
	}
	int m=(s+e)/2;
	make_segTree(s,m,(i<<1));
	make_segTree(m+1,e,(i<<1)+1);
	segTree[i]=merge(segTree[(i<<1)],segTree[(i<<1)+1]);
}

ll query(int s,int e,int i,int l,int r,int x) //from l to r less than x
{
	if(r<s || l>e)
		return 0;
	if(l<=s && r>=e)
		return (lower_bound(segTree[i].begin(),segTree[i].end(),x)-segTree[i].begin());
	int mid=(s+e)/2;
	ll q1=query(s,mid,(i<<1),l,r,x);
	ll q2=query(mid+1,e,(i<<1)+1,l,r,x);
	return q1+q2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<p > a;
	int i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(mp(val,i+1));
	}
	sort(a.begin(),a.end());
	st[1]=1;
	st[a[0].second]=1;
	for(i=1;i<n;i++)
	{
		if(a[i].first==a[i-1].first)
			st[a[i].second]=st[a[i-1].second]+1;
		else
			st[a[i].second]=1;

	}
	en[n]=1;
	en[a[n-1].second]=1;
	for(i=n-2;i>=0;i--)
	{
		if(a[i].first==a[i+1].first)
			en[a[i].second]=en[a[i+1].second]+1;
		else
			en[a[i].second]=1;
	}
	make_segTree(1,n,1);
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=query(1,n,1,i+1,n,st[i]);
	cout<<ans<<endl;
	return 0;
}