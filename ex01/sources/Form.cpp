#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:
	_name("DefaultForm"),
	_isSigned(false),
	_gradeToSign(LOWEST_GRADE),
	_gradeToExecute(LOWEST_GRADE)
{
	#ifdef DEBUG
		std::cout << "Form default constructor called" << std::endl;
	#endif
}

Form::Form( std::string const &name, int const &gradeToSign, int const &gradeToExecute )
	:
	_name(name),
	_isSigned(false),
	_gradeToSign(validateGrade(Sign, gradeToSign)),
	_gradeToExecute(validateGrade(Execute, gradeToExecute))
{
	#ifdef DEBUG
		std::cout << "Form parameterized constructor called" << std::endl;
	#endif
}

Form::Form( Form const &other )
	:
	_name(other.getName()),
	_isSigned(other.isSigned()),
	_gradeToSign(other.getGradeToSign()),
	_gradeToExecute(other.getGradeToExecute())
{
	#ifdef DEBUG
		std::cout << "Form copy constructor called" << std::endl;
	#endif
}

Form &Form::operator=( Form const &other )
{
	#ifdef DEBUG
		std::cout << "Form copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_isSigned = other.isSigned();
	}
	return *this;
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << "Form destructor called" << std::endl;
	#endif
}

std::ostream &operator<<( std::ostream& os, Form const& other )
{
	os << "\n------------------------------\n";
	os << " Form Information\n";
	os << "------------------------------\n";
	os << " Name:           " << other.getName() << "\n";
	os << " Grade to sign:  " << static_cast<unsigned int>(other.getGradeToSign()) << "\n";
	os << " Grade to exec:  " << static_cast<unsigned int>(other.getGradeToExecute()) << "\n";
	os << " Signed:         " << (other.isSigned() ? "Yes" : "No") << "\n";
	os << "------------------------------\n";
	return os;
}

std::string const&	Form::getName() const
{
	return this->_name;
}

bool	Form::isSigned() const
{
	return this->_isSigned;
}

uint8_t const&	Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

uint8_t const&	Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool	Form::beSigned( Bureaucrat const &bureaucrat )
{
	if (this->isSigned() == true)
	{
		return false;
	}
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
		return true;
	}
	else
	{
		throw Form::GradeTooLowException("bureaucrat's grade too low.");
	}
}

int	Form::validateGrade( Action action, int const& grade )
{
	std::string validatedGradeName;

	if (action == Sign)
	{
		validatedGradeName = "Grade to sign";
	}
	else
	{
		validatedGradeName = "Grade to execute";
	}

	if (grade < HIGHEST_GRADE)
	{
		throw Form::GradeTooHighException(validatedGradeName + " too high.");
	}
	if (grade > LOWEST_GRADE)
	{
		throw Form::GradeTooLowException(validatedGradeName + " too low.");
	}
	return grade;
}

Form::GradeException::GradeException( std::string const& message ) : message(message)
{}

const char*	Form::GradeException::what() const noexcept
{
	return this->message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string const& message) : GradeException(message)
{}

Form::GradeTooHighException::GradeTooHighException(std::string const& message) : GradeException(message)
{}
