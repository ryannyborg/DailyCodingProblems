// Day 2 - 03/20/2021
// Written By: Ryan Nyborg

// This problem was asked by Uber.
// Given an array of integers, return a new array such that each element at index i of the new array 
// is the product of all the numbers in the original array except the one at i. For example, if our 
// input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was 
// [3, 2, 1], the expected output would be [2, 3, 6].

#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int,5> inputArr = {1, 2, 3, 4, 5};
    array<int,5> outputArr = {};

    for(int i = 0; i < inputArr.size(); i++){
        int j = 0;
        int product = 0;
        while(j < inputArr.size()){
            if(j != i){
                if(product == 0){
                    product = inputArr[j];
                }
                else{
                    product = product * inputArr[j];
                } 
            }
            j++;
        }
        outputArr[i] = product;
    }

    for(int k = 0; k < outputArr.size(); k++){
        cout << outputArr[k];
        if (k != outputArr.size() - 1) {
            cout << ", ";
        }
    } 

    return 0;
}