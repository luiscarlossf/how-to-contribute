def quick_sort(A, p, r):
    i=p
    j=r 
    x = A[int((p+r)/2)]
    while i <= j:
        while A[i] < x:
            i += 1
        while A[j] > x:
            j -= 1
        if i <= j: 
            A[i], A[j] = A[j], A[i]
            i += 1
            j -= 1
    if (p < j):
        quick_sort(A, p, j)
    if (r > i):
        quick_sort(A, i, r)

def insertion_sort(v):
    for i in range(1, len(v)):
        x = v[i]
        j = i - 1
        while j >= 0 and x < v[j]:
            v[j + 1] = v[j]
            j = j - 1
            v[j + 1] = x

def ordenar(v):
    flag = 0
    for i in range(len(v) - 2):
        if not v[i] <= v[i + 1]:
            flag = 1
            break

    if flag == 1:
        quick_sort(v, 0, len(v) - 1)
    else:
        insertion_sort(v)