#pragma once // Modern preprocessor directive, ensures this file is only included once
#include<string.h>

class Student
{
private:
    // Private properties, only accessible from within the class
    int id;
    std::string name;
    float score;
    // A static variable is a variable that is shared by ALL objects of the Student class.
    // We use it to create an auto-increment ID, ensuring each student has a unique ID.
    static int next_id;   //static member
public:
    // Constructor: Function called when a new Student object is created.
    Student(const std::string &name, float score);
    ~Student();
    // --- Setters (to change information) ---
    //void setID(int new_id);
    void setName(const std:: string &new_name);
    void setScore(float new_score);

    // --- Getters (to get information) ---
    // The 'const' keyword at the end ensures these functions do not change the state of the object.
    int getID() const;
    const std::string& getName() const; // Return const reference for efficiency, avoid copying string
    float getScore() const;

    // Utility function to print a student's information
    void print() const;
};
