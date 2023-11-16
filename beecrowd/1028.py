def solve(a, b):
    while b != 0:
        a,b = b, a % b
        
    return a

def main():
    cases = int(input())

    for _ in range(cases):
        a, b = [int(i) for i in input().split()]
        a, b = max(a,b), min(a,b)
        
        print(solve(a, b))     

if __name__ == "__main__":
    main()
