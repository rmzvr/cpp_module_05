#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void	form_signing_tests()
{
	try
	{
		std::cout << "===== SIGNING FORMS TESTS =====\n\n";

		{
			std::cout << "[1] Successful signing (grade high enough)\n";
			Bureaucrat bureaucrat("Alice", 50);
			Form form("FormA", 60, 70);
			std::cout << bureaucrat << "\n" << form << "\n";
			bureaucrat.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[2] Failed signing (grade too low)\n";
			Bureaucrat bureaucrat("Bob", 120);
			Form form("FormB", 100, 100);
			std::cout << bureaucrat << "\n" << form << "\n";
			bureaucrat.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[3] Already signed form\n";
			Bureaucrat bureaucrat("Charlie", 20);
			Form form("FormC", 50, 50);
			std::cout << bureaucrat << "\n" << form << "\n";
			bureaucrat.signForm(form);
			bureaucrat.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[4] Multiple forms signed by one bureaucrat\n";
			Bureaucrat bureaucrat("Diana", 10);
			Form form1("FormD1", 20, 30);
			Form form2("FormD2", 15, 15);
			std::cout << bureaucrat << "\n" << form1 << "\n" << form2 << "\n";
			bureaucrat.signForm(form1);
			bureaucrat.signForm(form2);
			std::cout << form1 << "\n" << form2 << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[5] Multiple bureaucrats on the same form\n";
			Form form("FormE", 75, 75);
			Bureaucrat low("Eve", 120);
			Bureaucrat high("Frank", 50);
			std::cout << low << "\n" << high << "\n" << form << "\n";
			low.signForm(form);
			high.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[6] Edge case: Bureaucrat grade 150\n";
			Bureaucrat bureaucrat("Greg", 150);
			Form form("FormF", 150, 150);
			std::cout << bureaucrat << "\n" << form << "\n";
			bureaucrat.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[7] Edge case: Bureaucrat grade 1\n";
			Bureaucrat bureaucrat("Hank", 1);
			Form form("FormG", 1, 1);
			std::cout << bureaucrat << "\n" << form << "\n";
			bureaucrat.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[8] Bureaucrat signs many forms\n";
			Bureaucrat bureaucrat("Ivy", 42);
			Form form1("FormH1", 50, 50);
			Form form2("FormH2", 45, 45);
			Form form3("FormH3", 40, 40);
			std::cout << bureaucrat << "\n";
			std::cout << form1 << "\n" << form2 << "\n" << form3 << "\n";
			bureaucrat.signForm(form1);
			bureaucrat.signForm(form2);
			bureaucrat.signForm(form3);
			std::cout << form1 << "\n" << form2 << "\n" << form3 << "\n";
			std::cout << "--------------------------------------------\n";
		}

		{
			std::cout << "[9] Form with equal sign/execute grade\n";
			Bureaucrat bureaucrat("Jack", 10);
			Form form("FormI", 10, 10);
			std::cout << bureaucrat << "\n" << form << "\n";
			bureaucrat.signForm(form);
			std::cout << form << "\n";
			std::cout << "--------------------------------------------\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception in form_signing_tests: " << e.what() << '\n';
	}
}

static void form_copy_and_assignment_tests()
{
	std::cout << "===== FORM COPY & ASSIGNMENT TESTS =====\n\n";

	{
		std::cout << "[0] Creation with invalid grades\n";
		try
		{
			Form tooHigh("TooHighForm", 0, 50);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << "\n";
		}

		try
		{
			Form tooLow("TooLowForm", 50, 151);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << "\n";
		}
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[1] Copy constructor\n";
		Form original("FormX", 50, 100);
		std::cout << "Original before signing: " << original << "\n";

		Form copy(original);
		std::cout << "Copy (before signing original): " << copy << "\n";

		Bureaucrat signer("Alice", 40);
		original.beSigned(signer);
		std::cout << "Original after signing:  " << original << "\n";
		std::cout << "Copy after original signed: " << copy << "\n";
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[2] Assignment operator\n";
		Form original("FormX", 50, 100);
		original.beSigned(Bureaucrat("TempSigner", 40));

		Form assigned("Temp", 75, 75);
		std::cout << "Before assignment, assigned: " << assigned << "\n";

		assigned = original;
		std::cout << "After assignment, assigned:  " << assigned << "\n";

		Form another("AnotherForm", 60, 60);
		Bureaucrat signer2("Bob", 50);
		another.beSigned(signer2);

		std::cout << "Another (signed):       " << another << "\n";
		std::cout << "Assigned (unchanged):   " << assigned << "\n";
		std::cout << "--------------------------------------------\n";
	}

	{
		std::cout << "[3] Destructor test (observe output on scope exit)\n";
		Form temp("ScopedForm", 25, 25);
		std::cout << "Temp Form inside block: " << temp << "\n";
	}
	std::cout << "Exited block\n";
	std::cout << "--------------------------------------------\n";
}

int main()
{
	form_signing_tests();
	form_copy_and_assignment_tests();
	return 0;
}
