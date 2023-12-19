// Created by: Finn Kitor
// Created on: December 19th, 2023
// This program uses loops to create a list to calculate the average grades inputted from the user
#include <iostream>
#include <vector>

double calc_average(std::vector<int> marks) {
    // Checking if the list of marks is empty
    if (marks.size() == 0) {
        throw std::invalid_argument("List of marks is empty.");
    }
    // Calculating the sum of all marks
    int total = 0;
    for (int mark : marks) {
        total += mark;
    }
    // Calculating the average by dividing the sum by the number of marks
    double average = static_cast<double>(total) / marks.size();
    return average;
}

int main() {
    // Creating an empty list to store the marks
    std::vector<int> marks;
    // Loop to repeatedly ask the user for marks
    while (true) {
        try {
            int mark;
            // Asking the user to enter a mark
            std::cout << "Enter a mark between 0 and 100 (-1 to stop): ";
            std::cin >> mark;
            // Checking if the user wants to stop entering marks
            if (mark == -1) {
                break;
            }
            // Checking if the mark is within the valid range
            if (mark < 0 || mark > 100) {
                throw std::invalid_argument("Invalid mark. Please enter a mark between 0 and 100.");
            }
            // Adding the mark to the list
            marks.push_back(mark);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: Invalid input, you entered a string, not a mark." << std::endl;
        }
    }

    try {  // Calculating the average of the marks
        double average = calc_average(marks);
        // Displaying the average
        std::cout << "Average of marks: " << average << std::endl;
    } catch (std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
