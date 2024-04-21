/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:43:44 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 14:21:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
    : name("Undefined"),
      requiredGradeToSign(1),
      requiredGradeToExecute(1),
      isSigned(false)
{
}

AForm::~AForm() {}

AForm::AForm(AForm const &other)
    : name(other.name),
      requiredGradeToSign(other.requiredGradeToSign),
      requiredGradeToExecute(other.requiredGradeToExecute),
      isSigned(other.isSigned)
{
}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

AForm::AForm(std::string const &name, int requiredGradeToSign, int requiredGradeToExecute)
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
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
const char *AForm::AlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}
const char *AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed");
}

// Getters
std::string const &AForm::getName() const
{
    return (this->name);
}

int AForm::getRequiredGradeToSign() const
{
    return (this->requiredGradeToSign);
}

int AForm::getRequiredGradeToExecute() const
{
    return (this->requiredGradeToExecute);
}

bool AForm::getSignStatus() const
{
    return (this->isSigned);
}

// Functions
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (isSigned)
        throw AlreadySignedException();
    if (requiredGradeToSign < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw NotSignedException();
    if (executor.getGrade() > requiredGradeToExecute)
        throw GradeTooLowException();
    performAction();
}

// Overloads
std::ostream &operator<<(std::ostream &stream, AForm const &form)
{
    stream << form.getName() << " form has a grade required to sign of "
           << form.getRequiredGradeToSign() << " and a grade required to execute of "
           << form.getRequiredGradeToExecute() << ". The form is ";
    if (!form.getSignStatus())
        stream << "not ";
    stream << "signed";
    return (stream);
}
