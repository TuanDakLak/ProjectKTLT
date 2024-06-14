

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

bool checkTime(Date a,Date b) {
	if (a.thang < b.thang) return false;
	else if (a.thang>b.thang) return true;
	else if (a.thang == b.thang) {
		if (a.ngay < b.ngay) return false;
		return true;
	}
	
}
Semester createSemester() {
	Semester tmp;
	cout << "Hoc ki bao nhieu (1,2 hay 3) : "; cin >> tmp.semester;
	cout << "Nam hoc :"; cin >> tmp.startDate.nam; tmp.endDate.nam = tmp.startDate.nam;
	cout << "Ngay bat dau : " << endl;;
	cout << "\t\tNgay : ";
	cin >> tmp.startDate.ngay;
	cout << "\t\tThang : ";
	cin >> tmp.startDate.thang;
	cout << "Ngay ket thuc : "<<endl;
	cout << "\t\tNgay : ";
	cin >> tmp.endDate.ngay;
	cout << "\t\tThang : ";
	cin >> tmp.endDate.thang;
	while (checkTime(tmp.startDate, tmp.endDate)) {
		cout << "Thoi gian khong hop le!!Vui long nhap lai... \n";
		cout << "Ngay bat dau : " << endl;;
		cout << "\t\tNgay : ";
		cin >> tmp.startDate.ngay;
		cout << "\t\tThang : ";
		cin >> tmp.startDate.thang;
		cout << "Ngay ket thuc : " << endl;
		cout << "\t\tNgay : ";
		cin >> tmp.endDate.ngay;
		cout << "\t\tThang : ";
		cin >> tmp.endDate.thang;
	}
	tmp.list.head = tmp.list.tail = NULL;
	return tmp;
}
Course* CreateCourse() {
	Course* p = new Course();
	cin.ignore();
	cout << "ID mon hoc : ";
	getline(cin, p->id);
	cout << "Ten mon hoc : ";
	getline(cin, p->courseName);
	cout << "Ten giao vien : ";
	getline(cin, p->teacherName);
	cout << "So tin chi mon hoc do : ";
	cin >> p->credits;
	cout << "So luong sinh vien (toi da 50) : ";
	cin >> p->max;
	while (p->max < 0 || p->max>50) {
		cout << "So luong sinh vien da qua gioi han , vui long nhap lai!!";
		cout << "So luong sinh vien (toi da 50) : ";
		cin >> p->max;
	}
	cout << "THOI GIAN BUOI HOC DIEN RA :" << endl;
	cout << "\t\t\tNGAY TRONG TUAN:               THOI GIAN:" << endl;
	cout << "\t\t\tchon 2: Thu hai                 S1: 07:30\n";
	cout << "\t\t\tchon 3: Thu ba                  S2: 09:30\n";
	cout << "\t\t\tchon 4: Thu tu                  S3: 12:30\n";
	cout << "\t\t\tchon 5: Thu nam                 S4: 15:30\n";
	cout << "\t\t\tchon 6: Thu sau\n";
	cout << "\t\t\tchon 7: Thu bay\n";
	cout << "Hoc vao thu : "; cin >> p->dayOfWeek;
	cin.ignore();
	cout << "Hoc vao luc : "; getline(cin, p->session);
	return p;
}
void addCourseToSemester(Semester& hk) {
	Course* monHoc = CreateCourse();
	ofstream file;
	file.open("./Course/" + monHoc->id + ".csv", ios::out );
	if (!file.is_open()) {
		cout << "errol\n";
		return;
	}
	file << "ID,LAST NAME,FIST NAME,DATE OF BIRT"<<endl;
	if (monHoc == NULL) return;
	
	if (hk.list.head == NULL) {
		hk.list.head = hk.list.tail = monHoc;
		
		return;
	}
	Course* p = hk.list.head;
	while (1) {
		if (p->next == NULL) break;
		p = p->next;
	}
	p->next = monHoc;


	//file.close();
}


