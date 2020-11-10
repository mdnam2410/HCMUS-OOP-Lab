#include "DynamicArray.h"
#include "Rectangle.h"
#include "Student.h"
#include "Triangle.h"

#include <iostream>

void PressEnterToContinue()
{
    std::cout << "Nhan Enter de tiep tuc:";
    std::cin.ignore();
    std::string tmp;
    std::getline(std::cin, tmp);
}

template<typename T>
void PrintDefaultSettingInfo(T obj)
{
    T dummyObj;
    dummyObj.Info();
}

void IllustrateRectangle()
{
    std::cout << "\n============Rectangle============\n\n";
    std::cout << "Doi tuong Rectangle duoc tao mac dinh:\n";
    PrintDefaultSettingInfo(Rectangle());
    
    PressEnterToContinue();

    std::cout << "Tao doi tuong Rectangle do nguoi dung nhap:\n";
    std::cout << "Cu phap nhap diem: <toa_do_x> <toa_do_y>\n"
                 "Vi du: 1 2\n";
    Point tl, br;
    std::cout << "Nhap diem trai tren: ";
    std::cin >> tl;
    std::cout << "Nhap diem phai duoi: ";
    std::cin >> br;

    Rectangle R;
    R.SetTopLeft(tl);
    R.SetBottomRight(br);
    R.Info();
    std::cout << "\n\n";
}

void IllustrateTriangle()
{
    std::cout << "\n============Triangle============\n\n";
    std::cout << "Doi tuong Triangle duoc tao mac dinh:\n";
    PrintDefaultSettingInfo(Triangle());

    PressEnterToContinue();

    std::cout << "Tao doi tuong Triangle tuy chinh:\n";
    Point A, B, C;
    std::cout << "Nhap diem A: ";
    std::cin >> A;
    std::cout << "Nhap diem B: ";
    std::cin >> B;
    std::cout << "Nhap diem C: ";
    std::cin >> C;

    Triangle T;
    T.SetA(A);
    T.SetB(B);
    T.SetC(C);
    T.Info();
    std::cout << "\n\n";
}

void IllustrateStudent()
{
    std::cout << "\n============Student============\n\n";
    std::cout << "Doi tuong Student duoc tao mac dinh:\n";
    PrintDefaultSettingInfo(Student());

    PressEnterToContinue();

    std::cout << "Tao doi tuong Student tuy chinh:\n";

    std::string firstName, middleName, lastName;
    std::cout << "Nhap ho: ";
    std::cin >> firstName;
    std::cout << "Nhap ten dem: ";
    std::cin >> middleName;
    std::cout << "Nhap ten: ";
    std::cin >> lastName;

    Student S;
    S.SetFirstName(firstName);
    S.SetMiddleName(middleName);
    S.SetLastName(lastName);

    S.Info();
    std::cout << "\n\n";
}

void IllustrateDynamicArray()
{
    std::cout << "\n============DynamicArray============\n\n";
    std::cout << "Doi tuong DynamicArray duoc tao mac dinh:\n";
    PrintDefaultSettingInfo(DynamicArray());

    PressEnterToContinue();
    
    std::cout << "Tao doi tuong DynamicArray tuy chinh:\n";

    std::cout << "0. Huy mang va thoat\n"
                 "1. Them phan tu vao mang\n"
                 "2. Lay phan tu cua mang\n"
                 "3. In thong tin mang\n";

    DynamicArray da;
    int choice;
    while (true) {
        std::cout << "\nNhap lua chon: ";
        std::cin >> choice;
        switch (choice) {
        case 0:
            return;
        case 1:
        {
            int data;
            std::cout << "Nhap phan tu can them: ";
            std::cin >> data;
            da.PushBack(data);
            std::cout << "Them thanh cong!\n";
            break;
        }
        case 2:
        {
            int index;
            std::cout << "Nhap vi tri can lay: ";
            std::cin >> index;
            std::cout << "Phan tu tai vi tri " << index << ": " << da.GetAt(index) << '\n';
            break;
        }
        case 3:
            da.Info();
            break;
        default:
            std::cerr << "Nhap lua chon 0-3!\n";
        }
    }
}

int main()
{
    IllustrateRectangle();
    PressEnterToContinue();

    IllustrateTriangle();
    PressEnterToContinue();

    IllustrateStudent();
    PressEnterToContinue();

    IllustrateDynamicArray();
    return 0;
}