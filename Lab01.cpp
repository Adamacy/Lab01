#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <iostream>
#include <iterator>

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


int main()
{
    Student student("Adam", "Jakubiak");
    student.setAlbumNumber("123456");
    student.addGrade(2.0);
    student.addGrade(3.0);
    student.addGrade(3.5);
    student.calculateGrade();
    student.print();
    student.semesterPassed();
    return 0;
}