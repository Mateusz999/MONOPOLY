#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;
int indexId=0;

struct Grade {
    int grade;
    string date;
    string instructor;
};

struct Course {
    string name;
    vector<Grade> grades;
    Grade grade;
};


struct Student {
    int id;
    string studentID;
    string name;
    string surname;
    int currentSemester;
    map<int, vector<Course>> semesterCourses;
};

void addGrade(Course& course, int grade, string date, string instructor) {
    Grade newGrade = {grade, date, instructor};
    course.grade = newGrade;
}

void addCourseToSemester(Student *student, int semester, Course *course) {
    student->semesterCourses[semester].push_back(*course);
}

void displayGrades( Course course) {
    cout << setw(15) << course.name << setw(15)<< course.grade.grade<< setw(15) << course.grade.date << setw(15) <<  course.grade.instructor<<endl;
}

void headerGrades(){
    cout << "========================================================================"<<endl;
    cout << setw(15) << "Course" << setw(15) << "Grade" << setw(15) << "Date" << setw(15) << "Instructor"<<endl;
    cout << "========================================================================"<<endl;
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
    cout << "========================================================================" << endl;
    cout << setw(3) << "Id." << setw(15) << "Student's ID" << setw(10) << "Name" << setw(10) << "Surname" << setw(10) << "Semester" << setw(10) << "Story" << endl;
   
    cout << "========================================================================" << endl;
    for(Student el : studentsList){
        cout << setw(3) << el.id << setw(15) << el.studentID << setw(10) << el.name << setw(10) << el.surname << setw(10) << el.currentSemester << setw(10);

        if(el.semesterCourses.empty())cout << " No"<<endl;
        else cout << " Yes"<<endl;

    }
}

    void displayAllSemesters(const Student& student) {
    
    if(student.semesterCourses.empty()){
        cout << "History is empty"<<endl;
    }else {
        cout << "Displaying all semesters for student: " << student.name << "\n";
    for (const auto& semesterPair : student.semesterCourses) {
        int semester = semesterPair.first;
        const vector<Course>& courses = semesterPair.second;
        cout << "                               Semester: " << semester << "\n";
        headerGrades();
        for (const Course& course : courses) {
            displayGrades(course);
        }
        cout << "------------------------------------------------------------------------\n";
    }
    }

}
void deleteSemester(Student *student){
    displayAllSemesters(*student);
    int semester;
    cout << "Enter semester to delete: ";cin >> semester;
    auto it = student->semesterCourses.find(semester);
    if(it!= student->semesterCourses.end()){
        student->semesterCourses.erase(it);
        cout << "Semester " << semester << " has been removed"<<endl;
    }else{
        cout << "Semester " << semester << " not found " << endl; 
    }

};

void deleteSemestersAll(Student *student){
    if(student->semesterCourses.empty()) cout << "History is empty"<<endl;
    else{
        student->semesterCourses.clear();
        cout << "All semesters have been removed"<<endl;
    }
 
};

void displayCoursesForSemester(const map<int, vector<Course>>& semesterCourses, int semester) {
  auto it = semesterCourses.find(semester);
  if(it != semesterCourses.end()){
 cout << "Courses for semester " << semester << ":\n";
   
   headerGrades();
   for (const Course& course : it->second) {

            displayGrades(course);
        }
  }else cout << "There's no semester " << semester<<endl; 
   
}
void deleteCourseFromSemester(Student*student){
    int semester;
    string name;
    bool tag=true;
    cout << "Enter semester: ";cin >> semester;
  
    auto it = student->semesterCourses.find(semester);
    if(it!=student->semesterCourses.end()){
        cout << "Enter name: ";cin >> name;
        auto& courses = it->second;
        for(auto it = courses.begin();it<courses.end();it++){
            if(it->name == name){
                courses.erase(it);
            
                cout << "Course " << name << " has been removed"<<endl;
                
            }else{
              if(tag)  cout << "There's no course: " << name<<endl;
              tag = false;
            }
        }

    }else cout << "There's no semester" << semester<<endl;
};

