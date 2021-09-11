#include <iostream>
#include "LinkedADTList.h"


template<class DataType>
int LinkedADTList<DataType>::GetLength() {
    return 0;
}

template<class DataType>
void LinkedADTList<DataType>::PutItem(const DataType &item) {
    // Hint: where can you put the new node so that you don't have to traverse the list?
}

template<class DataType>
bool LinkedADTList<DataType>::GetItem(const DataType &item, DataType &found_item) {
    // Hint: Watch out that you don't crate an infinite loop.
    return false;
}

template<class DataType>
bool LinkedADTList<DataType>::isFull() {
    // Hint: There is a point at which the computer will run out of memory
    // but for our implementation it is safe to act as if memory is infinite.
    return false;
}

template<class DataType>
void LinkedADTList<DataType>::makeEmpty() {
    // Hint: You can't just set the length to 0, you need to worry about memory leaks.
    // Hint: Don't forget to reset the start and cursor as well.
}

template<class DataType>
bool LinkedADTList<DataType>::DeleteItem(const int &item) {
    // Hint: find the item first then work on deleting it
    // Don't delete the item until you've finish working on the list
    // Don't forget to clear the deleted node from memory.
    // This is the hardest method in the assignment, don't forget to breath.
    return false;
}


template<class DataType>
bool LinkedADTList<DataType>::GetNextItem(DataType &item) {
    // Hint: Think about what it should do if the list is empty
}

template<class DataType>
void LinkedADTList<DataType>::ResetList() {

}

// This is the destructor, it will run when the object is removed from memory
// I've included it here because we've not gone over them in class yet.
// This one deletes all the nodes in the list, if you change the names
// of the object properties make sure you update this code.

template<class DataType>
LinkedADTList<DataType>::~LinkedADTList() {

    Node<DataType>* temp;

    while(start != nullptr) {
        temp = start;
        start = temp->next;
        delete temp;
    }


}

