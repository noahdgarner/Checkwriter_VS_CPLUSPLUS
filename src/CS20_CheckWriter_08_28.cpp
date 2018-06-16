//============================================================================
// Name        : CS20_CheckWriter_08_28.cpp
// Author      : Noah Garner
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define _tWinMain wWinMain;
#include <tchar.h>
using namespace std;

string makeString(unsigned long int num);		//prototypes
void checkWriter(void);

int main() {
	cout << "Enter some integer values. Enter zero to stop.\n";
	checkWriter();
	cout << "Program ending, have a nice day!";
	return 0;
}

string makeString(unsigned long int num){
	string onesArray[] = {"","one","two","three","four","five","six","seven",		//array for numbers 1-19, when zero passes, empty string saved at[0]
					 "eight","nine","ten","eleven","twelve","thirteen","fourteen",
					 "fifteen","sixteen","seventeen","eighteen","nineteen",};

	string tensArray[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety",};	//array for 20-90 in increments of 10
	string hund = "hundred", thous = "thousand", mill = "million", bill = "billion";

	if (num >= 1000000000){
		int newNum = (num/1000000000);
		return makeString(newNum) + " " + bill + " " + makeString(num - newNum*1000000000);
	}
	else if (num >= 1000000){
        int newNum = (num/1000000);
        return makeString(newNum) + " " + mill + " " + makeString(num - newNum*1000000);
    }
    else if (num >= 1000){			//if num >= 1000, divides num by 1000 and returns num/1000 value through recursion of makeString to find hundreds, tens, ones
        int newNum = (num/1000);	//and returns thous string + (num - newNum*1000) (i.e. 324,105 => 324,105-324*1000 = 105) through recursion of makeString to find hundreds, tens, ones.
        return makeString(newNum) + " " + thous + " " + makeString(num - newNum*1000);
    }
    else if (num >= 100){			//if num >= 100, divides num by 100 and returns string at num/100 value in onesArray
        int newNum = (num/100);		//and returns hund string + (num - newNum*100) (i.e. 324 => 324-3*100 = 24) through recursion of makeString.
        return onesArray[newNum] + " " + hund + " " + makeString(num - newNum*100);
    }
    else if (num >= 20){			//if num >= 20, divides num by 10, subtracts 2 from that and returns string at tensNum-2 value in tensArray
        int tensNum = (num/10);		//and uses modulus 10 to grab the digit in the ones place, and returns the string at the onesNum value in onesArray
        int onesNum = (num%10);

        if (num%10 != 0)
        	return tensArray[tensNum - 2] + "-" + onesArray[onesNum];
        else
            return tensArray[tensNum - 2] + " " + onesArray[onesNum];
    }
    else							//if num is 1-9, function returns a string at num value in onesArray
        return onesArray[num];
}

void checkWriter(void){				//user input validation
	unsigned long int num = 0;

	do {
		cout << "Number: ";
		cin >> num;

		if (num > 3999999999)		//if num is neg or greater than 3999999999, re-prompts user
			cout << "That number is invalid. Enter an integer 'between' 1 and 3,999,999,999 or zero to stop.\n";
		else if (num == 0)			//if num is 0, the program will exit the do-while and terminate
			break;
		else
			cout << makeString(num) << "\n";
	} while (num != 0);
}
