//
//  array.h
//  OOP Assignment 2
//
//  Created by Syed Ahtsham on 4/25/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#ifndef array_h
#define array_h



#include <iostream>
using namespace std;


class Array;        //Forward declaration

//Function prototypes for overloaded << and >> operators
ostream &operator<<(ostream &, const Array &);
istream &operator>>(istream &, Array &);



class Array{
    
private:
    
    int * ptr;
    const int size;
    int local_average;
    int indexLA;  //indexLA member variable will be used as index for storing local average of objects into an array
    
    static int global_count;
    static int global_size;
    static int global_average;
    
    static int arrLA[1000];
    
    int validateSize(int );
    

    
public:
    
    //Constructors
    Array();
    Array(int);
    Array(const Array&);
    
    
    //getters for size and local average
    int getArraySize() const;
    int getLocalAverage();
    
    //Funcion to update the local average of an instance
    void updateLocalAverage();
    
    
    //static getters for static variables
    
    //getter for static variable global count to return total number of objects created
    static int getGlobalCount() {
        
        return global_count;
    }

    //getter for global size to return total size allocated to array instances
    static int getGlobalSize(){
        return global_size;
    }


    //getter for static variable globalAverage to calculate and return the Global average
    static int getGlobalAverage()
    {
        
        int tempAvg = 0;
        for(int i=0; i<global_count; i++)
        {
            tempAvg += arrLA[i];
        }
        
        tempAvg = tempAvg/global_count;
        
        return tempAvg;
    }
    
    
    
    //Copy Assignment operator overloaded
    const Array operator=(const Array &);
  
    //Arithmetic operator overloaded
    Array operator+(const Array &);
    Array operator-(const Array &);
    
    //Post increment and post decrement operators overloaded
    Array operator++(int);
    void operator++();
    
    //post decrement operators overloaded
    Array operator--(int);
    void operator--();
    
    //Error message printing functions
    void sizeError(const int);
    void subscriptError(const int );
    
    //Subscript and Function operators overloaded
    int &operator[](const int &);
    Array operator()(const int &, const int &);
    
    
    //Stream insertion and stream extraction operators overloaded
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);
    
    //Destructor
    ~Array();
    
};



#endif /* array_h */
