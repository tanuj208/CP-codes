#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int i;
		int array[200005];
		ll totalsum=0;
		for(i=0;i<n;i++)
		{
			cin>>array[i];
			totalsum+=array[i];
		}
		for(i=n;i<2*n;i++)
		{
			array[i]=array[i-n];
		}
		// for(i=0;i<2*n;i++)
		// {
		// 	cout<<array[i]<<" ";
		// }
		// cout<<endl;
		ll max=0;
		int j=1;
		ll sum1=0;
		ll sum2=0;
		int negative[200005];
		int flag=0;
		int neg;
		int m=0;
		int x;
		for(i=0;i<2*n;i++)
		{
			// cout<<sum1<<" "<<sum2<<endl;
			if(array[i]<0 && flag==0)
			{
				neg=-array[i];
				flag=1;
				continue;
			}
			if(array[i]<0 && flag==1)
			{
					flag=1;
				if(sum1>=neg && sum2>=neg)
				{
					negative[m]=1;
					m++;
				}
				if(sum1<neg || sum2<neg)
				{
					negative[m]=0;
					m++;
				}
				sum1=sum2;
				sum2=0;
				neg=-array[i];
			}
			if(flag==0 && array[i]>=0)
			{
				sum1+=array[i];
			}
			if(flag==1 && array[i]>=0)
			{
				sum2+=array[i];
			}
			if(i==2*n-1 && array[2*n-1]>=0)
			{
				if(sum1>=neg && sum2>=neg)
				{
					negative[m]=1;
					m++;
				}
				if(sum1<neg || sum2<neg)
				{
					negative[m]=0;
					m++;
				}
			}
			if(i==n-1)
			{
				x=negative[m-1];
			}
			if(i==2*n-1 && array[2*n-1]<0)
			{
				negative[m]=x;
				m++;
			}
		}
		// for(i=0;i<m;i++)
		// 	cout<<negative[i]<<" ";
		// cout<<endl;
		flag=0;
		for(i=0;i<m;i++)
		{
			if(negative[i]==0)
			{
				flag=1;
				break;
			}
		}
		// cout<<flag<<endl;
		if(flag==0)
		{
			cout<<(ll)k*(ll)totalsum<<endl;
			continue	;
		}
		ll sum=0;
		int len=m;
		m=0;
		ll maximum=0;
		for(i=0;i<2*n;i++)
		{
			if(array[i]>=0)
				sum+=array[i];
			if(array[i]<0 && negative[m]==1)
			{
				sum+=array[i];
				m++;
			}
			if(array[i]<0 && negative[m]==0)
			{
				m++;
				if(maximum<sum)
					maximum=sum;
				sum=0;
			}
		}
		cout<<maximum<<endl;
		// for(it=array.begin();it!=array.end();it++)
		// {
		// 	cout<<*it<<" ";
		// }
		// cout<<endl;
	}
	return 0;
}