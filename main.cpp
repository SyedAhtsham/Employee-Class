//
//  main.cpp
//  OOP Assignment 2
//
//  Created by Syed Ahtsham on 4/15/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include <iostream>
#include "array.h"
using namespace std;

int main() {
    
    
// *************************************************************************************
    
    //CODE FOR DEMONSTRATING THE ORDERLY FASHION INPUT FROM THE USER FOR ARRAY SIZE, AND ELEMENTS
    // THIS IS DONE IN ANOTHER SCOPE INSIDE THE MAIN
    
// *************************************************************************************
    
    
//    {
//
//    int no_of_instances = 0;
//
//    do
//    {
//        cout<<"Please enter valid number of Array instances you want to create: ";
//        cin>>no_of_instances;
//
//    }while(no_of_instances <= 0);
//
//
//    Array *objArr[no_of_instances];
//
//    int size = 0;
//
//    for(int i=0; i<no_of_instances; i++ )
//    {
//        do
//        {
//            cout<<endl;
//            cout<<"Enter the size of Array-"<<i+1<<" : ";
//            cin>>size;
//
//        }while(size <= 0);
//
//        cout<<endl;
//        objArr[i] = new Array(size);
//        cin>>*objArr[i];
//
//    }
//
//    cout<<endl;
//    cout<<endl;
//
//    cout<<"Global Average: "<<Array::getGlobalAverage()<<endl;
//
//    }
//
    
    
// *************************************************************************************
    
    //CODE FOR DEMONSTRATING THE OVERLOADED OPERATORS AND OTHER FUNCTIONS
    
// *************************************************************************************

    
    
    Array arr1(4);
    Array arr2(6);
    
    
    //INPUT THE ARR1 FROM THE USER
    cin>>arr1;
    cout<<endl;
    
    //INPUT THE ARR2 FROM THE USER
    cin>>arr2;
    cout<<endl;
    
    //DISPLAYING THE LOCAL AVERAGE OF ARR1
    cout<<"Displaying Local Average of Array arr1: "<<arr1.getLocalAverage()<<endl;
    
    //PRINTING THE GLOBAL AVERAGE
    cout<<"Global Average: "<<Array::getGlobalAverage()<<endl<<endl;
    
    
    //NOW CHANGING VALUE AT SOME INDEX OF AN ARRAY
    cout<<"Enter a new value at index '2' of Array arr1: ";
    cin>>arr1[2];
    
    //AND THEN DISPLAYING THE NEW LOCAL AND GLOBALE AVERAGE
    cout<<"\nDisplaying New Local Average of Array-1: "<<arr1.getLocalAverage()<<endl;
    cout<<"Global Average: "<<Array::getGlobalAverage()<<endl<<endl;
    
    
    //TESTING THE STREAM EXTRACTION OVERLOADED OPERATOR
    cout<<"Taking input for Array arr1 from the user: "<<endl;
    cin>>arr1;
    
    //TESTING THE STREAM INSERTION OVERLOADED OPERATOR
    cout<<"\nDisplaying the data of Array arr1: "<<endl<<endl;
    cout<<arr1;
    
    //AND THEN DISPLAYING THE NEW LOCAL AND GLOBAL AVERAGE
      cout<<"\nDisplaying New Local Average of Array-1: "<<arr1.getLocalAverage()<<endl;
      cout<<"Global Average: "<<Array::getGlobalAverage()<<endl<<endl;
    
    
    //TESTING THE ARITHMETIC + OVERLOADED OPERATOR WHERE SIZES ARE NOT SAME
    Array temp = arr1+arr2;
    
    if(temp.getArraySize() == arr1.getArraySize() && temp.getArraySize() == arr2.getArraySize())
    {
        cout<<"Sum of two Arrays: "<<temp;
    }
    
    //TESTING THE ARITHMETIC - OVERLOADED OPERATOR WHERE SIZES ARE NOT SAME
    Array temp2 = arr1-arr2;
    
    if(temp2.getArraySize() == arr1.getArraySize() && temp2.getArraySize() == arr2.getArraySize())
    {
        cout<<"Sum of two Arrays: "<<temp2;
    }
    
    Array arr3(3);
    Array arr4(3);
    
    cin>>arr3;
    cout<<endl;
    cin>>arr4;
    
    //TESTING THE ARITHMETIC + OVERLOADED OPERATOR
    cout<<"Sum of Two Arrays: "<<arr3+arr4<<endl;
    
    //TESTING THE ARITHMETIC - OVERLOADED OPERATOR
    cout<<"Difference of arr3 and arr4 : "<<arr4-arr3<<endl;
    
    
    //TESTING THE SUBSCRIPT [] OVERLOADED OPERATOR
    cout<<"Printing value at 1st index of Array arr3: "<<arr3[1]<<endl<<endl;
    
    //TESTING THE FUNCTION () OVERLOADED OPERATOR
    cout<<"Printing the values from 2nd to 4th index of Array arr2: "<<arr2(2,4)<<endl<<endl;
    
    
    //TESTING THE OVERLOADED POST INCREMENT ++ OPERATOR
    arr1++;
    cout<<arr1<<endl<<endl;
    
    
    //AND THEN DISPLAYING THE NEW LOCAL AND GLOBAL AVERAGE
    cout<<"\nDisplaying New Local Average of Array-1: "<<arr1.getLocalAverage()<<endl;
    cout<<"Global Average: "<<Array::getGlobalAverage()<<endl<<endl;
    
    
    //TESTING THE OVERLOADED POST DECREMENT -- OPERATOR
    arr2--;
    cout<<arr2<<endl<<endl;
    
    
    //AND THEN DISPLAYING THE NEW LOCAL AND GLOBAL AVERAGE
    cout<<"\nDisplaying New Local Average of Array-1: "<<arr2.getLocalAverage()<<endl;
    cout<<"Global Average: "<<Array::getGlobalAverage()<<endl<<endl;
    
    
    
    //DISPLAYING TOTAL NUMBER OF ARRAY INSTANCES CREATED AND TOTAL SIZE OF ARRAY OBJECTS
    cout<<"Total Number of Array Objects: "<<Array::getGlobalCount()<<endl<<endl;
    cout<<"Total Size of Array Objects: "<<Array::getGlobalSize()<<endl<<endl;
    cout<<endl;
    
    
    
    return 0;
}
