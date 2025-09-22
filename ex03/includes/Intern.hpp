#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <cstdint>

class AForm;

enum Forms
{
	ShrubberyCreation,
	RobotomyRequest,
	PresidentialPardon
};

class Intern
{
	private:
		AForm*	_makeShrubberyCreationForm( std::string const& target );
		AForm*	_makeRobotomyRequestForm( std::string const& target );
		AForm*	_makePresidentialPardonForm( std::string const& target );
	public:
		Intern();
		Intern( Intern const &other );
		Intern&	operator=( Intern const &other );
		~Intern();

		AForm*	makeForm( std::string const& formName, std::string const& formTarget );

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Form is not exist.";
				}
		};

};

#endif