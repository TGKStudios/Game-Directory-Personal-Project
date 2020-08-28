// FreeFormPairsTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class payCalc
{
public:
    float weeklyAdd(float pay, int hoursWorked)
    {
        return (pay * hoursWorked) ;
    }

    float biWeeklyAdd(float pay, int hoursWorked)
    {
        return (pay * hoursWorked) * 2;
    }

    float monthlyAdd(float pay, int hoursWorked)
    {
        return (pay * hoursWorked) * 4;
    }

    float anuallyAdd(float pay, int hoursWorked)
    {
        return (pay * hoursWorked) *52 ;
    }
};

template<typename T, typename U>
void processInput(payCalc p)
{
    T payTemp;
    U hoursTemp;
    std::cout << "Enter your hourly pay\n";
    std::cin >> payTemp;
    std::cout << "Enter the average number of hours you work per hour (20,40,etc.)\n";
    std::cin >> hoursTemp;

    std::cout << "Your weekly pay is: " << p.weeklyAdd(payTemp, hoursTemp) << "\n";
    std::cout << "Your biweekly pay is: " << p.biWeeklyAdd(payTemp, hoursTemp) << "\n";
    std::cout << "Your monthly pay is: " << p.monthlyAdd(payTemp, hoursTemp) << "\n";
    std::cout << "Your annual pay is: " << p.anuallyAdd(payTemp, hoursTemp) << "\n";

    return;
}
int main()
{
    payCalc p;
    processInput<float, int>(p);
    
}