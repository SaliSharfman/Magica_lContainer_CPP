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
    MagicalContainer(MagicalContainer &other): elements(other.elements){}// copy constructor
    ~MagicalContainer(){} //destructor
    MagicalContainer(MagicalContainer&& other) noexcept; // move constructor
    MagicalContainer &operator=(MagicalContainer&& other) noexcept; // move assignment operator
    MagicalContainer &operator=(const MagicalContainer &other);

    void addElement(int element);
    void removeElement(int element);
    int size() const {return (int)elements.size();}

    //AscendingIterator
    class AscendingIterator {
    private:
        const MagicalContainer &container;
        int curr;

    public:
        AscendingIterator(const MagicalContainer &container, int curr = 0): container(container), curr(curr) {} // constructor
        AscendingIterator(const AscendingIterator &other): container(other.container), curr(other.curr) {} // copy constructor
        ~AscendingIterator() {} //destructor
        AscendingIterator(AscendingIterator&& other) noexcept; // move constructor
        AscendingIterator& operator=(AscendingIterator&& other) noexcept; // move assignment operator
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
        SideCrossIterator(const MagicalContainer &container): container(container), right(0), left(-1) {} // defult constructor
        SideCrossIterator(int right, const MagicalContainer &container,  int left): container(container), right(right), left(left) {}// constructor
        SideCrossIterator(const SideCrossIterator &other): container(other.container), right(other.right), left(other.left) {}// copy constructor
        ~SideCrossIterator() {} // destructor
        SideCrossIterator(SideCrossIterator&& other) noexcept; // move constructor
        SideCrossIterator& operator=(SideCrossIterator&& other) noexcept; // move assignment operator
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
        vector<const int*> primeptr;
        int curr;

    public:
        PrimeIterator(const MagicalContainer &cont, int curr = 0);// constructor
        PrimeIterator(const PrimeIterator &other);// copy constructor
        ~PrimeIterator() {} // destructor
        PrimeIterator(PrimeIterator&& other) noexcept; // move constructor
        PrimeIterator& operator=(PrimeIterator&& other) noexcept; // move assignment operator
        PrimeIterator &operator++();
        bool isPrime(int element) const;
        int operator*() const;
        PrimeIterator &operator=(const PrimeIterator &other);
        bool operator==(const PrimeIterator &other) const{return curr == other.curr;}
        bool operator!=(const PrimeIterator &other) const{return curr != other.curr;}
        bool operator>(const PrimeIterator &other) const{return curr > other.curr;}
        bool operator<(const PrimeIterator &other) const{return curr < other.curr;}
        int size() const { return static_cast<int>(this->primeptr.size()); }
        PrimeIterator begin() const{return PrimeIterator(this->container, 0);}
        PrimeIterator end() const{return PrimeIterator(this->container, this->size());}
    
    };
};

}
