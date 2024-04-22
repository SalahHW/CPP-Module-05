/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:43:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/22 18:09:06 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "../Bureaucrat/Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const int requiredGradeToSign;
	const int requiredGradeToExecute;
	bool isSigned;

public:
	AForm();
	virtual ~AForm();
	AForm(AForm const &);
	AForm &operator=(AForm const &);

	AForm(std::string const &name, int requiredGradeToSign, int requiredGradeToExecute);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	// Getters
	std::string const &getName() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExecute() const;
	bool getSignStatus() const;

	// Functions
	void beSigned(Bureaucrat const &);
	void execute(Bureaucrat const &) const;
	virtual void performAction() const = 0;
};

// Overloads
std::ostream &operator<<(std::ostream &stream, AForm const &form);

#endif
