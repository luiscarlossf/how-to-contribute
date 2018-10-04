def maximo(sequencia):
    u"""Recebe uma sequência e retorna o valor máximo."""
    maior = sequencia[0]
    for i in sequencia:
        if maior < i:
            maior = i
    return maior


def minimo(sequencia):
    u"""Recebe uma sequência e retorna o valor mínimo."""
    menor = sequencia[0]
    for i in sequencia:
        if menor > i:
            menor = i
    return menor
