#ifndef fucntion_h
#define fucntion_h
#include <iostream>
using namespace std;
#include <string.h>
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
};
struct Semester {
    int semester;
    Date startDate, endDate;
    ListCourses list;
};

void addStudent(ListStudent& list, Student* x);
void viewOfCourse(ListCourses list);

void updateCourseIf(ListCourses& List);

#endif // !1



