#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <iostream>
#include <iterator>
#include "Lab01.h"

class Student {

    private:
        std::string name;
        std::string surname;
        std::vector<float> grades;
        std::string albumNumber;
        float finalGrade;

        

    public:
        Student(std::string n, std::string s) {
            name = n;
            surname = s;
        }
        void calculateGrade() {
            float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
            finalGrade = (sum / grades.size());
        }
        void print() {
            std::cout << "ID: " << albumNumber << "\n";
            std::cout << name << " " << surname << "\n";
            std::cout << "Grades: ";
            for (float grade : grades) {
                std::cout << grade << ", ";
            }
            std::cout << "\n" << "Mean grade: " << finalGrade << "\n";
        }
        bool addGrade(float grade) {
            if (grade >= 2.0 && grade <= 5.0) {
                grades.push_back(grade);
                return true;
            }
            return false;
        }
        std::string getName() {
            return name;
        }
        void setName(std::string n) {
            name = n;
        }
        void setSurname(std::string sn) {
            surname = sn;
        }
        std::string getSurname() {
            return surname;
        }
        bool setAlbumNumber(std::string an) {
            if (an.length() <= 6 && an.length() >= 5) {
                albumNumber = an;
                return true;
            }
            return false;
        }
        std::string getAlbumNumber() {
            return albumNumber;
        }
        void semesterPassed() {
            int numberOfTwos = std::count(grades.begin(), grades.end(), 2.0);
            if (numberOfTwos <= 1) {
                std::cout << "Passed";
            }
            else {
            std::cout << "Failed";
            }
        }
};

class Complex {
    float re;
    float im;

public:
    Complex(float a = 0, float b = 0) {
        re = a;
        im = b;
    }
    void setR(float a) {
        re = a;
    }
    float getRe() {
        return re;
    }
    void setIm(float b) {
        im = b;
    }
    float getIm() {
        return im;
    }
    void print() {
        if (im < 0) {
            std::cout << re << im << "i";
        }
        else {
            std::cout << re << "+" << im << "i";
        }
    }
    Complex add(Complex complex) {
        re = re + complex.re;
        im = im + complex.im;
        return Complex(re, im);
    }

};

void homeWorkPart1() {
    Student student("Adam", "Jakubiak");
    student.setAlbumNumber("123456");
    student.addGrade(2.0);
    student.addGrade(3.0);
    student.addGrade(3.5);
    student.calculateGrade();
    student.print();
    student.semesterPassed();
}

void homeWorkPart2() {
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.setIm(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i
}

int main()
{
    int choice;
    std::cout << "Which task do you want to run (1-Student, 2-Complex): ";
    std::cin >> choice;
    if (choice == 1) {
        homeWorkPart1();
    }
    else if (choice == 2) {
        homeWorkPart2();
    }
    else {
        std::cout << "Wrong task number";
    }
    return 0;
}