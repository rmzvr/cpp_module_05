#include "Bureaucrat.hpp"
#include <iostream>

static void grade_tests()
{
	std::cout << "===== GRADE TESTS =====\n\n";

	try {
		std::cout << "[1] Construct Bureaucrat with grade 0 (too high)\n";
		Bureaucrat b("Alice", 0);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[2] Construct Bureaucrat with grade 151 (too low)\n";
		Bureaucrat b("Bob", 151);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[3] Construct Bureaucrat with grade 42 (valid)\n";
		Bureaucrat b("Charlie", 42);
		std::cout << b << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Caught unexpected exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[4] Increase grade from 2 to 1 (valid)\n";
		Bureaucrat b("Dave", 2);
		std::cout << "Before: " << b << "\n";
		b.increaseGrade();
		std::cout << "After:  " << b << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[5] Increase grade from 1 to 0 (too high)\n";
		Bureaucrat b("Eve", 1);
		std::cout << "Before: " << b << "\n";
		b.increaseGrade();
		std::cout << "After:  " << b << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[6] Decrease grade from 149 to 150 (valid)\n";
		Bureaucrat b("Frank", 149);
		std::cout << "Before: " << b << "\n";
		b.decreaseGrade();
		std::cout << "After:  " << b << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[7] Decrease grade from 150 to 151 (too low)\n";
		Bureaucrat b("Grace", 150);
		std::cout << "Before: " << b << "\n";
		b.decreaseGrade();
		std::cout << "After:  " << b << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";

	try {
		std::cout << "[8] Multiple increases/decreases\n";
		Bureaucrat b("Hank", 75);
		std::cout << "Original: " << b << "\n";
		for (int i = 0; i < 10; ++i)
			b.increaseGrade(); // Should succeed
		std::cout << "After 10 increases: " << b << "\n";

		for (int i = 0; i < 20; ++i)
			b.decreaseGrade(); // Some may throw if goes below 1
		std::cout << "After 20 decreases: " << b << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "--------------------------------------------\n";
}


static void copy_and_assignment_tests()
{
	std::cout << "===== COPY & ASSIGNMENT TESTS =====\n\n";

	std::cout << "[5] Copy constructor\n";
	Bureaucrat original("Eve", 42);
	std::cout << "Original: " << original << "\n";

	Bureaucrat copy(original);
	std::cout << "Copy:     " << copy << "\n";
	std::cout << "--------------------------------------------\n";

	std::cout << "[6] Assignment operator\n";
	Bureaucrat assigned("Frank", 100);
	std::cout << "Before assignment, assigned: " << assigned << "\n";

	assigned = original;
	std::cout << "After assignment, assigned: " << assigned << "\n";
	std::cout << "--------------------------------------------\n";

	std::cout << "[7] Destructor test (observe output on scope exit)\n";
	{
		Bureaucrat temp("Grace", 75);
		std::cout << "Temp Bureaucrat inside block: " << temp << "\n";
	}
	std::cout << "Exited block\n";
	std::cout << "--------------------------------------------\n";
}

int main()
{
	copy_and_assignment_tests();
	grade_tests();
	return 0;
}
