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
