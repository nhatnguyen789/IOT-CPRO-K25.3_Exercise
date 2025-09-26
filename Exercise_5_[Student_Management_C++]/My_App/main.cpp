#include<iostream>
#include<limits>
#include"../Student_List/student_list.h"

void displayMenu()
{
    std::cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Edit Student\n";
    std::cout << "3. Remove Student\n";
    std::cout << "4. Print Student List\n";
    std::cout << "5. Print Average Score\n";
    std::cout << "0. Exit\n";
    std::cout << "=====================================\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    StudentList myClass;
    int choice;

    // Add some sample students
    myClass.addStudent("Michael Faraday", 9.5);
    myClass.addStudent("Thomas Edison", 8.0);

    while(true)
    {
        displayMenu();
        std::cin >> choice;

        // Check if input is valid
        if(std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore incorrect input
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean up the buffer after reading the number
        
        switch(choice)
        {
            // Add Student
            case 1: 
            {
                std::string name;
                float score;
                std::cout << "Enter name: ";
                getline(std::cin, name);
                std::cout << "Enter score: ";
                std::cin >> score;
                myClass.addStudent(name, score);
                std::cout << "Student added successfully!\n";
                break;
            }
            case 2: // Edit Student
            {
                int id;
                std::cout << "Enter ID of Student to edit: ";
                std::cin >> id;
                Student* student = myClass.findStudentById(id);
                if(student)
                {
                    std::string new_name;
                    float new_score;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter new name: ";
                    getline(std::cin, new_name);
                    std::cout << "Enter new score: ";
                    std::cin >> new_score;
                    student->setName(new_name);
                    student->setScore(new_score);
                    std::cout << "Student updated successfully!\n";
                }
                else
                {
                    std::cout << "Student with ID " << id << "not found!\n";
                }
                break;
            }
            case 3: // Remove Student
            {
                int id;
                std::cout << "Enter ID of student to remove: ";
                std::cin >> id;
                if(myClass.removeStudent(id))
                {
                    std::cout << "Student removed successfully!\n";
                }
                else
                {
                    std::cout << "Student with ID " << id << "not found.\n";
                }
                break;
            }
            case 4: //Print Student List
                // Use overloaded << operator to print the entire list.
                std::cout << myClass;
                break;
            case 5: //Print Average Score
                // Call friend function to print average score.
                printAverageScore(myClass);
                break;
            case 0: // Exit
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again\n";
                break;
        }
    }
    return 0;
}