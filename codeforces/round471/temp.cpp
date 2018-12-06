#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1e18
set<long long int>arr;
vector<ll> a;
void pre()
{
	//arr.insert(1);
	long long int j ;
	for (ll i = 2; i <= 1000000; ++i)
	{
		j=i*i*i;
		while(j <= M)
		{
			ll x = sqrt(j);
			if (x*x != j)
				arr.insert(j);
			if(M/i<j)break;

			j = j*i;
		}
	}
	for (set<ll>::iterator i = arr.begin(); i != arr.end(); ++i)
	{
		a.push_back(*i);		
	}
	// for(int i = 0 ;i<30;i++)
	// {
	// 	cout << arr[i] << endl;
	// }
	//sort(arr.begin(),arr.end());
} 



int main()
{
	pre();
	int n;
	scanf("%d",&n);
	ll x,y,ans;
	set<ll>::iterator itl,itu;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld",&x,&y);
			// itu = arr.upper_bound(y);
			//  itl = arr.lower_bound(x);
			ll p= lower_bound(a.begin(),a.end(),x)-a.begin();
		 
			  ll z = upper_bound(a.begin(),a.end(),y)-a.begin();
			  ans =z-p;
			  ans += sqrt(y) - (ll)sqrt(x-1);
		cout << ans<<endl;
	}
}