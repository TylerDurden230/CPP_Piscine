#include "Bureaucrat.hpp"
#include "Form.hpp"

		Bureaucrat::Bureaucrat() : _name("Bureau"), _grade(1)
        {
            std::cout << "Default's Construcrtor Called" << std::endl;
        }
        
        Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
        {
            *this = rhs;
        }

        Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
        {
            if (grade < 1)
                throw GradeTooHighException();
            else if (grade > 150)
                throw GradeTooLowException();
            else
            std::cout << MAGENTA << "Construcrtor Called for Bureaucrat " << _name << RESET << std::endl;
        }

		Bureaucrat::~Bureaucrat()
        {
            std::cout << "Destrucrtor Called for Bureaucrat " << _name << std::endl;
        }

		Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
        {
            this->_grade = rhs._grade;
            return *this;
        }

		std::string     Bureaucrat::getName() const
        {
            return this->_name;
        }

		int				Bureaucrat::getGrade() const
        {
            return  this->_grade;
        }

        void	Bureaucrat::increment()
        {
            if (this->_grade == 1)
                throw Bureaucrat::GradeTooHighException();
            else
            {
                this->_grade--;
                std::cout << _name << ": Grade Incremented" << std::endl;
            }
        }

		void	Bureaucrat::decrement()
        {
            if (this->_grade == 150)
                throw Bureaucrat::GradeTooLowException();
            else
            {
                this->_grade++;
                std::cout << _name << ": Grade Decremented" << std::endl;
            }
        }

        void	Bureaucrat::signForm(Form & f)
        {
            try 
            {
                f.beSigned(*this);
                std::cout << MAGENTA << this->getName() << " signs " << f.getName() << " Form " << RESET << std::endl;
            }
            catch (std::exception &e) 
            {
                std::cout << RED << this->getName() << " cannot sign " << f.getName() << " Form because of " << RESET;
                std::cout << e.what() << std::endl;
            }
        }

        void	Bureaucrat::executeForm(Form const & form)
        {
            std::cout << MAGENTA << "Bureaucrat " << this->_name << " is trying to execute " << form.getName() << " Form" << RESET << std::endl; 
            if (form.checkFormSignedStatus())
                try
                {
                    form.execute(*this);
                    std::cout << GREEN << this->_name << " executes " << form.getName() << RESET << std::endl;
                }
                catch(const std::exception& e)
                {
                    std::cout << RED << this->_name << " can't execute " << form.getName() << RESET << std::endl;
                    std::cerr << e.what() << std::endl;
                }
            else
                std::cout << RED << "This form has to be signed to be executed" << RESET << std::endl;
            
        }

        std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
        {
            return out << "Bureaucrat Name: " << rhs.getName() << ", grade: " << rhs.getGrade();
        }