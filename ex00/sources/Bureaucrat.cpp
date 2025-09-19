#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("DefaultBureaucrat"), _grade(150)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat default constructor called" << std::endl;
	#endif
}

Bureaucrat::Bureaucrat( std::string const& name, int const& grade )
	: _name(name)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	#endif
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat( Bureaucrat const &other )
	: _name(other.getName()), _grade(other.getGrade())
{
	#ifdef DEBUG
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	#endif
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &other )
{
	#ifdef DEBUG
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->setGrade(other.getGrade());
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG
		std::cout << "Bureaucrat destructor called" << std::endl;
	#endif
}

void	Bureaucrat::setGrade( int const& grade )
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException("Grade too low.");
	}
	this->_grade = grade;
}

std::string const&	Bureaucrat::getName() const
{
	return this->_name;
}

uint8_t const&	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::increaseGrade()
{
	std::cout << "Increasing " << this->getName() << " grade." << std::endl;
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::decreaseGrade()
{
	std::cout << "Decreasing " << this->getName() << " grade." << std::endl;
	this->setGrade(this->getGrade() + 1);
}

std::ostream &operator<<( std::ostream &os, Bureaucrat const &other )
{
	os << other.getName() << ", bureaucrat grade " << static_cast<unsigned int>(other.getGrade()) << ".";
	return os;
}

Bureaucrat::GradeException::GradeException( std::string const& message ) : message(message)
{}

const char*	Bureaucrat::GradeException::what() const noexcept
{
	return this->message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &message) : GradeException(message)
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &message) : GradeException(message)
{}
