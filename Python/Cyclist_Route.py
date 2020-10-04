"""
Author: Etienne Cárdenas Wertheimer
Date: 11-09-2020
Description:

The following program consists of a simulation, in which a path followed by a cyclist is, in this case, generated randomly.

From the path you can get:
    - The max height and the number of times crossed with the maxHeight() func
    - The heights above the given threshold by using filterHeights()
    - Peaks and the number of times crossed by using getPeaksFromRoute()

Constraints:
    1.- The first element cannot be a candidate for a peak, as it is the starting point
    2.- To be considered as a peak, the element of the list is greater than the previous element
    AND is greater than or equal to the element that follows
    3.- If the last element of the list is greater than the previous one, it is the last peak   
"""

import random
import matplotlib.pyplot as plt

def maxHeight(cyclistRoute):
    #Max element from the list
    top = max(cyclistRoute)
    #Get the number of occurrences of the max element in the list
    repeated = cyclistRoute.count(top)

    return (top, repeated)

def filterHeights(cyclistRoute, thld):

    filteredRoute = []

    for data in cyclistRoute:
        #If the data is greater than the threshold, then it is added to a new list to be returned
        if data > thld:
            filteredRoute.append(data)

    return filteredRoute

def getPeaksFromRoute(cyclistRoute):

    peaks = []
    #idxList will contain the set of peaks on the X axis
    idxList = []
    
    #If the list is not empty...
    if(cyclistRoute):
        #If the list only has one element...
        if(len(cyclistRoute) == 1):
            print("No peaks have been recorded")
        else:
            for i in range(len(cyclistRoute)):
                #Constraint 1.-
                if(i > 0 and i < len(cyclistRoute) - 1):
                    #Constraint 2.-
                    if(cyclistRoute[i]> cyclistRoute[i-1] and
                        cyclistRoute[i] >= cyclistRoute[i+1]):
                        peaks.append(cyclistRoute[i])
                        idxList.append(i)
                else:
                    #Constraint 3.-
                    if(i == len(cyclistRoute) - 1):
                        if(cyclistRoute[i] > cyclistRoute[i-1]):
                                peaks.append(cyclistRoute[i])
                                idxList.append(i)
                                
    peaks = [idxList, peaks]

    return peaks

def main():
    
    random.seed()
    #The length of the dataset will be a random number between 10 and 20
    N = random.randint(10, 20)

    cyclistRoute = []

    for i in range(N):
        ##Generate random height values between 0 and 10
        cyclistRoute.append(random.randint(0, 10))

    print("Your list of heights is as follows:\n\n", cyclistRoute)

    top, repeated = maxHeight(cyclistRoute)

    print("\nThe maximum altitude reached is: {0} units".format(top))
    
    if(repeated == 1):
        print("The number of times that height is repeated in the list is: {0} time".format(1))
    else:
        print("The number of times that height is repeated in the list is: {0} times".format(repeated))

    print("\nEnter a threshold to get the heights that are above:")
    
    thld = int(input("> "))

    filteredHeights = filterHeights(cyclistRoute, thld)

    print("\nThe heights above the threshold are contained in the following list:\n\n", filteredHeights)

    peaks = getPeaksFromRoute(cyclistRoute)

    if(len(peaks[0][:]) == 1):
        print("\nThe cyclist has crossed {0} peak".format(len(peaks[0][:])))
    else:
        print("\nThe cyclist has crossed {0} peaks".format(len(peaks[0][:])))

    print("The peaks crossed are contained in the following list:\n\n", peaks[1][:])

    #*** Path Plot ***
    xAxis = range(len(cyclistRoute))
    
    plt.plot(xAxis, cyclistRoute, label = "Path")
    plt.plot(peaks[0][:], peaks[1][:], "ro", markersize = 10, label = "Peaks")

    plt.title("Cyclist Route")
    plt.xlabel("Path")
    plt.ylabel("Height")
    plt.legend(loc = "best")
    
    plt.show()
    #*** End Plot ***
    
if __name__ == "__main__":
    main()
