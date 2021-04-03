#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "Student.h"
#include "StudentFile.h"

void generateStudents(int, string);

void bufferRead(vector<student>&, string, int);
void bufferRead(list<student>&, string, int);
void bufferRead(deque<student>&, string, int);

void writeToFile(vector<student>&, vector<student>&, int);
void writeToFile(list<student>&, list<student>&, int);
void writeToFile(deque<student>&, deque<student>&, int);

void testVector(vector<student>&, vector<student>&, vector<student>&, string, int);
void testList(list<student>&, list<student>&, list<student>&, string, int);
void testDeque(deque<student>&, deque<student>&, deque<student>&, string, int);


#endif // GENERAL_H_INCLUDED

