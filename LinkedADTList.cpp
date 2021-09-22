#include "LinkedADTList.h"

template<class DataType>
int LinkedADTList<DataType>::GetLength() {
    return length;
}

template<class DataType>
void LinkedADTList<DataType>::PutItem(const DataType &item) {
    // Hint: where can you put the new node so that you don't have to traverse the list?
    Node<DataType>* temp = new Node<DataType>;
    temp->value = item;
    temp->next = nullptr;
    // First node
    if (length == 0){
        start = temp;
        cursor = start;
    }else{ // Adds node to front of list
        temp->next = start;
        if (cursor == start) {
            cursor = temp;
        }
        start = temp;
    }
    // Incrementing length of the list
    length++;
}

template<class DataType>
bool LinkedADTList<DataType>::GetItem(const DataType &item, DataType &found_item) {
    // Hint: Watch out that you don't create an infinite loop.
    Node<DataType>* temp;
    temp = start;
    // While there are nodes, look through all nodes for value
    while(temp != nullptr) {
        // If search value is found, set found_item to item
        if(temp->value == item){
            found_item = item;
            return true;
        }
        // Tells loop to go through all nodes
        temp = temp->next;
    }
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
    length = 0;
    Node<DataType>* temp;
    // Code from ~LinkedADTList, clears the list
    while(start != nullptr) {
        temp = start;
        start = temp->next;
        delete temp;
    }
    // Resets cursor
    cursor = nullptr;
}

template<class DataType>
bool LinkedADTList<DataType>::DeleteItem(const DataType &item) {
    // Hint: find the item first then work on deleting it
    // Don't delete the item until you've finish working on the list
    // Don't forget to clear the deleted node from memory.
    // This is the hardest method in the assignment, don't forget to breathe.

    // List is empty (nothing to delete)
    if (length == 0) {
        return false;
    }
    Node<DataType>* temp;
    Node<DataType>* previous;

    // If the value in the first node matches the item being searched for, the start item is deleted
    if (start->value == item){
        // Initialize temp to start
        temp = start;
        // Move cursor from start to next node
        if (cursor == start) {
            cursor = temp->next;
        }
        start = temp->next; // Moves start to next node
        delete temp; // Deletes old start
        length--; // Decrements length (as a node was just deleted from the list)
        return true;
    }
    previous = start;

    // Goes through list until item is found
    while (previous->next != nullptr) {
        // Finds item
        if (previous->next->value == item) {
            temp = previous->next; // Initializes temp to current node
            previous->next = temp->next; // sets value of current node to the node temp is pointing to
            delete temp; // deletes old current
            length--; // Decrements length (as a node was just deleted from the list)
            return true;
        }else{ // Tells loop to go through all nodes
            previous = previous->next;
        }
    }
    // Item not found in list
    return false;
}

template<class DataType>
bool LinkedADTList<DataType>::GetNextItem(DataType &item) {
    // Hint: Think about what it should do if the list is empty

    // Sets item to the value of the node cursor is at
    if (cursor != nullptr) {
        item = cursor->value;
        // Increment cursor
        cursor = cursor->next;
        return true;
    }
    // If cursor == nullptr, can't get item
    return false;
}

template<class DataType>
void LinkedADTList<DataType>::ResetList() {
    // Sets cursor to start of list
    cursor = start;
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