#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int r,u,v,x,y;
	cin>>r>>u>>v>>x>>y;
	double i=sqrt((long long)(u-x)*(long long)(u-x)+(long long)(v-y)*(long long)(v-y));
	int j=ceil(i/(2.0*r));
	cout<<j<<endl;
}