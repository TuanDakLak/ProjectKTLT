//#include "function.h"
//
//int main() {
//	Semester HocKi;
//	ListStudent ds = CreateListStudent();
//	bool Run = true;
//	while (Run) {
//		cout << "1.Create a semester\n";
//		cout << "2.Add a course to this semester\n";
//		cout << "3.View list of course\n";
//		cout << "4.Update coures infomartion\n"; 
//		cout << "5.Add a student to the course\n";
//		cout << "0.end\n";
//		int chon = 0; cin >> chon;
//		if (chon == 1) {
//			HocKi = createSemester();
//		}
//		else if (chon == 2) {
//			addCourseToSemester(HocKi);
//		}
//		else if (chon == 3) {
//			viewOfCourse(HocKi.list);
//		}
//		else if (chon == 4) {
//			updateCourseInfo(HocKi.list);
//		}
//		else if (chon == 0) {
//			Run = false;
//		}
//		else if (chon == 5) {
//			Student* sinhVien = khoitaosinhvien();
//			addStudentToCourse(sinhVien, HocKi.list.head);
//		}
//
//	}
//	return 0;
//}
//
