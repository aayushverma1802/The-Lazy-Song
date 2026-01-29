f=lambda x,y:x+y

print(f)
print(f(5,6))

# Return the len of the string 
str_len=lambda s:len(s)
print(str_len("Aayush"))
print((lambda s:len("hello"))("hy"))

# Convert a list of integers to their corresponding sqaure values:
numbers= [1,2,3,4,5,6]
squares=list(map(lambda x:x**2,numbers))

print(squares)