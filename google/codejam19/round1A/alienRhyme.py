t = int(input())

for z in range(t):
	x = {}
	n = int(input())
	for i in range(n):
		s = input()
		if s[-1] in x:
			x[s[-1]].append(s)
		else:
			x[s[-1]] = [s]

	ans = 0
	v = 1

	while True:
		v += 1
		key_set = list(x.keys())
		for key in key_set:
			if len(x[key]) == 2:
				ans += 2
				x.pop(key)
			elif len(x[key]) == 1:
				x.pop(key)

		if len(x) == 0:
			break

		key_set = list(x.keys())
		xx = {}
		break_flag = False
		for key in key_set:
			for s in x[key]:
				if v > len(s):
					break_flag = True
					break
				tmp = s[-v:]
				if tmp in xx:
					xx[tmp].append(s)
				else:
					xx[tmp] = [s]
			if break_flag:
				break
		if break_flag:
			break

	q = "Case #" + str(z+1) + ": " + str(ans)
	print(q)




# print(t)