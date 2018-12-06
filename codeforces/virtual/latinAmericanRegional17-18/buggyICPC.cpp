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

bool isVowel(char c)
{
	if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u')
		return true;
	else
		return false;
}

bool isPalindrome(string s)
{
	ll i;
	for(i=0;i<sz(s);i++)
		if(s[i]!=s[sz(s)-i])
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	vector<ll> arr;
	ll cnt=0;
	ll vowels=0;
	ll i;
	for(i=0;i<sz(s);i++)
	{
		if(isVowel(s[i]))
		{
			vowels++;
			arr.pb(cnt);
			cnt=0;
		}
		else
			cnt++;
	}
	arr.pb(cnt);
	if(vowels==0)
	{
		cout<<1<<endl;
		return 0;
	}
	if(arr[0] != 0 && arr[sz(arr)-1] != 0)
	{
		cout<<0<<endl;
		return 0;
	}
	bool flag=isPalindrome(s);
	if(arr[0]==0 && arr[sz(arr)-1]==0 && flag)
	{
		if(vowels%2==1)
			cout<<1+arr[(vowels/2)+1]<<endl;
		else
			cout<<2+2*arr[vowels/2]<<endl;
		return 0;
	}
	if(vowels%2==0)
	{
		if(arr[0]!=0 && !flag)
			cout<<0<<endl;
		else if((arr[0]==0) || (arr[0]!=0 && flag))
			cout<<arr[vowels/2]+1<<endl;
	}
	else
	{
		if(arr[0]!=0 && !flag)
			cout<<0<<endl;
		else if(arr[0]!=0 && flag)
			cout<<arr[vowels/2]+1<<endl;
		else if(arr[0]==0)
			cout<<arr[(vowels/2)+1]+1<<endl;
	}
	return 0;
}