/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:43:44 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/20 08:42:44 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : name("Undefined"),
      requiredGradeToSign(1),
      requiredGradeToExecute(1),
      isSigned(false)
{
}

Form::~Form() {}

Form::Form(Form const &other)
    : name(other.name),
      requiredGradeToSign(other.requiredGradeToSign),
      requiredGradeToExecute(other.requiredGradeToExecute),
      isSigned(other.isSigned)
{
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

Form::Form(std::string const &name, int requiredGradeToSign, int requiredGradeToExecute)
    : name(name),
      requiredGradeToSign(requiredGradeToSign),
      requiredGradeToExecute(requiredGradeToExecute),
      isSigned(false)
{
    if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
        throw GradeTooLowException();
    if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
        throw GradeTooHighException();
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
const char *Form::AlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

// Getters
std::string const &Form::getName() const
{
    return (this->name);
}

int Form::getRequiredGradeToSign() const
{
    return (this->requiredGradeToSign);
}

int Form::getRequiredGradeToExecute() const
{
    return (this->requiredGradeToExecute);
}

bool Form::getSignStatus() const
{
    return (this->isSigned);
}

// Functions
void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (isSigned)
        throw AlreadySignedException();
    if (requiredGradeToSign < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    isSigned = true;
    std::cout << name << " form has been signed by "
              << bureaucrat.getName() << " bureaucrat." << std::endl;
}

// Overloads
std::ostream &operator<<(std::ostream &stream, Form const &form)
{
    stream << form.getName() << " form has a grade required to sign of "
           << form.getRequiredGradeToSign() << " and a grade required to execute of "
           << form.getRequiredGradeToExecute() << ". The form is ";
    if (!form.getSignStatus())
        stream << "not ";
    stream << "signed";
    return (stream);
}