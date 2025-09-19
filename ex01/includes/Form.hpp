#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

enum Action
{
	Sign,
	Execute
};

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		uint8_t const		_gradeToSign;
		uint8_t const		_gradeToExecute;

		static int	validateGrade(  Action action, int const& grade );
	public:
		Form();
		Form( std::string const& name, int const& gradeToSign, int const& gradeToExecute );
		Form( Form const& other );
		Form&	operator=( Form const& other );
		~Form();

		std::string const&	getName() const;
		bool				isSigned() const;
		uint8_t const&		getGradeToSign() const;
		uint8_t const&		getGradeToExecute() const;

		bool				beSigned( Bureaucrat const& bureaucrat );

		class GradeException : public std::exception
		{
			protected:
				std::string	message;
			public:
				explicit	GradeException( std::string const& message );
				const char*	what() const noexcept override;
		};

		class GradeTooLowException : public GradeException
		{
			public:
				explicit	GradeTooLowException( std::string const& message );
		};

		class GradeTooHighException : public GradeException
		{
			public:
				explicit	GradeTooHighException( std::string const& message );
		};
};

std::ostream& operator<<( std::ostream& os, Form const& other );

#endif