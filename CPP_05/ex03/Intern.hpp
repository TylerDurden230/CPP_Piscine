#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
    public:
	Intern();
	~Intern();
	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);

	Form* makeForm(std::string formName, std::string formTarget);
	Form* createPresidentialPardon(std::string formTarget);
	Form* createRobotomyRequest(std::string formTarget);
	Form* createShrubberyCreation(std::string formTarget);

    // createFormFunction punta a una member function di Intern che prende (std::string) come parametro
    typedef Form* (Intern::*createFormFunction)(std::string formTarget);
};

#endif