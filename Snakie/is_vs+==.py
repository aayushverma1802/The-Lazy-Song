a=4 
b='4'

print(a is b) #exact location of object in memory
print(a==b) #value

a=[1,2,43]
b=[1,2,43]

print(a is b) # This is false
print(a==b)  # This is true

a=3
b=3

#But how come in this case the answer of both is same
# Because 3 is a value and immutable 
#Python will not waste the memory and will utilize the same 
# instead of making a new value

a=None
b=None

print(a is b)
print(a is None)
print(a==b)