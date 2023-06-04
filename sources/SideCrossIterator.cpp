#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;



int MagicalContainer::SideCrossIterator::operator*() const {
    if (right>left)
        return container.elements[(vector<int>::size_type) right];
    return container.elements[(vector<int>::size_type) (container.size()- left -1)];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    int mid = container.size() / 2;
    if (container.size() % 2 == 0) 
        return SideCrossIterator(container, mid, mid-1);
    return SideCrossIterator(container, mid, mid);
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (&container!= &(other.container))
        throw runtime_error("hh");
    if (this != &other) {
        right = other.right;
        left = other.left;
    }
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if(*this==end())
        throw runtime_error("cant increment the last element.");
    if (right>left)
        ++left;
    else
        ++right;
    return *this;
}