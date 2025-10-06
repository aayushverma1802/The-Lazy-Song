def fun(*args):
    return sum(args)

print(fun(5,10,15))

def fun(**kwargs):
    for k,val in kwargs.items():
        print(k,val)

fun(a=1,b=2,c=3)
