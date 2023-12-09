// Experiment 14 Killer Sudoku Calculator
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "***** Killer Sudoku Calculator *****\n";
	
	int n, box;
	bool repeat = true;
	
	do{
		cout << "Sum of value: ";
		cin >> n;
		while (n < 3 || n > 45){
			cout << "That is an invalid value, please re-enter\n";
			cout << "Sum of value: ";
			cin >> n;
		}
		
		cout << "Number of cages: ";
		cin >> box;
		while (box < 2 || box > 9){
			cout << "That is an invalid value, please re-enter\n";
			cout << "Number of cages: ";
			cin >> box;
		}
		/*
		int exclude[9] = {0,0,0,0,0,0,0,0,0}, include[9] = {0,0,0,0,0,0,0,0,0};
		cout << "Other Requirements...\n"
		<< "Put 0 for no requirements\n";
		
		for (int count = 0; count < 9; count ++){
			cout << "Exclude: ";
			cin >> exclude[count];
			while (exclude[count] < 0 || exclude[count] > 9){
				cout << "That is an invalid value, please re-enter\n";
				cout << "Exclude: ";
				cin >> exclude[count];
			}
			if (exclude[count] == 0)
				break;
		}
		
		for (int count = 0; count < 9; count ++){
			cout << "Include: ";
			cin >> include[count];
			
			while (include[count] < 0 || include[count] > 9 ){
				cout << "That is an invalid value, please re-enter\n";
				cout << "Include: ";
				cin >> include[count];
			}
			if (include[count] == 0)
				break;
		}
		
		// Check repetition
		bool rep;
		for (int count = 0; count < 9; count ++){
			for (int count2 = 0; count2 < 9; count2 ++){
				if(include[count] == exclude[count2] && include[count] != 0){
					cout << "There is a repetition in the values.\n"
					<< "Number " << include[count] << " is repeated.\n"
					<< "Do you want to include (1) or exclude (0)? ";
					cin >> rep;
					
					if (rep)
						exclude[count2] = 0;
					else 
						include[count] = 0;
				}
			}
		}
		*/
		
		int value [100][box];
		for (int set = 0; set <= 100; set++){
			for (int index = 0; index <= box; index ++){
				value [set][index] = 0;
			}
		}
		int count = -1;
		
		// Box 1 
		for (int index1 = 1; index1 <= 9; index1++){
		// Box 2
			for (int index2 = index1 + 1; index2 <= 9; index2++){
				if (box == 2 && index1 + index2 == n) {
					count ++;
					value [count][0] = index1;
					value [count][1] = index2;	
				}
				
				if (box >= 3){
					for (int index3 = index2 + 1; index3 <= 9; index3++){
						if (box == 3 && index1 + index2 + index3 == n) {
							count ++;
							value [count][0] = index1;
							value [count][1] = index2;
							value [count][2] = index3;
						}
						
						if (box >= 4){
							for (int index4 = index3 + 1; index4 <= 9; index4++){
								if (box == 4 && index1 + index2 + index3 + index4 == n){
									count ++;
									value [count][0] = index1;
									value [count][1] = index2;
									value [count][2] = index3;
									value [count][3] = index4;
								}
								
								if (box >= 5){
									for (int index5 = index4 + 1; index5 <= 9; index5++){
										if (box == 5 && index1 + index2 + index3 + index4 + index5 == n){
											count ++;
											value [count][0] = index1;
											value [count][1] = index2;
											value [count][2] = index3;
											value [count][3] = index4;
											value [count][4] = index5;
										}
										
										if (box >= 6){
											for (int index6 = index5 + 1; index6 <= 9; index6++){
												if (box == 6 && index1 + index2 + index3 + index4 + index5 + index6 == n){
													count ++;
													value [count][0] = index1;
													value [count][1] = index2;
													value [count][2] = index3;
													value [count][3] = index4;
													value [count][4] = index5;
													value [count][5] = index6;											
												}
												
												if (box >= 7){
													for (int index7 = index6 + 1; index7 <= 9; index7++){
														if (box == 7 && index1 + index2 + index3 + index4 + index5 + index6 + index7 == n){
															count ++;
															value [count][0] = index1;
															value [count][1] = index2;
															value [count][2] = index3;
															value [count][3] = index4;
															value [count][4] = index5;
															value [count][5] = index6;
															value [count][6] = index7;
														}
													
														if (box >= 8){
															for (int index8 = index7 + 1; index8 <= 9; index8++){
																if (box == 8 && index1 + index2 + index3 + index4 + index5 + index6 + index7 + index8 == n){
																	count ++;
																	value [count][0] = index1;
																	value [count][1] = index2;
																	value [count][2] = index3;
																	value [count][3] = index4;
																	value [count][4] = index5;
																	value [count][5] = index6;
																	value [count][6] = index7;
																	value [count][7] = index8;
																}
																
																if (box == 9){
																	int index9 = 9;
																	if (index1 + index2 + index3 + index4 + index5 + index6 + index7 + index8 + index9== n){
																		count ++;
																		value [count][0] = index1;
																		value [count][1] = index2;
																		value [count][2] = index3;
																		value [count][3] = index4;
																		value [count][4] = index5;
																		value [count][5] = index6;
																		value [count][6] = index7;
																		value [count][7] = index8;
																		value [count][8] = index9;
																	}
																}
															}		
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}	
			}
		}
		
		
		if (value [0][1] == 0)
			cout << "There is no valid combinations.\n";
		else{
			for (int set = 0; set <= count; set++){
				for (int index = 0; index < box; index ++)
					cout << value [set][index] << " ";
				cout << endl;
			}
		}
		cout << "\nDo you want to do it again? (0-No)(1-Yes): ";
		cin >> repeat;
	}
	while (repeat);
}

// Get number
// Get number of cages
// Calculate the value
// Display value

