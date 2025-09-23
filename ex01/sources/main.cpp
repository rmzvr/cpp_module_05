#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

static void form_signing_tests()
{
	std::cout << BOLD CYAN "\n===== SIGNING FORMS TESTS =====\n\n" RESET;
	std::cout << BOLD "[1] " RESET GREEN "Successful signing (grade high enough)\n" RESET;
	try {
		Bureaucrat bureaucrat("Alice", 50);
		Form form("FormA", 60, 70);
		std::cout << CYAN << bureaucrat << "\n" << form << RESET "\n";
		bureaucrat.signForm(form);
		std::cout << CYAN << form << RESET "\n";
		std::cout << GREEN "OK\n" RESET;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[2] " RESET YELLOW "Failed signing (grade too low)\n" RESET;
	try {
		Bureaucrat bureaucrat("Bob", 120);
		Form form("FormB", 100, 100);
		std::cout << CYAN << bureaucrat << "\n" << form << RESET "\n";
		bureaucrat.signForm(form);
		std::cout << CYAN << form << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[3] " RESET CYAN "Already signed form\n" RESET;
	try {
		Bureaucrat bureaucrat("Charlie", 20);
		Form form("FormC", 50, 50);
		std::cout << CYAN << bureaucrat << "\n" << form << RESET "\n";
		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
		std::cout << CYAN << form << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[4] " RESET GREEN "Multiple forms signed by one bureaucrat\n" RESET;
	try {
		Bureaucrat bureaucrat("Diana", 10);
		Form form1("FormD1", 20, 30);
		Form form2("FormD2", 15, 15);
		std::cout << CYAN << bureaucrat << "\n" << form1 << "\n" << form2 << RESET "\n";
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		std::cout << CYAN << form1 << "\n" << form2 << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[5] " RESET CYAN "Multiple bureaucrats on the same form\n" RESET;
	try {
		Form form("FormE", 75, 75);
		Bureaucrat low("Eve", 120);
		Bureaucrat high("Frank", 50);
		std::cout << CYAN << low << "\n" << high << "\n" << form << RESET "\n";
		low.signForm(form);
		high.signForm(form);
		std::cout << CYAN << form << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[6] " RESET YELLOW "Edge case: Bureaucrat grade 150\n" RESET;
	try {
		Bureaucrat bureaucrat("Greg", 150);
		Form form("FormF", 150, 150);
		std::cout << CYAN << bureaucrat << "\n" << form << RESET "\n";
		bureaucrat.signForm(form);
		std::cout << CYAN << form << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[7] " RESET GREEN "Edge case: Bureaucrat grade 1\n" RESET;
	try {
		Bureaucrat bureaucrat("Hank", 1);
		Form form("FormG", 1, 1);
		std::cout << CYAN << bureaucrat << "\n" << form << RESET "\n";
		bureaucrat.signForm(form);
		std::cout << CYAN << form << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[8] " RESET CYAN "Bureaucrat signs many forms\n" RESET;
	try {
		Bureaucrat bureaucrat("Ivy", 42);
		Form form1("FormH1", 50, 50);
		Form form2("FormH2", 45, 45);
		Form form3("FormH3", 40, 40);
		std::cout << CYAN << bureaucrat << RESET "\n";
		std::cout << CYAN << form1 << "\n" << form2 << "\n" << form3 << RESET "\n";
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		bureaucrat.signForm(form3);
		std::cout << CYAN << form1 << "\n" << form2 << "\n" << form3 << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[9] " RESET GREEN "Form with equal sign/execute grade\n" RESET;
	try {
		Bureaucrat bureaucrat("Jack", 10);
		Form form("FormI", 10, 10);
		std::cout << CYAN << bureaucrat << "\n" << form << RESET "\n";
		bureaucrat.signForm(form);
		std::cout << CYAN << form << RESET "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD CYAN "\n===== END OF SIGNING FORMS TESTS =====\n" RESET;
}

static void form_copy_and_assignment_tests()
{
	std::cout << BOLD CYAN "\n===== FORM COPY & ASSIGNMENT TESTS =====\n\n" RESET;
	std::cout << BOLD "[1] " RESET GREEN "Copy constructor\n" RESET;
	try {
		Form original("FormX", 50, 100);
		std::cout << CYAN "Original before signing: " RESET << original << "\n";
		Form copy(original);
		std::cout << CYAN "Copy (before signing original): " RESET << copy << "\n";
		Bureaucrat signer("Alice", 40);
		original.beSigned(signer);
		std::cout << CYAN "Original after signing:  " RESET << original << "\n";
		std::cout << CYAN "Copy after original signed: " RESET << copy << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[2] " RESET GREEN "Assignment operator\n" RESET;
	try {
		Form original("FormX", 50, 100);
		original.beSigned(Bureaucrat("TempSigner", 40));
		Form assigned("Temp", 75, 75);
		std::cout << CYAN "Before assignment, assigned: " RESET << assigned << "\n";
		assigned = original;
		std::cout << CYAN "After assignment, assigned:  " RESET << assigned << "\n";
		Form another("AnotherForm", 60, 60);
		Bureaucrat signer2("Bob", 50);
		another.beSigned(signer2);
		std::cout << CYAN "Another (signed):       " RESET << another << "\n";
		std::cout << CYAN "Assigned (unchanged):   " RESET << assigned << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << MAGENTA "--------------------------------------------\n" RESET;

	std::cout << BOLD "[3] " RESET CYAN "Destructor test (observe output on scope exit)\n" RESET;
	try {
		Form temp("ScopedForm", 25, 25);
		std::cout << CYAN "Temp Form inside block: " RESET << temp << "\n";
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << RESET "\n";
	}
	std::cout << CYAN "Exited block" RESET "\n";
	std::cout << MAGENTA "--------------------------------------------\n" RESET;
	std::cout << BOLD CYAN "\n===== END OF FORM COPY & ASSIGNMENT TESTS =====\n" RESET;
}

int main()
{
	try
	{
		form_signing_tests();
		form_copy_and_assignment_tests();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Caught exception in main: " << e.what() << RESET << '\n';
	}
	return 0;
}
