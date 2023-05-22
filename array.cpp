//
//  array.cpp
//  OOP Assignment 2
//
//  Created by Syed Ahtsham on 4/25/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include "array.h"
#include <iostream>
using namespace std;



int TEMP_VALUE = -12345;

//Default constructor
Array::Array():size(5)
{
    
    ptr = new int[size];
    for(int i=0; i<size; i++)
    {
        ptr[i] = 0;
    }
    
    local_average = 0;
    
    indexLA = global_count;
    global_count++;
    global_size += size;
    
    
}

//Parameterized constructor
Array::Array(int s): size(validateSize(s))
{
    if(size==0)
    {
        ptr = NULL;
    }
    else{
        ptr = new int[size];
        
        for(int i=0; i<size; i++)
        {
            ptr[i] = 0;
        }
        
        local_average = 0;
        indexLA = global_count;
        
        global_count++;
        global_size += size;
        
    }
}

//Copy constructor
Array::Array(const Array &obj):size(obj.size)
{
    if(size == 0)
    {
        ptr = NULL;
    }
    else{
        
        ptr = new int[size];
        
        for(int i=0; i<size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
        
        local_average = 0;
        indexLA = global_count;
        global_count++;
        global_size += size;
    }
}


//Function to validate the size passed
int Array::validateSize(int size)
{
    if(size<0)
        return 1;
    return size;
}


//getter for array size
int Array::getArraySize() const
{
    return size;
}

//Function to update the local average of an object
void Array::updateLocalAverage()
{
    local_average = 0;
       for (int i=0; i<size; i++) {
           local_average += ptr[i];
       }
       
       local_average = local_average/size;
       arrLA[indexLA] = local_average;
}

//getter for getting local average of an array
int Array::getLocalAverage()
{
    this->updateLocalAverage();
    return local_average;
    
}



//Destructor
Array::~Array()
{
    if(size>0){
        delete[] ptr;
    }
    global_size -= size;
    global_count--;
}


//Copy assignment operator overloaded
const Array Array::operator=(const Array &right)
{
    if(right.size==0)
    {
        delete [] ptr;
        ptr = NULL;
        return *this;
    }
    if(ptr==right.ptr)
    {
        return *this;
    }
    if(size==right.size)
    {
        
        for(int i=0; i<size; i++)
        {
            ptr[i] = right.ptr[i];
        }
        
    }
    
    else if(size>right.size)
    {
        for(int i=0; i<right.size; i++)
        {
            ptr[i] = right.ptr[i];
        }
        
    }
    else{
        sizeError(101);
    }
    
    return *this;
    
}



//Error message printing function which will print a specific integer error code
void Array::sizeError(const int errorNo)
{
    if(errorNo==100){
        cout<<"\nERROR 100: Array sizes mismatched..."<<endl;
        
    }
    else{
        cout<<"\nERROR 101: Can't assign a larger size array into a smaller size array..."<<endl;
        
    }
}

//Arithmetic + operator overloaded
Array Array::operator+(const Array &arr)
{
    
    if(size!=arr.size)
    {
        sizeError(100);
        
        Array temp;
        
        return temp;
    }
    
    Array temp(size);
    
    for (int i=0; i<size; ++i) {
        temp.ptr[i] = ptr[i]+arr.ptr[i];
    }
    
    return temp;
    
}

//Arithmetic - operator overloaded
Array Array::operator-(const Array &arr)
{
    
    if(size!=arr.size)
    {
        sizeError(100);
        Array temp;
        
        return temp;
    }
    
    Array temp(size);
    
    for (int i=0; i<size; ++i) {
        temp.ptr[i] = ptr[i]-arr.ptr[i];
    }
    
    
    return temp;
    
}


//Post increment operator overloaded
Array Array::operator++(int)
{
    Array temp(size);
    temp = *this;
    for (int i=0; i<size; ++i) {
        
        ptr[i]++;
        
    }
    updateLocalAverage();
    
    return temp;
}

//Post increment operator overloaded
void Array::operator++()
{
    
    for (int i=0; i<size; ++i) {
        
        ptr[i]++;
        
    }
    updateLocalAverage();
    
}

//Post decrement operator overloaded
Array Array::operator--(int)
{
    Array temp(size);
    temp = *this;
    for (int i=0; i<size; ++i) {
        
        ptr[i]--;
        
    }
    
    updateLocalAverage();
    return temp;
}


//Post decrement operator overloaded
void Array::operator--()
{
    for (int i=0; i<size; ++i) {
        
        ptr[i]--;
        
    }
    
    updateLocalAverage();
    
}

//Subscript out of range error printing method
void Array::subscriptError(const int temp)
{
    cout<<"\nERROR 102: Subscript out of range.,"<<temp<<" returned"<<endl;
    
}

//Subscript operator overloaded
int & Array::operator[](const int &sub)
{
    if(sub < 0 || sub >= size)
    {
        subscriptError(TEMP_VALUE);
        return TEMP_VALUE;
    }
    
    return ptr[sub];
}


//funciton operator overloaded
Array Array::operator()(const int &startInd, const int &endInd)
{
    if(startInd <= 0 || endInd > size)
    {
        Array temp;
        cout<<"\nGiven Range is invalid... Default Array is returned"<<endl;
        return temp;
    }
    Array temp2((endInd-startInd) + 1);
    
    int j=0;
    for(int i=startInd-1; i<endInd; i++, j++)
    {
        temp2[j] = ptr[i];
    }
    
    return temp2;
}


//stream insertion operator overloaded
ostream &operator<<(ostream &out, const Array &obj)
{
    
    out<<"Displaying the Array: "<<endl;
    for(int i=0; i<obj.size; i++)
    {
        out<<obj.ptr[i];
        if(i!=obj.size-1)
            out<<", ";
        
    }
    out<<endl;
    return out;
}


//stream extraction operator overloaded
istream &operator>>(istream &in, Array &obj)
{
    cout<<"Enter the Elements of Array: "<<endl;
    for(int i=0; i<obj.size; i++)
    {
        cout<<"Value at ["<<i<<"]: ";
        in>>obj.ptr[i];
    }
    
    obj.updateLocalAverage();
    return in;
}



//Static variables declaration and initialization
int Array::global_count = 0;
int Array::global_size = 0;
int Array::global_average = 0;

int Array::arrLA[1000] = {0};  //array for storing the local averages of all instances created


