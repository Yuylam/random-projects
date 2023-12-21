// Base Converter
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int iniBase, finBase;
	float iniNum;
	long int finNum = 0;
	char finFra[7];
	int tempInt, tempFra;
	float num10 = 0;
	
	char iniNumx[20];
	char finNumx[20], finFrax[10];
	char tempIntx[20], tempFrax[20];
	
	cout << "***** Base Converter *****\n";
	
	cout << "Initial Base: ";
	cin >> iniBase;
	while (iniBase < 2 || iniBase > 16){
		cout << "That is an invalid value, please re-enter\n";
		cout << "Initial Base: ";
		cin >> iniBase;
	}
	
	// Get initial Number
	if (iniBase <= 10){
		bool valid = true;
		// If the number is less than base 10 - no alphabets in the value
		cout << "Initial Number: ";
		cin >> iniNum;	
		do{					
			// Separate initial number to whole and fractional part
			tempInt = iniNum / 1;
			tempFra = iniNum * 1000000 - tempInt * 1000000;
			
			// Validation
			int temp;
			temp = tempInt;
			while(temp){
				if (temp % 10 > iniBase){
					valid = false;
					break;
				}
				temp = temp / 10;
				valid = true;
			}
			if (valid){
				temp = tempFra;
				while(temp){
					if (temp % 10 > iniBase){
						valid = false;
						break;
					}
					temp = temp / 10;
					valid = true;
				}
			}
			if (!valid){
				cout << "That is an invalid value, please re-enter\n";
				cout << "Initial Number: ";
				cin >> iniNum;
			}	
		}while (!valid);
	}
	else{
		cout << "Initial Number: ";
		cin >> iniNumx;
		
		bool valid = true;
		do {
			for (int i = 0; i < strlen(iniNumx); i++){
				if (iniNumx[i] == '.')
					valid = true;
				else if (iniNumx[i] >= 48 && iniNumx[i] <= 57)
					valid = true;
				else if (iniNumx[i] >= 65 && iniNumx[i] <= 54 + iniBase)
					valid = true;
				else{
					valid = false;
					break;
				}			
			}
			if (!valid){
				cout << "That is an invalid value, please re-enter\n";
				cout << "Initial Number: ";
				cin >> iniNumx;
			}
		}
		while(!valid);
		
		// Separate initial number to whole and fractional part
		bool decimal = false;
		int index = 0;
		for (int i = 0; i < strlen(iniNumx); i++){
			if (iniNumx[i] == '.'){
				decimal = true;
				tempIntx[i] = '\0';
				continue;
			}
	
			if (!decimal){
				tempIntx[i] = iniNumx[i];
			}
			else{
				tempFrax[index] = iniNumx[i];
				index ++;
			}
			tempFrax[index] = '\0';
		}		
	}	
	
	cout << "Final Base: ";
	cin >> finBase;
	while (finBase == iniBase || iniBase < 2 || iniBase > 16){
		cout << "That is an invalid value, please re-enter\n";
		cout << "Final Base: ";
		cin >> finBase;
	}
	
	// Convert initial number to base 10
	if (iniBase < 10){
		// Convert integer part
		for (int i = 0; tempInt; i++){
			num10 += tempInt % 10 * pow(iniBase, i);
			tempInt = tempInt / 10;
		}	
		// Convert fractional part
		for (int i = -6; i <= -1; i++){
			num10 += tempFra % 10 * pow(iniBase, i);
			tempFra = tempFra / 10;
		}	
		cout << "Decimal: " << num10 << endl;
	}
	else if (iniBase == 10)
		num10 = iniNum;
	else if (iniBase > 10){
		// Convert integer part
		int power = 0;
		for (int i = strlen(tempIntx) - 1; i >= 0; i--){
			switch(tempIntx[i]){
				case 'A': case 'a': tempInt = 10; break;
				case 'B': case 'b': tempInt = 11; break;
				case 'C': case 'c': tempInt = 12; break;
				case 'D': case 'd': tempInt = 13; break;
				case 'E': case 'e': tempInt = 14; break;
				case 'F': case 'f': tempInt = 15; break;
				default : 			tempInt = tempIntx[i] - 48; break;
			}
			num10 += tempInt * pow(iniBase, power);
			power++;
		}	
		// Convert fractional part
		power = -1;
		for (int i = 0; i < strlen(tempFrax); i++){
			switch(tempFrax[i]){
				case 'A': tempFra = 10; break;
				case 'B': tempFra = 11; break;
				case 'C': tempFra = 12; break;
				case 'D': tempFra = 13; break;
				case 'E': tempFra = 14; break;
				case 'F': tempFra = 15; break;
				default : tempFra = tempFrax[i] - 48; break;
			}
			num10 += tempFra * pow(iniBase, power);
			power--;
		}	
		cout << "Decimal: " << num10 << endl;
	}
		
	// Separate decimal number to whole and fractional part
	tempInt = num10 / 1;
	tempFra = num10 * 1000000 - tempInt * 1000000;	
	
	// Convert decimal to respective base
	if (finBase < 10){
		// Convert integer part
		for (int i = 0; tempInt; i ++){
			finNum += tempInt % finBase * pow(10, i);
			tempInt = tempInt / finBase; 					// Need check if add floor correct or not
		}
		
		// Convert fractional part
		for (int i = 0; i < 6; i++){
			finFra[i] = tempFra * finBase / 1000000 + 48;
			tempFra =  tempFra * finBase % 1000000;
		}
		finFra[6] = '\0';
		cout << "Base " << finBase << ": " << finNum << "." << finFra << endl;
	}
	else if (finBase > 10){
		char tempNumx[20];
		// Convert integer part
		int i;
		for (i = 0; tempInt; i++){
			if (tempInt % finBase < 10)
				tempNumx[i] = tempInt % finBase + 48;
			else 
				tempNumx[i] = tempInt % finBase + 55;
			tempInt = tempInt / finBase;
		}
		tempNumx[i] = '\0';
		
		for (int i = 0; i <= strlen(tempNumx); i++){
			finNumx[strlen(tempNumx) - i - 1] = tempNumx[i];
		}
		finNumx[strlen(tempNumx)] = '\0';
		
		// Convert fractional Part
		for (i = 0; i < 6; i++){
			if ((tempFra * finBase / 1000000) < 10)
				finFrax[i] = floor(tempFra * finBase / 1000000) + 48;
			else
				finFrax[i] = floor(tempFra * finBase / 1000000) + 55;
			tempFra = tempFra * finBase % 1000000;
		}
		
		cout << "Base " << finBase << ": " << finNumx << "." << finFrax << endl;
	}
	
	return 0;
}