void editCourseFromSemester(Student*student){
    int semester;
    string name;
    bool tag=true;
    cout << "Enter semester: ";cin >> semester;
  
    auto it = student->semesterCourses.find(semester);
    if(it!=student->semesterCourses.end()){
        cout << "Enter name: ";cin >> name;
        auto& courses = it->second;
        for(auto it = courses.begin();it<courses.end();it++){
            if(it->name == name){
            cout << "Enter name";cin >> it->name;
            cout << "Enter grade";cin >> it->grade.grade;
            cout << "Enter date";cin >> it->grade.date;
            cout << "Enter instructor";cin >> it->grade.instructor;
                
            }else{
              if(tag)  cout << "There's no course: " << name<<endl;
              tag = false;
            }
        }

    }else cout << "There's no semester" << semester<<endl;
};


void semestralMenu(int &choice){
    cout << "===================================="<<endl;
    cout << "No.    Option"<<endl;
    cout << "===================================="<<endl;
    cout <<"1.      Add new course   "<<endl;
    cout <<"2.      Display selected semester   "<<endl;
    cout <<"3.      Display all semesters   "<<endl;
    cout <<"4.      Delete  all semesters  "<<endl;
    cout <<"5.      Delete  selected semester   "<<endl;
    cout <<"6.      Delete  course  "<<endl;
    cout <<"7.      Modify course   "<<endl;
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
    Course* nowy = new Course; 
    int semesterNumber;
    cout << "Enter name: "; cin >> nowy->name;
    cout << "Enter grade: "; cin >> nowy->grade.grade;
    cout << "Enter date: "; cin >> nowy->grade.date;
    cout << "Enter instructor: "; cin >> nowy->grade.instructor;
    cout << "Enter semester No: "; cin >> semesterNumber;
    addCourseToSemester(selectedStudent, semesterNumber, nowy); 
    cout << "After adding: Semester " << semesterNumber << " has " << selectedStudent->semesterCourses[semesterNumber].size() << " courses." << endl;
    delete nowy; 
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
        case 3:
        system("cls");
        displayAllSemesters(*selectedStudent);
        break;
        case 4:
            deleteSemestersAll(selectedStudent);
            break;
        case 5:
            deleteSemester(selectedStudent);
            break;
        case 6:
            deleteCourseFromSemester(selectedStudent);
            break;
        case 7:
            editCourseFromSemester(selectedStudent);
            break;
    }
}

void semestralStudent(vector<Student>& studentsList) {
    int studentId, choice;
    displayStudents(studentsList);
    cout << "Enter student's id: ";
    cin >> studentId;
    cout << endl;
    Student& selected = selectedStudent(studentsList, studentId);
    cout << endl;
    do {
        semestralMenu(choice);
        semestralCase(choice, &selected); 
    } while (choice != 0);
}
void addStudent(vector<Student> &studentsList){
    Student nowy;
    nowy.id = indexId;
    cout << "Enter Student's ID: "; cin>>nowy.studentID;
    cout << "Enter name: "; cin>>nowy.name;
    cout << "Enter surname: "; cin>>nowy.surname;
    cout << "Enter Semester: "; cin>>nowy.currentSemester;
    indexId++;
    studentsList.push_back(nowy);
};

void displayStudentsByKey(vector<Student>& studentsList){
    string Key;
    bool tag = true;
    cout << "Enter name to search: ";cin >> Key;
    cout << "========================================================================" << endl;
    cout << setw(3) << "Id." << setw(15) << " St. No" << setw(10) << "Name" << setw(10) << "Surname" << setw(10) << "Semester" << setw(10) << "Story" << endl;
    cout << "========================================================================" << endl;
    for(Student el : studentsList){
       if(el.name == Key){
            cout << setw(3) << el.id << setw(15) << el.studentID << setw(10) << el.name << setw(10) << el.surname << setw(10) << el.currentSemester << setw(10);

            tag = false;
            
       }   
    }
      if(tag == true)    cout << "          There's no student with name: " << Key<<endl;
}
void deleteStudent(vector<Student> &studentsList){
    int key;
    bool tag= true;
    cout << "Enter student's id to delete: ";cin>>key;
    for(int i =0;i<studentsList.size();i++){
        if(studentsList[i].id == key) {
            studentsList.erase(studentsList.begin() + i);
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

    do{
        menu(choice);
        switch (choice)
        {
        case 1:
            addStudent(studentsList);
            break;
        case 2:
            deleteStudent(studentsList);
            break;
        case 3:
            modifyStudent(studentsList);
            break;
        case 4:
            displayStudents(studentsList);
            break;
        case 5:
            displayStudentsByKey(studentsList);
            break;
        case 6:
            semestralStudent(studentsList);
            break;
        }
    }while(choice!=0);
    return 0;
}
