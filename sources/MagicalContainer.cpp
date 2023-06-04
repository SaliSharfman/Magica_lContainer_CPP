#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other) {
    if (this != &other) 
        this-> elements = other.elements; 
    return *this;
}
void MagicalContainer::addElement(int element) {
    auto insertionPoint = lower_bound(elements.begin(), elements.end(), element);
    elements.insert(insertionPoint, element);
}
void MagicalContainer::removeElement(int element) {
    elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
}


