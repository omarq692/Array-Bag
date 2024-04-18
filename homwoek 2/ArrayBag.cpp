
#include "ArrayBag.h"
#include <cstddef>
#include <iostream>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if

    return hasRoomToAdd;
}  // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
    return false; // STUB
 }  // end remove
*/

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if

    return canRemoveItem;
}  // end remove

/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
    // STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int curIndex = 0;       // Current array index
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
        {
            frequency++;
        }  // end if

        curIndex++;          // Increment to next entry
    }  // end while

    return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if

      curIndex++;           // Increment to next entry
   }  // end while

   return found;
}  // end contains
*/

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);

    return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }  // end if
    }  // end while

    return result;
}  // end getIndexOf
//
//#include "ArrayBag.h"
//
//// Default constructor
//template<class ItemType>
//ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}
//
//// getCurrentSize method
//template<class ItemType>
//int ArrayBag<ItemType>::getCurrentSize() const {
//    return itemCount;
//}
//
//// isEmpty method
//template<class ItemType>
//bool ArrayBag<ItemType>::isEmpty() const {
//    return itemCount == 0;
//}
//
//// add method
//template<class ItemType>
//bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
//    bool hasRoomToAdd = (itemCount < maxItems);
//    if (hasRoomToAdd) {
//        items[itemCount] = newEntry;
//        itemCount++;
//    }
//    return hasRoomToAdd;
//}
//
//// remove method
//template<class ItemType>
//bool ArrayBag<ItemType>::remove(const ItemType& anEntry) {
//    int locatedIndex = getIndexOf(anEntry);
//    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
//    if (canRemoveItem) {
//        itemCount--;
//        items[locatedIndex] = items[itemCount];
//    }
//    return canRemoveItem;
//}
//
//// clear method
//template<class ItemType>
//void ArrayBag<ItemType>::clear() {
//    itemCount = 0;
//}
//
//// getFrequencyOf method
//template<class ItemType>
//int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
//    int frequency = 0;
//    for (int i = 0; i < itemCount; ++i) {
//        if (items[i] == anEntry) {
//            frequency++;
//        }
//    }
//    return frequency;
//}
//
//// contains method
//template<class ItemType>
//bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {
//    return getIndexOf(anEntry) > -1;
//}
//
//// toVector method
//template<class ItemType>
//std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
//    std::vector<ItemType> bagContents;
//    for (int i = 0; i < itemCount; ++i) {
//        bagContents.push_back(items[i]);
//    }
//    return bagContents;
//}
//
//// getIndexOf method
//template<class ItemType>
//int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {
//    for (int i = 0; i < itemCount; ++i) {
//        if (items[i] == target) {
//            return i;
//        }
//    }
//    return -1; // Not found
//}
//
//// unionBags method
//template<class ItemType>
//ArrayBag<ItemType> ArrayBag<ItemType>::unionBags(const ArrayBag<ItemType>& anotherBag) const {
//    ArrayBag<ItemType> unionBag;
//    for (int i = 0; i < itemCount; ++i) {
//        unionBag.add(items[i]);
//    }
//    for (int i = 0; i < anotherBag.getCurrentSize(); ++i) {
//        unionBag.add(anotherBag.items[i]);
//    }
//    return unionBag;
//}
//
//// intersection method
//template<class ItemType>
//ArrayBag<ItemType> ArrayBag<ItemType>::intersection(const ArrayBag<ItemType>& anotherBag) const {
//    ArrayBag<ItemType> intersectionBag;
//    for (int i = 0; i < itemCount; ++i) {
//        ItemType currentItem = items[i];
//        if (anotherBag.contains(currentItem)) {
//            intersectionBag.add(currentItem);
//        }
//    }
//    return intersectionBag;
//}
//
//// difference method
//template<class ItemType>
//ArrayBag<ItemType> ArrayBag<ItemType>::difference(const ArrayBag<ItemType>& anotherBag) const {
//    ArrayBag<ItemType> differenceBag;
//    for (int i = 0; i < itemCount; ++i) {
//        ItemType currentItem = items[i];
//        if (!anotherBag.contains(currentItem)) {
//            differenceBag.add(currentItem);
//        }
//    }
//    return differenceBag;
//}
