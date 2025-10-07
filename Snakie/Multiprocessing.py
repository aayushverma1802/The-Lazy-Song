import multiprocessing

def print_cube(num):
    """
    function to print cube of given num
    """
    print("Cube : {}".format(num*num*num))

def print_squre(num):
    """
    function to print square of the given num
    """
    print("Square: {}".format(num*num))

if __name__=="__main__":
    #creating prcosses
    p1=multiprocessing.Process(target=print_squre,args=(10,))
    p2=multiprocessing.Process(target=print_cube,args=(10,))

    #Starting process 1
    p1.start()
    #Starting process 2
    p2.start()
    #wait until the process 2 is finished
    p2.join()

    #both process finised
    print("Done!")

