#include "function.h"
Semester createSemester() {
	Semester tmp;
	cout << "Hoc ki bao nhieu (1,2 hay 3) : "; cin >> tmp.semester;
	cout << "Nam hoc :"; cin >> tmp.startDate.nam; tmp.endDate.nam = tmp.startDate.nam;
	cout << "Ngay bat dau : ";
	cout << "\t\t\tNgay : ";
	cin >> tmp.startDate.ngay;
	cout << "\t\t\tThang : ";
	cin >> tmp.startDate.thang;
	cout << "Ngay ket thuc : ";
	cout << "\t\t\tNgay : ";
	cin >> tmp.endDate.ngay;
	cout << "\t\t\tThang : ";
	cin >> tmp.endDate.thang;
	return tmp;
}
Course* CreateCourse() {
	Course* p = new Course();
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

}
void addCourseToSemester(Semester& hk) {
	Course* monHoc =
}
void addStudent(ListStudent& list, Student* x) {
	if (x == NULL) return;
	if (list.head == NULL) {
		list.head = x;
		list.tail = x;
		return;
	}
	x->next = list.head;
	list.head = x;
}

void viewOfCourse(ListCourses list) {
	if (list.head == NULL) {
		cout << "khong co mon hoc nao trong danh sach" << endl;
		return;
	}
	int i = 1;
	while (list.head != NULL) {
		cout << "Mon hoc thu " << i << endl;
		cout << "\t\tNgay bat dau mon hoc : " << list.startDate.ngay << "/" << list.startDate.thang << "/" << list.startDate.nam << endl;
		cout << "\t\tNgay ket thuc mon hoc : " << list.endDate.ngay << "/" << list.endDate.thang << "/" << list.endDate.nam << endl;
		cout << "\t\tTen mon hoc : " << list.head->courseName << endl;
		cout << "\t\tMa mon hoc :" << list.head->id << endl;
		cout << "\t\tTen giao vien day mon hoc do :" << list.head->teacherName << endl;
		i++;
		list.head = list.head->next;
	}
}

void updateCourseIf(ListCourses& List) {
	string Id;
	cout << "Nhap ma mon hoc de cap nhat thong tin : ";
	getline(cin, Id);
	Course* p = List.head;
	while (p != NULL) {
		if (p->id == Id) {
			cout << "Ban muon cap nhat thong tin nao " << endl;
			cout << "\t1.Cap nhat ma mon hoc. \n";
			cout << "\t2.Cap nhat ten mon hoc.\n ";
			cout << "\t3.Cap nhat ten giao vien.\n";
			int chon = 0; cin >> chon;
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






