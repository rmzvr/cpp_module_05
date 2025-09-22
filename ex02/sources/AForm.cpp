#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:
	_name("DefaultForm"),
	_isSigned(false),
	_gradeToSign(LOWEST_GRADE),
	_gradeToExecute(LOWEST_GRADE)
{
	#ifdef DEBUG
		std::cout << "AForm default constructor called" << std::endl;
	#endif
}

AForm::AForm( std::string const &name, int const &gradeToSign, int const &gradeToExecute )
	:
	_name(name),
	_isSigned(false),
	_gradeToSign(validateGrade(Sign, gradeToSign)),
	_gradeToExecute(validateGrade(Execute, gradeToExecute))
{
	#ifdef DEBUG
		std::cout << "AForm parameterized constructor called" << std::endl;
	#endif
}

AForm::AForm( AForm const &other )
	:
	_name(other.getName()),
	_isSigned(other.isSigned()),
	_gradeToSign(other.getGradeToSign()),
	_gradeToExecute(other.getGradeToExecute())
{
	#ifdef DEBUG
		std::cout << "AForm copy constructor called" << std::endl;
	#endif
}

AForm &AForm::operator=( AForm const &other )
{
	#ifdef DEBUG
		std::cout << "AForm copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_isSigned = other.isSigned();
	}
	return *this;
}

AForm::~AForm()
{
	#ifdef DEBUG
		std::cout << "AForm destructor called" << std::endl;
	#endif
}

std::ostream &operator<<( std::ostream& os, AForm const& other )
{
	os << "\n------------------------------\n";
	os << " Name:           " << other.getName() << "\n";
	os << " Grade to sign:  " << static_cast<unsigned int>(other.getGradeToSign()) << "\n";
	os << " Grade to exec:  " << static_cast<unsigned int>(other.getGradeToExecute()) << "\n";
	os << " Signed:         " << (other.isSigned() ? "Yes" : "No") << "\n";
	os << "------------------------------\n";
	return os;
}

std::string const&	AForm::getName() const
{
	return this->_name;
}

bool	AForm::isSigned() const
{
	return this->_isSigned;
}

uint8_t const&	AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

uint8_t const&	AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool	AForm::beSigned( Bureaucrat const &bureaucrat )
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
		throw AForm::GradeTooLowException("bureaucrat's grade too low.");
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
	{
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException("Grade to execute too low.");
	}
	executeAction();
}

int	AForm::validateGrade( Action action, int const& grade )
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
		throw AForm::GradeTooHighException(validatedGradeName + " too high.");
	}
	if (grade > LOWEST_GRADE)
	{
		throw AForm::GradeTooLowException(validatedGradeName + " too low.");
	}
	return grade;
}

AForm::GradeException::GradeException( std::string const& message ) : message(message)
{}

const char*	AForm::GradeException::what() const noexcept
{
	return this->message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string const& message) : GradeException(message)
{}

AForm::GradeTooHighException::GradeTooHighException(std::string const& message) : GradeException(message)
{}
