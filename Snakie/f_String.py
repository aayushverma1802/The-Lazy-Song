# formatted string literal
l=[1,2,3,4,5]

for i in l:
    for j in l:
        print(f'({i},{j})')
        
print("""using Format""")
for i in l:
    for j in l:
        print('({},{})'.format(i,j))


        