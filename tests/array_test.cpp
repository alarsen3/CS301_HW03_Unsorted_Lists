#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../ArrayADTList.cpp"


TEST_CASE("Should create a array ADT list") {
    ArrayADTList<int> list;
}


TEST_CASE("New List should be empty") {
    ArrayADTList<int> list;
    REQUIRE(list.GetLength() == 0);
}

TEST_CASE("Length should be 1 after adding an item") {
    ArrayADTList<int> list;
    list.PutItem(4);
    REQUIRE(list.GetLength() == 1);
}

TEST_CASE("Length should be 3 after adding 3 items") {
    ArrayADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE(list.GetLength() == 3);
}

TEST_CASE("Should not be full to start")  {
    ArrayADTList<int> list;
    REQUIRE_FALSE(list.isFull());
}


TEST_CASE("MakeEmpty should make the list empty") {
    ArrayADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    list.makeEmpty();
    REQUIRE(list.GetLength() == 0);

}

TEST_CASE("Should be full after adding the 100th item") {
    ArrayADTList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.PutItem(i);
    }
    REQUIRE(list.isFull());

}

TEST_CASE("Should throw error when adding the 101th item") {
    ArrayADTList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.PutItem(i);
    }
    REQUIRE_THROWS_AS(list.PutItem(101), ArrayADTList<int>::FullError);

}

TEST_CASE("Should throw an error with a message of 'List is Full.'") {
    ArrayADTList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.PutItem(i);
    }

    try {
        list.PutItem(101);
        REQUIRE_FALSE(FALSE);
    } catch (ArrayADTList<int>::FullError& error) {
        REQUIRE(strcmp(error.message(), "List is full.") == 0);
    }
}

TEST_CASE("Should be able to get an item after adding it") {
    ArrayADTList<int> list;
    list.PutItem(7);
    int item;
    REQUIRE(list.GetItem(7,item));
    REQUIRE(item == 7);
}

TEST_CASE("Delete should return false when the item is not in the list") {
    ArrayADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE_FALSE(list.DeleteItem(1));
}

TEST_CASE("Should not be able to get an item after deleting it") {
    ArrayADTList<int> list;
    list.PutItem(4);
    list.PutItem(5);
    list.PutItem(6);
    REQUIRE(list.DeleteItem(5));
    REQUIRE(list.GetLength() == 2);
    int item;
    REQUIRE_FALSE(list.GetItem(5, item));
}

TEST_CASE("Should receive false when getting an item from an empty list") {
    ArrayADTList<int> list;
    int item;
    REQUIRE_FALSE(list.GetItem(9, item));
}

TEST_CASE("Should be able to get other items after an item has been deleted") {
    ArrayADTList<int> list;
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
    ArrayADTList<int> list;
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


TEST_CASE("Deleting from an empty list should return false") {
    ArrayADTList<int> list;
    REQUIRE_FALSE(list.DeleteItem(9));
}

TEST_CASE("Deleting an item that is not there should return a false") {
    ArrayADTList<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PutItem(i);
    }
    REQUIRE_FALSE(list.DeleteItem(11));
}

TEST_CASE("Deleted Items should not show up in iterations"){
    ArrayADTList<int> list;
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

TEST_CASE("RestList should more the cursor back to the start"){
    ArrayADTList<int> list;
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

