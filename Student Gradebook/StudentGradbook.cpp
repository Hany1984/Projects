// 🎓 Student Gradebook
// Description:
// Create a system to manage student grades for multiple subjects.
// Each student has a name, ID, and marks in 3 subjects.
// The program should calculate the total, average, and grade for each student, and support adding multiple students.
// Use vector to store student objects, and optionally save/load data using CSV.

// Requirements:
    // Create class Student with:
        // Private members: id, name, marks[3].
        // Methods:
            // getTotal()
            // getAverage()
            // getGrade() → returns A, B, C, or F based on average.
    // Create class Gradebook with:
        // A vector<Student> to store multiple students.
        // Methods to:
            // Add a new student.
            // Display all students with totals and grades.
            // Sort students by average marks (highest first).
            // (Optional) Save/load students to a CSV file.