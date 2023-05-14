#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"

TEST_CASE("Binary search tree recursive search") {
    BSTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    SUBCASE("Search for an existing value") {
        CHECK(bst.rsearch(6) == 6);
        CHECK(bst.rsearch(8) == 8);
        CHECK(bst.rsearch(3) == 3);
        CHECK(bst.rsearch(10) == 10);
        CHECK(bst.rsearch(14) == 14);
        CHECK(bst.rsearch(4) == 4);
        
    }

    SUBCASE("Search for a non-existing value") {
        CHECK_THROWS_WITH(bst.rsearch(11), "not found value");
    }

    SUBCASE("Search for a value in an empty tree") {
        BSTree emptyBST;
        CHECK_THROWS_WITH(emptyBST.rsearch(5), "empty tree search");
    }
}

TEST_CASE("Testing BSTree::rinsert function") {
    BSTree tree;

    SUBCASE("Inserting into empty tree") {
        tree.rinsert(10);
        CHECK(tree.rsearch(10) == 10);
    }

    SUBCASE("Inserting into non-empty tree") {
        tree.rinsert(10);
        tree.rinsert(5);
        tree.rinsert(15);
        tree.rinsert(3);
        tree.rinsert(7);
        tree.rinsert(12);
        tree.rinsert(17);

        CHECK(tree.rsearch(3) == 3);
        CHECK(tree.rsearch(7) == 7);
        CHECK(tree.rsearch(10) == 10);
        CHECK(tree.rsearch(12) == 12);
        CHECK(tree.rsearch(15) == 15);
        CHECK(tree.rsearch(17) == 17);

        CHECK_THROWS_AS(tree.rsearch(2), std::out_of_range);
    }

    SUBCASE("Inserting existing value") {
        tree.rinsert(10);
        tree.rinsert(5);
        tree.rinsert(15);
        tree.rinsert(5);

        CHECK(tree.rsearch(5) == 5);
    }
}