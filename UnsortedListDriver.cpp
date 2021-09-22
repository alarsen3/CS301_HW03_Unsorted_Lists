// Use this driver to try out your code, print to cout and so on
#include "ArrayADTList.cpp"
#include "LinkedADTList.cpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {

    ArrayADTList<int> adtList;
    for (int i = 0; i < 150; ++i) {
        try {
            adtList.PutItem(i * 2);
        } catch (ArrayADTList<int>::FullError) {
            cout << "Array Full at " << i << endl;
            break;
        }
    }

    int FoundItem1, FoundItem2;
    if ( adtList.GetItem(2, FoundItem1) ) {
        cout << "Found " << FoundItem1 << endl;
    }

    if ( adtList.GetItem(3, FoundItem2) ) {
        cout << "Found " << FoundItem2 << endl;
    }

    int nextItem;
    adtList.GetNextItem(nextItem);
    cout << "Next Item: " << nextItem << endl;

    adtList.GetNextItem(nextItem);
    cout << "Next Item: " << nextItem << endl;

    int itemToDelete2 = 2;
    adtList.DeleteItem(itemToDelete2);

    itemToDelete2 = 3;
    adtList.DeleteItem(itemToDelete2);


    // Linked List

    LinkedADTList<int> list;
    assert(list.GetLength() == 0);

    list.PutItem(4);
    assert(list.GetLength() == 1);

    list.makeEmpty();
    assert(list.GetLength() == 0);

    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    assert(list.GetLength() == 3);

    list.makeEmpty();
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    list.makeEmpty();
    assert(list.GetLength() == 0);

    list.makeEmpty();
    for (int i = 0; i < 100; ++i) {
        list.PutItem(i);
    }
    assert(list.isFull() == false);

    list.makeEmpty();
    list.PutItem(7);
    int item;
    assert(list.GetItem(7,item));
    assert(item == 7);

    list.makeEmpty();
    assert(list.GetItem(9, item) == false);

    list.makeEmpty();
    assert(list.GetNextItem(item) == false);

    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    list.DeleteItem(4);
    assert(list.GetLength() == 2);

//    list.makeEmpty();
//    assert(list.DeleteItem(9) == false);


    list.makeEmpty();
    list.ResetList();
    bool stale_items[10];
    for (int i = 0; i < 10; ++i) {
        stale_items[i] = true;
        list.PutItem(i);
    }

    list.DeleteItem(4);
    stale_items[4] = false;

    list.DeleteItem(7);
    stale_items[7] = false;

    while(list.GetNextItem(item)) {
        stale_items[item] = false;
    }

    for (int i = 0; i < 10; ++i) {
        assert(stale_items[i] == false);
    }





    return 0;
}