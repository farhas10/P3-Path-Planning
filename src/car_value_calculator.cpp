#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/**
 * A struct for holding information about a car.
 */
struct Car {
    /**
     * The make (brand) of the car.
     */
    string make;
    
    /**
     * The model of the car.
     */
    string model;

    /**
     * The year the car was made.
     */
    int year;

    /**
     * The current value of the car in dollars.
     */
    float price_dollars;

    /**
     * Whether the car is used.
     */
    bool used = false;
};

/**
 * Calculate the value of the car at some point in the future.
 * @param  car The car to calculate the value of.
 * @param  years_from_now The number of years out to estimate the value.
 * @return  The estimated value.
 * 
 * Calculate the value using value = price_now * e^(-r * t) where r is the depreciation
 * rate and t is the years_from_now. Let's say Mercedes cars have a depreciation of 15%
 * or 0.15, and Teslas have a depreciation of 25% or 0.25. All other cars have a rate of
 * 20% or 0.20.
 */
float calculateCarValue(Car car, float years_from_now) {

    //Tesla rate condition.
    if (car.make == "Tesla" || car.make == "tesla"){
        return (car.price_dollars * pow(2.7182818, -0.25 * years_from_now));
    }

    //Mercedes rate condition.
    else if (car.make == "Mercedes" || car.make == "mercedes"){
        return (car.price_dollars * pow(2.7182818, -0.15 * years_from_now));
    }

    //All else rate condition.
    else{
        return (car.price_dollars * pow(2.7182818, -0.20 * years_from_now));
    }

}

int main() {

    // *** Task: Collect information about the car then calculate its value with calculate_car_value() *** //
    Car car;
    int depreciation;
    cout << "Enter the make of your car: " << "\n";
    cin >> car.make;
    cout << "Enter the model of your car: " << "\n";
    cin >> car.model;
    cout << "Enter the year of your car: " << "\n";
    cin >> car.year;
    cout << "Enter the current price of your car: " << "\n";
    cin >> car.price_dollars;
    cout << "How long would you like to calculate the depreciation?" << "\n";
    cin >> depreciation;
    cout << "In " << depreciation << " years, the car will be worth: " << calculateCarValue(car, depreciation) << "\n";
    
    // *** End Student Code *** //

    return 0;
}