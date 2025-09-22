#include <random>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

const char*	RobotomyRequestForm::NAME = "RobotomyRequestForm";
const int	RobotomyRequestForm::GRADE_TO_SIGN = 72;
const int	RobotomyRequestForm::GRADE_TO_EXECUTE = 45;

RobotomyRequestForm::RobotomyRequestForm()
	:
	AForm(RobotomyRequestForm::NAME, RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXECUTE),
	_target("")
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm( std::string const& target )
	:
	AForm(RobotomyRequestForm::NAME, RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXECUTE),
	_target(target)
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &other )
	:
	AForm(other),
	_target(other.getTarget())
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	#endif
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const & )
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	#endif
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
	#endif
}

void RobotomyRequestForm::executeAction() const
{
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	distrib(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE);

	int	random_value = distrib(gen);
	std::cout << "\n* Initiating robotomy sequence... *\n";
	std::cout << "BZZZZZZZ... VRRRRRR... *drilling noises*\n\n";
	if (random_value == MIN_RANDOM_VALUE)
	{
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << "'s robotomy failed" << std::endl;
	}
}

std::ostream &operator<<( std::ostream& os, RobotomyRequestForm const& other )
{
	os << "\n------------------------------\n";
	os << " RobotomyRequestForm Information\n";
	os << "------------------------------\n";
	os << " Name:           " << other.getName() << "\n";
	os << " Target:         " << other.getTarget() << "\n";
	os << " Grade to sign:  " << static_cast<unsigned int>(other.getGradeToSign()) << "\n";
	os << " Grade to exec:  " << static_cast<unsigned int>(other.getGradeToExecute()) << "\n";
	os << " Signed:         " << (other.isSigned() ? "Yes" : "No") << "\n";
	os << "------------------------------\n";
	return os;
}

std::string const&	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}
