#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <AForm.hpp>

# define MIN_RANDOM_VALUE 0
# define MAX_RANDOM_VALUE 1

class RobotomyRequestForm : public AForm
{
	private:
		std::string const	_target;
		static const char*	NAME;
		static const int	GRADE_TO_SIGN;
		static const int	GRADE_TO_EXECUTE;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string const& target );
		RobotomyRequestForm( RobotomyRequestForm const& other );
		RobotomyRequestForm&	operator=( RobotomyRequestForm const& other );
		~RobotomyRequestForm();

		std::string const&	getTarget() const;

		void				executeAction() const;
};

std::ostream& operator<<( std::ostream& os, RobotomyRequestForm const& other );

#endif