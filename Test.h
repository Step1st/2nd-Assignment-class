#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "Student.h"
#include "StudentFile.h"

void generateStudents(int, string);


template<class T>
void bufferRead(T& group, string fileName, int n) {
    string eil;
    student temp;
    std::stringstream startBuffer;
    std::stringstream lines;
    std::fstream input;

    int k;
    int t = 1;

    try
    {
        input.open(fileName.append(std::to_string(n)).append(".txt"));
        if (input.fail())
        {
            throw 1;
        }
    }
    catch (int e)
    {
        cout << "Failed to open file" << endl;
        cout << "Make sure file 'kursiokai.txt' is in the right directory" << endl;
        system("pause");
        exit(e);
    }
    std::getline(input, eil);
    startBuffer << input.rdbuf();
    input.close();
    while (startBuffer) {
        try
        {
            if (!startBuffer.eof()) {
                std::getline(startBuffer, eil);
                lines << eil;
                lines >> temp.firstName >> temp.lastName;
                while (!lines.eof()) {
                    lines >> k;
                    temp.homeworkGrades.push_back(k);
                }

                lines.clear();
                temp.examGrade = temp.homeworkGrades.back();
                temp.homeworkGrades.pop_back();
                temp.homeworkGrades.shrink_to_fit();
                temp.homeworkSize = temp.homeworkGrades.size();
                group.push_back(temp);
                temp.homeworkGrades.erase(temp.homeworkGrades.begin(), temp.homeworkGrades.end());
                temp = {};
                t++;
            }
            else break;
        }
        catch (std::exception& e)
        {
            cout << "A memory error has occurred\n";
            exit(1);
        }
    }
    startBuffer.clear();

}


template <class T>
void writeToFile(T& groupGood, T& groupBad, int n, string dir) {
    string op1;
    string op2;
    if (std::is_same<T, vector<student>>::value)
    {
        dir.append("/vector");
        op1 = dir + "/kietiakiai.txt";
        op2 = dir + "/vargsiukai.txt";
    }
    if (std::is_same<T, list<student>>::value)
    {
        dir.append("/list");
        op1 = dir + "/kietiakiai.txt";
        op2 = dir + "/vargsiukai.txt";
    }
    if (std::is_same<T, deque<student>>::value)
    {
        dir.append("/deque");
        op1 = dir + "/kietiakiai.txt";
        op2 = dir + "/vargsiukai.txt";
    }

    int dir_ = _mkdir(dir.c_str());

    std::ofstream output1(op1.append(std::to_string(n)).append(".txt"));
    std::ofstream output2(op2.append(std::to_string(n)).append(".txt"));
    std::stringstream endBuffer1;
    std::stringstream endBuffer2;

    endBuffer1 << "First name          Last name           Final grade(average)\n";
    endBuffer2 << "First name          Last name           Final grade(average)\n";

    endBuffer1 << "-----------------------------------------------------------\n";
    endBuffer2 << "-----------------------------------------------------------\n";

    auto start = std::chrono::high_resolution_clock::now();
    for (student& i : groupGood)
    {
        endBuffer1 << std::setprecision(2) << std::fixed << i.firstName << string(20 - i.firstName.length(), ' ')
                   << i.lastName << string(21 - i.lastName.length(), ' ') << i.finalGrade << endl;
    }

    for (student& i : groupBad)
    {
        endBuffer2 << std::setprecision(2) << std::fixed << i.firstName << string(20 - i.firstName.length(), ' ')
                   << i.lastName << string(21 - i.lastName.length(), ' ') << i.finalGrade << endl;
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "writing to buffer took " << diff.count() << " s" << endl;

    output1 << endBuffer1.str();
    output1.close();

    output2 << endBuffer2.str();
    output2.close();
}


template<class T>
void Test(T& group, T& groupGood, T& groupBad, string fileName, int n, string dir) {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Reading..." << endl;
    bufferRead(group, fileName, n);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Reading took " << std::fixed << diff.count() << " s" << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << "Calculating..." << endl;
    finalGradeAverage(group, group.size());
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Calculating took " << std::fixed << diff.count() << " s" << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << "Sorting..." << endl;
    sortStudents(group, groupGood, groupBad);
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Sorting took " << std::fixed << diff.count() << " s" << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << "Writing..." << endl;
    writeToFile(groupGood, groupBad, n, dir);
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Writing took " << std::fixed << diff.count() << " s" << endl;
    group.clear();
    groupGood.clear();
    groupBad.clear();
}

template<class T>
void Test2(T& group, T& groupGood, string fileName, int n, string dir) {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Reading..." << endl;
    bufferRead(group, fileName, n);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Reading took " << std::fixed << diff.count() << " s" << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << "Calculating..." << endl;
    finalGradeAverage(group, group.size());
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Calculating took " << std::fixed << diff.count() << " s" << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << "Sorting..." << endl;
    sortStudents2(group, groupGood);
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Sorting took " << std::fixed << diff.count() << " s" << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << "Writing..." << endl;
    writeToFile(groupGood, group, n, dir);
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Writing took " << std::fixed << diff.count() << " s" << endl;
    group.clear();
    groupGood.clear();
}

#endif // GENERAL_H_INCLUDED

