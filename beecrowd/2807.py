memo = {}

def solve(n):
    global memo
    sequence = []

    if n == 1:
        memo[n] = 1
        return [1]
    elif n == 2:
        memo[n - 1] = 1
        memo[n] = 1
        return [1,1]
    elif n not in memo:
        sequence.extend(solve(n - 1))
        memo[n] = memo[n - 1] + memo[n - 2]
        sequence.insert(0, memo[n])
    else:
        for i in range(n):
            sequence.append(memo[n - i ])
    return sequence

def main():
    n = int(input())
    
    print(*solve(n))
       

if __name__ == "__main__":
    main()
