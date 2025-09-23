# C++ Module 05 – Bureaucrats and Forms (42 Cursus)

This module explores exception-safe C++, object relationships, inheritance, polymorphism, and a factory pattern through a Bureaucrat/Form workflow. It is part of the 42 school C++ curriculum and emphasizes robust design with clear error handling.

## Educational Purpose (42 Program)
- Practice designing and propagating typed exceptions
- Enforce class invariants (grade ranges, signed state)
- Apply inheritance and pure virtual functions for polymorphic behavior
- Use a factory (Intern) with member function pointers
- Follow the Orthodox Canonical Form across classes

## Exercise goals and takeaways

### ex00 — Bureaucrat: invariants and typed exceptions
- Goals
  - Model a class with strict invariants (grade 1..150)
  - Throw precise exceptions on invalid state transitions
  - Practice Orthodox Canonical Form (ctor/copy/assign/dtor)
- What you practice
  - Validating inputs both in constructors and mutators
  - Writing a custom exception hierarchy with useful messages
  - Operator<< for readable diagnostics
- Why it’s useful
  - Real systems rely on defensive programming around invariants
  - Clear, typed failures speed up debugging and testing
- Tiny snippet (real code)
```cpp
void Bureaucrat::setGrade(int const& grade) {
    if (grade < HIGHEST_GRADE) throw Bureaucrat::GradeTooHighException("Grade too high.");
    if (grade > LOWEST_GRADE)  throw Bureaucrat::GradeTooLowException("Grade too low.");
    this->_grade = grade;
}
```

### ex01 — Form: cross-class collaboration and state
- Goals
  - Introduce a signable "Form" with required grades
  - Coordinate behavior between two classes via a clean API
  - Surface user-facing feedback on success/failure
- What you practice
  - Encapsulating state transitions (`beSigned`) with validation
  - Catching and reporting errors at the integration point
- Why it’s useful
  - Mirrors real approval workflows (permissions, preconditions)
  - Encourages clear error reporting paths
- Tiny snippet (real code)
```cpp
void Bureaucrat::signForm(Form &form) {
    try {
        if (form.beSigned(*this)) std::cout << getName() << " signed " << form.getName() << std::endl;
        else std::cout << "Form '" << form.getName() << "' is already signed.\n";
    } catch (const std::exception& e) {
        std::cerr << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
```

### ex02 — AForm: abstraction and safe execution
- Goals
  - Evolve Form into an abstract base with polymorphic execution
  - Enforce the contract: must be signed, and executor must be qualified
- What you practice
  - Designing an abstract interface (`executeAction`) and a safe template method (`execute`)
  - Throwing specific exceptions on contract violations
- Why it’s useful
  - Separates common checks from specialized behavior
  - Reduces duplication and centralizes safety checks
- Tiny snippet (real code)
```cpp
class AForm {
public:
    virtual void executeAction() const = 0;
    void execute(Bureaucrat const & executor) const; // performs checks, then calls executeAction
};
```

### ex03 — Intern: factory pattern with member function pointers
- Goals
  - Create forms by name using a single entry point
  - Map strings to constructors via member function pointers
- What you practice
  - Table-driven dispatch without long if/else or switch chains
  - Isolating creation logic and reporting unknown requests
- Why it’s useful
  - Extensible creation patterns seen in CLI tools, services, plugins
  - Simplifies client code and reduces coupling
- Tiny snippet (real code)
```cpp
AForm* Intern::makeForm(std::string const &name, std::string const &target) {
    std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*f[])(std::string const&) = {
        &Intern::_makeShrubberyCreationForm, &Intern::_makeRobotomyRequestForm, &Intern::_makePresidentialPardonForm
    };
    for (size_t i = 0; i < 3; ++i)
        if (types[i] == name) { std::cout << "Intern creates " << name << std::endl; return (this->*f[i])(target); }
    throw Intern::FormNotFoundException();
}
```

## Test Style and Ergonomics
- Colorized output for readability:
```cpp
#define RESET "\033[0m" // RED, GREEN, YELLOW, CYAN, MAGENTA, BOLD
```
- Top-level try/catch in mains to fail gracefully:
```cpp
int main() { try { /* run tests */ } catch (const std::exception& e) {
    std::cerr << "Caught exception in main: " << e.what() << '\n'; } }
```

## Build & Run
```bash
# Build and run each exercise
cd ex00 && make && ./ex00
cd ../ex01 && make && ./ex01
cd ../ex02 && make && ./ex02
cd ../ex03 && make && ./ex03

# Optional: debug build (adds -DDEBUG -g -O0)
make debug
```

---
All snippets above come directly from this repository and showcase the core ideas without unnecessary boilerplate.
