#include <bits/stdc++.h>
using namespace std; 

void printZuko() {
	cout << right << setw(35) << "/\\_/\\\n";
	cout << right << setw(36) << "( o.o )\n";
	cout << right << setw(36) << "> - <\n\n";
}

void printLine() {
	for (int i = 0; i < 63; i++){
			cout << "-";
	}
}

string toLower(string feature) {
	string newFeature = "";
	char featureArr[feature.length() + 1];
	for (int i = 0; i < feature.length(); i++) {
		featureArr[i] = tolower(feature.at(i));
		newFeature = newFeature + featureArr[i];
	}
	return newFeature; 
}

int gcd(long long int num1, long long int num2) {
	if (num1 == 0)
		return num2;
	else if (num2 == 0)
		return num1;
	else if (num1 == num2)
		return num1;
	else if (num1 > num2)
		return gcd(num1 - num2, num2);
	else 
		return gcd(num1, num2 - num1);
}

void lcm() {

}

void option2() {
	string feature;
	printLine();
	cout << endl << endl;
	cout << "Please select a feature: ";
	getline (cin, feature);
	feature = toLower(feature);
	if (feature == "gcd" || feature == "a") {
		long long int num1, num2; 
		cout << "\nGCD Calculator\n\n"; 
		cout << "Number 1: ";
		cin >> num1; 
		cout << "Number 2: ";
		cin >> num2; 
		cout << "\nGCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << endl << endl;
	}
	else if (feature == "lcm" || feature == "b")
		lcm();
}

void option1() {
	string availableFeatures;
	ifstream features;
	features.open("features.txt");
	printLine();
	cout << endl << endl;
	while (!features.eof()) {
		getline (features, availableFeatures);
		cout << availableFeatures << endl;
	}
	cout << endl;
	option2(); 
}

void option3() {
	string aboutZukomath;
	ifstream about;
	about.open("about.txt");
	printLine();
	cout << endl << endl;
	while (!about.eof()) {
		getline (about, aboutZukomath);
		cout << aboutZukomath << endl;
	}
	cout << endl;
}

int option4() {
	printLine();
	cout << endl << endl;
	printZuko();
	cout << "        Thank you for using ZukoMath, see you next time!\n\n";
	printLine();
	return 0;
}

string getOption(string option) {
	string newOption;
	printLine();
	if (option == "1" || option == "2" || option == "3") {
		cout << "\n\nPlease select another option: ";
	}
	else {
		cout << "\n\nPlease select a valid option: ";
	}
	getline (cin, newOption);
	cout << endl;
	return newOption;
}

int main() {
	printLine();
	string option;
	int cont = 1;
	cout << endl << endl; 
	printZuko();
  cout << "Welcome to Zukomath, my name is Zuko! How may I help you today?\n\n";
	cout << "1) Available Features\n";
	cout << "2) Enter a Feature\n";
	cout << "3) About Zukomath\n";
	cout << "4) Exit\n\n";
	printLine();
	cout << "\n\nPlease select an option: ";
	getline (cin, option);
	cout << endl;
	while (cont == 1) {
		if (option == "1") {
			option1();
			option = getOption(option);
		}
		else if (option == "2") {
			option2();
			option = 1;
		}
		else if (option == "3") {
			option3();
			option = getOption(option);
		}
		else if (option == "4") {
			cont = option4();
		}
		else {
			option = getOption(option);
		}
	}
} 