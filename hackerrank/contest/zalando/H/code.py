# A[] is the original array
# ft[] is the fenwick tree maintaining the diffs initialized with 0
 
# Add v to A[p]
def update(p, v):
  for (; p <= N; p += p&(-p))
    ft[p] += v 	 

# Add v to A[a...b] 
def update(a, b, v):     
  update(a, v)     
  update(b + 1, -v)  	 

# Return A[b]	 
def query(b):     
  sum = 0     
  for(; b > 0; b -= b&(-b))
    sum += ft[b]
  return sum + A[b]