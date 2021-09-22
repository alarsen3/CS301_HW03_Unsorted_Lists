#ifndef NODE
#define NODE

template <class DataType>
struct Node {
    DataType value;
    Node<DataType>* next;
};
#endif

#ifndef UNSORTED_LISTS_LINKEDADTLIST_H
#define UNSORTED_LISTS_LINKEDADTLIST_H

template <class DataType>
class LinkedADTList {

public:
    virtual ~LinkedADTList();

    int GetLength();
    void PutItem(const DataType &item);
    bool GetItem(const DataType &item, DataType &found_item);
    bool isFull();
    void makeEmpty();
    bool DeleteItem(const DataType &item);
    bool GetNextItem(DataType &item);
    void ResetList();

private:
    Node<DataType>* start = nullptr;
    long length = 0;                  // Use this property to keep track of the list length
    Node<DataType>* cursor = start;   // Use this property only in GetNextItem and Reset list
};

#endif //UNSORTED_LISTS_LINKEDADTLIST_H