#pragma once
#include "subject.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
protected:
    string StdName;      // 학생 이름
    int Hakbun;          // 학번
    //동적할당 받을 과목 수
    int SubNum;
    float AveGPA; // 교과목 평균 평점
    Subject* Sub; // 과목 주소

private:
    inline void inputValue(int& num);
    inline void inputValue(string& str);


public:
    void initialize();//멤버 변수 초기화. 전부 없던 걸로
    //학생 이름, 학번, 입력 받을 과목 수
    void initialize(string _StdName, int _Hakbun, int _SubNum);//내가 대입해주는 값으로 초기화
    void inputStudentInfo();
    void calAveGPA();
    void printData() const;//이 함수 안의 값은 어떤 변수도 바꿀 수 없음을 의미하는 const
    // 안에있는 과목들만 동적할당 해제
    void Remove();
};
