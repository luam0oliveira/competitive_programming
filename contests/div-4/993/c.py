t = int(input())

for i in range(t):
    n,a,b,c = map(int,input().split())
    
    sum = min(a,n)
    sum += min(b, n)
    sum += min(c, 2*n - sum)
    print(sum)