#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void concrete_form_tests()
{
	std::cout << "===== CONCRETE FORM TESTS =====\n\n";

	{
		std::cout << "[1] ShrubberyCreationForm success\n";
		Bureaucrat high("Alice", 1);
		ShrubberyCreationForm form("home");
		std::cout << "Bureaucrat before: " << high << "\n";
		std::cout << "Form before: " << form << "\n";
		std::cout << "Trying to sign...\n";
		high.signForm(form);
		std::cout << "Form after sign: " << form << "\n";
		std::cout << "Trying to execute...\n";
		high.executeForm(form);
		std::cout << "Bureaucrat after: " << high << "\n";
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[2] ShrubberyCreationForm exec fail (not signed)\n";
		Bureaucrat high("Bob", 1);
		ShrubberyCreationForm form("garden");
		std::cout << "Bureaucrat: " << high << "\n";
		std::cout << "Form: " << form << "\n";
		std::cout << "Trying to execute (should fail)...\n";
		try {
			high.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << "\n";
		}
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[3] ShrubberyCreationForm sign/exec fail (grade too low)\n";
		Bureaucrat low("Charlie", 150);
		ShrubberyCreationForm form("yard");
		std::cout << "Bureaucrat: " << low << "\n";
		std::cout << "Form: " << form << "\n";
		std::cout << "Trying to sign (should fail)...\n";
		low.signForm(form);
		std::cout << "Form after sign attempt: " << form << "\n";
		std::cout << "Trying to execute (should fail)...\n";
		try {
			low.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << "\n";
		}
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[4] RobotomyRequestForm multiple executions (random)\n";
		Bureaucrat mid("Dave", 1);
		RobotomyRequestForm form("targetX");
		std::cout << "Bureaucrat: " << mid << "\n";
		std::cout << "Form: " << form << "\n";
		std::cout << "Trying to sign...\n";
		mid.signForm(form);
		std::cout << "Form after sign: " << form << "\n";
		for (int i = 0; i < 5; i++) {
			std::cout << "Execution attempt #" << (i+1) << "...\n";
			mid.executeForm(form);
		}
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[5] RobotomyRequestForm sign/exec fail (grade too low)\n";
		Bureaucrat low("Eve", 100);
		RobotomyRequestForm form("targetY");
		std::cout << "Bureaucrat: " << low << "\n";
		std::cout << "Form: " << form << "\n";
		std::cout << "Trying to sign (should fail)...\n";
		low.signForm(form);
		std::cout << "Form after sign attempt: " << form << "\n";
		std::cout << "Trying to execute (should fail)...\n";
		try {
			low.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << "\n";
		}
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[6] PresidentialPardonForm success\n";
		Bureaucrat prez("Frank", 1);
		PresidentialPardonForm form("Marvin");
		std::cout << "Bureaucrat before: " << prez << "\n";
		std::cout << "Form before: " << form << "\n";
		std::cout << "Trying to sign...\n";
		prez.signForm(form);
		std::cout << "Form after sign: " << form << "\n";
		std::cout << "Trying to execute...\n";
		prez.executeForm(form);
		std::cout << "Bureaucrat after: " << prez << "\n";
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[7] PresidentialPardonForm exec fail (not signed)\n";
		Bureaucrat high("Grace", 1);
		PresidentialPardonForm form("Arthur");
		std::cout << "Bureaucrat: " << high << "\n";
		std::cout << "Form: " << form << "\n";
		std::cout << "Trying to execute (should fail)...\n";
		try {
			high.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << "\n";
		}
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[8] PresidentialPardonForm sign/exec fail (grade too low)\n";
		Bureaucrat low("Hank", 50);
		PresidentialPardonForm form("Ford");
		std::cout << "Bureaucrat: " << low << "\n";
		std::cout << "Form: " << form << "\n";
		std::cout << "Trying to sign (should fail)...\n";
		low.signForm(form);
		std::cout << "Form after sign attempt: " << form << "\n";
		std::cout << "Trying to execute (should fail)...\n";
		try {
			low.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << "\n";
		}
		std::cout << "--------------------------------------------\n";
	}
}

int main()
{
	try {
		concrete_form_tests();
	}
	catch(const std::exception& e) {
		std::cerr << "Caught exception in main: " << e.what() << '\n';
	}
	return 0;
}
