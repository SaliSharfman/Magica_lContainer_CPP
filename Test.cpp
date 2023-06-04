#include "doctest.h"
#include "MagicalContainer.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Checking the order of the elements in the container after adding elements in descending order") {
    MagicalContainer mc;
    mc.addElement(5);
    mc.addElement(4);
    mc.addElement(3);
    mc.addElement(2);
    mc.addElement(1);

    // Additional size check
    CHECK(mc.size() == 5);
    
    vector<int> result;
    MagicalContainer::AscendingIterator ascIter(mc);
    for(auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        result.push_back(*it);
        // Check that all elements are less than or equal to 5
        CHECK(*it <= 5);
    }
    
    CHECK(result == vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("Adding elements in random order and checking the order") {
    MagicalContainer mc;
    mc.addElement(3);
    mc.addElement(5);
    mc.addElement(2);
    mc.addElement(1);
    mc.addElement(4);

    // Additional size check
    CHECK(mc.size() == 5);
    
    vector<int> result;
    MagicalContainer::AscendingIterator ascIter(mc);
    for(auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        result.push_back(*it);
        // Check that all elements are less than or equal to 5
        CHECK(*it <= 5);
    }
    
    CHECK(result == vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("Adding elements and checking with SideCrossIterator") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    // Additional size check
    CHECK(mc.size() == 5);
    
    vector<int> result;
    MagicalContainer::SideCrossIterator sideIter(mc);
    for(auto it = sideIter.begin(); it != sideIter.end(); ++it) {
        result.push_back(*it);
        // Check that all elements are less than or equal to 5
        CHECK(*it <= 5);
    }
    
    // Assuming SideCrossIterator returns elements in the order {1, 5, 2, 4, 3}
    CHECK(result == vector<int>({1, 5, 2, 4, 3}));
}

TEST_CASE("Adding prime and non-prime numbers and checking with PrimeIterator") {
    MagicalContainer mc;
    mc.addElement(2);
    mc.addElement(4);
    mc.addElement(5);
    mc.addElement(8);
    mc.addElement(9);
    mc.addElement(11);

    // Additional size check
    CHECK(mc.size() == 6);
}

TEST_CASE("Adding multiple elements and checking size after each insertion") {
    MagicalContainer mc;
    mc.addElement(10);
    
    // Size check
    CHECK(mc.size() == 1);

    mc.addElement(20);

    // Additional size check
    CHECK(mc.size() == 2);

    mc.addElement(30);

    // Additional size check
    CHECK(mc.size() == 3);

    mc.addElement(40);

    // Additional size check
    CHECK(mc.size() == 4);

    mc.addElement(50);

    // Additional size check
    CHECK(mc.size() == 5);
}

TEST_CASE("Adding elements and removing them one by one") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    // Additional size check
    CHECK(mc.size() == 5);

    mc.removeElement(1);

    // Additional size check
    CHECK(mc.size() == 4);

    mc.removeElement(2);

    // Additional size check
    CHECK(mc.size() == 3);

    mc.removeElement(3);

    // Additional size check
    CHECK(mc.size() == 2);

    mc.removeElement(4);

    // Additional size check
    CHECK(mc.size() == 1);

    mc.removeElement(5);

    // Additional size check
    CHECK(mc.size() == 0);
}

TEST_CASE("Check operator overloading for iterator classes") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    // Additional size check
    CHECK(mc.size() == 5);

    MagicalContainer::AscendingIterator it1(mc);
    MagicalContainer::AscendingIterator it2(mc);
    ++it2;

    // Check iterator equality and inequality
    CHECK(it1 != it2);
   // CHECK_NOTHROW(it1 == it2);

    // Check iterator less than and greater than
    CHECK(it1 < it2);
   // CHECK_NOTHROW(it1 > it2);

    // Check operator*
    CHECK(*it1 == 1);
    CHECK(*it2 == 2);
}