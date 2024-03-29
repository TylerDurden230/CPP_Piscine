#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


class Form {
	private:
		const std::string _name;
		bool              _signed;
		const int         _reqGradeToSign;
		const int         _reqGradeToExec;
	public:
		Form();
		~Form();
		Form(const Form& rhs);
		Form &operator=(const Form& rhs);
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec);
		std::string		getName() const;
		bool			getSigned() const;
		int				getreqGradeToSign() const;
		int				getreqGradeToExec() const;
		void			beSigned(const Bureaucrat& b);
		class 			GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Exception: Grade too High";
			}
		};
		class 			GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Exception: Grade too Low";
			}
		};
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif