#include <fstream>
#include <random>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const char*	ShrubberyCreationForm::NAME = "ShrubberyCreationForm";
const int	ShrubberyCreationForm::GRADE_TO_SIGN = 145;
const int	ShrubberyCreationForm::GRADE_TO_EXECUTE = 137;

ShrubberyCreationForm::ShrubberyCreationForm()
	:
	AForm(ShrubberyCreationForm::NAME, ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXECUTE),
	_target("")
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target )
	:
	AForm(ShrubberyCreationForm::NAME, ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXECUTE),
	_target(target)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &other )
	:
	AForm(other),
	_target(other.getTarget())
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	#endif
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const & )
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	#endif
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	#endif
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile(this->getTarget() + "_shrubbery");
	if (!outfile.is_open())
	{
		throw std::runtime_error("Could not open file");
	}

	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	distrib(0, 5);

	int	random_value = distrib(gen);

	switch (random_value)
	{
	case Sapling:
		outfile << "  ^\n / \\\n/___\\\n  |\n";
		break;
	case Classic:
		outfile << "   ^\n  ^^^\n ^^^^^\n^^^^^^^\n   |\n";
		break;
	case Stacked:
		outfile <<	"    *\n"
						"   ***\n"
						"  *****\n"
						" *******\n"
						"*********\n"
						"   |||\n";
		break;
	case Pyramid:
		outfile <<	"      /\\\n"
						"     /  \\\n"
						"    /++++\\\n"
						"   /  ++  \\\n"
						"  /  ++++  \\\n"
						" /++++++++\\\n"
						"/    ++    \\\n"
						"/++++++++++\\\n"
						"      ||\n";
		break;
	case Pine:
		outfile <<	"     /\\\n"
				"    /  \\\n"
				"   / /\\ \\\n"
				"  / /  \\ \\\n"
				" /_/____\\_\\\n"
				"    ||||\n";
		break;
	default:
		outfile <<	"     *\n"
						"    /#\\\n"
						"   /###\\\n"
						"  /-o-#-\\\n"
						" /##-o-##\\\n"
						"/#-O-###-#\\\n"
						"    |||\n";
		break;
	}
	outfile.close();
}

std::ostream &operator<<( std::ostream& os, ShrubberyCreationForm const& other )
{
	os << "\n------------------------------\n";
	os << " ShrubberyCreationForm Information\n";
	os << "------------------------------\n";
	os << " Name:           " << other.getName() << "\n";
	os << " Target:         " << other.getTarget() << "\n";
	os << " Grade to sign:  " << static_cast<unsigned int>(other.getGradeToSign()) << "\n";
	os << " Grade to exec:  " << static_cast<unsigned int>(other.getGradeToExecute()) << "\n";
	os << " Signed:         " << (other.isSigned() ? "Yes" : "No") << "\n";
	os << "------------------------------\n";
	return os;
}

std::string const&	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}
