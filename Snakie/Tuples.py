tup=(1,2,3,4,5,6,"green")
print(type(tup),tup)

if 6 in tup:
    print("Yes 6 is present in tuple")

# Tuple is immutable so this just makes a new tuple 
# When we use the slicing method
tup2=tup[1:4]
print(tup2)

# tuple operations 
tuple1=(0,1,2,3,4,23,2,34,4,3,3,3,8,2)
res1=tuple1.count(3)
res2=tuple1.index(3,4,12)
# index(value, start, end)
print("Count of 3 in tuple1 is:",res1)
print("Indeex of 3 in tuple2 is:",res2)
