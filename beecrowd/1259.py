def main():
    n = int(input())

    impares = []
    pares = []

    for _ in range(n):
        num = int(input())

        if num % 2 == 0:
            pares.append(num)
        else:
            impares.append(num)
    
    pares.sort()
    impares.sort(reverse=True)

    print(*pares, sep="\n")
    print(*impares, sep="\n")

if __name__ == "__main__":
    main()
