
#ifndef GRADECALCULATOR2_0_CALCULATOR_H
#define GRADECALCULATOR2_0_CALCULATOR_H

#include <fstream>

void programs(int numProg, double prog[30], double &ptsTotal, double &ptsEarned);

void practicums(int numPract, double pract[30], double &ptsTotal, double &ptsEarned);

void groupProjects( double groupProg, double &ptsTotal, double &ptsEarned);

void exams(int numExam, double exams[2], double &ptsTotal, double &ptsEarned);

void final(int numFinal, double finals[2], double &ptsTotal, double &ptsEarned);

void print(double ptsEarnedProg, double ptsTotalProg, double ptsEarnedPract, double ptsTotalPract,
      double ptsEarnedGroup, double ptsTotalGorup, double ptsEarnedExams, double ptsTotalExams,
      double ptsEarnedFinals, double ptsTotalFinals, std::ofstream &output);

void printOut(double ptsEarnedProg, double ptsTotalProg, double ptsEarnedPract, double ptsTotalPract,
              double ptsEarnedGorup, double ptsTotalGorup, double ptsEarnedExams, double ptsTotalExams,
              double ptsEarnedFinals, double ptsTotalFinals, double &ptsTotal, double &ptsEarned, std::ofstream &output);

#endif //GRADECALCULATOR2_0_CALCULATOR_H
