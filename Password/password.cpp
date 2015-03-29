//=============================================================================
// Author: Maxwell Partington
// Class : CS421
// Project: 1
// Date: 10/28/13 
//=============================================================================

#include <iostream>
#include <string> 
#include <locale>
using namespace std; 

int numOfUppers = 0;
int numOfDigits = 0;
int length = 0;

int qZero(string test);
int qOne(string test, int position1);
int qTwo(string test,int position2);
int qThree(string test, int position3);
int qFour(string test, int position4);
int qFive(string test, int position5);
int qSix(string test, int position6);
int qSeven(string test);
int qEight(string test);
int qNine(string test);
int qTen(string test);
int qEleven(string test);
int finalState(int final1, int final2, int final3);
int errorState(int test1, int test2, int test3);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main()
{
	string password;

	cout << "\n===========================================================" << endl;
	cout << "Please input a password that is between 6-10 characters," << endl;
	cout << "has at least 2 upper case letters, and at least 2 numbers." << endl;
	cout << "===========================================================" << endl;
	cout << "Password: " ;
	cin >> password;
	cout << password[0] << endl;
	cout << password[1] << endl;
	cout << "Moving to qZero..." << endl;
	qZero(password);


//	for (int i = 0; i < password.length(); i++)
//	{
//	
//	
//
//	}
	

}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qZero(string zero)
{
	int i = 0;	
	char test = zero[i];
//	cout << "I = " << i << endl;	
	cout << "Evaluating: " << "("<< test << ")"<< endl;
	if (isupper(test))
	{
		numOfUppers++;
		length++;
	}
	else if (isdigit(test))
	{
		numOfDigits++;
		length++;
	}
	else if (isascii(test))
	{
		length++;
	}
	else if (test == '\0')
	{	
		errorState(numOfDigits, numOfUppers, length);
	}

	cout << "Moving to qOne..." << endl;
	qOne(zero, i++);

}//end qOne
//-----------------------------------------------------------------------------

