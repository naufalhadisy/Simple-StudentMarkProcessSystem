// Assignment 123

// ============ Group member: ================== 
// - Naufal Hadi Syukrima 			(A19EC0272) 
// - Ammar Hawari Abdillah 			(A19EC0220) 
// - Ramadhan Muhammad Jumantoro	(A19EC0277)
// =============================================



#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Constants
const int ROWS = 10;
const int COLS = 3;

// Function prototypes
string getGrade(int);
void readData(string, string [], int [], int []);
void processData(string [], int [], int [], int [][COLS]);
void writeResult(string [], int [][COLS], string);

int main() {
	string name[ROWS];
	int course_work[ROWS];
	int final_exam[ROWS];
	
	// 'result' is two dimensional array of string type paramater 
	// with column info as follows:
	// column 1 => student name, column 2 => total mark, column 3 => grade
	int result[ROWS][COLS];
	
	// Start to read data, process data and write result here
	//readData("cwfe.txt", name, course_work, final_exam);
	readData("cwfe.txt", name, course_work, final_exam);
	processData(name, course_work, final_exam, result);
	writeResult(name, result, "result.txt");
	
	return 0;
}

// Function implementations
string getGrade(int m) {
	if (m >= 90) return "A+";
	if (m >= 80) return "A";
	if (m >= 75) return "A-";
	if (m >= 70) return "B+";
	if (m >= 65) return "B";
	if (m >= 60) return "B-";
	if (m >= 55) return "C+";
	if (m >= 50) return "C";
	if (m >= 45) return "C-";
	if (m >= 40) return "D+";
	if (m >= 35) return "D";
	if (m >= 30) return "D-";
	
	return "E";
}

void readData(string filename, string n [], int cw [], int fe [])
 {
 
 	cout << "Reading data from " << filename << " file...\n";
 
    ifstream infile;
    infile.open(filename.c_str());
 
    if (infile.is_open())
    {
        for (int k = 0; k < ROWS; k++)
        {
            infile >> n[k] >> cw[k] >> fe[k];
            cout << n[k] << " " << " " << cw[k] << " " << fe[k] << endl;
        }
 
        infile.close(); // CLose input file
    }
    else { //Error message
        cerr << "Can't find input file " << filename << endl;
    }
 
 
}
 
 
void processData(string n [], int cw [], int fe [], int rslt[][COLS]) 
{
	cout << "\nProcessing data...\n\n";
	
	int total[ROWS];
 	
 	for (int m = 0; m < ROWS; m++)
        {	
        	rslt[m][COLS] = cw[m] + fe[m]; //summing the score
 		}
 		
}
 
 
void writeResult(string n [], int rslt[][COLS], string filename) 
{	
	cout << "Writing result to " << filename << " file...\n";
	
	string outfilename = "result.txt";
    ofstream outfile;
 	outfile.open(filename.c_str());
 	
 	
        for (int m = 0; m < ROWS; m++)
        {
			cout << n[m] << " " << rslt[m][COLS] << " " << getGrade(rslt[m][COLS])<<endl;	
																					
			outfile << n[m] << " " << rslt[m][COLS] << " " << getGrade(rslt[m][COLS])<<endl; 
        	
        }
 
        outfile.close(); // Close output file
    
 
}
