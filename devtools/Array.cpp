// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//for defaulting array to 7 when default constructor is called
#define DEFAULT 7 

//
// Array
//
template <typename T>
Array <T>::Array (void)
    : Array_Base <T> (DEFAULT)
{}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
    : Array_Base <T> (length)
{}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
    : Array_Base <T> (length, fill)
{}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array <T> & arr)
    : Array_Base <T> (arr)
{}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array <T> & rhs)
{
    //check for no self assignment
    if (this != &rhs) {        
       this -> resize(rhs.max_size());
       this -> cur_size_ = rhs.size();

        // Copy elements from rhs to this
        for (size_t iter = 0; iter < rhs.size(); iter++) {
            this -> set (iter, rhs.get(iter));
        }
     
    }    
    return *this;    
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //if max_size > new_size then change cur_size
    if (this->max_size() >= new_size) {
        this -> cur_size_ = new_size; 
    }
    
    else {
        //make temporary memory
        T *temp_data_ = new T [new_size];

        //set temporay contents with this->data contents and null T if iter >= size
        for (size_t iter = 0; iter < this -> size(); iter++) {
            temp_data_[iter] = this->data_[iter];
        }

        //delete and reallocate
        delete [] this->data_;
        this->data_ = temp_data_;

        //update new max size
        this->max_size_ = new_size;

    }
}

template <typename T>
void Array<T>::push_back(T value) {
    // Ensure there's room to add another element.
    if (this->cur_size_ == this->max_size_) {
        this->resize(this->cur_size_ + 5); 
    }

    this->set(this->cur_size_, value); // Set the value at the current size
    this->resize(this->cur_size_ + 1); // Increment the size to reflect the new element
}
