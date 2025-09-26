#include<iostream>
#include"student.h"

// *Important*: You must define and initialize the static variable outside the class.
// This line creates the variable 'next_id_' and assigns an initial value of 1.
int Student::next_id = 100;

// --- Implement Constructor ---
Student::Student(const std::string &name, float score)
{
    this->id = next_id++;
    this->name = name;
    this->score = score;
}

Student::~Student()
{
}

// --- Implement Setters ---
void Student::setName(const std::string &new_name)
{
    this->name = new_name;
}

void Student::setScore(float new_score)
{
    this->score = new_score;
}

// --- Implement Getters functions ---
int Student::getID() const
{
    return this->id;
}

const std::string& Student::getName() const
{
    return this->name;
}

float Student::getScore() const
{
    return this->score;
}

// --- Implement Print function ---
void Student::print() const
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Score: " << this->score << std::endl;
}
