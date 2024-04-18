#include <string>
#include <iostream>

#include "ArrayBag.h"
#include "ArrayBag.cpp"
// Method for union of two bags
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::unionBags(const ArrayBag<ItemType> &anotherBag) const {
    ArrayBag<ItemType> unionBag;
    for (int i = 0; i < itemCount; ++i) {
        unionBag.add(items[i]);
    }
    for (int i = 0; i < anotherBag.getCurrentSize(); ++i) {
        unionBag.add(anotherBag.items[i]);
    }
    return unionBag;
}
// Method to compute the intersection of two bags
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::intersection(const ArrayBag<ItemType>& anotherBag) const {
    ArrayBag<ItemType> resultBag;
    for (int i = 0; i < itemCount; ++i) {
        ItemType currentItem = items[i];
        if (anotherBag.contains(currentItem)) {
            resultBag.add(currentItem);
            ArrayBag<ItemType> tempBag = anotherBag;
            tempBag.remove(currentItem);
        }
    }
    return resultBag;
}
// Method to compute the difference of two bags
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::difference(const ArrayBag<ItemType>& anotherBag) const {
    ArrayBag<ItemType> resultBag;
    for (int i = 0; i < itemCount; ++i) {
        ItemType currentItem = items[i];
        if (!anotherBag.contains(currentItem)) {
            resultBag.add(currentItem);
        }
    }
    return resultBag;
}
int main() {
    ArrayBag<int> bag1;
    ArrayBag<int> bag2;
    bag1.add(1);
    bag1.add(2);
    bag1.add(2);
    bag1.add(3);
    bag2.add(2);
    bag2.add(3);
    bag2.add(4);
    // Test unionBags
    ArrayBag<int> unionResult = bag1.unionBags(bag2);
    std::vector<int> unionVector = unionResult.toVector();
    std::cout << "Union of bag1 and bag2: ";
    for (const auto& item : unionVector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    // Test intersection
    ArrayBag<int> intersectionResult = bag1.intersection(bag2);
    std::vector<int> intersectionVector = intersectionResult.toVector();
    std::cout << "Intersection of bag1 and bag2: ";
    for (const auto& item : intersectionVector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    // Test difference
    ArrayBag<int> differenceResult = bag1.difference(bag2);
    std::vector<int> differenceVector = differenceResult.toVector();
    std::cout << "Difference of bag1 and bag2: ";
    for (const auto& item : differenceVector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}