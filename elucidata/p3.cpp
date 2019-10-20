#include <bits/stdc++.h>
using namespace std;

double p;

// zero means heads
int coinOutput()
{
	int x=rand()%100;
	if(x<p*100)
		return 0;
	else
		return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>p;
	if(p>=1 || p<=0)
	{
		cout<<"Probability should be between zero to one\n";
		return 0;
	}
  	srand (time(NULL));
  	// Let heads be H and tails be T.
	// getting HT and TH has same probability p(1-p)
	// we can use this fact to divide the problem into getting 1 to 3 and from 4 to 6
	// if we get HT and numbers possible are 1 to 3, if TH then 4 to 6, other than that we will repeat the experiment
	// then again getting HTT, THT and TTH has same probability p(1-p)^2, we can use to decide final number
	int flag1 = -1; // to decide between 1st half and 2nd half
	int flag2 = -1; // to decide between the 3 available numbers
	while(true)
	{
		if(flag1!=-1)
		{
			if(flag2!=-1)
				break;
			int h1=coinOutput();
			int h2=coinOutput();
			int h3=coinOutput();

			int ones=0;
			if(h1==1)
				ones++;
			if(h2==1)
				ones++;
			if(h3==1)
				ones++;
			if(ones!=2)
				continue;

			if(h1==0)
				flag2=0;
			else if(h2==0)
				flag2=1;
			else
				flag2=2;
		}
		else
		{
			int h1=coinOutput();
			int h2=coinOutput();
			if(h1==h2)
				continue;
			else
				flag1=h1;
		}
	}
	if(flag1==0)
	{
		if(flag2==0)
			cout<<1<<endl;
		else if(flag2==1)
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
	else
	{
		if(flag2==0)
			cout<<4<<endl;
		else if(flag2==1)
			cout<<5<<endl;
		else
			cout<<6<<endl;
	}
	return 0;
}