#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <iostream>

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Bureaucrat;

enum Action
{
	Sign,
	Execute
};

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		uint8_t const		_gradeToSign;
		uint8_t const		_gradeToExecute;

		static int	validateGrade(  Action action, int const& grade );
	public:
		AForm();
		AForm( std::string const& name, int const& gradeToSign, int const& gradeToExecute );
		AForm( AForm const& other );
		AForm&	operator=( AForm const& other );
		virtual	~AForm();

		std::string const&	getName() const;
		bool				isSigned() const;
		uint8_t const&		getGradeToSign() const;
		uint8_t const&		getGradeToExecute() const;

		bool				beSigned( Bureaucrat const& bureaucrat );

		virtual void		executeAction() const = 0;

		void				execute(Bureaucrat const & executor) const;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Form is not signed.";
				}
		};
};

std::ostream& operator<<( std::ostream& os, AForm const& other );

#endif