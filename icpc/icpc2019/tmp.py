import random
t=1
print(t)



stt = "abcdefghijklmnopqrst"
for i in range(t):
	n = 1000000
	k = 100000
	print(n)
	print(k)

	st = ""
	for j in range(n):
		x = random.randint(0,19)
		# print(x)
		st += str(stt[x])
	print(st)

	for hel in range(k):
		y = random.randint(1,20)
		st = ""
		for j in range(y):
			x = random.randint(0,19)
			# print(x)
			st += str(stt[x])
		sttt = set(sorted(st))
		st = list(sttt)
		st=''.join(st)
		print(st)