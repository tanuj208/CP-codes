#include <bits/stdc++.h>

using namespace std;

int main()
{
	string brackets;
	cin>>brackets;
	int i,j,open=0,close=0,question=0;
	long long ans=0;
	int flag=0;
	for(i=0;i<(int)brackets.length();i++)
	{
		open=0;
		question=0;
		flag=0;
		for(j=i;j<(int)brackets.length();j++)
		{
			// cout<<open<<" "<<close<<" "<<question<<endl;
			if(brackets[j]=='(')
				open++;
			if(brackets[j]==')')
			{
				open--;
				if(open<0)
					break;
			}
			if(brackets[j]=='?')
				question++;
			// for(int k=i;k<=j;k++)
			// 	cout<<brackets[k];
			// // cout<<" ";
			// // cout<<open<<" "<<question<<endl;
			if(abs(open)>question && open<0)
				break;
			if(open<question && question>0)
			{
				question--;
				open++;	
			}
			if(abs(open)<=question && (question-abs(open))%2==0)
			{
				if(brackets[j]=='(')
					ans--;
				// else
				// {
				// 	for(int k=i;k<=j;k++)
				// 		cout<<brackets[k];
				// 	cout<<endl;
				// }	
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}