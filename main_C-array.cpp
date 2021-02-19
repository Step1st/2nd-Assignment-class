#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct student
{
    string firstName, lastName;
    int* homeworkGrades = nullptr;
    int homeworkSize = 0, examGrade;
    double finalGrade;
};

void homeworkGrades(bool, student&);
bool isdigits(string&);
int* arrayResize(int*, int);
bool validateName(string);
string getDigits();
int getExam();
void generateGrades(bool, student&);
void finalGradeAverage(student*, int);
void finalGradeMedian(student*, int);
void print(student*, int, bool);

int main(){
    student *group;   // student array
    int n;            // number of students
    bool run = true;  // used to for while loops in main
    bool gradeNumber; // flag for if grade number is known

    cout << "Enter the number of students: ";
    n = std::stoi(getDigits());
    group = new student[n];

    for (int i=0; i<n; i++)
    {
        cout << "Enter students first name: ";
        do {
           cin >> group[i].firstName;
           cout << endl;
        }
        while(!validateName(group[i].firstName));

        cout << "Enter students last name: ";
        do{
            cin >> group[i].lastName;
            cout << endl;
        }
        while(!validateName(group[i].lastName));

        string ansGrade;
        cout << "Is the number of grades known?(y/n): ";
        do{
            cin >> ansGrade;
            if(ansGrade == "y" || ansGrade == "Y")
            {
                int temp;
                cout << "Enter the number of grades: ";
                do {
                    temp = std::stoi(getDigits());
                    if (temp > 0)
                    {
                        group[i].homeworkSize = temp;
                        run = false;
                    }
                    else
                    {
                        cout << "Error! the number of grades cant be 0" << endl;
                        cout << "Try to enter your number again: ";
                        run = true;
                    }
                }
                while(run);
                gradeNumber = true;
            }
            else if (ansGrade == "n" || ansGrade == "N")
            {
                gradeNumber = false;
                run = false;
            }
            else
            {
                cout << endl;
                cout << "Error: bad entry" << endl;
                cout << "Try again(y/n): ";
                run = true;
            }
        }
        while(run);

        string ansRandom;
        cout <<"Generate grades randomly?(y/n): ";
        do {
            cin >> ansRandom;
            if (ansRandom == "y" || ansRandom == "Y")
            {
                cout << endl;
                generateGrades(gradeNumber, group[i]);
                run = false;
            }
            else if (ansRandom == "n" || ansRandom == "N")
            {
                homeworkGrades(gradeNumber, group[i]);
                cout << endl <<"Enter students exam grade: ";
                group[i].examGrade = getExam();
                run = false;
            }
            else
            {
            cout << endl;
            cout << "Error: bad entry" << endl;
            cout << "Try again(y/n): ";
            run = true;
            }
        }
        while(run);

    }

    string ansMedian;
    cout << "Use median for final grade?(y/n): ";
    do{
        cin >> ansMedian;
        if (ansMedian == "y" || ansMedian == "Y")
        {
            finalGradeMedian(group, n);
            print(group, n, true);
            run = false;
        }
        else if (ansMedian == "n" || ansMedian == "N")
        {
            finalGradeAverage(group, n);
            print(group, n, false);
            run = false;
        }
        else
        {
            cout << endl;
            cout << "Error: bad entry" << endl;
            cout << "Try again(y/n): ";
            run = true;
        }
    }
    while(run);
}

//gets homework grades

void homeworkGrades(bool gradeNumber, student& Student){
    bool run = true;
    string Grade;
    if (gradeNumber)
    {
        Student.homeworkGrades = new int[Student.homeworkSize];
        for (int i=0; i<Student.homeworkSize; i++)
        {
            do{
                cout << i + 1 << ". Enter grade: ";
                cin >> Grade;
                if  (isdigits(Grade) && std::stoi(Grade) <= 10 && std::stoi(Grade) >= 0 )
                {
                    Student.homeworkGrades[i] = std::stoi(Grade);
                    run = false;
                }
                else
                {
                    cout << "Error: invalid grade" << endl;
                    run = true;
                }
            }
            while(run);
        }
    }
    else
    {
        cout << endl <<"To finish entering grades type in 'end'" << endl;
        do{
            cout << Student.homeworkSize + 1 << ". Enter grade: ";
            cin >> Grade;
            if  (isdigits(Grade) && std::stoi(Grade) <= 10 && std::stoi(Grade) >= 0 )
            {
                Student.homeworkGrades = arrayResize(Student.homeworkGrades, Student.homeworkSize);
                Student.homeworkGrades[Student.homeworkSize] = std::stoi(Grade);
                Student.homeworkSize++;
            }
            else if (Grade == "end")
            {
                run = false;
            }
            else
            {
                cout << "Error: invalid grade" << endl;
            }

            if (Student.homeworkSize == 0 && Grade == "end")
            {
                cout << "Error! Please enter at least one grade" << endl;
                run =true;
            }
        }
        while (run);
    }
}

