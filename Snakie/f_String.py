# formatted string literal
l=[1,2,3,4,5]

for i in l:
    for j in l:
        print(f'({i},{j})')
        
print("""using Format""")
for i in l:
    for j in l:
        print('({},{})'.format(i,j))


    
name="aayush"
age=18
print(f"hello my name is {name} and age is {age}")
print(f"hello my name is {{name}} and age us {{age}}")