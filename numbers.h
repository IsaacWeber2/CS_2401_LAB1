
/**
 *   @file: numbers.h
 * @author: Isaac Weber
 *   @date: June 13, 2021
 *  @brief: A little class that holds a dynamic array of numbers
 */

#include <iostream>
using namespace std;

size_t byte_count = 0;
class Numbers {
   public:
    Numbers();
    // You will need to add a destructor in here
    void add(unsigned long item);
    void resize();
    void remove_last();
    void display(ostream& outs);
    unsigned long* reveal_address() const;
    // This is added after first three questions answered:
    void operator = (const Numbers& other);
    // This is used in Part 2 and would normally not be in a container	unsigned
    //long * reveal_address()const;
    // This is a function that you add in Part 2
    ~Numbers();
   private:
    unsigned long* data;
    size_t used;
    size_t capacity;
};

Numbers::Numbers() {
    data = new unsigned long[5];
    used = 0;
    capacity = 5;
    byte_count += 5 * sizeof(unsigned long);
}

void Numbers::add(unsigned long item) {
    if (used == capacity) resize();
    data[used] = item;
    used++;
}

void Numbers::resize() {
    unsigned long* tmp;
    tmp = new unsigned long[capacity + 5];
	//copy is a standard function that copies a segment of an array to
	//another array. More description can be found in section: 
    copy(data, data + used, tmp);
    delete[] data;
    capacity += 5;
    byte_count += 5 * sizeof(unsigned long);
    data = tmp;
}

void Numbers::remove_last() { used--; }

void Numbers::display(ostream& outs) {
    for (size_t i = 0; i < used; ++i) outs << data[i] << ' ';
}

unsigned long* Numbers::reveal_address() const { return data; }

// You will need to write the implementation of this overloaded operator

void Numbers::operator = (const Numbers& other){

    if (this != &other)
    {
        delete [] data;
        data = new unsigned long[capacity];

        for (int i = 0; i < used; i++)
        {
            data[i] = other.data[i];
        }



    }
    
}


Numbers ::~Numbers()
{
    delete [] data;
    byte_count = byte_count - capacity *sizeof(unsigned long);
    
}