#include <iostream>
#include <vector>
#include <numeric>
class Student {

private:
    std::string name;
    std::string surname;
    std::vector<float> grades;
    std::string album_number;
    float final_grade;
public:
    Student(std::string n, std::string s) {
        name = n;
        surname = s;
    }
    Student(std::string n) {
        name = n;
    }
    void calculate_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        finalGrade = (sum / grades.size());
    }
    void print() {
        std::cout << name << " " << surname << ": ";
        for (float grade : grades) {
            std::cout << grade << ",";
        }
        std::cout << "Final grade: " << finalGrade << "\n";
    }
    bool add_grade(float grade) {
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
};


int main()
{
    Student student("Adam", "J"); /*{ "Adam", "J", {5.0, 4.5, 3.0} };*/
    Student student2("Jan");
    for (int i = 0; i <= 5; i++) {
        student.add_grade(i);
    }
    student.calculate_grade();
    student.print();
    std::cout << student.getName() << "\n";
    student.setName("Marek");
    std::cout << student.getName() << "\n";
    return 0;
}