#include "function.h"
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
	Course* p=List.head;
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
void addStudentInCourse( ListStudent &list,Course tmp) {
	
}





