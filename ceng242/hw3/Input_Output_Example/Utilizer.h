#ifndef HW3_UTILIZER_H
#define HW3_UTILIZER_H

#include <random>
#include <iostream>
#include <fstream>
#include <string>

// Use this class as-is.
// Usage Example:
// double new_performance = Utilizer::generatePerformance();
// Car newCar = Car("blabla", new_performance);

// int laptime_variance = Utilizer::generateLaptimeVariance(car_performance);
// Laptime variance(laptime_variance)


// DO NOT MODIFY THIS FILE.
// YOU WILL NOT SUBMIT THIS FILE

class Utilizer {
private:
    
    

public:

    static double generatePerformance() {
        static int line= 1;
        int line_no = 0;
        double value=0.0;
        std::string sLine = "";
        std::ifstream read;
        std::size_t offset = 0;
        read.open("performance.txt");

        while (line_no != line && getline(read, sLine)) {
            ++line_no;
        }

        if (line_no == line) {
            value = std::stod(sLine,&offset);
        } else {
            std::cout<<"ERROR"<<std::endl;
        }
        line++;

        
        return value;

    }
    static int generateLaptimeVariance(double performance) {
        static int line= 1;
        int line_no = 0;
        int value;
        std::string sLine = "";
        std::ifstream read;
        std::size_t offset = 0;
        read.open("laptime_variance.txt");

        while (line_no != line && getline(read, sLine)) {
            ++line_no;
        }

        if (line_no == line) {
            value = std::stoi(sLine,&offset);
        } else {
            std::cout<<"ERROR"<<std::endl;
        }
        line++;
        return value;
        
    }

    static int generateAverageLaptime() {
        static int line= 1;
        int line_no = 0;
        int value = 0;
        std::string sLine = "";
        std::ifstream read;
        std::size_t offset = 0;
        read.open("average_laptimes.txt");
        while (line_no != line && getline(read, sLine)) {
            ++line_no;
        }

        if (line_no == line) {
            value = std::stoi(sLine,&offset);
        } else {
            std::cout<<"ERROR"<<std::endl;
        }
        line++;
        return value;
        
    }
};


#endif //HW3_UTILIZER_H