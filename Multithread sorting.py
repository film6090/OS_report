import random
from threading import Thread
import threading

def qsort(array,left,right):

    print("thead {0} is sorting {1}".format(threading.current_thread(), array[left:right]))

    i = left
    j = right
    pivot = array[(left + right)//2]
    temp = 0
    while(i <= j):
        while(pivot > array[i]):
            i = i+1
        while(pivot < array[j]):
            j = j-1
        if(i <= j):
            temp = array[i]     
            array[i] = array[j]
            array[j] = temp
            
            i = i + 1
            j = j - 1

    lthread = None
    rthread = None

    if (left < j):
        lthread = Thread(target = lambda: qsort(array,left,j))
        lthread.start()

    if (i < right):
        rthread = Thread(target=lambda: qsort(array,i,right))
        rthread.start()

    if lthread is not None: lthread.join()
    if rthread is not None: rthread.join()
    return array


'''testing below'''
ls = [random.randint(0,100) for i in range(50)]
res = qsort(ls, 0, len(ls) - 1)
print(res)