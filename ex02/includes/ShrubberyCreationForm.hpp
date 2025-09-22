#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <AForm.hpp>

enum Tree
{
	Sapling,
	Classic,
	Stacked,
	Pyramid,
	Pine,
	Decorated
};

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	_target;
		static const char*	NAME;
		static const int	GRADE_TO_SIGN;
		static const int	GRADE_TO_EXECUTE;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string const& target );
		ShrubberyCreationForm( ShrubberyCreationForm const& other );
		ShrubberyCreationForm&	operator=( ShrubberyCreationForm const& other );
		~ShrubberyCreationForm();

		std::string const&	getTarget() const;

		void				executeAction() const;
};

std::ostream& operator<<( std::ostream& os, ShrubberyCreationForm const& other );

#endif