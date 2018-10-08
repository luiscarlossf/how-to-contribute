from playfair_cipher import playfair_enc, playfair_dec
s = "man the wolf plugin for python in vscode is so cool"
k = "yeahbro"

encrypted_result = playfair_enc(k, s)
print(f'Encrypted result = {encrypted_result}')
print(f'Concatenated Encrypted result : {"".join(encrypted_result)}')

print('\n')

decrypted_result = playfair_dec(k, encrypted_result)
print(f'Decrypted result = {decrypted_result}')
print(f'Concatenated Decrypted result : {"".join(decrypted_result)}')
