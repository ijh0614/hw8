#pragma once
#include "subject.h"
#include <iomanip>

inline void Subject::inputValue(int& num) {
    cin >> num;
    cin.ignore();
}
inline void Subject::inputValue(string& str) {
    getline(cin, str);
}


void Subject::initialize() {
    SubName = "Korean";
    Hakjum = 3;
    Grade = "A+";
}
void Subject::initialize(string _SubName, int _Hakjum, string _Grade) {
    SubName = _SubName;
    Hakjum = _Hakjum;
    Grade = _Grade;
}

void Subject::inputData() {
    cout << "교과목명 : ";
    inputValue(SubName);//Sub[i].SubName 으로는 접근할 수 없음!!

    cout << "과목 학점 : ";
    inputValue(Hakjum);

    //ABC같은 등급 입력
    cout << "과목 등급 : ";
    inputValue(Grade);
}

float Subject::getGPA() {
    if (Grade == "A+")
    {
        return 4.5 * Hakjum;
    }
    else if (Grade == "A0" || Grade == "A")
    {
        return 4.0 * Hakjum;
    }
    else if (Grade == "B+")
    {
        return 3.5 * Hakjum;
    }
    else if (Grade == "B0" || Grade == "B")
    {
        return 3.0 * Hakjum;
    }
    else if (Grade == "C+")
    {
        return 2.5 * Hakjum;
    }
    else if (Grade == "C0" || Grade == "C")
    {
        return 2.0 * Hakjum;
    }
    else if (Grade == "D+")
    {
        return 1.5 * Hakjum;
    }
    else if (Grade == "D0" || Grade == "D")
    {
        return 1.0 * Hakjum;
    }
    else if (Grade == "F")
    {
        return 0.0;
    }
    else
    {
        return -1;
    }
}

void Subject::calGPA() {
    GPA = getGPA();
    
    //GPA계산 후처리
    if (GPA < 0)
    {
        cout << "잘못된 형식의 등급입니다. 프로그램을 종료합니다.";
        exit(1);
    }
}

void Subject::printData() const {
    cout << right << setw(12) << SubName << setw(12) << Hakjum << setw(12) << Grade << setw(12) << GPA << endl;
}