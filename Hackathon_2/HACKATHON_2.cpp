/*
*This program has been developed to compute and suggest the best three options of device
available or at least one device based on the input file 
*Developers: Yeo Ying Sheng, Edu Sinusi, Challven Japirin
*Contact: yeousm@student.usm.my, sinusiedu@student.usm.my, challven001@student.usm.my
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	//Declaration of variables
	char feature, inputAgain;
	int speed, processor, make, budget, rom, ram, mainCam, frontCam, battery, //Different specifications of device
		cnt = 1, //Acts as a counter
		makePrior = 0,
		proPrior = 0,
		speedPrior = 0,
		romPrior = 0,
		ramPrior = 0,
		mainCamPrior = 0,
		frontCamPrior = 0,
		batPrior = 0;
		
	fstream inputFile; 
	inputFile.open("input 2.txt", ios::in); //Open a file to read information from the file
	
	//Menu for Device Purchasing System
	cout << "Recommendation System for Device Purchasing" << endl;
	cout << "---------------------------" << endl;
	cout << "List of Features Available" << endl;
	cout << "---------------------------" << endl;
	cout << "a. Model\t" << "e. Processor speed\t" << "i. Front camera" << endl;
	cout << "b. Make\t\t" << "f. ROM size\t\t" << "j. Battery capacity" << endl;
	cout << "c. Price\t" << "g. RAM size\t" << endl;
	cout << "d. Processor\t" << "h. Main camera\t" << endl;
	cout << "---------------------------" << endl;	
	cout << '\n';
	
	cout << "Please enter your budget (RM): "; //Obtain the budget or ceiling value of a user to spend
	cin >> budget;
	
	//A while loop that loops as long as inputAgain is not equal to the character n
	while(inputAgain != 'n')
	{
		cout << "Please pick a feature according to the importance of the feature (b - j), (c) option is not available: "; //Obtain the preference of a user according to priority
		cin >> feature;
		cout << "---------------------------------------------------------------------------" << endl;
		if(feature == 'b') 
		{
			cout << "Make Available" << endl; //Display the makes available to be chosen from based on the file
			cout << "---------------" << endl;
			cout << "1. Samsung\n2. Vivo\n3. Apple\n4. Sony" << endl;
			cout << "---------------" << endl;
			cout << "Please make a choice (1 - 4), or 5 if make is not in the list: ";
			cin >> make; //Get the preferred make from the user
			cin.ignore(); 
			makePrior = cnt;			
		}
		else if(feature == 'd')
		{
			cout << "Processor Available" << endl; //Display the processors available to be chosen from based on the file
			cout << "---------------" << endl;
			cout << "1. Octa-core\n2. Hexa-core" << endl;
			cout << "---------------" << endl;
			cout << "Please make a choice (1 - 2): ";
			cin >> processor; //Get the preferred processor from the user
			cin.ignore();
			proPrior = cnt;
		}
		else if(feature == 'e')
		{
			cout << "Processor Speed Available" << endl; //Display the processor speed available to be chosen from based on the file
			cout << "---------------" << endl;
			cout << "1. 2.84 Kyro\n2. 2.95 Kyro\n3. 2.73 Mongoose M5\n4. 2.9 Cortex-X1\n5. 2.2 Cortex-A76\n6. 2.4 Cortex-A78\n7. 3.22 Avalanche" << endl;
			cout << "---------------" << endl;
			cout << "Please make a choice (1 - 7): ";
			cin >> speed; //Get the preferred processor speed from the user
			cin.ignore();
			speedPrior = cnt;
		}
		else if(feature == 'f')
		{
			cout << "Please enter your preferred ROM size (GB): "; 
			cin >> rom; //Get the preferred ROM size from the user
			cin.ignore();
			romPrior = cnt;
		}
		else if(feature == 'g')
		{
			cout << "Please enter your preferred RAM size (GB): "; 
			cin >> ram; //Get the preferred RAM size from the user
			cin.ignore();
			ramPrior = cnt;
		}
		else if(feature == 'h')
		{
			cout << "Please enter your preferred main camera (Megapixel): ";
			cin >> mainCam; //Get the preferred main camera specification from the user
			cin.ignore();
			mainCamPrior = cnt;
		}
		else if(feature == 'i')
		{
			cout << "Please enter your preferred front camera (Megapixel): ";
			cin >> frontCam; //Get the preferred front camera specification from the user
			cin.ignore();
			frontCamPrior = cnt;
		}
		else if(feature == 'j')
		{
			cout << "Please enter your preferred battery capacity (mAh): ";
			cin >> battery; //Get the preferred front camera specification from the user
			cin.ignore();
			batPrior = cnt;
		}
		cout << "Do you have another preference? (y/n): "; //y represents yes, n represents no
		cin >> inputAgain; //Get the input whether the user wants to input another preference or not
		cnt++; //cnt will increment by one on each iteration of the loop
	}
	
	cnt--;
	
	string model, data, recModel_1, recModel_2, recModel_3;
	int numData, priceData, recModelPrice_1, recModelPrice_2, recModelPrice_3, counter;
	
	while(true)
	{
		inputFile.seekg(0, ios::beg); //Seek an arbitrary position of 0 in the file
		counter = 1; //A counter to store integer literals
		bool budgetEnough = false; 
		int minPrice = 100000; 
		string phoneMinPrice;
		
		while(!inputFile.eof()) //A while loop that loops as long as the end of file is not reached
		{
			getline(inputFile, model, '\t'); //Read information from the file
			getline(inputFile, data, '\t');
			
			if(!(((data == "Samsung") && (make == 1)) || ((data == "Vivo") && (make == 2)) || ((data == "Apple") && (make == 3)) || ((data == "Sony") && (make == 4))) && (makePrior != 0))
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			inputFile >> priceData; //Read the price of a device from the file
			
			if(priceData < minPrice) //Runs the if statement if the price of device is lower than minPrice
			{
				minPrice = priceData;
				phoneMinPrice = model;
			}
			
			if(budget < priceData) 
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			
			if(!budgetEnough)
			{
				budgetEnough = true;
			}
			
			inputFile >> data;
			
			if(!(((data == "Octa-core") && (processor == 1)) || ((data == "Hexa-core") && (processor == 2))) && (proPrior != 0))
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			
			getline(inputFile, data, '\t');
			getline(inputFile, data, '\t');
			
			if(!(((data == "2.84 Kyro") && (speed == 1)) || ((data == "2.95 Kyro") && (speed == 2)) || ((data == "2.73 Mongoose M5") && (speed == 3)) || ((data == "2.9 Cortex-X1") && (speed == 4)) || ((data == "2.2 Cortex-A76") && (speed == 5)) || ((data == "2.4 Cortex-A78") && (speed == 6)) || ((data == "3.22 Avalanche") && (speed == 7))) && (speedPrior != 0))                                                                         
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			inputFile >> numData;
			
			if((numData < rom) && (romPrior != 0))
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			inputFile >> numData;
			
			if((numData < ram) && (ramPrior != 0))
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			inputFile >> numData;
			
			if((numData < mainCam) && (mainCamPrior != 0))
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			inputFile >> numData;
			
			if((numData < frontCam) && (frontCamPrior != 0))
			{
				getline(inputFile, data, '\n');
				data = "";
				continue;
			}
			inputFile >> numData;
			
			if((numData < battery) && (batPrior != 0))
			{
				continue;
			}
			
			
			if(counter == 1)
			{
				recModel_1 = model;
				recModelPrice_1 = priceData;
				counter++;
			}
			else if(counter == 2)
			{
				recModel_2 = model;
				recModelPrice_2 = priceData;
				counter++;
			}
			else if(counter == 3)
			{
				recModel_3 = model;
				recModelPrice_3 = priceData;
				counter++;
				break;
			}
			if(!inputFile.eof())
			{
				getline(inputFile, data, '\n');
			}
		}
		
		if(counter == 4 || (counter > 1 && counter < 4 && cnt == 1)) //Run this statement if 3 device are suggested, or 1 or 2 device are suggested with only one preference left
		{
			break;
		}
		else if((counter > 1 && counter < 4 && cnt > 1) || ((counter == 1) && (cnt > 0))) //Run this statement if 1 or 2 device are suggested with more than one preference left or 0 device is suggested with more than 0 preference left
		{
			if(makePrior == cnt)
			{
				makePrior = 0;
				cnt--;
			}

			else if(proPrior == cnt)
			{
				proPrior = 0;
				cnt--;
			}
			else if(speedPrior == cnt)
			{
				speedPrior = 0;
				cnt--;
			}
			else if(romPrior == cnt)
			{
				romPrior = 0;
				cnt--;
			}
			else if(ramPrior == cnt)
			{
				ramPrior = 0;
				cnt--;
			}
			else if(mainCamPrior == cnt)
			{
				mainCamPrior = 0;
				cnt--;
			}
			else if(frontCamPrior == cnt)
			{
				frontCamPrior = 0;
				cnt--;
			}
			else if(batPrior == cnt)
			{
				batPrior = 0;
				cnt--;
			}	
		}
		else if((counter == 1) && (cnt == 0) && !budgetEnough) //Run this statement if 0 device is suggested with 0 preference left and the user does not have enough budget to purchase the device
		{
			cout << "---------------------------------------------------------------" << endl;		
			cout << "Your budget is lower than the minimum requirement." << endl;
			cout << "Phone with the lowest price: " << phoneMinPrice << endl;
			cout << "Price: RM" << minPrice << endl;
			cout << "You do not have sufficient budget to purchase the accessories." << endl;
			cout << "---------------------------------------------------------------" << endl;	
			return 0;
		}
	}

	int selDev, selDevPrice;
	string selDevModel; 	
	
	cout << "List of Suggested Devices" << endl;
	cout << "--------------------------" << endl;
	if(counter == 4) //Display the models of device suggested
	{
		cout << "1. " << recModel_1 << endl;
		cout << "2. " << recModel_2 << endl;
		cout << "3. " << recModel_3 << endl;
	}
	else if(counter == 3)
	{
		cout << "1. " << recModel_1 << endl;
		cout << "2. " << recModel_2 << endl;
	}
	else if(counter == 2)
	{
		cout << "1. " << recModel_1 << endl;
	}
	
	cout << "--------------------------" << endl;
	cout << "Please select your preferred device: "; //Allow user to input device preferred
	cin >> selDev;
	if(selDev == 1)
	{
		selDevPrice = recModelPrice_1;
		selDevModel = recModel_1;
	}
	else if(selDev == 2)
	{
		selDevPrice = recModelPrice_2;
		selDevModel = recModel_2;
	}
	else if(selDev == 3)
	{
		selDevPrice = recModelPrice_3;
		selDevModel = recModel_3;
	}
	
	int acc, accPrice, tempBudget;
	string accName;
	bool enoughMoney = true;
	
	cout << "--------------------------" << endl;
	cout << "List of Accessories" << endl;
	cout << "--------------------------" << endl;
	cout << "1. Screen Protector - RM 20" << endl;
	cout << "2. Phone Case - RM 30" << endl;
	cout << "3. Earphone - RM 100" << endl;
	cout << "--------------------------" << endl;
	
	budget -= selDevPrice;
	
	if(budget < 20) //Determine whether the user has enough budget to buy accessories or not
	{
		cout << "Sorry, you don't have sufficient budget to purchase the accessories." << endl;
		enoughMoney = false;
	}
	
	
	while(enoughMoney == true) 
	{
		tempBudget = budget; 
		cout << "Please select only ONE of these accessories (1 - 3): ";
		cin >> acc;
		if (acc == 1)
		{
			accPrice = 20;
			accName = "Screen Protector";
		}
		else if(acc == 2)
		{
			accPrice = 30;
			accName = "Phone Case";
		}
		else if(acc == 3)
		{
			accPrice = 100;
			accName = "Earphone";
		}
	
		tempBudget -= accPrice;
		if(tempBudget < 0)
		{
			cout << "You don't have sufficient budget to purchase this accessory." << endl;
		}
		else if(tempBudget >= 0)
		{
			cout << "Selection Successful" << endl;
			enoughMoney = false; //To end the while loop
		}
	}
	
	//Display the summary of selected devices of the user
	cout << "---------------------------------------------" << endl;
	cout << "Summary" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Selected Device: " << selDevModel << endl;
	cout << "Selected accessory: " << accName << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Thank you for using our service!" << endl;
	cout << "---------------------------------------------" << endl;
	
	inputFile.close();

	return 0;
}
