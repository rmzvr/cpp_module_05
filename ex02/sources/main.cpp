#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define CYAN	"\033[36m"
#define MAGENTA	"\033[35m"
#define BOLD	"\033[1m"

static void	concrete_form_tests()
{
	std::cout << BOLD CYAN "\n===== CONCRETE FORM TESTS =====\n\n" RESET;

	{
		std::cout << BOLD "[1] " RESET GREEN "ShrubberyCreationForm (success)\n" RESET;
		Bureaucrat high("Alice", 1);
		ShrubberyCreationForm form("home");
		std::cout << CYAN "Bureaucrat before: " RESET << high << "\n";
		std::cout << CYAN "Form before: " RESET << form << "\n";
		std::cout << YELLOW "Trying to sign...\n" RESET;
		high.signForm(form);
		std::cout << CYAN "Form after sign: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute...\n" RESET;
		high.executeForm(form);
		std::cout << CYAN "Bureaucrat after: " RESET << high << "\n";
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[2] " RESET YELLOW "ShrubberyCreationForm (exec fail, not signed)\n" RESET;
		Bureaucrat high("Bob", 1);
		ShrubberyCreationForm form("garden");
		std::cout << CYAN "Bureaucrat: " RESET << high << "\n";
		std::cout << CYAN "Form: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute (should fail)...\n" RESET;
		try
		{
			high.executeForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[3] " RESET YELLOW "ShrubberyCreationForm (sign/exec fail, grade too low)\n" RESET;
		Bureaucrat low("Charlie", 150);
		ShrubberyCreationForm form("yard");
		std::cout << CYAN "Bureaucrat: " RESET << low << "\n";
		std::cout << CYAN "Form: " RESET << form << "\n";
		std::cout << YELLOW "Trying to sign (should fail)...\n" RESET;
		low.signForm(form);
		std::cout << CYAN "Form after sign attempt: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute (should fail)...\n" RESET;
		try
		{
			low.executeForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[4] " RESET GREEN "RobotomyRequestForm (multiple executions)\n" RESET;
		Bureaucrat mid("Dave", 1);
		RobotomyRequestForm form("targetX");
		std::cout << CYAN "Bureaucrat: " RESET << mid << "\n";
		std::cout << CYAN "Form: " RESET << form << "\n";
		std::cout << YELLOW "Trying to sign...\n" RESET;
		mid.signForm(form);
		std::cout << CYAN "Form after sign: " RESET << form << "\n";
		for (int i = 0; i < 5; i++)
		{
			std::cout << YELLOW "Execution attempt #" << (i + 1) << "...\n" RESET;
			mid.executeForm(form);
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[5] " RESET YELLOW "RobotomyRequestForm (sign/exec fail, grade too low)\n" RESET;
		Bureaucrat low("Eve", 100);
		RobotomyRequestForm form("targetY");
		std::cout << CYAN "Bureaucrat: " RESET << low << "\n";
		std::cout << CYAN "Form: " RESET << form << "\n";
		std::cout << YELLOW "Trying to sign (should fail)...\n" RESET;
		low.signForm(form);
		std::cout << CYAN "Form after sign attempt: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute (should fail)...\n" RESET;
		try
		{
			low.executeForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[6] " RESET GREEN "PresidentialPardonForm (success)\n" RESET;
		Bureaucrat prez("Frank", 1);
		PresidentialPardonForm form("Marvin");
		std::cout << CYAN "Bureaucrat before: " RESET << prez << "\n";
		std::cout << CYAN "Form before: " RESET << form << "\n";
		std::cout << YELLOW "Trying to sign...\n" RESET;
		prez.signForm(form);
		std::cout << CYAN "Form after sign: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute...\n" RESET;
		prez.executeForm(form);
		std::cout << CYAN "Bureaucrat after: " RESET << prez << "\n";
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[7] " RESET YELLOW "PresidentialPardonForm (exec fail, not signed)\n" RESET;
		Bureaucrat high("Grace", 1);
		PresidentialPardonForm form("Arthur");
		std::cout << CYAN "Bureaucrat: " RESET << high << "\n";
		std::cout << CYAN "Form: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute (should fail)...\n" RESET;
		try
		{
			high.executeForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[8] " RESET YELLOW "PresidentialPardonForm (sign/exec fail, grade too low)\n" RESET;
		Bureaucrat low("Hank", 50);
		PresidentialPardonForm form("Ford");
		std::cout << CYAN "Bureaucrat: " RESET << low << "\n";
		std::cout << CYAN "Form: " RESET << form << "\n";
		std::cout << YELLOW "Trying to sign (should fail)...\n" RESET;
		low.signForm(form);
		std::cout << CYAN "Form after sign attempt: " RESET << form << "\n";
		std::cout << YELLOW "Trying to execute (should fail)...\n" RESET;
		try
		{
			low.executeForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	std::cout << BOLD CYAN "\n===== END OF CONCRETE FORM TESTS =====\n" RESET;
}

int	main(void)
{
	try
	{
		concrete_form_tests();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Caught exception in main: " << e.what() << RESET << '\n';
	}
	return 0;
}
