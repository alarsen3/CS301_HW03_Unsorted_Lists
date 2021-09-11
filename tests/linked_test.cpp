#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../LinkedADTList.cpp"


TEST_CASE("Should create a array ADT list") {
    LinkedADTList<int> list;
}

TEST_CASE("New List should be empty") {
    LinkedADTList<int> list;
    REQUIRE(list.GetLength() == 0);
}

TEST_CASE("Length should be 1 after adding an item") {
    LinkedADTList<int> list;
    list.PutItem(4);
    REQUIRE(list.GetLength() == 1);
}

TEST_CASE("Length should be 3 after adding 3 items") {
    LinkedADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE(list.GetLength() == 3);
}

TEST_CASE("MakeEmpty should make the list empty") {
    LinkedADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    list.makeEmpty();
    REQUIRE(list.GetLength() == 0);

}

TEST_CASE("Should not be full to start")  {
    LinkedADTList<int> list;
    REQUIRE_FALSE(list.isFull());
}

TEST_CASE("Should not be full after adding the 100th item") {
    LinkedADTList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.PutItem(i);
    }
    REQUIRE_FALSE(list.isFull());

}

TEST_CASE("Should be able to get an item after adding it") {
    LinkedADTList<int> list;
    list.PutItem(7);
    int item;
    REQUIRE(list.GetItem(7,item));
    REQUIRE(item == 7);
}

TEST_CASE("Should receive false when getting an item from an empty list") {
    LinkedADTList<int> list;
    int item;
    REQUIRE_FALSE(list.GetItem(9, item));
}
TEST_CASE("List should be shorter after deleting and item") {
    LinkedADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE(list.DeleteItem(4));
    REQUIRE(list.GetLength() == 2);
}


TEST_CASE("Deleting from an empty list should return false") {
    LinkedADTList<int> list;
    REQUIRE_FALSE(list.DeleteItem(9));
}

TEST_CASE("Deleting an item that is not there should return a false") {
    LinkedADTList<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PutItem(i);
    }
    REQUIRE_FALSE(list.DeleteItem(11));
}

TEST_CASE("Delete should return false when the item is not in the list") {
    LinkedADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE_FALSE(list.DeleteItem(1));
}

TEST_CASE("Should not be able to get an item after deleting it") {
    LinkedADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE(list.DeleteItem(5));
    bool test = list.GetLength() == 2;
    REQUIRE(test);
    int item;
    test = list.GetItem(5, item);
    REQUIRE_FALSE(test);
}

TEST_CASE("Should be able to get other items after an item has been deleted") {
    LinkedADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE(list.DeleteItem(5));
    REQUIRE(list.GetLength() == 2);
    int item;
    REQUIRE(list.GetItem(4, item));
    REQUIRE(list.GetItem(6, item));
}



TEST_CASE("Should be able to iterate over all the list items"){
    LinkedADTList<int> list;
    bool stale_items[10];
    for (int i = 0; i < 10; ++i) {
        stale_items[i] = true;
        list.PutItem(i);
    }

    int item;
    while(list.GetNextItem(item)) {
        stale_items[item] = false;
    }

    for (int i = 0; i < 10; ++i) {
        REQUIRE_FALSE(stale_items[i]);
    }

}

TEST_CASE("Deleted Items should not show up in iterations"){
    LinkedADTList<int> list;
    bool stale_items[10];
    for (int i = 0; i < 10; ++i) {
        stale_items[i] = true;
        list.PutItem(i);
    }

    list.DeleteItem(4);
    stale_items[4] = false;

    list.DeleteItem(7);
    stale_items[7] = false;

    int item;
    while(list.GetNextItem(item)) {
        stale_items[item] = false;
    }

    for (int i = 0; i < 10; ++i) {
        REQUIRE_FALSE(stale_items[i]);
    }
}

TEST_CASE("GetNextItem should return false when list is emtpy") {
    LinkedADTList<int> list;
    int item;
    REQUIRE_FALSE(list.GetNextItem(item));
}

TEST_CASE("RestList should more the cursor back to the start"){
    LinkedADTList<int> list;
    bool stale_items[5];
    for (int i = 0; i < 5; ++i) {
        stale_items[i] = true;
        list.PutItem(i);
    }
    int item;

    list.GetNextItem(item);
    list.GetNextItem(item);

    list.ResetList();

    while(list.GetNextItem(item)) {
        stale_items[item] = false;
    }

    for (int i = 0; i < 5; ++i) {
        REQUIRE_FALSE(stale_items[i]);
    }
}