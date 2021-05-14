#pragma once
#include <iostream>
#include <string>

using namespace std;

class Subject {
protected:
    string SubName; // 과목이름
    int Hakjum;     // 과목학점
    string Grade="hi";   // 과목등급
    float GPA;      // 과목 평점

private:
    inline void inputValue(int& num);
    inline void inputValue(string& str);


public:
    void initialize();//멤버 변수 초기화. 전부 없던 걸로
    //과목명, 학점, 등급 
    void initialize(string _SubName, int _Hakjum, string _Grade);//내가 대입해주는 값으로 초기화
    void inputData();
    void calGPA();//평점 계산
    float getGPA();//평점 반환
    void printData() const;
};