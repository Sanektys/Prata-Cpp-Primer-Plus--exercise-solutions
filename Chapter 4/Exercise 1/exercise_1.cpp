#include <iostream>


int main() {
	  std::cout << "What is your first name? ";
  	char firstName[40] = {};
  	std::cin.getline(firstName, 39);
	  std::cout << "What is your last name? ";
  	char lastName[40]{};
  	std::cin.getline(lastName, 39);
  	std::cout << "What letter grade do you deserve? ";
  	char grade = '\0';
  	std::cin >> grade;
  	std::cout << "What is your age? ";
	  short age(0);
  	std::cin >> age;

  	grade = grade + 1;
	  std::cout << "Name: " << lastName << ", " << firstName << std::endl
		          << "Grade: " << grade << "\nAge: " << age << std::endl;


  	return 0;
}
