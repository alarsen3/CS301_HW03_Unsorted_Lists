#include "ArrayADTList.h"


template <class Datatype>
int ArrayADTList<Datatype>::GetLength() {
    return 0;
}

template<class DataType>
void ArrayADTList<DataType>::PutItem(const DataType &item) {

}

template<class DataType>
bool ArrayADTList<DataType>::GetItem(const DataType &item, DataType &found_item) {
    return false;
}

template<class DataType>
bool ArrayADTList<DataType>::isFull() const {
    return false;
}

template<class DataType>
void ArrayADTList<DataType>::makeEmpty() {
}

template<class DataType>
bool ArrayADTList<DataType>::DeleteItem(const int &item) {
    // Hint: you only need to move one item.
    return false;
}

template<class DataType>
void ArrayADTList<DataType>::ResetList() {

}

template<class DataType>
bool ArrayADTList<DataType>::GetNextItem(DataType &item) {
    return false;
}
