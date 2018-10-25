
//Created By: Ashley Lu Couch
// This program calculates my grade in Computer Science Class
//Last Edited 10/24/2018

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "Calculator.h"

using namespace std;

int main() {
  //show percentage of each category
  bool show = true;

//open input file
  ifstream gradesFile;
  gradesFile.open("grades.txt");

  if (gradesFile.is_open()) {

    //open output file
    ofstream gradesCalculated;
    gradesCalculated.open("classGrade.txt");

    //set output of catagories if false
    string showTF;
    gradesFile >> showTF;

    if (showTF == "false" || showTF == "False") {
      show = false;
    }

    string ignore;
    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //get the number of programs
    int numOfPrograms;
    gradesFile >> numOfPrograms;

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //make the array for programs
    double program[30];
    for (int x = 0; x <= numOfPrograms; x++) {
      gradesFile >> program[x];
    }

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //get the number of practicums
    int numOfPracticums;
    gradesFile >> numOfPracticums;

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //make the array for practicums
    double practicum[9];
    for (int x = 0; x < numOfPracticums; x++) {
      gradesFile >> practicum[x];
    }

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //set the percentage for group project
    double groupProg;
    gradesFile >> groupProg;

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //get the number of exams
    int numOfExams;
    gradesFile >> numOfExams;

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //make an array for exams
    double exam[2];
    for (int x = 0; x < numOfExams; x++) {
      gradesFile >> exam[x];
    }

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //get the number of finals
    int numOfFinals;
    gradesFile >> numOfFinals;

    //ignore text lines
    getline(gradesFile, ignore);
    getline(gradesFile, ignore);

    //make an array for the finals
    double finals[2];
    for (int x = 0; x < numOfFinals; x++) {
      gradesFile >> finals[x];
    }

    //initalize totals
    //points total
    double ptsTotal = 0, ptsTProg = 0, ptsTPract = 0, ptsTExams = 0, ptsTGroup = 0, ptsTFinals = 0;
    //points earned totals
    double ptsEarned = 0, ptsEProg = 0, ptsEPract = 0, ptsEExams = 0, ptsEGroup = 0, ptsEFinals = 0;

    //run the calculations if grades exist in category
    if (numOfPrograms >= 0)//if we have some number of programs
      programs(numOfPrograms, program, ptsTProg, ptsEProg);
    if (numOfPracticums > 0)//if we have some number of practicums
      practicums(numOfPracticums, practicum, ptsTPract, ptsEPract);
    if (numOfExams > 0)//if we have some number of exams
      exams(numOfExams, exam, ptsTExams, ptsEExams);
    if (groupProg >= 1.0)//if we have a grade for group project
      groupProjects(groupProg, ptsTGroup, ptsEGroup);
    if (numOfFinals > 0)//if we have some number of finals
      final(numOfFinals, finals, ptsTFinals, ptsEFinals);

    //show percentage of each category
    if (show == true) {
      print(ptsEProg, ptsTProg, ptsEPract, ptsTPract, ptsEGroup, ptsTGroup, ptsEExams, ptsTExams, ptsEFinals,
            ptsTFinals, gradesCalculated);
    }

    //Final Grade Calculation
    printOut(ptsEProg, ptsTProg, ptsEPract, ptsTPract, ptsEGroup, ptsTGroup, ptsEExams, ptsTExams,
             ptsEFinals, ptsTFinals, ptsTotal, ptsEarned, gradesCalculated);

    gradesCalculated.close();

  }

  gradesFile.close();

}


