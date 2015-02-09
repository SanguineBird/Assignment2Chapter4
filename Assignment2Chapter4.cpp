/*
Meghan Moore
February 7, 2015
CIT 245 - Data Structures and Programming C++
Assignment 2 - Chapter 4
Purpose: Write a program that reduces a fraction to lowest terms.
*/

#include <iostream> //cin, cout, cerr
using namespace std;

void reduce(int num, int den);
int gcd(int num, int den);
bool repeatPrompt();

//------------------------------
int main(){
  int num, den;
  bool tryAgain;
  
  cout << "This program takes the numerator and denominator of a fraction \nand reduces the fraction to its lowest terms.\n\n";
  
  do{
    cout << "Enter the numerator:\n";
    cin >> num;
    cout << "\nEnter the denominator:\n";
    cin >> den;
    cout << endl << endl;
    
    reduce(num, den);
    tryAgain = repeatPrompt();
  }while (tryAgain = true);
} //end main function

//------------------------------
/*Precondition: The funciton is called with two arguments:
an integer representing the numerator of a fraction,
and another integer representing the denomenator of the same fraction.
Postcondition: The function prints the greatest common denominator of the
two integers, and the lowest terms of their fraction to the screen.*/
void reduce(int num, int den){
  int rNum, rDen; //lowest terms
  int g = gcd(num, den); //calls function for greatest common denominator
  
  rNum = num / g;
  rDen = den / g;
  
  cout << "The greatest common denominator is " << g << endl;
  cout << "The reduced fraction is " << rNum << "/" << rDen << endl << endl;
} //end reduce function

//------------------------------
/*Precondition: The funciton is called with two arguments:
an integer representing the numerator of a fraction,
and another integer representing the denomenator of the same fraction.
Postcondition: The function returns the greatest common denominator of the two integer arguments.*/
int gcd(int a, int b){
  //uses Euclid's algorithm
  int t = b - a;
  
  while(t != 0){
    b = a;
    a = t;
    t = b - a;
  } //end while
  
  return a;
} //end gcd function

//------------------------------
/*This function asks the user if they wish to repeat the calling function.
Precondition: function is called into a loop dependent on a boolean value
where a return value of 'false' will end the loop.
Postcondition: If the user selects 1 for 'yes', the function will return
true. If the user selects 0 for 'exit', the function will return 'false'.
If any other input is given, the prompt will repeat.*/
bool repeatPrompt(){
  
  bool validInput, repeat;
  int input;

  do{
    cout << "Try Again? (1 = yes, 0 = exit)\n";
    cin >> input;
    cout << endl << endl;
  
    switch (input){
      case 0:
        validInput = true;
        repeat = false;
        break;
      case 1:
        validInput = true;
        repeat = true;
        break;
      default:
        validInput = false;
    } //end switch
  } while(validInput == false);
  
  return repeat;
} //end repeatPrompt
