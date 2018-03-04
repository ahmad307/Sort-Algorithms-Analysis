import matplotlib.pyplot as plt
import numpy as np

def single_sort_chart(sort_name,times):
    plt.bar(np.arange(6), times,color='orange',width=[0.2,0.3,0.4,0.5,0.7,1])
    plt.plot(np.arange(6), times)

    #naming labels
    xlabels = ['100','500','1k','100k','500k','1m']
    plt.xticks(np.arange(6),xlabels)
    plt.xlabel('Array Size')
    plt.ylabel('Time (ms)')
    plt.title(sort_name + 'Sort')

    plt.show()
    #plt.savefig(sort_name + 'Sort')    #Saves charts in png format
    plt.clf()


#Reading data from Results File
data_file = open('sortResults_milliseconds.txt','r')
data = []
for line in data_file:  #Builds 2D Char array with sorting data
    data.append(line.split(' '))
data_file.close()


#Building plot for each Sort Algorithm (Done)
for i in range(0,5):
    #Passes sort name and sort data converted to integers
    single_sort_chart(data[i][0],list(map(int,data[i][1:7])))


#Building a plot for all algorithms side by side
'''Value Error present!'''
'''data = np.array(data)
pos,width,space = np.arange(6),0.5,0
for i in range(1,7):
    times =  list(map(int,data[:,space + 1]))
    plt.bar(pos+width,times,width)
    space += 1

plt.show()'''