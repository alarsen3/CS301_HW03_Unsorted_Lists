#ifndef UNSORTED_LISTS_ARRAYADTLIST_H
#define UNSORTED_LISTS_ARRAYADTLIST_H

template <class DataType>
class ArrayADTList {

public:
    class FullError {
    public:
        char const *message() { return "List is full."; }
    };

    int GetLength();
    void PutItem(const DataType &item);
    bool GetItem(const DataType &item, DataType &found_item);
    bool isFull() const;
    void makeEmpty();
    bool DeleteItem(const int &item);
    bool GetNextItem(DataType &item);
    void ResetList();

private:
    // Feel free to change these property names if you want
    static const long MAX_SIZE = 100;
    DataType items[MAX_SIZE];
    long length = 0; // Use this property to keep track of the list length
    long cursor = 0; // Use this property only in GetNextItem, Reset list
};

#endif //UNSORTED_LISTS_ARRAYADTLIST_H