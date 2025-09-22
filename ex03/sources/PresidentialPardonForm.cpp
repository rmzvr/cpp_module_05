#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

const char*	PresidentialPardonForm::NAME = "PresidentialPardonForm";
const int	PresidentialPardonForm::GRADE_TO_SIGN = 25;
const int	PresidentialPardonForm::GRADE_TO_EXECUTE = 5;

PresidentialPardonForm::PresidentialPardonForm()
	:
	AForm(PresidentialPardonForm::NAME, PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXECUTE),
	_target("")
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm( std::string const& target )
	:
	AForm(PresidentialPardonForm::NAME, PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXECUTE),
	_target(target)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &other )
	:
	AForm(other),
	_target(other.getTarget())
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	#endif
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const & )
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	#endif
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
	#endif
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<( std::ostream& os, PresidentialPardonForm const& other )
{
	os << "\n------------------------------\n";
	os << " PresidentialPardonForm Information\n";
	os << "------------------------------\n";
	os << " Name:           " << other.getName() << "\n";
	os << " Target:         " << other.getTarget() << "\n";
	os << " Grade to sign:  " << static_cast<unsigned int>(other.getGradeToSign()) << "\n";
	os << " Grade to exec:  " << static_cast<unsigned int>(other.getGradeToExecute()) << "\n";
	os << " Signed:         " << (other.isSigned() ? "Yes" : "No") << "\n";
	os << "------------------------------\n";
	return os;
}

std::string const&	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}
