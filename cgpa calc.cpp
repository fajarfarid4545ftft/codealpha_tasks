#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name, grade;
    int subjects;
    float creditHours;
    float gradePoint;
    float totalCredits = 0, totalPoints = 0; 

    cout << "===== CGPA Calculator =====" << endl;

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter number of subjects: ";
    cin >> subjects;

    for(int i = 1; i <= subjects; i++) {
        cout << "\nSubject " << i << endl;

        cout << "Enter credit hours: ";
        cin >> creditHours;

        cout << "Enter letter grade (A, B+, B, C+, C, D, F): ";
        cin >> grade;

       
        if(grade == "A") {
            gradePoint = 4.0;
        }
        else if(grade == "B+") {
            gradePoint = 3.5;
        }
        else if(grade == "B") {
            gradePoint = 3.0;
        }
        else if(grade == "C+") {
            gradePoint = 2.5;
        }
        else if(grade == "C") {
            gradePoint = 2.0;
        }
        else if(grade == "D") {
            gradePoint = 1.0;
        }
        else {
            gradePoint = 0.0;  
        }

        
        totalCredits = totalCredits + creditHours;
        totalPoints = totalPoints + (creditHours * gradePoint);
    }

    float cgpa = totalPoints / totalCredits;

    cout << "\n===== Result =====" << endl;
    cout << "Student Name: " << name << endl;
    
    
    cout << fixed << setprecision(2);
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
