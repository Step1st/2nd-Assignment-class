#include "Test.h"

void generateStudents(int n, string fileName) {
    std::ifstream test;
    test.open(fileName.append(std::to_string(n)).append(".txt"));
    test.close();
    if (test.fail())
    {
        std::ofstream output(fileName);
        std::stringstream endBuffer;
        student Student;
        bool run = true;
        using chronoClock = std::chrono::high_resolution_clock;
        unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(0, 10);
        std::uniform_int_distribution<int> distributionSize(2, 20);

        cout << "Generating..." << endl;
        auto start = std::chrono::high_resolution_clock::now();

        int a = distributionSize(generator);

        for (int i = 1; i <= n; i++)
        {

            endBuffer << endl;
            int b = log10(i) + 1;
            endBuffer << "Vardas" << i << string(25 - (6 + b), ' ') << "Pavarde" << i << string(25 - (7 + b), ' ');
            for (int j = 0; j < a; j++)
            {
                endBuffer << distribution(generator) << "    ";
            }
        }
        output << endBuffer.str();
        output.close();

        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Generating " << n << " took " << diff.count() << " s" << endl;
    }
}

void bufferRead(vector<student>& group, string fileName, int n) {
    string eil;
    student temp;
    std::stringstream startBuffer;
    std::stringstream lines;
    std::fstream input;
    int k;
 
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
        if (!startBuffer.eof()) {
            std::getline(startBuffer, eil);
            lines << eil;

            lines >> temp.firstName >> temp.lastName;

            while (!lines.eof())
            {
                lines >> k;
                temp.homeworkGrades.push_back(k);
            }
            lines.clear();
            temp.examGrade = temp.homeworkGrades.back();
            temp.homeworkGrades.pop_back();
            temp.homeworkGrades.shrink_to_fit();
            temp.homeworkSize = temp.homeworkGrades.size();
            group.push_back(temp);
            temp = {};
        }
        else break;
    }
    startBuffer.clear();

    std::sort(group.begin(), group.end(), compareByLastName);
}

void bufferRead(list<student>& group, string fileName, int n) {
    string eil;
    student temp;
    std::stringstream startBuffer;
    std::stringstream lines;
    std::fstream input;
    int k;

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
        if (!startBuffer.eof()) {
            std::getline(startBuffer, eil);
            lines << eil;

            lines >> temp.firstName >> temp.lastName;

            while (!lines.eof())
            {
                lines >> k;
                temp.homeworkGrades.push_back(k);
            }
            lines.clear();
            temp.examGrade = temp.homeworkGrades.back();
            temp.homeworkGrades.pop_back();
            temp.homeworkGrades.shrink_to_fit();
            temp.homeworkSize = temp.homeworkGrades.size();
            group.push_back(temp);
            temp = {};
        }
        else break;
    }
    startBuffer.clear();

}

void bufferRead(deque<student>& group, string fileName, int n) {
    string eil;
    student temp;
    std::stringstream startBuffer;
    std::stringstream lines;
    std::fstream input;
    int k;

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
        if (!startBuffer.eof()) {
            std::getline(startBuffer, eil);
            lines << eil;

            lines >> temp.firstName >> temp.lastName;

            while (!lines.eof())
            {
                lines >> k;
                temp.homeworkGrades.push_back(k);
            }
            lines.clear();
            temp.examGrade = temp.homeworkGrades.back();
            temp.homeworkGrades.pop_back();
            temp.homeworkGrades.shrink_to_fit();
            temp.homeworkSize = temp.homeworkGrades.size();
            group.push_back(temp);
            temp = {};
        }
        else break;
    }
    startBuffer.clear();

    std::sort(group.begin(), group.end(), compareByLastName);
}

void writeToFile(vector<student>& groupGood, vector<student>& groupBad, int n) {
    const char* dir = "test/vector";
    _mkdir(dir);
    string op1 = "test/vector/kietiakiai.txt";
    string op2 = "test/vector/vargšiukai.txt";
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

void writeToFile(list<student>& groupGood, list<student>& groupBad, int n) {
    const char* dir = "test/list";
    _mkdir(dir);
    string op1 = "test/list/kietiakiai.txt";
    string op2 = "test/list/vargšiukai.txt";
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

void writeToFile(deque<student>& groupGood, deque<student>& groupBad, int n) {
    const char* dir = "test/deque";
    _mkdir(dir);
    string op1 = "test/deque/kietiakiai.txt";
    string op2 = "test/deque/vargšiukai.txt";
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

void testVector(vector<student>& group, vector<student>& groupGood, vector<student>& groupBad, string fileName, int n){
    cout << "\nVector\n";
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
    writeToFile(groupGood, groupBad, n);
    groupGood.erase(groupGood.begin(), groupGood.end());
    groupBad.erase(groupBad.begin(), groupBad.end());
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Writing took " << std::fixed << diff.count() << " s" << endl;
}


void testList(list<student>& group, list<student>& groupGood, list<student>& groupBad, string fileName, int n) {
    cout << "\nList\n";
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
    writeToFile(groupGood, groupBad, n);
    groupGood.erase(groupGood.begin(), groupGood.end());
    groupBad.erase(groupBad.begin(), groupBad.end());
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Writing took " << std::fixed << diff.count() << " s" << endl;
}

void testDeque(deque<student>& group, deque<student>& groupGood, deque<student>& groupBad, string fileName, int n) {
    cout << "\nDeque\n";
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
    writeToFile(groupGood, groupBad, n);
    groupGood.erase(groupGood.begin(), groupGood.end());
    groupBad.erase(groupBad.begin(), groupBad.end());
    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Writing took " << std::fixed << diff.count() << " s" << endl;
}
