#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

// Main function
int main() {
    int totalStudents;
    cout << "Enter Number of Students: ";
    cin >> totalStudents;

    // Store studentdata
    map<string, vector<int>> studentData;

    for (int s = 0; s < totalStudents; ++s) {
        string name;
        vector<int> scores;

        cout << "Enter Name of Student "<<s+1<<": ";
        cin >> name;

        int score;
        for (int sub = 1; sub <= 3; ++sub) {
            cout << "Enter marks for Subject " << sub << ": ";
            cin >> score;
            scores.push_back(score);
        }

        studentData[name] = scores;
    }

    cout << "\nStudent Performance:\n";

    // Store name and average
    vector<pair<string, double>> averages;

    for (auto &entry : studentData) {
        const string &studentName = entry.first;
        const vector<int> &subjectMarks = entry.second;

        double total = accumulate(subjectMarks.begin(), subjectMarks.end(), 0);
        double avg = total / subjectMarks.size();

        cout << "Student: " << studentName << ", Marks: ";
        for (size_t i = 0; i < subjectMarks.size(); ++i) {
            cout << subjectMarks[i] << " ";
        }
        cout << ", Average: " << avg << endl;

        averages.push_back(make_pair(studentName, avg));
    }

    // Determine topper using max_element
    auto bestStudent = max_element(
        averages.begin(), averages.end(),
        [](const pair<string, double> &a, const pair<string, double> &b) {
            return a.second < b.second;
        });

    cout << "Topper: " << bestStudent->first << " with average " << bestStudent->second << endl;

    return 0;
}