void viewOfCourse(ListCourses list) {
	if (list.head == NULL) {
		cout << "khong co mon hoc nao trong danh sach" << endl;
		return;
	}
	int i = 1;
	while (list.head != NULL) {
		cout << "Mon hoc thu " << i << endl;
		cout << "\t\tTen mon hoc : " << list.head->courseName << endl;
		cout << "\t\tMa mon hoc :" << list.head->id << endl;
		cout << "\t\tTen giao vien day mon hoc do : " << list.head->teacherName << endl;
		cout << "\t\tSo tin chi : " << list.head->credits << endl;
		cout << "\t\tHoc vao thu " << list.head->dayOfWeek;
		if (list.head->session == "S1") {
			cout << " 07:30\n";
		}
		else if (list.head->session == "S2") {
			cout << " 09:30\n";
		}
		else if (list.head->session == "S3") {
			cout << " 12:30\n";
		}
		else if (list.head->session == "S4") {
			cout << " 15:30\n";
		}
		i++;
		list.head = list.head->next;
	}
}

void updateCourseInfo(ListCourses& List) {
	string Id;
	cin.ignore();
	cout << "Nhap id mon hoc de cap nhat thong tin : ";
	getline(cin, Id);
	if (List.head->id == Id) {
		cout << "Ban muon cap nhat thong tin nao " << endl;
		cout << "\t1.Cap nhat ma mon hoc. \n";
		cout << "\t2.Cap nhat ten mon hoc.\n ";
		cout << "\t3.Cap nhat ten giao vien.\n";
		int chon = 0; cin >> chon;
		cin.ignore();
		if (chon == 1) {
			cout << "\t\tNhap ma lop moi : "; getline(cin, List.head->id);
		}
		else if (chon == 2) {
			cout << "\t\tNhap ten moc hoc moi : "; getline(cin, List.head->courseName);
		}
		else if (chon == 3) {
			cout << "\t\tNhap ten giao vien moi : "; getline(cin, List.head->teacherName);
		}
		return;
	}
	Course* p = List.head;
	while (p != NULL) {
		if (p->id == Id) {
			cout << "Ban muon cap nhat thong tin nao " << endl;
			cout << "\t1.Cap nhat ma mon hoc. \n";
			cout << "\t2.Cap nhat ten mon hoc.\n ";
			cout << "\t3.Cap nhat ten giao vien.\n";
			int chon = 0; cin >> chon;
			cin.ignore();
			if (chon == 1) {
				cout << "\t\tNhap ma lop moi : "; getline(cin, p->id);
			}
			else if (chon == 2) {
				cout << "\t\tNhap ten moc hoc moi : "; getline(cin, p->courseName);
			}
			else if (chon == 3) {
				cout << "\t\tNhap ten giao vien moi : "; getline(cin, p->teacherName);
			}
		}
		p = p->next;
	}

}
void fileListStudent(Course* x, Student *a) {
	if (x == NULL) {
		return;
	}
	ofstream file("./Course/" + x->id + ".csv",ios::out|ios::app);
	file << a->studentID << "," << a->lastName << "," << a->firstName << "," << a->dateOfBirth.ngay << "/" << a->dateOfBirth.thang << "/" << a->dateOfBirth.nam << endl;

	//file.close();
}
void addStudentToCourse(Student*&a, Course* x) {
	if (x == NULL) {
		cout << "Mon hoc ko ton tai " << endl;
		return;
	}
	if (a->enrolledCourses.head == NULL) {
		a->enrolledCourses.head = a->enrolledCourses.tail = x;
		fileListStudent(x,a);
		return;
	}
	Course* p = a->enrolledCourses.head;
	while (1) {
		if (p->next == NULL) break;
		p = p->next;
	}
	p->next = x;
	fileListStudent(x, a);
}

ListStudent CreateListStudent() {
	ListStudent l;
	l.head = l.tail = NULL;
	return l;
}

void tu6_11() {
	Semester HocKi;
	bool Run = true;
	while (Run) {
		cout << "1.Create a semester\n";
		cout << "2.Add a course to this semester\n";
		cout << "3.View list of course\n";
		cout << "4.Update coures infomartion\n";
		cout << "5.Add a student to the course\n";
		cout << "0.end\n";
		int chon = 0; cin >> chon;
		if (chon == 1) {
			HocKi = createSemester();
		}
		else if (chon == 2) {
			addCourseToSemester(HocKi);
		}
		else if (chon == 3) {
			viewOfCourse(HocKi.list);
		}
		else if (chon == 4) {
			updateCourseInfo(HocKi.list);
		}
		else if (chon == 0) {
			Run = false;
		}
		else if (chon == 5) {
			Student* sinhVien = khoitaosinhvien();
			addStudentToCourse(sinhVien, HocKi.list.head);
		}

	}
}

int main() {
	tu6_11();
	return 0;
}








