#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Color macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

static void test_makeForm()
{
	std::cout << BOLD CYAN "\n===== INTERN MAKEFORM TESTS =====\n\n" RESET;

	Intern someRandomIntern;
	Bureaucrat high("Alice", 1);   // can sign/execute all
	Bureaucrat low("Bob", 150);    // cannot sign/execute any
	AForm* form;

	// [1] ShrubberyCreationForm success
	std::cout << BOLD "[1] " RESET GREEN "ShrubberyCreationForm (success)\n" RESET;
	try {
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << CYAN "Signing... " RESET;
		high.signForm(*form);
		std::cout << CYAN "Executing... " RESET;
		high.executeForm(*form);
		delete form;
		std::cout << GREEN "OK\n" RESET;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [2] ShrubberyCreationForm fail (low grade)
	std::cout << BOLD "[2] " RESET YELLOW "ShrubberyCreationForm (sign/exec fail)\n" RESET;
	try {
		form = someRandomIntern.makeForm("shrubbery creation", "garden");
		std::cout << CYAN "Signing... " RESET;
		low.signForm(*form);
		std::cout << CYAN "Executing... " RESET;
		try {
			low.executeForm(*form);
		} catch (const std::exception& e) {
			std::cerr << RED "Caught exception on exec: " << e.what() << RESET "\n";
		}
		delete form;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [3] RobotomyRequestForm success (multiple executions)
	std::cout << BOLD "[3] " RESET GREEN "RobotomyRequestForm (success, multiple exec)\n" RESET;
	try {
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << CYAN "Signing... " RESET;
		high.signForm(*form);
		for (int i = 0; i < 3; ++i) {
			std::cout << CYAN "Executing (" << (i+1) << ")... " RESET;
			high.executeForm(*form);
		}
		delete form;
		std::cout << GREEN "OK\n" RESET;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [4] RobotomyRequestForm fail (low grade)
	std::cout << BOLD "[4] " RESET YELLOW "RobotomyRequestForm (sign/exec fail)\n" RESET;
	try {
		form = someRandomIntern.makeForm("robotomy request", "TargetX");
		std::cout << CYAN "Signing... " RESET;
		low.signForm(*form);
		std::cout << CYAN "Executing... " RESET;
		try {
			low.executeForm(*form);
		} catch (const std::exception& e) {
			std::cerr << RED "Caught exception on exec: " << e.what() << RESET "\n";
		}
		delete form;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [5] PresidentialPardonForm success
	std::cout << BOLD "[5] " RESET GREEN "PresidentialPardonForm (success)\n" RESET;
	try {
		form = someRandomIntern.makeForm("presidential pardon", "Marvin");
		std::cout << CYAN "Signing... " RESET;
		high.signForm(*form);
		std::cout << CYAN "Executing... " RESET;
		high.executeForm(*form);
		delete form;
		std::cout << GREEN "OK\n" RESET;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [6] PresidentialPardonForm fail (low grade)
	std::cout << BOLD "[6] " RESET YELLOW "PresidentialPardonForm (sign/exec fail)\n" RESET;
	try {
		form = someRandomIntern.makeForm("presidential pardon", "Arthur");
		std::cout << CYAN "Signing... " RESET;
		low.signForm(*form);
		std::cout << CYAN "Executing... " RESET;
		try {
			low.executeForm(*form);
		} catch (const std::exception& e) {
			std::cerr << RED "Caught exception on exec: " << e.what() << RESET "\n";
		}
		delete form;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [7] Invalid form name (should throw)
	std::cout << BOLD "[7] " RESET RED "Invalid form name\n" RESET;
	try {
		form = someRandomIntern.makeForm("unknown form", "Target");
		delete form; // should not reach here
	} catch (const std::exception& e) {
		std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	// [8] Edge case: empty target
	std::cout << BOLD "[8] " RESET CYAN "Empty target\n" RESET;
	try {
		form = someRandomIntern.makeForm("shrubbery creation", "");
		std::cout << CYAN "Signing... " RESET;
		high.signForm(*form);
		std::cout << CYAN "Executing... " RESET;
		high.executeForm(*form);
		delete form;
		std::cout << GREEN "OK\n" RESET;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD CYAN "\n===== END OF MAKEFORM TESTS =====\n" RESET;
}

int main()
{
	test_makeForm();
	return 0;
}
