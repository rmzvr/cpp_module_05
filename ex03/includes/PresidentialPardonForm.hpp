#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
	private:
		std::string const	_target;
		static const char*	NAME;
		static const int	GRADE_TO_SIGN;
		static const int	GRADE_TO_EXECUTE;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string const& target );
		PresidentialPardonForm( PresidentialPardonForm const& other );
		PresidentialPardonForm&	operator=( PresidentialPardonForm const& other );
		~PresidentialPardonForm();

		std::string const&	getTarget() const;

		void				executeAction() const;
};

std::ostream& operator<<( std::ostream& os, PresidentialPardonForm const& other );

#endif