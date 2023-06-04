#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, int curr) : container(container),curr(curr) {
    while (this->curr < this->container.size() && !isPrime(this->container.elements[(vector<int>::size_type) this->curr]))
        this->curr++;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), curr(other.curr) {
    while (this->curr < this->container.size() && !isPrime(this->container.elements[(vector<int>::size_type) this->curr]))
        this->curr++;
}



MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if(*this==end())
        throw runtime_error("cant increment the last element.");
    while (++curr < container.size() && !isPrime(container.elements[(vector<int>::size_type) curr])){}
    return *this;
}


bool MagicalContainer::PrimeIterator::isPrime(int element) const {
    if (element <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(element); ++i)
        if (element % i == 0)
            return false;
    return true;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return this->container.elements[(std::vector<int>::size_type) curr];
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (&container!= &(other.container))
        throw runtime_error("different containers.");
    if (this != &other)
        curr = other.curr;
    return *this;
}
