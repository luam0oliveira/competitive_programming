a,b = map(int, input().split())
c = list(map(int, input().split()))
d = {}
visited = [0] * a

for i in range(a):
    if c[i] - b >= 0:
        if (not (c[i] - b) in d):
            d[i - b] = []
        

        d[c[i]-b].append((i+1))
    if (not (c[i] + b) in d):
        d[c[i] + b] = []
    
    d[c[i] + b].append(-(i+1))


count = 0
for i in d:
    d[i].sort()
    for j in range(len(d[i])): 
        if (visited[abs(d[i][j]) - 1]): continue; 
        if (d[i][j] > 0):
            visited[d[i][j]-1] = 1
            count += 1
            break
        else:
            visited[abs(d[i][j])-1] = 1
            count += 1
            break
print(count)

    