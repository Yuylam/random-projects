// Palindromes
#include <iostream>
#include <vector>
using namespace std;

int main(){
	char x[50];
	char cont2;
	int i;
	bool cont = true;
	
	do{
		bool p = true;
		// Get palindrome
		cout << "***** Palindrome Detector *****\n";
		cout << "Enter a palindrome: ";
		cin >> x;
		
		// Get the location of the last character
		for (i = 0; i < 50; i ++){
			if (x[i] == '\0'){
				i--;
				break;
			}
		}
		
		// Determine if it is palindrome
		for (int index = 0; index <= i / 2; index ++){
			if (x[index] != x[i - index]){
				p = false;
				break;
			}
		}
		
		// Display result
		if (p)
			cout << "It is a palindrome\n\n";
		else
			cout << "It is not a palindrome\n\n";
		
		// Repeat or not
		cout << "Do you want to repeat (Y/N): ";
		cin >> cont2;
		while (cont2 != 'Y' && cont2 != 'y' && cont2 != 'N' && cont2 != 'n'){
			cout << "That is an invalid value, please re-enter\n";
			cout << "Do you want to repeat (Y/N): ";
			cin >> cont2;
		}
		if (cont2 == 'n' || cont2 == 'N')
			cont = false;
		
		cout << endl;
	}
	while (cont);
	
	return 0;
}
