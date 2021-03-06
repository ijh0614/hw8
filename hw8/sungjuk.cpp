#include "student.h"
#include "subject.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

inline int printMenu();
inline void inputValue(string str)
{
    getline(cin, str);
}; //오버로딩한 inline함수. 입력들을 대체한다.
inline void inputValue(string* str)
{
    getline(cin, *str);
};
inline void inputValue(int& num)
{
    cin >> num;
    cin.ignore();
};

void printAllData(Student* student, int studentNum);

Student* stdSearch(Student* stList, int studentNum, string searchName);
void modify(Student* searchResult, int studentNum);

int main()
{
    int select = 0;     //사용자가 메뉴에서 선택하는 값
    int studentNum = 0; //동적할당 받을 학생 수
    string searchName;
    Student* searchResult = NULL;//검색 결과 
    Student* stList = NULL;

    cout << "2018038074 임종훈\n"
        << endl;

    while (select != 4)
    { //6이 나올 때까지 메뉴 반복 출력
        //1,2,3,4,5,6 이외의 값을 입력하면 프로그램 반복.
        select = printMenu();

        if (select == 1)
        {
            cout << "성적 관리할 학생 수를 입력하세요 : ";
            inputValue(studentNum);

            stList = new Student[studentNum];//객체 동적할당

            for (int i = 0; i < studentNum; i++)
            {
                cout << i + 1 << "번째 학생 이름과 학번을 입력하세요." << endl;
                stList[i].inputStudentInfo();
            }
        }
        else if (select == 2) {
            printAllData(stList, studentNum);//객체 배열의 주소를 전달
        }

        else if (select == 3){
            cout << "검색 할 학생 이름 : ";
            inputValue(&searchName);

            //학생 주소 반환
            searchResult = stdSearch(stList, studentNum, searchName);

            if (searchResult == NULL)
            {
                cout << "학생을 찾을 수 없습니다.\n"
                     << endl;
            }
            else{
                modify(searchResult, studentNum);
                stList->calAveGPA();
            }
        }

        else if (select == 4) {
            for (int a = 0; a < studentNum; a++)
            {
                stList[a].~Student();
            }
            delete[] stList;
            break;
        }
    }
}


void printAllData(Student* student, int studentNum) {
    cout << "          전체 학생 성적 보기" << endl;
    cout << "==================================================" << endl;
    for (int i = 0; i < studentNum; i++)
    {
        student[i].printData();
    }
}


inline int printMenu()
{
    int num = 0;
    cout << "===== 메뉴 =====\n";
    cout << "1. 학생 성적 입력\n";
    cout << "2. 전체 학생 성적 보기\n";
    cout << "3. 학생 정보 수정\n";
    cout << "4. 프로그램 종료\n\n";
    cout << "원하는 기능을 입력하세요: ";

    inputValue(num);
    //cin.fail()은 cin 명령이 실패하면 true를 반환

    /*if(cin.fail()){
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
위의 코드를 사용하려고 했으나 repl에서는 정상작동하고 vsc에서는 오류가 발생하는 현상 때문에 사용하지 못 함.
max에 인자 전달이 부족하다는데 구글링 해봐도 비슷한 사례를 찾지 못해 옳지 못한 값을 입력하면 강제종료하게끔 프로그램 수정*/
    if (cin.fail())
    {
        cout << "옳지 않은 형식입니다. 프로그램을 종료합니다." << endl;
        exit(1);
    }
    if (num < 0 || num > 6)
    {
        cout << "옳지 않은 형식입니다. 프로그램을 종료합니다." << endl;
        exit(1);
    }

    return num;
}

Student* stdSearch(Student* stList, int studentNum, string searchName){
    for (int a = 0; a < studentNum; a++)
    {
        if (searchName == stList[a].getStdName())
        {
            return &stList[a];
        }
    }

    return NULL;
}

void modify(Student* searchResult, int studentNum){
    string select;
    Subject* sub;
    cout << "수정<StudentInfo/SubjectInfo> : ";

    while (1)
    {
        inputValue(&select);
        if (select == "SubjectInfo")
        {
            sub = searchResult->subSearch();
            sub->modify();
            break;
        }
        else if (select == "StudentInfo")
        {
            searchResult->modify();
            break;
        }
        else
        {
            cout << "입력 오류입니다. 다시 입력해주세요.\n\n";
        }
    }
}