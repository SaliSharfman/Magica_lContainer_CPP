#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;



int MagicalContainer::AscendingIterator::operator*() const {
    return this->container.elements[(vector<int>::size_type) curr];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if(*this==end())
        throw runtime_error("cant increment the last element.");
    ++curr;
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
    if (&container!= &(other.container))
        throw runtime_error("hh");
    if (this != &other)
        curr = other.curr;
    return *this;
}
