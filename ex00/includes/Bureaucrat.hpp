#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdint>

class Bureaucrat
{
	private:
		std::string const	_name;
		uint8_t				_grade;
	public:
		Bureaucrat();
		Bureaucrat( std::string const& name, int const& grade );
		Bureaucrat( Bureaucrat const &other );
		Bureaucrat&	operator=( Bureaucrat const &other );
		~Bureaucrat();
		
		std::string const&	getName() const;
		uint8_t const&		getGrade() const;
		
		void				setGrade( int const& grade );

		void				increaseGrade();
		void				decreaseGrade();

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

std::ostream& operator<<( std::ostream& os, Bureaucrat const& other );

#endif