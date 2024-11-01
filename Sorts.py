import random
import matplotlib.pyplot as plt
import numpy

global N
global len_arr
len_arr=100

def InsertSort(alist):
    srav = 0
    perem = 0
    length = len(alist)
    for i in range(1, length):
        temp = alist[i]
        perem+=1
        j = i - 1

        srav += 1
        while (j >= 0 and temp < alist[j]):
            srav+=1
            alist[j + 1] = alist[j]
            j -= 1
            perem += 1
        alist[j + 1] = temp
        perem += 1
    arr = []
    arr.append(perem)
    arr.append(srav)
    return (arr)


def SelectSort(alist):
    srav = 0
    perem = 0
    length = len(alist)
    for i in range(0, length - 1):
        smallest = i
        for j in range(i + 1, length):
            srav += 1
            if alist[j] < alist[smallest]:
                smallest = j
        alist[i], alist[smallest] = alist[smallest], alist[i]
        perem += 1
    arr = []
    arr.append(perem)
    arr.append(srav)
    return (arr)


def BubbleSort(a):
    srav = 0
    perem = 0
    for i in range(len(a) - 1):
        for k in range(len(a) - 1 - i):
            srav += 1
            if a[k] > a[k + 1]:
                a[k], a[k + 1] = a[k + 1], a[k]
                perem += 1
    arr = []
    arr.append(perem)
    arr.append(srav)
    return (arr)


def merge_sort(nums, perem_m, srav_m):
    length = len(nums)
    if length > 1:
        mid = length // 2
        left = nums[:mid]
        right = nums[mid:]
        merge_sort(left, perem_m, srav_m)
        merge_sort(right, perem_m, srav_m)
        i = j = k = 0
        while i < len(left) and j < len(right):
            srav_m[0] += 1
            if left[i] < right[j]:
                nums[k] = left[i]
                perem_m[0] += 1
                i += 1
            else:
                nums[k] = right[j]
                perem_m[0] += 1
                j += 1
            k += 1
        while i < len(left):
            nums[k] = left[i]
            perem_m[0] += 1
            i += 1
            k += 1
        while j < len(right):
            perem_m[0] += 1
            nums[k] = right[j]
            j += 1
            k += 1
    return (nums)


def MergeSort(a):
    perem_m = []
    srav_m = []
    perem_m.append(0)
    srav_m.append(0)
    merge_sort(a, perem_m, srav_m)
    arr = []
    arr.append(perem_m[0])
    arr.append(srav_m[0])
    return (arr)


N = 1


def Graph_for_InsertSort():
    Perem_arr = [0] * len_arr
    Srav_arr = [0] * len_arr
    for n in range(1, len_arr+1):
        for number in range(N):
            random_array = [random.randint(1, 100) for _ in range(1, n + 1)]
            a=InsertSort(random_array)
            Perem_arr[n - 1] += a[0]
            Srav_arr[n - 1] += a[1]
        Perem_arr[n - 1] /= N
        Srav_arr[n - 1] /= N

    return Perem_arr, Srav_arr


def Graph_for_SelectSort():
    Perem_arr = [0] * len_arr
    Srav_arr = [0] * len_arr
    for n in range(1, len_arr+1):
        for number in range(N):
            random_array = [random.randint(1, 100) for _ in range(1, n + 1)]
            a=SelectSort(random_array)

            Perem_arr[n - 1] += a[0]
            Srav_arr[n - 1] += a[1]
        Perem_arr[n - 1] /= N
        Srav_arr[n - 1] /= N
    return Perem_arr, Srav_arr


def Graph_for_BubbleSort():
    Perem_arr = [0] * len_arr
    Srav_arr = [0] * len_arr
    for n in range(1, len_arr+1):
        for number in range(N):
            random_array = [random.randint(1, 100) for _ in range(1, n + 1)]
            Perem_arr[n - 1] += BubbleSort(random_array)[0]
            Srav_arr[n - 1] += BubbleSort(random_array)[1]
        Perem_arr[n - 1] /= N
        Srav_arr[n - 1] /= N

    return Perem_arr, Srav_arr


