#include <bits/stdc++.h>
using namespace std;

vector<long long> avengers;
long long n,k,A,B;

// rec(l,r) returns minimum power needed to destroy l to r (inclusive)
long long rec(long long l, long long r)
{
	long long i=lower_bound(avengers.begin(),avengers.end(),l)-avengers.begin();
	long long j=upper_bound(avengers.begin(),avengers.end(),r)-avengers.begin();
	j--;
        // calculating positions of l and r in avengers array to calculate x
	long long x=j-i+1;
	long long power_consumed;
        // if there is no avenger in that subarray
	if(x==0)
		power_consumed=A;
	else
	{
	    power_consumed=B*x*(r-l+1);
            // power consumed for operation 2. (r-l+1 is length of subarray)
	}
        // if l is equal to r or if there is no avenger in the subarray, then do not go into recursion further
	if(l==r || x==0)
		return power_consumed;
	long long mid=(l+r)/2;
	// taking minimum of two operations.
	long long minPower=min(power_consumed, rec(l,mid)+rec(mid+1,r));
	return minPower;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>A>>B;
	int i;
	for(i=0;i<k;i++)
	{
		int val;
		cin>>val;
		avengers.push_back(val);
	}
	sort(avengers.begin(),avengers.end());
	long long x = (long long)1<<n;
	cout<<rec(1,x)<<endl;
	return 0;
}