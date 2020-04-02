from Bag import Bag


def printBag(bagIterator):
    while bagIterator.valid():
        print(bagIterator.getCurrent())
        bagIterator.next()
    print("\n")


def main():
    b = Bag()
    bagIterator = b.iterator()
    b.add(4)
    b.add(11)
    b.add(4)
    b.add(77)
    b.add(8)
    printBag(bagIterator)
    print(b.frequences)


main()
