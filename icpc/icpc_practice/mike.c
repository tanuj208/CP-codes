#include<stdio.h>
int a[100002]={0};
int y[100002]={0};
int dpx[100002];
int dpy[100002];

int f(int x)
{
	if(x==1)
	{
		dpx[x]=a[x];
		return dpx[x];
	}
	else
	{
		if(dpx[y[x]]==-1)
			dpx[y[x]]=f(y[x]);
		if(dpx[y[x]]+1<a[x])
		{
			dpx[x]=a[x];
			return dpx[x];
		}
		else if(dpx[y[x]]+1>=a[x])
		{
			dpx[x]=(dpx[y[x]]+1);
			return dpx[x];
		}
	}
}

int g(int x)
{
	if(x==1)
	{
		dpy[x]=1;
		return dpy[x];
	}
	else
	{
		if(dpx[y[x]]==-1)
			dpx[y[x]]=f(y[x]);
		//printf("%d",dpx[y[x]]);
		if(dpy[y[x]]==-1)
			dpy[y[x]]=g(y[x]);
		if(dpx[y[x]]+1<a[x])
		{
			dpy[x]=1;
			return dpy[x];
		}
		else if(dpx[y[x]]+1>a[x])
		{
			dpy[x]=dpy[y[x]];
			return dpy[x];
		}
		else if(dpx[y[x]]+1==a[x])
		{
			//printf("%d\n",dpy[y[x]]);
			dpy[x]=dpy[y[x]]+1;
			return dpy[x];
		}
	}
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int i;
	int value;
	for(i=0;i<100002;i++)
	{
		dpx[i]=-1;
		dpy[i]=-1;
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=n;i++)
		scanf("%d",&y[i]);
	int x,val;
	int operation;
//	printf("%d",dpx[1]);
	while(q--)
	{
		scanf("%d",&operation);
		if(operation==1)
		{
			scanf("%d",&x);
			printf("%d %d\n",f(x),g(x));
		}
		else if(operation==0)
		{
			scanf("%d %d",&x,&value);
			a[x]=value;
		}
	}
	return 0;
}


