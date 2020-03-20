import numpy as np

def test(R, C, V, m, n, k):
	R_prime = np.zeros(n + 1)
	C_prime = np.zeros(k)
	V_prime = np.zeros(k)
	print(C_prime)

	for i in range(k):
		R_prime[C[i]] += 1


	for i in range(1, n + 1):
		R_prime[i] += R_prime[i - 1]


	for r in range(m - 1, -1, -1):
		for j in range(R[r+ 1] - 1, R[r] - 1, -1):
			print()
			c = C[j]
			idx = (int)(R_prime[c]) - 1
			R_prime[c] -= 1
			C_prime[idx] = r
			V_prime[idx] = V[j]

	print(R_prime)
	print(C_prime)
	print(V_prime)


R = [0, 2, 3, 5]
C = [1, 3, 2, 0, 1]
V = [9, 1, 1, 3, 8]
m = 3
n = 4
k = 5
test(R,C,V,m,n,k)
