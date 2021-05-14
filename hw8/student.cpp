#include "student.h"

inline void Student::inputValue(int &num){
    cin >> num;
    cin.ignore();
}
inline void Student::inputValue(string &str){
    getline(cin, str);
}



void Student::inputStudentInfo()
{
    cout << "이름 : ";
    inputValue(StdName);
    cout << "학번 : ";
    inputValue(Hakbun);
    cout << "과목의 수를 입력하세요 : ";
    inputValue(SubNum);

    Sub = new Subject[SubNum];//std 한명마다 즉, 함수를 실행할 때 마다 과목 수만큼 동적할당

    cout << "* 수강한 과목 " << SubNum << "개와 각각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;

    for (int i = 0; i < SubNum; i++)
    {
        Sub[i].inputData();

        //과목 평점 계산 후 평점에 저장.
        Sub[i].calGPA();
        cout << endl;
    }

    calAveGPA();
}

void Student::initialize(string _StdName, int _Hakbun, int _SubNum){
    Sub = new Subject[SubNum]; //과목 수만큼 동적할당
    StdName = _StdName;
    Hakbun = _Hakbun;
    SubNum = _SubNum;
}

void Student::initialize(){
    StdName = "임종훈";
    Hakbun = 2018038074;
    SubNum = 1;
    Sub = new Subject[SubNum]; //과목 수만큼 동적할당
}

void Student::printData() const{
    cout << "이름 : " << StdName << " 학번 : " << Hakbun << endl;
    cout << "==================================================" << endl;
    cout << "      과목명     과목학점     과목등급     과목평점" << endl;
    cout << "==================================================" << endl;

    //width() 대신 setw 사용.
    //setprecision(2); ???????????????? 반복문 안에 밖에 다 써줘도 해결 X
    for (int i = 0; i < SubNum; i++)
    {
        //cout.precision(2);
       Sub[i].printData();
    }

    cout << "==================================================" << endl;
    cout.width(50);
    cout.precision(2);

    // fixed를 써주지 않으면 뒤의 0은 출력되지 않음.
    cout << "평균평점   " << fixed << setprecision(2) << AveGPA << endl;
}

void Student::calAveGPA(){
    float sum = 0;

    for (int i = 0; i < SubNum; i++)
    {
        sum = sum + Sub[i].getGPA();//학점 반환
    }
    AveGPA = sum / SubNum;
}

void Student::Remove(){
    delete[] Sub;
}
