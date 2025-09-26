#include<iostream>
#include<string.h>
#include"student_list.h"

StudentList::StudentList()
{
}

StudentList::~StudentList()
{
}

void StudentList::addStudent(const std::string &name, float score)
{
    // Create a new Student object and add it to the end of the vector.
    students.push_back(Student(name, score));
}

bool StudentList::removeStudent(int id)
{
    // Iterate through the vector to find the student with the matching ID.
    for(auto i = students.begin(); i != students.end(); ++i)
    {
        if(i->getID() == id)
        {
            // If found, remove from vector and return true.
            students.erase(i);
            return true;
        }
    }
    // If not found, return false.
    return false;
}

Student* StudentList::findStudentById(int id)
{
    // Iterate through the vector
    for(auto &student : students)
    {
        if(student.getID() == id)
        {
            // Returns the address of the found student
            return &student;
        }
    }
    // If not found, return null pointer.
    return nullptr;
}

// --- Operator overloading implementation ---
Student& StudentList::operator[](size_t index)
{
    return students[index];
}

const Student& StudentList::operator[](size_t index) const
{
    return students[index];
}

// --- Implementing Friend functions ---
// Note: Friend functions are implemented like normal functions, without StudentList::
void printAverageScore(const StudentList& list)
{
    if(list.students.empty())
    {
        std::cout << "The list is empty. No average score." << std::endl;
        return;
    }

    float totalscore = 0.0f;
    // Use range-based for loop to iterate over the list.
    // 'list.students_' is accessible because this function is a friend.
    for(const auto& student : list.students)
    {
        totalscore += student.getScore();
    }

    std::cout << "Average score of: " << list.students.size() << " students is: "
              << totalscore / list.students.size() << std::endl; 
}

std::ostream& operator<<(std::ostream& os, const StudentList& list)
{
    os << "--- Student List ---" << std::endl;
    if(list.students.empty())
    {
        os << "No students in the list." << std::endl;
    }
    else
    {
        // 'list.students_' is accessible because this function is a friend.
        for(const auto& student : list.students)
        {
            // Use the print() function of the Student class
            os << "Name: " << student.getName() << std::endl; 
            os << "ID: " << student.getID() << std::endl;
            os << "Score: " << student.getScore() << std::endl;
        }
    }
    os << "--------------------" << std::endl;
    return os;
}