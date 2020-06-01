#include <bits/stdc++.h>
using namespace std;

vector<long long> av;
long long n,k,A,B;

long long rec(long long l, long long r)
{
	long long i=lower_bound(av.begin(),av.end(),l)-av.begin();
	long long j=upper_bound(av.begin(),av.end(),r)-av.begin();
	j--;
	long long x=j-i+1;
	long long cost;
	if(x==0)
		cost=A;
	else
		cost=B*x*(r-l+1);
	if(l==r)
		return cost;
	if(x==0)
		return cost;
	long long mid=(l+r)/2;
	long long xx=min(cost, rec(l,mid)+rec(mid+1,r));
	return xx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>A>>B;
	long long i;
	for(i=0;i<k;i++)
	{
		long long val;
		cin>>val;
		av.push_back(val);
	}
	sort(av.begin(),av.end());
	long long x = (long long)1<<n;
	cout<<rec(1,x)<<endl;
	return 0;
}