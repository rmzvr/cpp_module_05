#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	Bureaucrat high("Alice", 1);
	Bureaucrat low("Bob", 150);
	AForm* form;

	{
		std::cout << BOLD "[1] " RESET GREEN "ShrubberyCreationForm (success)\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("shrubbery creation", "home");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Signing... " RESET;
			high.signForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception signing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Executing... " RESET;
			high.executeForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception executing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		delete form;
		std::cout << GREEN "OK\n" RESET;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[2] " RESET YELLOW "ShrubberyCreationForm (sign/exec fail)\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("shrubbery creation", "garden");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		std::cout << CYAN "Signing... " RESET;
		low.signForm(*form);
		
		try
		{
			std::cout << CYAN "Executing... " RESET;
			low.executeForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception on exec: " << e.what() << RESET "\n";
		}
		delete form;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[3] " RESET GREEN "RobotomyRequestForm (success, multiple exec)\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("robotomy request", "Bender");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Signing... " RESET;
			high.signForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception signing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		for (int i = 0; i < 3; ++i) {
			try
			{
				std::cout << CYAN "Executing (" << (i+1) << ")... " RESET;
				high.executeForm(*form);
			}
			catch (const std::exception& e)
			{
				std::cerr << RED "Exception executing form: " << e.what() << RESET "\n";
				delete form;
				std::cout << MAGENTA "--------------------------------------------\n" RESET;
				return;
			}
		}
		delete form;
		std::cout << GREEN "OK\n" RESET;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[4] " RESET YELLOW "RobotomyRequestForm (sign/exec fail)\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("robotomy request", "TargetX");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		std::cout << CYAN "Signing... " RESET;
		low.signForm(*form);
		
		try
		{
			std::cout << CYAN "Executing... " RESET;
			low.executeForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception on exec: " << e.what() << RESET "\n";
		}
		delete form;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[5] " RESET GREEN "PresidentialPardonForm (success)\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("presidential pardon", "Marvin");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Signing... " RESET;
			high.signForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception signing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Executing... " RESET;
			high.executeForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception executing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		delete form;
		std::cout << GREEN "OK\n" RESET;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[6] " RESET YELLOW "PresidentialPardonForm (sign/exec fail)\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("presidential pardon", "Arthur");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		std::cout << CYAN "Signing... " RESET;
		low.signForm(*form);
		
		try
		{
			std::cout << CYAN "Executing... " RESET;
			low.executeForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception on exec: " << e.what() << RESET "\n";
		}
		delete form;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[7] " RESET RED "Invalid form name\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("unknown form", "Target");
			delete form;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Caught exception: " << e.what() << RESET "\n";
		}
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	{
		std::cout << BOLD "[8] " RESET CYAN "Empty target\n" RESET;
		form = nullptr;
		try
		{
			form = someRandomIntern.makeForm("shrubbery creation", "");
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception creating form: " << e.what() << RESET "\n";
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Signing... " RESET;
			high.signForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception signing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		try
		{
			std::cout << CYAN "Executing... " RESET;
			high.executeForm(*form);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Exception executing form: " << e.what() << RESET "\n";
			delete form;
			std::cout << MAGENTA "--------------------------------------------\n" RESET;
			return;
		}
		delete form;
		std::cout << GREEN "OK\n" RESET;
		std::cout << MAGENTA "--------------------------------------------\n" RESET;
	}

	std::cout << BOLD CYAN "\n===== END OF MAKEFORM TESTS =====\n" RESET;
}

int main()
{
	try
	{
		test_makeForm();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Caught exception in main: " << e.what() << RESET << '\n';
	}
	return 0;
}
