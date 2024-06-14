#include "function.h"
Year CreateSchoolYear() {
    Year y;
    cout << "The begining of the school year: ";
    cin >> y.From;
    cout << "The end of the school year: ";
    cin >> y.To;
    return y;
}
Class* khoitaolophoc() {
    Class* a = new Class();
    cout << "Input the class name: ";
    cin >> a->className;
    a->next = NULL;
    return a;
}
void nhapngay(Student*& s)
{
    cout << "Input date: ";
    cin >> s->dateOfBirth.ngay;
    cout << "Input month: ";
    cin >> s->dateOfBirth.thang;
    cout << "Input year: ";
    cin >> s->dateOfBirth.nam;
}
Student* khoitaosinhvien()
{
    Student* s = new Student();

    cout << "Enter NO: ";
    cin >> s->NO;
    cin.ignore();
    cout << "Enter student id: ";
    getline(cin, s->studentID, '\n');
    cout << "Enter last name: ";
    getline(cin, s->lastName, '\n');
    cout << "Enter first name: ";
    getline(cin, s->firstName, '\n');
    cout << "Enter gioi tinh: ";
    getline(cin, s->gender, '\n');
    cout << "Enter social id: ";
    getline(cin, s->socialID, '\n');
    nhapngay(s);
    s->next = NULL;
    return s;
}
void AddClass(ListClasses& s)
{
    Class* l = khoitaolophoc();
    if (s.head == NULL)
    {
        s.head = s.tail = l;
        return;
    }
    else
    {
        s.tail->next = l;
        s.tail = l;
        return;
    }
}
void AddnClass(ListClasses& s, int n)
{
    for (int i = 0; i < n; i++)
    {
        AddClass(s);
    }
}
void AddStudent(ListStudent& s)
{
    Student* p = khoitaosinhvien();
    if (p != NULL)
    {
        if (s.head == NULL)
        {
            s.head = s.tail = p;
        }
        else
        {
            s.tail->next = p;
            s.tail = p;
        }
    }
}
void importfile(char tenfile[])
{
    ListStudent s;
    s.head = s.tail = NULL;
    Student* tmp = s.head;
    ifstream f;
    f.open(tenfile);
    if (!f.is_open())
    {
        cout << "Khong the doc file " << tenfile << endl;
        return;
    }
    string line;
    getline(f, line);
    while (f)
    {
        getline(f, tmp->studentID, ',');
        getline(f, tmp->firstName, ',');
        getline(f, tmp->lastName, ',');
        getline(f, tmp->gender, ',');

        getline(f, tmp->socialID, ',');
        tmp = tmp->next;
    }

}
Year themnam()
{
    Year schoolYear = CreateSchoolYear();
    return schoolYear;
}
void print(Class* list)
{
    Student* tmp = list->list.head;
    if (tmp == NULL)
    {
        cout << "----------------INFORMATION----------------\n";
        cout << "Empty Class !" << endl;
        cout << "-------------------------------------------\n";
    }
    if (list == NULL) return;
    while (tmp != NULL)
    {
        cout << "----------------INFORMATION----------------\n";
        cout << "NO: " << tmp->NO << endl;
        cout << "Student ID: " << tmp->studentID << endl;
        cout << "Last name: " << tmp->lastName << endl;
        cout << "First name: " << tmp->firstName << endl;
        cout << "Gioi tinh: " << tmp->gender << endl;
        cout << "Social ID: " << tmp->socialID << endl;
        cout << "Born date: " << endl;
        cout << "Day: " << tmp->dateOfBirth.ngay << endl;
        cout << "Month: " << tmp->dateOfBirth.thang << endl;
        cout << "Year: " << tmp->dateOfBirth.nam << endl;
        cout << "-------------------------------------------\n";
        tmp = tmp->next;
    }
}
//int main()
//{
//    ListClasses listclasses;
//    listclasses.head = listclasses.tail = NULL;
//    Year schoolYear = themnam();
//    int numClasses;
//    cout << "Enter amount of classes: ";
//    cin >> numClasses;
//    AddnClass(listclasses, numClasses);
//    schoolYear.listclasses = listclasses;
//
//
//    ListStudent studentList;
//    studentList.head = studentList.tail = nullptr;
//
//
//    string name;
//    cout << "Enter class name: ";
//    cin >> name;
//    Class* tmp = listclasses.head;
//    while (tmp != NULL)
//    {
//        if (tmp->className == name)
//        {
//            int numStudents;
//            cout << "Enter amount of student: ";
//            cin >> numStudents;
//            for (int i = 0; i < numStudents; i++) {
//                cout << "Enter the infomation of student number " << i + 1 << endl;
//                AddStudent(studentList);
//            }
//            tmp->list = studentList;
//            break;
//        }
//        tmp = tmp->next;
//    }
//    if (tmp == NULL)
//    {
//        cout << "There's no infomation about entered class !" << endl;
//    }
//
//    tmp = listclasses.head;
//    cout << "Enter class name to printout information: " << endl;
//    string classname;
//    cin >> classname;
//    while (tmp != NULL)
//    {
//        if (tmp->className == classname)
//        {
//            print(tmp);
//            break;
//        }
//        tmp = tmp->next;
//    }
//    return 0;
//}