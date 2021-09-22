#include "ArrayADTList.h"
using namespace std;

template <class Datatype>
int ArrayADTList<Datatype>::GetLength() {
    return length;
}

template<class DataType>
void ArrayADTList<DataType>::PutItem(const DataType &item) {
    // Ensures array isn't full, if so throws error
    if (length == MAX_SIZE){
        ArrayADTList<DataType>::FullError error;
        throw (error);
    }else{ // Otherwise, puts item into array and increments length
        items[length] = item;
        length++;
    }
}

template<class DataType>
bool ArrayADTList<DataType>::GetItem(const DataType &item, DataType &found_item) {
    // Loop goes through array searching for item
    for (int i = 0; i < length; i++){
        // Once item is found within array, return true. Otherwise, return false
        if (items[i] == item){
            found_item = item;
            return true;
        }
    }
    return false;
}

template<class DataType>
bool ArrayADTList<DataType>::isFull() const {
    bool full;
    // Checks if array is full by comparing length to max size; returns true if so, false otherwise
    if (length == MAX_SIZE) {
        full = true;
    }else{
        full = false;
    }
    return full;
}

template<class DataType>
void ArrayADTList<DataType>::makeEmpty() {
    // Clears list by setting length to 0
    length = 0;
}

template<class DataType>
bool ArrayADTList<DataType>::DeleteItem(const int &item) {
    // Hint: you only need to move one item.
    // For loop goes through entire array
    for (int i = 0; i < length; i++){
        // If the item in the array matches the item being searched for, set the found item's data to
        // the data from the item at the end of the array, then decrement length, effectively deleting it
        if (items[i] == item) {
            items[i] = items[length-1];
            length--;
            return true;
            }
        }
    // Value not found in array
    return false;
    }


template<class DataType>
bool ArrayADTList<DataType>::GetNextItem(DataType &item) {
   // Ensures that we aren't at the end of the array
    if (cursor == length){
       return false;
   }else{ // Return item at current position then increment cursor
       item = items[cursor];
       cursor++;
       return true;
   }
}

template<class DataType>
void ArrayADTList<DataType>::ResetList() {
    // Moves cursor to start of the array
    cursor = 0;
}