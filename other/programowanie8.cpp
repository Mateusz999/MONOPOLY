#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;
int indexId=0;
// Struktura opisująca ocenę
struct Grade {
    int grade;
    string date;
    string instructor;
};

// Struktura opisująca przedmiot
struct Course {
    string name;
    vector<Grade> grades;
    Grade grade;
};

// Struktura opisująca studenta
struct Student {
    int id;
    string name;
    int currentSemester;
    map<int, vector<Course>> semesterCourses; // Historia kursów na poszczególnych semestrach
};

// Funkcja do dodawania oceny do przedmiotu
void addGrade(Course& course, int grade, string date, string instructor) {
    Grade newGrade = {grade, date, instructor};
    course.grade = newGrade;
}

// Funkcja do dodawania przedmiotu do semestru
void addCourseToSemester(Student *student, int semester, Course *course) {
    student->semesterCourses[semester].push_back(*course);
}

// Funkcja do wyświetlania ocen dla danego przedmiotu
void displayGrades( Course course) {
    cout << "Name for course: " << course.name << " Grade: " << course.grade.grade<< " date: " << course.grade.date << " instructor : " <<  course.grade.instructor<<endl;
        
}


void menu(int &choice){
    cout << "===================================="<<endl;
    cout << "No.    Option"<<endl;
    cout << "===================================="<<endl;
    cout <<"1.      Add student   "<<endl;
    cout <<"2.      Delete student   "<<endl;
    cout <<"3.      Modify student   "<<endl;
    cout <<"4.      Display students   "<<endl;
    cout <<"5.      Search student   "<<endl;
    cout <<"6.      Student semestral history   "<<endl;
    cout <<"0.      Exit   "<<endl;
    cout << "Enter your choice: ";
    cin >> choice;


};
void displayStudents(vector<Student>& studentsList){
    cout << "====================================" << endl;
    cout << setw(3) << "Id." << setw(10) << "Name" << setw(10) << "Semester" << setw(10) << "Story" << endl;
    cout << "====================================" << endl;
    for(Student el : studentsList){
        cout << setw(3) << el.id << setw(10) << el.name << setw(10) << el.currentSemester << setw(10);
        if(el.semesterCourses.empty())cout << " No"<<endl;
        else cout << " Yes"<<endl;

    }
}
void displaySemester(Student &student) {
    int semester;
    cout << "Which semester do you want to see? : ";
    cin >> semester;
    cout << "\n";

 
        // Pobranie kursów dla danego semestru
        const vector<Course>& semestr = student.semesterCourses.at(semester);
        
        // Wyświetlenie kursów
        for (const Course& el : semestr) {
            displayGrades(el);
        }
    } 
// Funkcja do wyświetlania wszystkich przedmiotów na danym semestrze
void displayCoursesForSemester(const map<int, vector<Course>>& semesterCourses, int semester) {
    cout << "Courses for semester " << semester << ":\n";
   
   auto it = semesterCourses.find(semester);
   for (const Course& course : it->second) {

            displayGrades(course);
        }
}


void semestralMenu(int &choice){

    
    cout << "===================================="<<endl;
    cout << "No.    Option"<<endl;
    cout << "===================================="<<endl;
    cout <<"1.      Add new course   "<<endl;
    cout <<"2.      Display selected semester   "<<endl;
    cout <<"3.      Display all semesters   "<<endl;
    cout <<"4.      Delete  course  "<<endl;
    cout <<"5.      Delete semester   "<<endl;
    cout <<"6.      Modify grade   "<<endl;
    cout <<"0.      Exit   "<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
   

};
Student& selectedStudent(vector<Student>&studentsList, int id){
    for(Student &el : studentsList){
       if(el.id == id){
        cout << el.name;
        cout << el.semesterCourses.empty();
            return el;
            
       } 
}
};
void addNewCourse(Student* selectedStudent) {
    Course* nowy = new Course; // Tworzenie obiektu dynamicznego
    int semesterNumber;
    cout << "Enter name: "; cin >> nowy->name;
    cout << "Enter grade"; cin >> nowy->grade.grade;
    cout << "Enter date"; cin >> nowy->grade.date;
    cout << "Enter instructor"; cin >> nowy->grade.instructor;
    cout << "Enter semester No : "; cin >> semesterNumber;
    addCourseToSemester(selectedStudent, semesterNumber, nowy); // Przekazanie adresu obiektu
    cout << "After adding: Semester " << semesterNumber << " has " << selectedStudent->semesterCourses[semesterNumber].size() << " courses." << endl;
    delete nowy; // Zwolnienie zaalokowanej pamięci
}


