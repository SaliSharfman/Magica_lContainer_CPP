#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel {

class MagicalContainer {

private:
    vector<int> elements;

public:
    MagicalContainer(){} //default constructor
    MagicalContainer(MagicalContainer &other): elements(other.elements){}
    ~MagicalContainer(){} //destructor
    MagicalContainer &operator=(const MagicalContainer &other);

    void addElement(int element);
    void removeElement(int element);
    int size() const {return elements.size();}
    


    //AscendingIterator
    class AscendingIterator {
    private:
        const MagicalContainer &container;
        int curr;

    public:
        AscendingIterator(const MagicalContainer &container, int curr = 0): container(container), curr(curr) {}
        AscendingIterator(const AscendingIterator &other): container(other.container), curr(other.curr) {}
        int operator*() const;
        AscendingIterator &operator++();
        AscendingIterator &operator=(const AscendingIterator &other);
        bool operator==(const AscendingIterator &other) const{return curr == other.curr;}
        bool operator!=(const AscendingIterator &other) const{return curr != other.curr;}
        bool operator>(const AscendingIterator &other) const{return curr > other.curr;}
        bool operator<(const AscendingIterator &other) const{return curr < other.curr;}
        AscendingIterator begin() const{return AscendingIterator(this->container, 0);}
        AscendingIterator end() const{return AscendingIterator(this->container, this->container.size());}
    };


     //SideCrossIterator
    class SideCrossIterator {
    private:
        const MagicalContainer &container;
        int right, left;

    public:
        SideCrossIterator(const MagicalContainer &container, int right = 0, int left = -1): container(container), right(right), left(left) {}
        SideCrossIterator(const SideCrossIterator &other): container(other.container), right(other.right), left(other.left) {}
        int operator*() const;
        SideCrossIterator begin() const;
        SideCrossIterator end() const;

        SideCrossIterator &operator=(const SideCrossIterator &other);
        bool operator== (const SideCrossIterator &other) const {return right == other.right && left == other.left;}
        bool operator!= (const SideCrossIterator &other) const {return right != other.right || left != other.left;}
        bool operator> (const SideCrossIterator &other) const {return right > other.right || left > other.left;}
        bool operator< (const SideCrossIterator &other) const {return right < other.right && left < other.left;}
        
        SideCrossIterator &operator++();
    };

    //PrimeIterator
    class PrimeIterator{

    private:
        const MagicalContainer &container;
        int curr;

    public:
        PrimeIterator(const MagicalContainer &cont, int curr = 0);
        PrimeIterator(const PrimeIterator &other);
        PrimeIterator &operator++();
        bool isPrime(int element) const;
        int operator*() const;
        PrimeIterator &operator=(const PrimeIterator &other);
        bool operator==(const PrimeIterator &other) const{return curr == other.curr;}
        bool operator!=(const PrimeIterator &other) const{return curr != other.curr;}
        bool operator>(const PrimeIterator &other) const{return curr > other.curr;}
        bool operator<(const PrimeIterator &other) const{return curr < other.curr;}
        PrimeIterator begin() const{return PrimeIterator(this->container, 0);}
        PrimeIterator end() const{return PrimeIterator(this->container, this->container.size());}
    
    };
};

}
