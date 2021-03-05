#include "Student.h"
#include "General.h"

int main() {
    vector<student> group;  // student vector
    int n;                  // number of students
    bool run = true;        // used for while loops in main
    bool gradeNumber;       // flag for if grade number is known
    string readfile;
    string ansMedian;
    cout << "Get students from file or enter manually?(f/m): ";
    do {
        cin >> readfile;
        if (readfile == "f" || readfile == "F")
        {
            cout << "Use median for final grade?(y/n): ";
            do {
                cin >> ansMedian;
                if (ansMedian == "y" || ansMedian == "Y")
                {
                    bufferRead(group);
                    finalGradeMedian(group, group.size());
                    auto start3 = std::chrono::high_resolution_clock::now();
                    cout << "Writing..." << endl;
                    writeToFile(group, group.size(), true);
                    run = false;
                    std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3; 
                    std::cout << "Writing took " << diff3.count() << " s" << endl;
                }
                else if (ansMedian == "n" || ansMedian == "N")
                {
                    bufferRead(group);
                    finalGradeAverage(group, group.size());
                    auto start3 = std::chrono::high_resolution_clock::now();
                    cout << "Writing..." << endl;
                    writeToFile(group, group.size(), false);
                    run = false;
                    std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3; 
                    std::cout << "Writing took " << diff3.count() << " s" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Error: bad entry" << endl;
                    cout << "Try again(y/n): ";
                    run = true;
                }
            }
            while (run);

            run = false;
        }
        else if (readfile == "m" || readfile == "M")
        {
            cout << "Enter the number of students: ";

            do
            {
                try
                {
                    n = std::stoi(getDigits());
                    run = false;
                }
                catch (std::exception& e)
                {
                    cout << "Error: number entered is to big." << endl;
                    cout << "Try again: ";
                    run = true;
                }
            } 
            while (run);

            for (int i = 0; i < n; i++)
            {
                group.push_back(student());

                cout << "Enter students first name: ";
                do {
                    cin >> group[i].firstName;
                    cout << endl;
                }
                while (!validateName(group[i].firstName));

                cout << "Enter students last name: ";
                do {
                    cin >> group[i].lastName;
                    cout << endl;
                }
                while (!validateName(group[i].lastName));

                string ansGrade;
                cout << "Is the number of grades known?(y/n): ";
                do {
                    cin >> ansGrade;
                    if (ansGrade == "y" || ansGrade == "Y")
                    {
                        int temp;
                        cout << "Enter the number of grades: ";
                        do {
                            do {
                                try
                                {
                                    temp = std::stoi(getDigits());
                                    run = false;
                                }
                                catch (std::exception& e)
                                {
                                    cout << "Error: number entered is to big." << endl;
                                    cout << "Try again: ";
                                    run = true;
                                }
                            }                             while (run);

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
                        while (run);
                        gradeNumber = true;
                    }
                    else if (ansGrade == "n" || ansGrade == "N")
                    {
                        cout << endl;
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
                while (run);

                string ansRandom;
                cout << "Generate grades randomly?(y/n): ";
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
                        cout << endl << "Enter students exam grade: ";
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
                while (run);
            }
            group.shrink_to_fit();

            cout << "Use median for final grade?(y/n): ";
            do {
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
            while (run);
            run = false;
        }
        else
        {
            cout << endl;
            cout << "Error: bad entry" << endl;
            cout << "Try again(f/m): ";
        }
    }
    while (run);
    system("pause");
}
