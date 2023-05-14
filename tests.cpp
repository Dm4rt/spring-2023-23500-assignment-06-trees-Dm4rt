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

TEST_CASE("BSTree delete function") {
    SUBCASE("Delete leaf node") {
        BSTree tree;
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        tree.insert(7);
        tree.remove(7);
        CHECK_THROWS_AS(tree.rsearch(7), std::out_of_range);
        CHECK(tree.search(5) == 5);
    }

    SUBCASE("Delete node with one child") {
        BSTree tree;
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        tree.insert(7);
        tree.remove(5);
        CHECK_THROWS_AS(tree.rsearch(5), std::out_of_range);
        CHECK(tree.search(7) == 7);
        CHECK(tree.search(15) == 15);
    }

    SUBCASE("Delete node with two children") {
        BSTree tree;
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        tree.insert(7);
        tree.insert(13);
        tree.insert(17);
        tree.insert(12);
        tree.insert(14);
        tree.remove(15);
        CHECK_THROWS_AS(tree.rsearch(2), std::out_of_range);
        CHECK(tree.search(17) == 17);
        CHECK(tree.search(12) == 12);
        CHECK(tree.search(14) == 14);
    }
}

TEST_CASE("BSTree height function") {
  BSTree tree;

  SUBCASE("Empty tree") {
    CHECK(tree.findHeight() == 0);
  }

  SUBCASE("Tree with one node") {
    tree.insert(10);
    CHECK(tree.findHeight() == 1);
  }

  SUBCASE("Tree with two nodes") {
    tree.insert(10);
    tree.insert(5);
    CHECK(tree.findHeight() == 2);
  }

  SUBCASE("Tree with three nodes") {
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    CHECK(tree.findHeight() == 2);
  }

  SUBCASE("Tree with four nodes") {
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    CHECK(tree.findHeight() == 3);
  }

  SUBCASE("Tree with five nodes") {
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    CHECK(tree.findHeight() == 3);
  }

  SUBCASE("Tree with six nodes") {
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(17);
    CHECK(tree.findHeight() == 3);
  }

  SUBCASE("Tree with seven nodes") {
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(17);
    tree.insert(13);
    CHECK(tree.findHeight() == 3);
  }
}

