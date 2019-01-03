#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

ll ans[100005];

void func4(ll st)
{
	ll A,B,C,D;
	cout<<"1 "<<st<<" "<<st+1<<" "<<st+2<<"\n";
	fflush(stdout);
	cin>>A;

	cout<<"1 "<<st+1<<" "<<st+2<<" "<<st+3<<"\n";
	fflush(stdout);
	cin>>B;

	cout<<"1 "<<st<<" "<<st+1<<" "<<st+3<<"\n";
	fflush(stdout);
	cin>>C;

	cout<<"1 "<<st<<" "<<st+2<<" "<<st+3<<"\n";
	fflush(stdout);
	cin>>D;

	// cout<<(A^C^D)<<endl;

	ans[st]=A^C^D;
	// cout<<st<<" "<<(A^C^D)<<" "<<ans[st]<<endl;
	ans[st+3]=A^B^ans[st];
	ans[st+2]=D^ans[st]^ans[st+3];
	ans[st+1]=C^ans[st]^ans[st+3];
	// cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<endl;
	return;
}

void func5(ll st)
{
	ll a,b,c,d,e;

	cout<<"1 "<<st<<" "<<st+1<<" "<<st+2<<"\n";
	fflush(stdout);
	cin>>a;

	cout<<"1 "<<st+1<<" "<<st+2<<" "<<st+3<<"\n";
	fflush(stdout);
	cin>>b;

	cout<<"1 "<<st+2<<" "<<st+3<<" "<<st+4<<"\n";
	fflush(stdout);
	cin>>c;

	cout<<"1 "<<st+3<<" "<<st+4<<" "<<st<<"\n";
	fflush(stdout);
	cin>>d;

	cout<<"1 "<<st+4<<" "<<st<<" "<<st+1<<"\n";
	fflush(stdout);
	cin>>e;

	ans[st+2]=b^d^e;
	ans[st+1]=a^c^d;
	ans[st]=a^ans[st+1]^ans[st+2];
	ans[st+3]=b^ans[st+1]^ans[st+2];
	ans[st+4]=c^ans[st+2]^ans[st+3];
	return;
}

void func6(ll st)
{
	ll a,b,c,d,e,f;

	cout<<"1 "<<st<<" "<<st+2<<" "<<st+3<<"\n";
	fflush(stdout);
	cin>>a;

	cout<<"1 "<<st+1<<" "<<st+3<<" "<<st+4<<"\n";
	fflush(stdout);
	cin>>b;

	cout<<"1 "<<st+2<<" "<<st+4<<" "<<st+5<<"\n";
	fflush(stdout);
	cin>>c;

	cout<<"1 "<<st+3<<" "<<st+5<<" "<<st<<"\n";
	fflush(stdout);
	cin>>d;

	cout<<"1 "<<st+4<<" "<<st<<" "<<st+1<<"\n";
	fflush(stdout);
	cin>>e;

	cout<<"1 "<<st+5<<" "<<st+1<<" "<<st+2<<"\n";
	fflush(stdout);
	cin>>f;

	ans[st+4]=a^c^d;
	ans[st+5]=b^d^e;
	ans[st]=c^e^f;
	ans[st+2]=c^ans[st+4]^ans[st+5];
	ans[st+1]=e^ans[st]^ans[st+4];
	ans[st+3]=d^ans[st]^ans[st+5];
	return;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i=0;
		cin>>n;
		if(n%4==0)
		{
			for(i=0;i<n;i+=4)
				func4(i+1);
		}
		else if(n%4==1)
		{
			func5(i+1);
			i+=5;
			for(;i<n;i+=4)
				func4(i+1);
		}
		else if(n%4==2)
		{
			func6(i+1);
			i+=6;
			for(;i<n;i+=4)
				func4(i+1);
		}
		else
		{
			func5(i+1);
			i+=5;
			func6(i+1);
			i+=6;
			for(;i<n;i+=4)
				func4(i+1);
		}
		cout<<"2 ";
		for(i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		ll verdict;
		cin>>verdict;
		if(verdict==-1)
			break;
	}
	return 0;
}