def Graph_for_MergeSort():
    Perem_arr = [0] * len_arr
    Srav_arr = [0] * len_arr
    for n in range(1, len_arr+1):
        for number in range(N):
            random_array = [random.randint(1, 100) for _ in range(1, n + 1)]
            Perem_arr[n - 1] += MergeSort(random_array)[0]
            Srav_arr[n - 1] += MergeSort(random_array)[1]
        Perem_arr[n - 1] /= N
        Srav_arr[n - 1] /= N

    return Perem_arr, Srav_arr

#Выводит массивы - результат каждой функции подсчета нужных величин.
# Graph_for_InsertSort()
#Graph_for_SelectSort()
# Graph_for_BubbleSort()
#Graph_for_MergeSort()
def Print_InsertSort():
    print('Перестановки')
    for i in range(1, len_arr+1):
        print(i, ' ', Graph_for_InsertSort()[0][i-1])
    print('Сравнения')
    for i in range(1, len_arr+1):
        print(i, ' ', Graph_for_InsertSort()[1][i-1])

def Print_SelectSort():
    print('Перестановки')
    for i in range(1, len_arr + 1):
        print(i, ' ', Graph_for_SelectSort()[0][i - 1])
    print('Сравнения')
    for i in range(1, len_arr+1):
        print(i, ' ', Graph_for_SelectSort()[1][i - 1])
def Print_BubbleSort():
    print('Перестановки')
    for i in range(1, len_arr + 1):
        print(i, ' ', Graph_for_BubbleSort()[0][i - 1])
    print('Сравнения')
    for i in range(1, len_arr+1):
        print(i, ' ', Graph_for_BubbleSort()[1][i - 1])

def Print_MergeSort():
    print('Перестановки')
    for i in range(1, len_arr + 1):
        print(i, ' ', Graph_for_MergeSort()[0][i - 1])
    print('Сравнения')
    for i in range(1, len_arr+1):
        print(i, ' ', Graph_for_MergeSort()[1][i - 1])

#Print_InsertSort() распечатать массив перемещений и сравнений

x=[i for i in range(1, len_arr+1)]
InsertSort_graph_moving=Graph_for_InsertSort()[0]
SelectSort_graph_moving=Graph_for_SelectSort()[0]
BubbleSort_graph_moving=Graph_for_BubbleSort()[0]
MergeSort_graph_moving=Graph_for_MergeSort()[0]
#plt.subplot(1, 1, 1)
plt.figure(1)
plt.plot(x, InsertSort_graph_moving, marker='o')
plt.plot(x, SelectSort_graph_moving, marker='o')
plt.plot(x, BubbleSort_graph_moving, marker='o')
plt.plot(x, MergeSort_graph_moving, marker='o')
ax=plt.gca()
ax.legend(['Insert Sort', 'Select Sort', 'Bubble Sort', 'Merge Sort'])
plt.title('Moving')

InsertSort_graph_comparison=Graph_for_InsertSort()[1]
SelectSort_graph_comparison=Graph_for_SelectSort()[1]
BubbleSort_graph_comparison=Graph_for_BubbleSort()[1]
MergeSort_graph_comparison=Graph_for_MergeSort()[1]
plt.figure(2)
plt.plot(x,InsertSort_graph_comparison, marker='o')
plt.plot(x,SelectSort_graph_comparison, marker='o')
plt.plot(x, BubbleSort_graph_comparison, marker='o')
plt.plot(x, MergeSort_graph_comparison, marker='o')
ax1=plt.gca()
ax1.legend(['Insert Sort', 'Select Sort', 'Bubble Sort', 'Merge Sort'])
plt.title('Comparison')
plt.show()
''''
plt.figure(3)

InsertSort_graph_comparison1=numpy.array(InsertSort_graph_comparison, int)
SelectSort_graph_comparison1=numpy.array(SelectSort_graph_comparison, int)
BubbleSort_graph_comparison1=numpy.array(BubbleSort_graph_comparison, int)
print(BubbleSort_graph_comparison1-SelectSort_graph_comparison1)
plt.plot(x, InsertSort_graph_comparison1-BubbleSort_graph_comparison1)
plt.show()
'''