void semestralCase(int semestralChoice, Student* selectedStudent) {
    switch (semestralChoice) {
        case 1:
            cout << selectedStudent->semesterCourses.empty();
            addNewCourse(selectedStudent);
            break;
        case 2:
            system("cls");
            int semester;
            cout << "Which one semester? "; cin >> semester;
            displayCoursesForSemester(selectedStudent->semesterCourses, semester);
            break;
    }
}



void semestralStudent(vector<Student>& studentsList) {
    int studentId, choice;
    displayStudents(studentsList);
    cout << "Enter student's id: ";
    cin >> studentId;
    cout << endl;
    Student& selected = selectedStudent(studentsList, studentId); // Przekazanie referencji
    cout << endl;
    do {
        semestralMenu(choice);
        semestralCase(choice, &selected); // Przekazanie referencji
    } while (choice != 0);
}
void addStudent(vector<Student> &studentsList){
    Student nowy;
    nowy.id = indexId;
    cout << "Enter name: "; cin>>nowy.name;
    cout << "\nEnter Semester: "; cin>>nowy.currentSemester;
    indexId++;
    studentsList.push_back(nowy);
};

void displayStudentsByKey(vector<Student>& studentsList){
    string Key;
    bool tag = true;
    cout << "Enter name to search: ";cin >> Key;
    cout << "====================================" << endl;
    cout << setw(3) << "Id." << setw(10) << "Name" << setw(10) << "Semester" << setw(10) << "Story" << endl;
    cout << "====================================" << endl;
    for(Student el : studentsList){
       if(el.name == Key){
            cout << setw(3) << el.id << setw(10) << el.name << setw(10) << el.currentSemester << setw(10);

            tag = false;
            
       }   
    }
      if(tag == true)    cout << "          Empty array"<<endl;
}
void deleteStudent(vector<Student> &studentsList){
    int key;
    bool tag= true;
    cout << "Enter student's id to delete: ";cin>>key;
    
    for (auto it = studentsList.begin(); it != studentsList.end(); ++it) {
        if (it->id == key) {
            studentsList.erase(it);
            
            tag =false;
        }
    }
    
if(tag == true)    cout << "Student with ID " << key << " not found." << endl;
else cout << "Student with ID " << key << " has been removed." << endl;

}
void modifyStudent(vector <Student>&studentsList){
    int key;
    bool tag = true;
    cout << "Enter student's id to modify: ";cin>>key;
        for (auto it = studentsList.begin(); it != studentsList.end(); ++it) {
        if (it->id == key) {
            cout << "Enter new name: ";cin>>it->name;
            cout << "Enter new semester: ";cin>>it->currentSemester;
            tag = false;
        }
    }
    if(tag == true)    cout << "Student with ID " << key << " not found." << endl;
else cout << "Student with ID " << key << " has been removed." << endl;
};
 vector <Student> studentsList;
int main() {
   
    int choice;
    // Przykładowe użycie


    do{
        menu(choice);
        switch (choice)
        {
        case 1:
            cout <<"add"<<endl;
            addStudent(studentsList);
            break;
        case 2:
            cout <<"delete"<<endl;
            deleteStudent(studentsList);
            break;
        case 3:
            cout <<"modify"<<endl;
            modifyStudent(studentsList);
            break;
        case 4:
            cout <<"display"<<endl;
            displayStudents(studentsList);
            break;
        case 5:
            cout <<"search"<<endl;
            displayStudentsByKey(studentsList);
            break;
        case 6:
            cout <<"insert"<<endl;
            semestralStudent(studentsList);
            break;
        }
    }while(choice!=0);
    return 0;
}
