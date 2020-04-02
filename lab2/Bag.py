class Bag:

    # creates a new, empty Bag
    def __init__(self):
        self.objects = []
        self.frequences = []

    # adds a new element to the Bag
    # complexity: O(n)
    def add(self, e):
        if e not in self.objects:
            self.objects.append(e)
            self.frequences.append(1)
        else:
            index = 0
            for obj in self.objects:
                if obj == e:
                    self.frequences[index] += 1
                    return
                index += 1

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    # complexity: O(n)
    def remove(self, e):
        if e in self.objects:
            index = 0
            for obj in self.objects:
                if obj == e:
                    self.frequences[index] -= 1
                    if self.frequences[index] == 0:
                        self.objects.remove(e)
                        self.frequences.remove(self.frequences[index])
                index += 1
            return True
        return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    # complexity: O(n)
    def search(self, e):
        return e in self.objects

    # counts and returns the number of times the element e appears in the bag
    # complexity: O(n)
    def nrOccurrences(self, e):
        index = 0
        for obj in self.objects:
            if e == obj:
                return self.frequences[index]
            index += 1
        return 0

    # returns the size of the Bag (the number of elements)
    # complexity: Theta(n)
    def size(self):
        number = 0
        for i in range(len(self.frequences)):
            number += self.frequences[i]
        return number

    # returns True if the Bag is empty, False otherwise
    # complexity: Theta(n)
    def isEmpty(self):
        return len(self.objects) == 0

    # returns a BagIterator for the Bag
    def iterator(self):
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        self._bag = b
        self._current = 0
        self._currentFrequency = 0

    # returns True if the iterator is valid
    #complexity: Theta(1)
    def valid(self):
        return self._current < len(self._bag.objects)

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    # complexity: Theta(1)
    def getCurrent(self):
        if self._current >= len(self._bag.objects):
            raise ValueError
        else:
            return self._bag.objects[self._current]

    # moves the iterator to the next element
    #throws ValueError if the iterator is not valid
    # complexity: Theta(1)
    def next(self):
        if self.valid():
            if self._currentFrequency < self._bag.frequences[self._current] - 1:
                self._currentFrequency += 1
            elif self._currentFrequency == self._bag.frequences[self._current] - 1:
                self._current += 1
                self._currentFrequency = 0
        else:
            raise ValueError

    # sets the iterator to the first element from the Bag
    # complexity: Theta(1)
    def first(self):
        self._current = 0
        self._currentFrequency = 0
