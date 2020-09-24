"""
Author: Etienne Cárdenas Wertheimer
Date: 11-09-2020
Description:

The following program allow you to test four different implementations of the bubble sort algorithm
,given a simple list, in which you can see graphically how efficient is it in time

Every function return a sorted list "l" and "n" times that the function swap two values
"""

import matplotlib.pyplot as plt

def bubbleSort1(l): #N Iters => i = n = i*j = n*n = n^2
    n = 0
    for i in range(0, len(l)):
        for j in range(0, len(l)):
            if(l[i] < l[j]): 
                l[i], l[j] = l[j], l[i] 
                n += 1

    return l, n


def bubbleSort2(l): #N Iters => n + (n-1) + (n-2) + ... + 2 + 1 = n(n+1)/2
    n = 0
    for i in range(0, len(l)):
        for j in range(i, len(l)):
            if(l[i] > l[j]): 
                l[i], l[j] = l[j], l[i] 
                n += 1

    return l, n

def bubbleSort3(l): #N Iters => (n-1) + (n-2) + ... 2 + 1 = n(n-1)/2
    n = 0
    for i in range(0, len(l)):
        for j in range(0, len(l) - i -1):
            if(l[j] > l[j+1]): 
                l[j], l[j+1] = l[j+1], l[j] 
                n += 1

    return l, n

def bubbleSort4(l): #N Iters = i = n-1
    n = 0
    for i in range(0, len(l)):
        swapped = False
        for j in range(0, len(l) - i -1):
            if(l[j] > l[j+1]):
                l[j], l[j+1] = l[j+1], l[j]
                n += 1
                swapped = True
        if(not swapped):
            break

    return l, n

def main():

    l = [1, 5, 1, 3, 1, 17, 2, 2]

    #Bubble Sort algorithm 1
    newL, n = bubbleSort1(l)
    print(newL)
    y = []
    for i in range(len(newL)):
        y.append(i**2)

    x = list(range(0, len(y)))
    f = plt.figure()
    
    plt.plot(y, label="Basic Bubble sort")

    #Bubble Sort algorithm 2
    newL, n = bubbleSort2(l)
    print(newL)
    y = []
    for i in range(len(newL)):
        y.append(i*(i-1)/2)

    x = list(range(0, len(y)))

    plt.plot(y, label="Bubble sort 1 Limiting 'j' idx")

    #Bubble Sort algorithm 3
    newL, n = bubbleSort3(l)
    print(newL)
    y = []
    for i in range(len(newL)):
        y.append(i*(i+1)/2)

    x = list(range(0, len(y)))

    plt.plot(y, label="Bubble sort 2 Limiting 'j' idx\nskipping the last ordered element ")

    #Bubble Sort algorithm 4
    newL, n = bubbleSort4(l)
    print(newL)
    y = []
    for i in range(len(newL)):
        y.append(i-1)

    x = list(range(0, len(y)))

    plt.plot(y, label="Bubble sort Stopping the algorithm\nif inner loop didn't cause any swap")

    plt.title("Bubble Sort Implementation")
    plt.xlabel("Number of Values")
    plt.ylabel("Iterations")
    plt.legend(loc = "best")
    
    plt.show()
    
if __name__ == "__main__":
    main()
