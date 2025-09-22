#include "Intern.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	#ifdef DEBUG
		std::cout << "Intern default constructor called" << std::endl;
	#endif
}

Intern::Intern( Intern const & )
{
	#ifdef DEBUG
		std::cout << "Intern copy constructor called" << std::endl;
	#endif
}

Intern &Intern::operator=( Intern const & )
{
	#ifdef DEBUG
		std::cout << "Intern copy assignment operator called" << std::endl;
	#endif
	return *this;
}

Intern::~Intern()
{
	#ifdef DEBUG
		std::cout << "Intern destructor called" << std::endl;
	#endif
}

AForm*	Intern::_makeShrubberyCreationForm( std::string const &target )
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::_makeRobotomyRequestForm( std::string const &target )
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::_makePresidentialPardonForm( std::string const &target )
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
	std::string	types[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		(Intern::*functions[])( std::string const &target ) = { &Intern::_makeShrubberyCreationForm, &Intern::_makeRobotomyRequestForm, &Intern::_makePresidentialPardonForm };

	for (size_t i = 0; i < 3; i++)
	{
		if (types[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*functions[i])(formTarget);
		}
	}
	throw Intern::FormNotFoundException();
}