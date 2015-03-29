//=============================================================================
// Author: Maxwell Partington
// Class : CS421
// Project: 2
// Date: 11/27/13 
// Description: This program is designed to replicate a pushdown automata.  
// Compilation: To compile this program, use "g++ -o project2 project2.cpp"
// Running:     To run the program, type "./project2"
//=============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

//-----------------------------------------------------------------------------
// The following are global variables, and function declarations for the 
// program. 
//-----------------------------------------------------------------------------
int i = 0;
int PDA(string inputs);
int q0(string);
void q1(string);
void qf(string);
int qE(char, string);
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// This is the declaration and creation of the stack that will be used for the
// simulated automata. 
//-----------------------------------------------------------------------------
class pdaStack : public std::stack<char>
{
        public:
                using std:: stack<char> :: c;
};

pdaStack pda;
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Description: The main function opens and reads the file and moves each
// 		string into the PDA function for it to then be processed. When
//		the while loop reaches the end of the file and there are no more
//		strings to read, the function completes, and the program ends. 
//		If the file needed cannot be read, then the program exits. 
//-----------------------------------------------------------------------------
int main()
{
        string inputFromFile;
        ifstream pdaFile("input.txt");

        if (pdaFile.is_open())
        {
                cout << "\n============================================";
                cout << "\nFile found... Opening file... Processing...";
                cout << "\n============================================" << endl;

                while ( !pdaFile.eof())
                {
                        getline(pdaFile, inputFromFile);
                        PDA(inputFromFile);
                        i++;
		}//end while
 
		cout << "\n###########################################################################################" << endl;
                cout << "The program has finished processing your file, closing file ";
                cout << "and exiting program. Thank you!" << endl;
		cout << "###########################################################################################\n" << endl;
                pdaFile.close();
        }
        else
        {
                cout << "\n==========================================";
                cout << "\n    FILE NOT FOUND. EXITING PROGRAM.";
                cout << "\n==========================================\n" << endl;
        }
}//end main
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Description: This function is designed to simulate a PDA. It accepts each 
// 		string passed into it by the main function and moves to the first
//		state of the simulated PDA. Before moving to q0, it empties out
//		the created stack from above to make sure there is nothing in it. 
//-----------------------------------------------------------------------------
int PDA(string input)
{

	cout << "\n------------------------------------------------------------" << endl;
        cout << "Evaluating string #" << i << " in file. The string is: '" << input << "'"<< endl;
        cout << "------------------------------------------------------------\n" << endl;

        while (pda.empty() != 1)
        {
                pda.pop();
        }
	
	cout << "------------------------------------------------------------" << endl;
	cout << "Moving to q0..." << endl;
	cout << "------------------------------------------------------------\n" << endl; 

	q0(input);		
	
}//end PDA
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Description: This function analyzes the inputted string by looking at each 
// 		character individually. If the character is accepted and in
// 		the language, then this function says where to pop or push items 
//		onto or off of the stack. Secondly, it moves to q1 if it has to
// 		pop items off of the stack. 
//-----------------------------------------------------------------------------
int q0(string input)
{
	int j = 0;
	while ( j < input.length())
        {
                if ((input[j] == '(') || (input[j] == ')') || (input[j] == '[') || (input[j] == ']'))
                {
                        if((pda.empty() == 1) && (input[j] == '('))
                        {
                                cout << "Pushing: '" << input[j] << "' onto stack." << endl;
                                pda.push(input[j]);
                        }
                        else if((pda.empty() == 1) && (input[j] == '['))
                        {
                                cout << "Pushing: '" << input[j] << "' onto stack." << endl;
                                pda.push(input[j]);
                        }
                        else if((pda.top() == '(') && (input[j] == '('))
                        {
                                cout << "Pushing: '" << input[j] << "' onto stack." << endl;
                                pda.push(input[j]);
                        }
                        else if ((pda.top() == '(') && (input[j] == '['))
                        {
                                cout << "Pushing: '" << input[j] << "' onto stack." << endl;
                                pda.push(input[j]);
                        }
                        else if((pda.top() == '[') && (input[j] == '('))
                        {
                                cout << "Pushing: '" << input[j] << "' onto stack." << endl;
                                pda.push(input[j]);
                        }
                        else if ((pda.top() == '[') && (input[j] == '['))
                        {
                                cout << "Pushing: '" << input[j] << "' onto stack." << endl;
                                pda.push(input[j]);
			}
			else if ((pda.top() == '(') && (input[j] == ']'))
			{
				cout << "\nAn error occured, moving to qe..." << endl;
				qE(input[j], input);
				break;
			}
			else if ((pda.top() == '[') && (input[j] == ')'))
			{
				cout << "\nAn error occured, moving to qe..." << endl; 
				qE(input[j], input);
				break; 
			}
			else if ((pda.top() == '(') && (input[j] == ')'))
                        {
				cout << "\nInput symbol: '" << input[j] << "' read... moving to q1..." << endl;
                    		q1(input);
		        }
                        else if ((pda.top() == '[') && (input[j] == ']'))
                        {
                                cout << "\nInput symbol: '" << input[j] << "' read... moving to q1..."  << endl;
				q1(input);
                        }
		}
		else
                {
			qE(input[j], input);
                }
	j++;
	}
}//end q0
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Description: q1 is accessed if a closing parenthesis is read by the automata
// 		and a matching parenthesis is found for it. If the stack is 
//		empty after the last pop of the stack, then the automata moves
//		to qf and the string is accepted by the language. 
//-----------------------------------------------------------------------------
void q1(string q0Input)
{
	cout << "Popping: '" << pda.top() << "' off of stack.\n" << endl;
        pda.pop();
	cout << "Returning to q0..." << endl;
        if (pda.empty() == 1)
        {
		cout << "\nNo more input to read, stack is empty, moving to qf." << endl;
		qf(q0Input);
        }
}//end q1
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Description: qf is only accessed if there are no more parentheses in the stack
//		and if the string is balanced and accepted by the automata. 
//-----------------------------------------------------------------------------
void qf(string final)
{
	cout << "\n************************************************" << endl;
	cout << "Parentheses are balanced for string " << final << endl;
	cout << "************************************************" << endl;	
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Description: The state qE is accessed when there are no matching parentheses 
// 		for the string given, or there is a character in the string 
//		that is not in the alphabet of the language. 
//-----------------------------------------------------------------------------
int qE(char symbol, string errorString)
{
	if ((symbol == ')') || (symbol == ']'))
	{
		cout << "No matching open parentheses for: '" << symbol << "' found." << endl;
		cout << "Parentheses are not balanced " << errorString << endl;
	}
	else
	{
	 	cout << "Invalid character: '" << symbol << "' present in string. This string";
         	cout << " is not accepted by the language." << endl;
	}
}//end qE 
//-----------------------------------------------------------------------------