int qOne(string one, int position)
{
	char test = one[position];
//	cout << "I = " << i << endl;
	cout << "Evaluating: " << test << endl;
	cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(test))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(test))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(test)) //&& (test != '\0'))
                length++;
        else if (test == '\0')
        {
                errorState(length, numOfUppers, numOfDigits);
	}

	cout << "Moving to qTwo..." <<endl;
        qTwo(one, position++);


}//end qOne
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qTwo(string two, int position)
{
	char test = two[position];
//	cout << "I = " << i << endl;
	cout << "Evaluating: " << test << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(test))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(test))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(test) && (test != '\0'))
                length++;
        else if (test == '\0')
        {
                errorState(length, numOfUppers, numOfDigits);
        }

        cout << "Moving to qThree..." <<endl;
        qThree(two, position++);


}//end qTwo
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qThree(string three, int position)
{ 
	char test = three[position];
//	cout << "I = " << i << endl;
	cout << "Evaluating: " << test << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(test))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(test))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(test) && (test != '\0'))
                length++;
        else if (test == '\0')
        {
                errorState(length, numOfUppers, numOfDigits);
        }

        cout << "Moving to qFour..." <<endl;
        qFour(three, position++);


}//end qThree
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qFour(string four, int position)
{
	char test = four[position];
//	cout << "I = " << i << endl;
	   cout << "Evaluating: " << test << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(test))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(test))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(test) && (test != '\0'))
                length++;
        else if (test == '\0')
        {
                errorState(length, numOfUppers, numOfDigits);
        }

        cout << "Moving to qFive..." <<endl;
        qFive(four, position++);


}//end qFour
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qFive(string five, int position)
{
	char test = five[position];
//	cout << "I = " << i << endl;
	int next = length;
//   cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(test))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(test))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(test) && (test != '\0'))
                length++;
        else if (test == '\0')
        {
                errorState(length, numOfUppers, numOfDigits);
        }
	if ((numOfUppers >= 2) && (numOfDigits >= 2))
        {
			cout << "\nLENGTH: " << length;
                        cout << "\nUPPERS: " << numOfUppers;
                        cout << "\nDIGITS: " << numOfDigits;
                        cout << "\nPassword is valid. Thank you!" << endl;
                        return(0);
	}
	else
        {
		cout << "Moving to qSix..." <<endl;
       // 	qSix(password);
	}
}//end qFive
//-----------------------------------------------------------------------------
/*
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qSix(char six)
{
	int next = length;
   cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(password[i]))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(password[i]))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(password[i]) && (password[i] != '\0'))
                length++;

        if ((numOfUppers >= 2) && (numOfDigits >= 2) && (length == 7) && (password[length++] == '\0'))
        {
                        cout << "UPPERS: " << numOfUppers;
                        cout << "DIGITS: " << numOfDigits;
                        cout << "Password is valid. Thank you!" << endl;
                        return(0);
        }
	else
	{
        cout << "Moving to qSeven..." <<endl;
        qSeven(password[i++]);
	}

}//end qSix
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qSeven(char seven)
{
   cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(password[i]))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(password[i]))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(password[i]) && (password[i] != '\0'))
                length++;
        if ((numOfUppers >= 2) && (numOfDigits >= 2) && (length == 8))
        {
                        cout << "UPPERS: " << numOfUppers;
                        cout << "DIGITS: " << numOfDigits;
                        cout << "Password is valid. Thank you!" << endl;
                        return(0);
        }

        cout << "Moving to qEight..." <<endl;
        qEight(password[i++]);

}//end qSeven
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qEight(char eight)
{
	cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(password[i]))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(password[i]))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(password[i]) && (password[i] != '\0'))
                length++;
	if ((numOfUppers >= 2) && (numOfDigits >= 2) && (length == 9))
        {
                        cout << "UPPERS: " << numOfUppers;
                        cout << "DIGITS: " << numOfDigits;
                        cout << "Password is valid. Thank you!" << endl;
                        return(0);
        }
	else
	{
     	  	 cout << "Moving to qNine..." <<endl;
       		 qNine(password[i++]);
	}
}//end qEight
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qNine(char nine)
{
   	cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(password[i]))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(password[i]))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(password[i]) && (password[i] != '\0'))
                length++;
        if ((numOfUppers >= 2) && (numOfDigits >= 2) && (length == 10))
        {
                        cout << "UPPERS: " << numOfUppers;
                        cout << "DIGITS: " << numOfDigits;
                        cout << "Password is valid. Thank you!" << endl;
                        return(0);
        }
	else
        cout << "Moving to qTen..." <<endl;
        qTen(password[i++]);
}//end qNine
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int qTen(char ten)
{
	   cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(password[i]))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(password[i]))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(password[i]) && (password[i] != '\0'))
                length++;
        else if (password[i] == '\0')
        {
                finalState(numOfUppers,numOfDigits, length);
        }
	cout << "Moving to qEleven..." <<endl;
	qEleven(password[i++]);

}//end qTen
//-----------------------------------------------------------------------------

int qEleven(char eleven)
{   	
	cout << "Evaluating: " << password[i] << endl;
        cout << "Length: " << length << "Digits: " << numOfDigits << "Uppers: " << numOfUppers << endl;
        if (isupper(password[i]))
        {
                numOfUppers++;
                length++;
        }
        else if (isdigit(password[i]))
        {
                numOfDigits++;
                length++;
        }
        else if (isascii(password[i]) && (password[i] != '\0'))
                length++;
        else if (password[i] == '\0')
        {
                finalState(numOfUppers,numOfDigits, length);
        }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int finalState(int numOfUppers,int numOfDigits, int length)
{
	string retry = "y";

	cout << "UPPERS: " << numOfUppers;
        cout << "   DIGITS: " << numOfDigits;
	cout << "   Length: " << length;
		if ((numOfUppers >= 2) && (numOfDigits >= 2) && ((length >= 6) || (length <= 10)))
		{
			cout << "UPPERS: " << numOfUppers;
			cout << "DIGITS: " << numOfDigits;
			cout << "Password is valid. Thank you!" << endl;
			return(0);
		//	while (retry == "y")
		//	{
		///		cout << "Would you like to try another? (y/n)" <<endl;
		//		cin >> retry;
		//		main();
		//	}	
		}
		else 
			errorState(length, numOfUppers, numOfDigits);
}//end finalState
//-----------------------------------------------------------------------------
*/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int errorState(int finalLength, int upper, int digit)
{
	cout << "\nFinal length: " <<finalLength;
	cout << "  Uppers: " << upper;
	cout << "  DIGITS: " << digit;
	if (finalLength < 6 || finalLength > 10)
	{
		cout << "Password is too short." << endl;
		cout << "Please, try again." << endl;
	}
	else if (upper < 2)
	{
		cout << "There are not enough uppercase characters." << endl;
		cout << "Please, try again." << endl;
	}
	else if (digit < 2)
	{
		cout << "There are not enough digits." << endl; 
		cout << "Please, try again." << endl;
	}

	string password = " ";
	int numOfUppers = 0;
	int numOfDigits = 0;
	int i = 0;
	int length = 0;
	bool final = false;
	main();
}
//-----------------------------------------------------------------------------

