#pragma once
#include<vector>
#include"../Student/student.h"

class StudentList
{
private: 
    // Use C++'s std::vector to store a list of Student objects.
    // Vector is a dynamic array, very flexible and efficient.
    std::vector<Student> students;
public:
    
    StudentList();
    ~StudentList();
    // --- List management methods ---
    
    void addStudent(const std::string &name, float score);
    void editStudent(int id, const std::string &new_name, float new_score);
    bool removeStudent(int id);

    // Returns a pointer so that the original student in the vector can be changed directly
    Student* findStudentById(int id);

    // --- Operator overload [] ---
    // Allows accessing students as an array: studentList[i]
    // Returns by reference (&) so students can be modified (e.g. studentList[0].setName("New Name");)
    Student& operator[](size_t index);
    const Student& operator[](size_t index) const; // const version for constant objects

    // --- Declare Friend ---
    // Allows the function 'printAverageScore' and the operator '<<' to access the private member 'students'.
    
    // Friend function to calculate and print average score.
    friend void printAverageScore(const StudentList &list);

    // Overload operator << to print the entire list to ostream (e.g. std::cout).
    friend std::ostream& operator<<(std::ostream &os, const StudentList &list);
};