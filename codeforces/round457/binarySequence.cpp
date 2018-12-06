#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[100005];
ll power,value;

void x(ll val)
{
	power=0;
	value=1;
	while(value<=val)
	{
		value*=2;
		power+=1;
	}
	value/=2;
	power--;
	return;
}

int main()
{
	ll n,k;
	ll i;
	cin>>n>>k;
	// if(n==1)
	// {
	// 	//
	// 	return 0;
	// }
	ll temp=n;
	ll m=0;
	while(temp!=0)
	{
		x(temp);
		temp-=value;
		arr[m]=power;
		m++;
	}
	if(k<m)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	stack <ll> st;
	for(i=m-1;i>=0;i--)
	{
		st.push(arr[i]);
	}
	ll max=0;
	ll count=m;
	ll same=0;
	ll j;
	while(count!=k)
	{
		// cout<<" j";
		same=0;
		max=st.top();
		while(!st.empty() && st.top()==max)
		{
			same++;
			st.pop();
		}
		for(i=1;i<=same;i++)
		{
			st.push(max-1);
			st.push(max-1);
			count++;
			if(count==k)
			{
				for(j=i+1;j<=same;j++)
				{
					st.push(max);
				}
				while(!st.empty())
				{
					cout<<st.top()<<" ";
					st.pop();
				}
				cout<<endl;
				return 0;
			}
		}
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}