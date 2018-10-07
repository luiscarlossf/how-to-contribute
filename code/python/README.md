### playfair_cipher.py
 - Main functions :-
    - `playfair_enc(key,pt)`
        - _arguments_
            - key **[reqd]**
            - pt (_plaintext_) as a _string_ **[reqd]**
        - _returns_
            - list of strings each of length two
    - `playfair_dec(key,ct)`
        - _arguments_
            - key **[reqd]**
            - ct (_ciphertext_) as a _list_ of _strings_ i.e. the _ciphertext_ is split into chunks of length two(result of the `playfair_enc` function) **[reqd]**
        - _returns_
            - list of strings each of length two
   > **NOTE** :
   > - Both parameters passed i.e. key and plaintext/ciphertext have to be in lowercase. This can be done using the `str.lower()` function in python where `str` is the string variable you want to convert to lowercase.
   >  - **[reqd]** states that the parameter/argument is a required one i.e. the function wouldn't work as desired if the **[reqd]** parameter is not passed
   > - For the variable that is being returned, `''.join(list_of_strings)` could be used to just get a concatenated version of the strings. (It hasn't been implemented over here for brevity)

 - **Eg:-**
    ```python
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
    ```

 - **Result :-**
   ```
   Encrypted result = ['kb', 'pn', 'ba', 'vc', 'md', 'si', 'yn', 'gp', 'rc', 'on', 'bn', 'ed', 'pg', 'pu', 'qd', 'cf', 'op', 'xh', 'pd', 'dc', 'di']
   Concatenated Encrypted result : kbpnbavcmdsiyngprconbnedpgpuqdcfopxhpddcdi


   Decrypted result = ['ma', 'nt', 'he', 'wo', 'lf', 'pl', 'ug', 'in', 'fo', 'rp', 'yt', 'ho', 'ni', 'nv', 'sc', 'od', 'ei', 'sx', 'so', 'co', 'ol']
   Concatenated Decrypted result : manthewolfpluginforpythoninvscodeisxsocool
   ```