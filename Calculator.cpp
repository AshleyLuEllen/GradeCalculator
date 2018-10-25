
#include "Calculator.h"
#include <iostream>
#include <iomanip>

using namespace std;

void programs(int numProg, double prog[30], double &ptsTotal, double &ptsEarned) {
  double ptsProg = 30;
  for (int x = 0; x <= numProg; x++) {
    ptsTotal += ptsProg;
    ptsEarned += ptsProg * prog[x];
  }
}

void practicums(int numPract, double pract[30], double &ptsTotal, double &ptsEarned) {
  double ptsPract;
  for (int count = numPract - 1; count >= 0; count--) {

    if (count >= 7)//if the practicum number is 8-10
      ptsPract = 100;
    else if (count == 6)//if the practicum number is 7
      ptsPract = 75;
    else if (count >= 3)//if the practicum number is 4-6
      ptsPract = 50;
    else//if the practicum number is 1-3
      ptsPract = 25;

    ptsTotal += ptsPract;
    ptsEarned += ptsPract * pract[count];
  }
}

void groupProjects(double groupProg, double &ptsTotal, double &ptsEarned) {
  double ptsGroup = 300;
  ptsTotal += ptsGroup;
  ptsEarned += ptsGroup * groupProg;
}

void exams(int numExam, double exams[2], double &ptsTotal, double &ptsEarned) {
  double ptsExam = 300;
  for (int x = 0; x < numExam; x++) {
    ptsTotal = ptsTotal + ptsExam;
    ptsEarned += 300 * exams[x];
  }
}

void final(int numFinal, double finals[2], double &ptsTotal, double &ptsEarned) {
  double ptsFinal = 800;
  for (int x = 0; x < numFinal; x++) {
    ptsTotal += ptsFinal;
    ptsEarned += ptsFinal * finals[x];
  }
}

void print(double ptsEarnedProg, double ptsTotalProg, double ptsEarnedPract, double ptsTotalPract,
           double ptsEarnedGroup, double ptsTotalGroup, double ptsEarnedExams, double ptsTotalExams,
           double ptsEarnedFinals, double ptsTotalFinals, ofstream &output) {

  if (ptsEarnedProg > 1)
    output << "Percent on programs " << fixed << setprecision(2) << ptsEarnedProg / ptsTotalProg * 100 << "%\n";
  if (ptsEarnedPract > 1)
    output << "Percent on practicums " << fixed << setprecision(2) << ptsEarnedPract / ptsTotalPract * 100 << "%\n";
  if (ptsEarnedExams > 1)
    output << "Percent on exams " << fixed << setprecision(2) << ptsEarnedExams / ptsTotalExams * 100 << "%\n";
  if (ptsEarnedGroup > 1.0)
    output << "Percent on the group project " << fixed << setprecision(2) << ptsEarnedGroup / ptsTotalGroup * 100
           << "%\n";
  if (ptsEarnedFinals > 1)
    output << "Percent on finals " << fixed << setprecision(2) << ptsEarnedFinals / ptsTotalFinals * 100 << "%\n";
}

void printOut(double ptsEarnedProg, double ptsTotalProg, double ptsEarnedPract, double ptsTotalPract,
              double ptsEarnedGroup, double ptsTotalGroup, double ptsEarnedExams, double ptsTotalExams,
              double ptsEarnedFinals, double ptsTotalFinals, double &ptsTotal, double &ptsEarned, ofstream &output) {

  ptsTotal = ptsTotalProg + ptsTotalPract + ptsTotalGroup + ptsTotalExams + ptsTotalFinals;
  ptsEarned = ptsEarnedProg + ptsEarnedPract + ptsEarnedGroup + ptsEarnedExams + ptsEarnedFinals;

  output << "Total Points Lost: " << ptsTotal - ptsEarned << endl;
  output << ptsEarned << " / " << ptsTotal << endl;
  output << fixed << setprecision(3) << ptsEarned / ptsTotal * 100 << "%" << endl;

}

