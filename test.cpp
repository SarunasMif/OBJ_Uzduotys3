#include "headers_vector.h"
#include "Studentas.h"
//g++ -o test test.cpp Studentas.cpp

void test_constructors() {
    // Test default constructor
    Student_Data s1;
    cout << "Default constructor:" << endl;
    cout << "Name: " << s1.vardas() << endl;
    cout << "Surname: " << s1.pavarde() << endl;
    cout << "HW: ";
    for (double grade : s1.ND()) {
        cout << grade << " ";
    }
    cout << endl << "Exam: " << s1.egzaminas() << endl;
    cout << ".........................................." << endl;
    // Test constructor with input stream
    istringstream iss("John Doe 1 1 1 1 1");
    Student_Data s2;
    cout << "Test with input stream" << endl << endl;
    cout << "Data to be inputed: Name(John), Surname(Doe), HW(1 1 1 1), Exam(1)" << endl;
    cout << "Original s2 data (before input): " << endl;
    cout << "Name: " << s2.vardas() << endl;
    cout << "Surname: " << s2.pavarde() << endl;
    cout << "HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "Exam: " << s2.egzaminas() << endl << endl;
    s2.readStudent(iss);
    cout << "s2 data (after input): " << endl;
    cout << "Name: " << s2.vardas() << endl;
    cout << "Surname: " << s2.pavarde() << endl;
    cout << "HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "Exam: " << s2.egzaminas() << endl;
    cout << ".........................................." << endl;

    // Test copy constructor
    cout << "Test copy construtor" << endl << endl;
    cout << "Original s2 data: " << endl;
    cout << "s2. Name: " << s2.vardas() << endl;
    cout << "s2. Surname: " << s2.pavarde() << endl;
    cout << "s2. HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s2. Exam: " << s2.egzaminas() << endl << endl;

    Student_Data s3;
    cout << "Original s3 data (before copy): " << endl;
    cout << "s3. Name: " << s3.vardas() << endl;
    cout << "s3. Surname: " << s3.pavarde() << endl;
    cout << "s3. HW: ";
    for (double grade : s3.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s3. Exam: " << s3.egzaminas() << endl << endl;

    s3 = s2;

    cout << "s2 data (after copy): " << endl;
    cout << "s2. Name: " << s2.vardas() << endl;
    cout << "s2. Surname: " << s2.pavarde() << endl;
    cout << "s2. HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s2. Exam: " << s2.egzaminas() << endl << endl;

    cout << "s3 data (after copy): " << endl;
    cout << "s3. Name: " << s3.vardas() << endl;
    cout << "s3. Surname: " << s3.pavarde() << endl;
    cout << "s3. HW: ";
    for (double grade : s3.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s3. Exam: " << s3.egzaminas() << endl;
    cout << ".........................................." << endl;
    // Test move constructor
    cout << "Test move constructor" << endl << endl;
    cout << "Original s3 data (before move): " << endl;
    cout << "s3. Name: " << s3.vardas() << endl;
    cout << "s3. Surname: " << s3.pavarde() << endl;
    cout << "s3. HW: ";
    for (double grade : s3.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s3. Exam: " << s3.egzaminas() << endl << endl;
    Student_Data s4;
    cout << "Original s4 data (before move): " << endl;
    cout << "s4. Name: " << s4.vardas() << endl;
    cout << "s4. Surname: " << s4.pavarde() << endl;
    cout << "s4. HW: ";
    for (double grade : s4.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s4. Exam: " << s4.egzaminas() << endl << endl;

    s4 = move(s3);
    cout << "s3 data (after move): " << endl;
    cout << "s3. Name: " << s3.vardas() << endl;
    cout << "s3. Surname: " << s3.pavarde() << endl;
    cout << "s3. HW: ";
    for (double grade : s3.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s3. Exam: " << s3.egzaminas() << endl << endl;

    cout << "s4 data (after move): " << endl;
    cout << "s4. Name: " << s4.vardas() << endl;
    cout << "s4. Surname: " << s4.pavarde() << endl;
    cout << "s4. HW: ";
    for (double grade : s4.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s4. Exam: " << s4.egzaminas() << endl;
    cout << ".........................................." << endl;
}

void test_assignment_operators() {
    // Test copy assignment
    istringstream iss("John Doe 1 1 1 1 1");
    Student_Data s1;
    s1.readStudent(iss);
    cout << "Test copy assignment" << endl << endl;
    cout << "s1 data (before copy assigment): " << endl;
    cout << "s1. Name: " << s1.vardas() << endl;
    cout << "s1. Surname: " << s1.pavarde() << endl;
    cout << "s1. HW: ";
    for (double grade : s1.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s1. Exam: " << s1.egzaminas() << endl << endl;
    
    Student_Data s2;
    cout << "Original s2 data (before copy assigment): " << endl;
    cout << "s2. Name: " << s2.vardas() << endl;
    cout << "s2. Surname: " << s2.pavarde() << endl;
    cout << "s2. HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s2. Exam: " << s2.egzaminas() << endl << endl;

    s2 = s1;
    cout << "s1 data (after copy assignment): " << endl << endl;

    cout << "s1. Name: " << s1.vardas() << endl;
    cout << "s1. Surname: " << s1.pavarde() << endl;
    cout << "s1. HW: ";
    for (double grade : s1.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s1. Exam: " << s1.egzaminas() << endl << endl;

    cout << "s2 data (after copy assigment): " << endl;
    cout << "s2. Name: " << s2.vardas() << endl;
    cout << "s2. Surname: " << s2.pavarde() << endl;
    cout << "s2. HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s2. Exam: " << s2.egzaminas() << endl << endl;
    cout << ".........................................." << endl;

    // Test move assignment
    cout << "Test move assignment" << endl << endl;
    cout << "s2 data (before move assigment): " << endl;
    cout << "s2. Name: " << s2.vardas() << endl;
    cout << "s2. Surname: " << s2.pavarde() << endl;
    cout << "s2. HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s2. Exam: " << s2.egzaminas() << endl << endl;
    Student_Data s3;
    cout << "s3 data (before move assigment): " << endl;
    cout << "s3. Name: " << s3.vardas() << endl;
    cout << "s3. Surname: " << s3.pavarde() << endl;
    cout << "s3. HW: ";
    for (double grade : s3.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s3. Exam: " << s3.egzaminas() << endl << endl;

    s3 = move(s2);

    cout << "s2 data (after move assigment): " << endl;
    cout << "s2. Name: " << s2.vardas() << endl;
    cout << "s2. Surname: " << s2.pavarde() << endl;
    cout << "s2. HW: ";
    for (double grade : s2.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s2. Exam: " << s2.egzaminas() << endl << endl;

    cout << "s3 data (after move assigment): " << endl;
    cout << "s3. Name: " << s3.vardas() << endl;
    cout << "s3. Surname: " << s3.pavarde() << endl;
    cout << "s3. HW: ";
    for (double grade : s3.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s3. Exam: " << s3.egzaminas() << endl << endl;
    
    cout << ".........................................." << endl;
}

void test_input_output_methods() {
    // Test manual input
    Student_Data s1;
    cout << "Test manual Input/Output" << endl << endl;
    cout << "s1 data (before manual input): " << endl;
    cout << "s1. Name: " << s1.vardas() << endl;
    cout << "s1. Surname: " << s1.pavarde() << endl;
    cout << "s1. HW: ";
    for (double grade : s1.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s1. Exam: " << s1.egzaminas() << endl << endl;

    s1.SetName("John");
    s1.SetSurname("Doe");
    s1.SetHW({3, 3, 3, 3});
    s1.SetExam(3);

    cout << "s1 data (after manual input): " << endl;
    cout << "s1. Name: " << s1.vardas() << endl;
    cout << "s1. Surname: " << s1.pavarde() << endl;
    cout << "s1. HW: ";
    for (double grade : s1.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s1. Exam: " << s1.egzaminas() << endl << endl;
    cout << ".........................................." << endl;

}

void test_AverageCalculations() {
    istringstream iss("John Doe 6 7 3 4 9 8");
    Student_Data s1;
    s1.readStudent(iss);
    cout << "Test average calculations" << endl << endl;
    cout << "s1 data to be used for calculations: " << endl;
    cout << "s1. HW: ";
    for (double grade : s1.ND()) {
        cout << grade << " ";
    }
    cout << endl << "s1. Exam: " << s1.egzaminas() << endl << endl;

    cout << "Test median grade calculations (answer should be 7.2): " << median_grade(s1) << endl;
    cout << "Test average grade calculations (answer should be 7.12): " << avg_grade(s1) << endl;

    cout << ".........................................." << endl;
}

void test_Person_accesability() {
    // Person Sdata;

    // string name = "John";
    // string surname = "Doe";

    // Sdata.SetName(name);
    // Sdata.SetSurname(surname);

    // cout << Sdata.vardas() << " " << Sdata.pavarde() << endl;
}

int main() {
    test_constructors();
    test_assignment_operators();
    test_input_output_methods();
    test_AverageCalculations();
    //test_Person_accesability();
    
    system ("pause");
}