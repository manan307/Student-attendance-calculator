# Student-attendance-calculator
This C program is designed to manage student attendance records. It provides functionality for adding, displaying, searching, modifying, and deleting student details. Additionally, it allows for authentication to ensure that only authorized users can access the system.

Here's a breakdown of the main functionalities and components of the code:

Struct Definition: The program defines a struct student, which contains fields for student name, roll number, attendance for each course, and total attendance.

Global Variables: It declares an array students to store student records and total_students to keep track of the number of students.

Functions:

login: Authenticates users with a predefined username and password.
insert_student: Allows users to input student details including name, roll number, and attendance for each course. Calculates and displays aggregate attendance.
display_students: Displays all stored student details including name, roll number, aggregate attendance, and attendance for each course.
search_student_by_roll_number: Searches for a student by roll number and displays their details if found.
search_student_by_name: Searches for a student by name and displays their details if found.
delete_student: Deletes a student record based on the roll number.
modify_student: Modifies student details based on roll number.
attendence_percentage: Calculates and displays attendance percentage for a student.
save_data and load_data: Save and load student data to/from a file named "students.dat".
Main Function:

Authenticates the user through the login function.
Loads existing student data from the file.
Enters a loop to continuously prompt the user for choices until they choose to exit.
Provides a menu with options to perform various operations such as inserting student details, displaying students, searching by roll number or name, calculating attendance, deleting, modifying, saving data, or exiting the program.
Overall, this program serves as a basic student attendance management system, allowing administrators to manage student records efficiently. It incorporates file handling for data persistence and basic user authentication for security. However, there are areas for improvement such as input validation and error handling to enhance robustnes and reliability.
