from pprint import pprint

# taking "i"
letter_one = 'i'
to_replace = 'j'

def create_matrix(key):
    lalpha = [chr(i) for i in range(97, 97+26)]
    lalpha.remove(to_replace)
    key = key.replace(to_replace, letter_one)
    lmat = list(dict.fromkeys(key))
    for c in lalpha:
        if c not in lmat:
            lmat.append(c)
    mat = [lmat[i*5:(i+1)*5] for i in range(0, 5)]
    if __name__ == "__main__":
        print('\nMatrix : -')
        pprint(mat)
    return mat

def split_pt(pt):
    ind = 0
    pt_new = []
    while(ind < len(pt)):
        if(ind == len(pt)-1):
            pt_new.append(f'{pt[ind]}x')
            break
        elif(pt[ind+1] == pt[ind]):
            pt_new.append(f'{pt[ind]}x')
            ind += 1
            continue
        else:
            pt_new.append(pt[ind:ind+2])
            ind += 2
            continue
    if __name__ == "__main__":
        print(f'Split plain text : {pt_new}')
    return(pt_new)

def find(mat, s):
    rno = 0
    for r in mat:
        if s in r:
            r, c = rno, r.index(s)
            return([r, c])
        rno += 1

def map_char(mat, flag, ch1_pos, ch2_pos):
    r1, c1 = ch1_pos[0], ch1_pos[1]
    r2, c2 = ch2_pos[0], ch2_pos[1]
    if(r1 == r2):
        ch1_n = mat[r1][(c1 + flag * 1) % 5]
        ch2_n = mat[r2][(c2 + flag * 1) % 5]
    elif(c1 == c2):
        ch1_n = mat[(r1 + flag * 1) % 5][c1]
        ch2_n = mat[(r2 + flag * 1) % 5][c2]
    else:
        diff = c1 - c2
        ch1_n = mat[r1][c1 - diff]
        ch2_n = mat[r2][c2 + diff]
    return([ch1_n, ch2_n])

def map_matrix(mat, ch1_pos, ch2_pos, operation):
    if(operation == 'e'):
        flag = 1
    else:
        flag = -1
    ch1_n, ch2_n = map_char(mat, flag, ch1_pos, ch2_pos)
    return([ch1_n, ch2_n])

def encrypt(mat, pt):
    ct = []
    for ch in pt:
        ch1_pos = find(mat, ch[0])
        ch2_pos = find(mat, ch[1])
        chs = map_matrix(mat, ch1_pos, ch2_pos, 'e')
        ct.append(''.join(chs))
    return(ct)

def playfair_enc(key, pt):
    mat = create_matrix(key)
    pt = pt.replace(' ', '')
    sec_pt = split_pt(pt)
    ct = encrypt(mat, sec_pt)
    return ct

def decrypt(mat, ct):
    pt = []
    for ch in ct:
        ch1_pos = find(mat, ch[0])
        ch2_pos = find(mat, ch[1])
        chs = map_matrix(mat, ch1_pos, ch2_pos, 'd')
        pt.append(''.join(chs))
    return(pt)

def playfair_dec(key, ct):
    mat = create_matrix(key)
    sec_pt = decrypt(mat, ct)
    return sec_pt

def main():
    print("Enter plain text :-")
    pt = input("> ").lower()
    print("Enter key :-")
    key = input("> ").lower()
    ct = playfair_enc(key, pt)
    print(f'Encrypted text : {ct}')
    sec_pt = playfair_dec(key, ct)
    print(f'Decrypted text : {sec_pt}')


if __name__ == "__main__":
    main()
