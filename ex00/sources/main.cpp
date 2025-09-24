#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

static void copy_and_assignment_tests()
{
	std::cout << BOLD CYAN "\n===== COPY & ASSIGNMENT TESTS =====\n\n" RESET;

	std::cout << BOLD "[1] " RESET GREEN "Copy constructor\n" RESET;
	Bureaucrat original("Eve", 42);
	std::cout << CYAN "Original: " RESET << original << "\n";
	Bureaucrat copy(original);
	std::cout << CYAN "Copy:     " RESET << copy << "\n";
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[2] " RESET GREEN "Assignment operator\n" RESET;
	Bureaucrat assigned("Frank", 100);
	std::cout << CYAN "Before assignment, assigned: " RESET << assigned << "\n";
	assigned = original;
	std::cout << CYAN "After assignment, assigned: " RESET << assigned << "\n";
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[3] " RESET CYAN "Destructor test (observe output on scope exit)\n" RESET;
	{
		Bureaucrat temp("Grace", 75);
		std::cout << CYAN "Temp Bureaucrat inside block: " RESET << temp << "\n";
	}
	std::cout << CYAN "Exited block\n" RESET;
	std::cout << MAGENTA "--------------------------------------------\n" RESET;
	std::cout << BOLD CYAN "\n===== END OF COPY & ASSIGNMENT TESTS =====\n" RESET;
}

static void grade_tests()
{
	std::cout << BOLD CYAN "\n===== GRADE TESTS =====\n\n" RESET;

	Bureaucrat* b = nullptr;
	std::cout << BOLD "[1] " RESET YELLOW "Construct Bureaucrat with grade 0 (too high)\n" RESET;
	try {
		b = new Bureaucrat("Alice", 0);
		delete b;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[2] " RESET YELLOW "Construct Bureaucrat with grade 151 (too low)\n" RESET;
	try {
		b = new Bureaucrat("Bob", 151);
		delete b;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[3] " RESET GREEN "Construct Bureaucrat with grade 42 (valid)\n" RESET;
	try {
		b = new Bureaucrat("Charlie", 42);
		std::cout << CYAN << *b << RESET "\n";
		delete b;
	} catch (const std::exception& e) {
		std::cerr << RED "Caught unexpected exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[4] " RESET GREEN "Increase grade from 2 to 1 (valid)\n" RESET;
	try {
		Bureaucrat d("Dave", 2);
		std::cout << CYAN "Before: " RESET << d << "\n";
		d.increaseGrade();
		std::cout << CYAN "After:  " RESET << d << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[5] " RESET YELLOW "Increase grade from 1 to 0 (too high)\n" RESET;
	try {
		Bureaucrat e("Eve", 1);
		std::cout << CYAN "Before: " RESET << e << "\n";
		e.increaseGrade();
		std::cout << CYAN "After:  " RESET << e << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[6] " RESET GREEN "Decrease grade from 149 to 150 (valid)\n" RESET;
	try {
		Bureaucrat f("Frank", 149);
		std::cout << CYAN "Before: " RESET << f << "\n";
		f.decreaseGrade();
		std::cout << CYAN "After:  " RESET << f << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[7] " RESET YELLOW "Decrease grade from 150 to 151 (too low)\n" RESET;
	try {
		Bureaucrat g("Grace", 150);
		std::cout << CYAN "Before: " RESET << g << "\n";
		g.decreaseGrade();
		std::cout << CYAN "After:  " RESET << g << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[8] " RESET CYAN "Multiple increases/decreases\n" RESET;
	try {
		Bureaucrat h("Hank", 75);
		std::cout << CYAN "Original: " RESET << h << "\n";
		for (int i = 0; i < 10; ++i)
			h.increaseGrade();
		std::cout << CYAN "After 10 increases: " RESET << h << "\n";
		for (int i = 0; i < 20; ++i)
			h.decreaseGrade();
		std::cout << CYAN "After 20 decreases: " RESET << h << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD CYAN "\n===== END OF GRADE TESTS =====\n" RESET;
}

int main()
{
	try
	{
		copy_and_assignment_tests();
		grade_tests();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Caught exception in main: " << e.what() << RESET << '\n';
	}
	return 0;
}
