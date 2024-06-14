#ifndef fucntion_h
#define fucntion_h
#include <iostream>
using namespace std;

#include "fstream"
#include <string>
struct Date {
    int ngay, thang, nam;
};
struct User {
    string id;
    string password;
    string lastName;
    string firstName;
    string className;
    string gender;
    bool isStaff;
    User* prev;
    User* next;
};
struct Course {
    string id;
    string courseName;
    string teacherName;
    int max = 50;
    int credits;
    int dayOfWeek;
    string session;
    Course* prev;
    Course* next;
};
struct ListCourses {
    Course* head;
    Course* tail;
    Date startDate, endDate;
    int size = 0;
};
struct ListUser {
    User* head;
    User* tail;
    int size;
};
struct Student {
    int NO;
    string studentID;
    string lastName;
    string firstName;
    string gender;
    string socialID;
    Date dateOfBirth;
    int academicYear;
    ListCourses enrolledCourses;
    Student* prev;
    Student* next;
};
struct ListStudent {
    Student* head;
    Student* tail;
    string className;
    string year;
};
struct Class {
    ListStudent list;
    string className;
    Class* prev;
    Class* next;
};
struct ListClasses {
    Class* head;
    Class* tail;
    int size;
};
struct Year {
    int From, To;
    ListClasses listclasses;
};
struct Semester {
    int semester;
    Date startDate, endDate;
    ListCourses list;
};

Semester createSemester();
Course* CreateCourse();
void addCourseToSemester(Semester& hk);
void viewOfCourse(ListCourses list);

void updateCourseInfo(ListCourses& List);
void fileListStudent(Course* x, Student* a);
void addStudentToCourse(Student*&a, Course* x);
void nhapngay(Student*& s);
Student* khoitaosinhvien();
void AddStudent(ListStudent& s);
ListStudent CreateListStudent();
#endif // !1



