import os
import glob

path_name = input('Path name: ')
ext_name = input('Extension name: ')
new_ext = input('The new extension: ')

path = f'{path_name}.{ext_name}'

for path in glob.glob(path):
    rename = path.replace(ext_name, new_ext)
    os.rename(path, rename)

