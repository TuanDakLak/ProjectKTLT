#include <iostream>
#include <string>
using namespace std;
struct ASM {
    char* taikhoan;
    char* matkhau;
};
struct Class
{
    string ten;
    Class* next;
};
struct student {
    int year;
    int no;
    int studentid;
    char firstname[20];
    char lastname[20];
    bool gender;
    Class cl;
    char* taikhoan;
    char* matkhau;
};
struct user {
    student st;
    ASM as;
};
struct year {
    char yeartime[10];
};
Class* createclass()
{
    Class* a = new Class();
    cout << "Nhap ten lop: " << endl;
    cin.ignore();
    getline(cin,a->ten,'\n');
    a->next = NULL;
    return a;
}
void addclass(Class*& a)
{
    Class* tmp = createclass();

}
// Thêm hàm tạo năm học mới
int main()
{
    year a;
    cout << "Nhap khoang thoi gian nam hoc: ";
    cin >> a.yeartime;
    cout << "da xong \n";

    return 0;
}