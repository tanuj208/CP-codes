#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,k,m;
	cin>>n>>k>>m;
	vector<long long> a;
	long long i;
	long long sum = 0;
	long long cur_elem = n;
	for(i=0;i<n;i++)
	{
		long long val;
		cin>>val;
		sum += val;
		a.push_back(val);
	}
	sort(a.begin(),a.end());
	i = 0;
	long long j = n - 1;
	long long cnt = 0;
	while(m--)
	{
		long long x1 = (1 + sum) * (cur_elem - 1);
		long long x2 = (sum - a[i]) * cur_elem;
		if(x1 < x2 && i!=n-1)
		{
			sum-=a[i];
			i++;
			cur_elem --;
		}
		else
		{
			sum++;
			cnt++;
			a[j]++;
			if(cnt==k)
			{
				cnt=0;
				j--;
			}
		}
		if(i>j)
			break;
	}
	double ans = (double)sum/(double)cur_elem;
	printf("%.10lf\n", ans);
	return 0;
}