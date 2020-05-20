class MinHeap:
    def __init__(self, array):
        self.heap = self.buildHeap(array)

    def buildHeap(self, array):
        firstParentIdx = (len(array) - 2) // 2
        for idx in reversed(range(firstParentIdx + 1)):
            self.siftDown(idx, len(array) - 1, array)
        return array

    def siftDown(self, currIndex, endIndex, heap):
        childOne = currIndex * 2 + 1
        while childOne <= endIndex:
            if (childOne < endIndex):
                # there are two children
                minima = None
                if self.heap[childOne] < self.heap[childOne + 1]:
                    minima = childOne
                else:
                    minima = childOne + 1

                if self.heap[currIndex] > self.heap[minima]:
                    self.swap(minima, currIndex, self.heap)
                    currIndex = minima
                    childOne = currIndex * 2 + 1
                else:
                    break
            else:
                # if there is only one child
                minima = childOne
                if self.heap[currIndex] > self.heap[minima]:
                    self.swap(minima, currIndex, self.heap)
                    currIndex = minima
                    childOne = currIndex * 2 + 1
                else:
                    break

    def siftUp(self, currIndex, heap):
        parentIndex = (currIndex - 1) // 2
        while self.heap[currIndex] < self.heap[parentIndex] and currIndex > 0:
            self.swap(currIndex, parentIndex, self.heap)
            currIndex = parentIndex
            parentIndex = (currIndex - 1) // 2

    def swapit(self, i, j, heap):
        heap[i], head[j] = heap[j], heap[i]

    def peek(self):
        return self.heap[0]

    def remove(self):
        swapit(0, len(self.heap) - 1, self.heap)
        valueToRemove = self.heap.pop()
        self.siftDown(0, len(self.heap) - 1, self.heap)
        return valueToRemove

    def insert(self, value):
        self.heap.append(value)
        self.siftUp(len(self.heap) - 1, self.heap)
