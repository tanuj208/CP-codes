while True:
	n,m,x=input().split()
	n=int(n)
	m=int(m)
	x=int(x)
	if n==0:
		break
	s=((2*x+(m-1)*n)*m)//2
	a=x%m
	b=n%m
	curr=0
	if b==0:
		s=s-(a*m)
		curr=m
	while curr<m:
		t=(m-a)//b;
		if a+t*b>=m:
			t-=1
		t=min(t,m-curr-1)
		s=s-((2*a+t*b)*(t+1))//2
		curr+=t+1
		a=(a+(t+1)*b)%m
	print(int(s//m))
	if n==0:
		break