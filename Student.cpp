#include "Student.h"
#include "General.h"

bool compareByLastName(const student& a, const student& b) {
    return a.lastName < b.lastName;
}

void bufferRead(vector<student>& group) {
    string eil;
    std::stringstream startBuffer;
    std::stringstream lines;
    student temp;
    int j = 0;
    int k;
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Reading..." << endl;
    std::fstream input("kursiokai.txt");
    std::getline(input, eil);
    startBuffer << input.rdbuf();
    input.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Reading took " << diff.count() << " s" << endl;


    auto start2 = std::chrono::high_resolution_clock::now();
    cout << "Processing..." << endl;
    while (startBuffer) {
        if (!startBuffer.eof()) {
            std::getline(startBuffer, eil);
            lines << eil;
            
            lines >> temp.firstName >>temp.lastName;  

            while (!lines.eof())
            {
                lines >> k;
                temp.homeworkGrades.push_back(k);
            }
            lines.clear();
            temp.examGrade = temp.homeworkGrades[temp.homeworkGrades.size() - 1];
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
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Processing took: " << diff2.count() << " s" << endl;
}

void writeToFile(vector<student>& group, int n, bool isMedian) {
    std::ofstream output("output.txt");
    std::stringstream endBuffer;
    if (isMedian)
    {
        endBuffer << "First name          Last name           Final grade(median)\n";
        endBuffer << "----------------------------------------------------------\n";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            endBuffer << std::setprecision(2) << std::fixed << group.at(i).firstName << string(20 - group.at(i).firstName.length(), ' ')
                << group.at(i).lastName << string(21 - group.at(i).lastName.length(), ' ') << group.at(i).finalGrade << endl;
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
        std::cout << "writing to buffer took " << diff.count() << " s" << endl;
    }
    else
    {
        endBuffer << "First name          Last name           Final grade(average)\n";
        endBuffer << "-----------------------------------------------------------\n";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            endBuffer << std::setprecision(2) << std::fixed << group.at(i).firstName << string(20 - group.at(i).firstName.length(), ' ')
                << group.at(i).lastName << string(21 - group.at(i).lastName.length(), ' ') << group.at(i).finalGrade << endl;
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
        std::cout << "writing to buffer took " << diff.count() << " s" <<endl;
    }

    output << endBuffer.str();
    output.close();
}


void homeworkGrades(bool gradeNumber, student& Student) {
    bool run = true;
    string Grade;
    if (gradeNumber)
    {
        for (int i = 0; i < Student.homeworkSize; i++)
        {
            do {
                cout << Student.homeworkGrades.size() + 1 << ". Enter grade: ";
                cin >> Grade;
                if (isdigits(Grade) && std::stoi(Grade) <= 10 && std::stoi(Grade) >= 0)
                {
                    Student.homeworkGrades.push_back(std::stoi(Grade));
                    run = false;
                }
                else
                {
                    cout << "Error: invalid grade" << endl;
                    run = true;
                }
            }
            while (run);
        }
    }
    else
    {
        cout << endl << "To finish entering grades type in 'end'" << endl;
        do {
            cout << Student.homeworkGrades.size() + 1 << ". Enter grade: ";
            cin >> Grade;
            if (isdigits(Grade) && std::stoi(Grade) <= 10 && std::stoi(Grade) >= 0)
            {
                Student.homeworkGrades.push_back(std::stoi(Grade));
            }
            else if (Grade == "end" || Grade == "END")
            {
                Student.homeworkSize = Student.homeworkGrades.size();
                Student.homeworkGrades.shrink_to_fit();
                run = false;
            }
            else
            {
                cout << "Error: invalid grade" << endl;
            }

            if (Student.homeworkGrades.empty() && Grade == "end")
            {
                cout << "Error! Please enter at least one grade" << endl;
                run = true;
            }
        }
        while (run);
    }
}

//Gets exam grade and checks it

int getExam() {
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
    while (!valid);

    return Grade;
}

//Generates random homework grades and exam grade

void generateGrades(bool gradeNumber, student& Student) {
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
    for (int i = 0; i < Student.homeworkSize; i++)
    {
        Student.homeworkGrades.push_back(distribution(generator));
        cout << Student.homeworkGrades[i] << " ";
    }
    Student.examGrade = distribution(generator);
    cout << endl << "Generated exam grade: " << Student.examGrade << endl << endl;

}

//Calculates final grade with average grade

void finalGradeAverage(vector<student>& group, int n) {
    double average;
    for (int i = 0; i < n; i++)
    {
        average = 0;
        for (int j = 0; j < group[i].homeworkSize; j++)
        {
            average = average + group[i].homeworkGrades[j];
        }
        average = average / group[i].homeworkSize;
        group[i].finalGrade = (average * 0.4) + (group[i].examGrade * 0.6);
    }
}

//Calculates final grade with median

void finalGradeMedian(vector<student>& group, int n) {
    double median;
    for (int i = 0; i < n; i++)
    {
        std::sort(group[i].homeworkGrades.begin(), group[i].homeworkGrades.end());
        median = group[i].homeworkGrades[(group[i].homeworkSize / 2)];
        if (group[i].homeworkSize % 2 == 0)
        {
            median = (median + group[i].homeworkGrades[(group[i].homeworkSize / 2) - 1]) / 2;
        }
        group[i].finalGrade = (median * 0.4) + (group[i].examGrade * 0.6);
    }
}

//Prints results

void print(vector<student>& group, int n, bool isMedian) {
    cout << endl;
    if (isMedian)
    {
        cout << "First name          Last name           Final grade(median)" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].firstName << string(20 - group[i].firstName.length(), ' ')
                << group[i].lastName << string(21 - group[i].lastName.length(), ' ') << group[i].finalGrade << endl;
        }
    }
    else
    {
        cout << "First name          Last name           Final grade(average)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].firstName << string(20 - group[i].firstName.length(), ' ')
                << group[i].lastName << string(21 - group[i].lastName.length(), ' ') << group[i].finalGrade << endl;
        }
    }
}
