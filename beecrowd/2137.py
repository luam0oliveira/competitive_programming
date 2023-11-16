# apesar do python ter um metodo que faz a ordenacao de uma lista, quis impleme
# entar o algoritmo do merge sort para entender seu funcionamento e sua impleme
# ntacao

def merge_sort(lista):
    if len(lista) < 2:
        return
     
    tam_lista = len(lista)
    left_arr = lista[:tam_lista // 2]
    right_arr = lista[tam_lista //2:]

    merge_sort(left_arr)
    merge_sort(right_arr)
    
    # Merge
    i = 0
    j = 0
    k = 0
    
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] < right_arr[j]:
            lista[k] = left_arr[i]
            i += 1
        else:
            lista[k] = right_arr[j]
            j += 1
        k += 1
    
    while i < len(left_arr):
        lista[k] = left_arr[i]
        i += 1
        k += 1
    
    while j < len(right_arr):
        lista[k] = right_arr[j]
        j += 1
        k += 1
    
def solve(lista):
    merge_sort(lista)

def main():
    while True:
        try:
            n = int(input())
            
            lista = []

            for _ in range(n):
                cod = input()
                lista.append(cod)

            # print(*solve(lista), sep="\n")
            solve(lista)
            # lista.sort()
            print(*lista, sep="\n")
        except:
            break   

if __name__ == "__main__":
    main()
