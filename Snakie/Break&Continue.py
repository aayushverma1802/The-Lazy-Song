for i in range(19):
    if i==10:
        break
    print("5X",i+1,"=",5*i+1)

print(50*"*")
for i in range(19):
    if i==10:
        continue
    print("5X",i+1,"=",5*i+1)


# Do while loop 
while True:
    print(i)
    i=i+1
    if(i%100==0):
        break