// Day 1 - 03/19/2021
// Written By: Ryan Nyborg

// This problem was recently asked by Google.
// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

#include <iostream>

using namespace std;

class UserNumbers {
    private:
        int k; // if 2 numbers equal k, then return true
        int list[100];
    public: 
        bool AnyPairEqToInput(int);
        void set_values (int[], int);
};

bool UserNumbers::AnyPairEqToInput (int arrSize) {
    int sum;
    //int arrSize = *(&list + 1) - list;
    bool result = false;

    for(int i=0; i<arrSize; i++){
        for(int j=i+1; j<arrSize; j++){
            sum = list[i] + list[j];
            if(sum == k){
                result = true;
                return result;
            }
        }
    }
    return result;
}

void UserNumbers::set_values (int x[], int y){
    int arrSize = *(&list + 1) - list;

    for(int i=0; i<arrSize; i++){
        list[i] = x[i];
    }
    k = y;
}

int main(){
    UserNumbers userNums;
    int arrSize = 0;
    int k;
    
    while(arrSize < 2 || arrSize > 100){
        cout << "How many numbers (between 2 and 100) do you want to add? ";
        cin >> arrSize;
        cout << "You've entered " << arrSize << "\n";
    }

    int userInput[arrSize];

    for(int i=0; i<arrSize; i++){
        cin >> userInput[i];
    }

    cout << "Enter sum to check for: ";
    cin >> k;
    
    userNums.set_values(userInput, k);
    bool result = userNums.AnyPairEqToInput(arrSize);
    cout << "Result is " << boolalpha << result;

    return 0;
}