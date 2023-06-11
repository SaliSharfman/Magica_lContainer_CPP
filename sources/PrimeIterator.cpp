#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, int curr) : container(container),curr(curr) {
    int i =0;
    while (i < this->container.size()){
        if(isPrime(this->container.elements[(vector<int>::size_type) i]))
            this->primeptr.push_back(&container.elements[(vector<int>::size_type)i]);
        i++;
    }
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), curr(other.curr), primeptr(other.primeptr){
   
}



MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if(*this==end())
        throw runtime_error("cant increment the last element.");
    curr++;
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
    return *this->primeptr[(std::vector<int>::size_type) curr];
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (&container!= &(other.container))
        throw runtime_error("different containers.");
    if (this != &other)
        curr = other.curr;
    return *this;
}