//checks is string is only made out of digits

bool isdigits(string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

//Resizes dynamic array

int* arrayResize(int* arr, int arraySize){
    int* newArr = new int[arraySize+1];
    for(int i = 0; i < arraySize; i++)
    {
       newArr[i] = arr[i];
    }
    delete [] arr;
    return newArr;
}

//checks if name is only made out of letters

bool validateName(string name){
    for (char i : name)
    {
        if (!isalpha(i))
        {
            cout << "Error! Please use only letters" << endl;
            cout << "Try to enter students name again: ";
            return false;
        }
    }
    return true;
}

//Returns string that is only digits

string getDigits(){
    bool valid;
    string number;
    do {
        cin >> number;
        cout << endl;
            if (!isdigits(number))
            {
                cout << "Error! Please enter only digits" << endl;
                cout << "Try to enter your number again: ";
                valid = false;
            }
            else
            {
                valid = true;
            }
        }
    while(!valid);

    return number;
}

//Gets exam grade and checks it

int getExam(){
    int Grade;
    bool valid = false;
    do
    {
        Grade = std::stoi(getDigits());
        if (Grade > 10)
        {
            cout << "Error: invalid grade" << endl;
            cout << "Try to enter exam grade again: ";
        }
        else
        {
            valid = true;
        }
    }
    while(!valid);

    return Grade;
}

//Generates random homework grades and exam grade

void generateGrades(bool gradeNumber, student& Student){
    using chronoClock = std::chrono::high_resolution_clock;
    unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10);

    if (!gradeNumber)
    {
        std::uniform_int_distribution<int> distributionSize(1, 15);
        Student.homeworkSize = distributionSize(generator);
    }

    cout << "Generated " << Student.homeworkSize << " homework grades: ";
    Student.homeworkGrades = new int[Student.homeworkSize];
    for (int i=0; i<Student.homeworkSize; i++)
    {
        Student.homeworkGrades[i] = distribution(generator);
        cout << Student.homeworkGrades[i] << " ";
    }
    Student.examGrade = distribution(generator);
    cout << endl << "Generated exam grade: " << Student.examGrade << endl << endl;

}

//Calculates final grade with average grade

void finalGradeAverage(student* group, int n){
    double average;
    for (int i=0; i<n; i++)
    {
        average = 0;
        for (int j=0; j<group[i].homeworkSize; j++)
        {
            average = average + group[i].homeworkGrades[j];
        }
        average = average / group[i].homeworkSize;
        group[i].finalGrade = (average*0.4) + (group[i].examGrade*0.6);
    }
}

//Calculates final grade with median

void finalGradeMedian(student* group, int n){
    double median;
    for (int i=0; i<n; i++)
    {
        std::sort(group[i].homeworkGrades, group[i].homeworkGrades+group[i].homeworkSize);
        median = group[i].homeworkGrades[(group[i].homeworkSize/2)];
        if (group[i].homeworkSize%2 == 0)
        {
            median = (median + group[i].homeworkGrades[(group[i].homeworkSize/2)-1]) / 2;
        }
        group[i].finalGrade = (median*0.4) + (group[i].examGrade*0.6);
    }
}

//Prints results

void print(student* group, int n, bool isMedian){
    cout << endl;
    if (isMedian)
    {
        cout << "First name          Last name           Final grade(median)" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i=0; i<n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].firstName << string (20-group[i].firstName.length(), ' ')
                 << group[i].lastName << string (21-group[i].lastName.length(), ' ')  << group[i].finalGrade << endl;
        }
    }
    else
    {
        cout << "First name          Last name           Final grade(average)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i=0; i<n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].firstName << string (20-group[i].firstName.length(), ' ')
                 << group[i].lastName << string (21-group[i].lastName.length(), ' ')  << group[i].finalGrade << endl;
        }
    }
}
