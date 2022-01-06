/***********************************************************************************************************************
 * Student name: Meech Lamirande Kabuasa
 * Student number: 040880736
 * Version: 1.0
 * Assignment number: 3
 * Course name and number CST8233_300
 * Lab section number: 302
 * Professor’s name: Dr Hala Own
 * Due date of assignment: March 9th, 2021
 * Submission date of assignment:
 * List of source and header files in the project:
 *      ->Main.cpp
 *
 * DESCRIPTION OF THE PROBLEM:
 * ----------------------------------------------
 * the oscillation of a building is increasing exponentially.
 * the equation we're approximating is
 * D(t) = e^t cost (t)
 *
 * Algorithm:   Determine the Maclaurin Series approximation to D(t) = etcos(t)
 *              for 4 seconds
 *              so range =
 *              [ x = 0, x < 5 ]
 *
 *
 *               as a power series in t
 *               (all variables are doubles)
 *               the first 7 non-zero terms (you need 7 for the truncation error on 6 terms). Then
 *               as often as the user wishes to repeat,
 *               allow the user to choose the number of
 *               2 non-zero terms (from 1 to 6) in the series approximation
 *               what range (between 0.0 and 4.0) of values of t to evaluate
 *               in 10 equal increments.
 *
 *
 *
 *              EXTRA REQUIREMENTS:
 *
 *             For each value of t the Maclaurin series approximation is output together with
 *           the exact value from the math library. Also output the relative error in
 *                two ways:
 *               1. From comparison with the exact value calculated using the math library
 *               functions:
 *               Exact % Error = 100*(exact value – series value)/exact value
 *               2. From the first truncated term. This gives you an idea of how well the first
 *               truncated term approximates to the error.
 *               Truncation % Error = 100*(first truncated term/series value)*
 *
 *
*******************************************************************************************************************************/
//#define DEBUG
//#define TEST
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#define increment 10
#define factorial_of_2 2
#define factorial_of_4 24
#define factorial_of_6 720
using namespace std;

/*************************************************************************************************************************
 * Function Prototypes
 * Version:  1.0
 * Author: Meech Lamirande Kabuasa
 ************************************************************************************************************************/
double function_(double t);
int test(istream &cin);
double Mclaurin_Calculation(double x,int term);
int derivative(int term, double inc);


/*************************************************************************************************************************
 * Function Name: function_()
 * Purpose: this function returns the TRUE value
 * In Parameters: double t
 * Out Parameters: The true value of f(t)
 * Version:  1.0
 * Author: Meech Lamirande Kabuasa
 ************************************************************************************************************************/
double function_(double t){
    return (exp(t)*cos(t));
}

/*************************************************************************************************************************
 * Function Name: test
 * Purpose: handles the input from user to make sure it's valid input.
 * In Parameters: pointer to a cin
 * Out Parameters: a valid integer
 * Version:  1.0
 * Author: Meech Lamirande Kabuasa
 ************************************************************************************************************************/
int test(istream &cin) {
    int selec;
    while ((cin >> selec).fail() || cin.peek() != '\n' || selec < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input\n";
    }
    return selec;
}

/*************************************************************************************************************************
 * Function Name: Mclaurin_Calculation()
 * Purpose: this function returns the series calculation and is hard coded to improve accurracy and effiency.
 * In Parameters: double t
 * Out Parameters: The true value of f(t)
 * Version:  1.0
 * Author: Meech Lamirande Kabuasa
 ************************************************************************************************************************/
double Mclaurin_Calculation(double x,int term){
    switch(term){
        case 1: return 1;
        case 2: return 1+x;
        case 3: return 1 + x - (x*x*x/3);
        case 4: return 1 + x - (x*x*x/3) - (x*x*x*x/6);
        case 5: return 1 + x - (x*x*x/3) - (x*x*x*x/6) - (x*x*x*x*x/30);
        case 6: return 1 + x - (x*x*x/3) - (x*x*x*x/6) - (x*x*x*x*x/30) + (x*x*x*x*x*x*x/630);
        case 7: return 1 + x - (x*x*x/3) - (x*x*x*x/6) - (x*x*x*x*x/30) + (x*x*x*x*x*x*x/630) + (x*x*x*x*x*x*x*x/2520);
        default:return -1;
    }
   }
   //TODO: GOT TO FIX THIS HEAD TO ACCEPT THE INCREMENT RANGE

/*************************************************************************************************************************
 * Function Name: Derivative()
 * Purpose: this is the heart-beat of the program, it loops trough our 11 interval iteration and calculates the value of f(t) for what ever # of terms the user desires.
 * In Parameters: integer #of terms and the double which is is the increment.
 * Out Parameters: exit status.
 * Version:  1.0
 * Author: Meech Lamirande Kabuasa
 ************************************************************************************************************************/
int derivative(int term, double inc){
    int i;
    double x,
    sum=0,
    true_value=0,
    truncation_error,
    Absolute_error,sum_plus;
    inc/=(double)increment;
    cout<<"t\t\t\tD(t)Series\t\tD(t)Exact\t\t%RExactE\t\t%RSerE"<<endl;
    for(i = 0; i < increment+1; i++){
        x = i * inc;
        true_value = function_(x);
        sum = Mclaurin_Calculation(x,term);
        sum_plus = Mclaurin_Calculation(x,term+1);
        if(sum == -1 || sum_plus == -1){
            //error checking.
            return -1;
        }
        Absolute_error = 100*abs(true_value -sum)/true_value;
        truncation_error = 100*( abs(sum-(sum_plus))/sum);
        cout << setprecision(6)<< scientific << x << "\t\t" << sum << "\t\t"<<true_value <<"\t\t" << Absolute_error <<"\t\t"<< truncation_error<<endl;
    }
    return 0;
}

/*************************************************************************************************************************
 * Function Name: Main()
 * Purpose: main program handles menu and main functions.
 * Out Parameters: exit status.
 * Version:  1.0
 * Author: Meech Lamirande Kabuasa
 ************************************************************************************************************************/
int main() {
    cout << "Evaluate the Maclaurin Series approximation to D(t)= exp(t) * cos(t)"<< endl;
    int selection,term_series,range;
#ifndef TEST
    while(1){
        cout<< "1: Evaluate the series\n"
               "2: quit" <<endl;
        selection = test(cin);
        if(selection==1){
            cout<<"Please enter the number of (non-zero) terms in the series (1, 2, 3, 4, 5 or 6):"<<endl;
            term_series = test(cin);
            cout<<"Please enter the range of t to evaluate in 10 increments (0.0 < t < +4.0): 4"<<endl;
            range = test(cin);
            cout<<"*****************************************************************************************"<<endl;
            cout << "t\t" << "D(t)series\t" << "D(t)Exact\t" << "%RExactE\t" << "%RExactE\t" << endl;
#endif
#ifdef DEBUG
    term_series = 6;
    range = 4;
#endif
    //TODO t            D(t)series         D(t)Exact            %RExactE        %RSerE
    if(derivative(term_series, range)==-1){
        cout<<"error"<<endl;
    }else{
        cout<<"*****************************************************************************************"<<endl;
        cout<<"\n\n";
    }
#ifndef TEST
    }else if(selection ==2){
        break;
    }else{
        cout<<"invalid input."<<endl;
    }

    }
#endif
    return 0;
}

