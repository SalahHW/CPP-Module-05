/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:41 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/17 04:06:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
    : name("Undifined"),
      is_signed(false),
      grade_to_sign(1),
      grade_to_exec(1)
{
    std::cout << this->name << " form constructed" << std::endl;
}

AForm::~AForm()
{
    std::cout << this->name << " form destructed" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name),
      is_signed(other.is_signed),
      grade_to_sign(other.grade_to_sign),
      grade_to_exec(other.grade_to_exec)
{
    std::cout << "AForm" << this->name << " copied" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    this->is_signed = other.is_signed;
    return *this;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec)
    : name(name),
      is_signed(false),
      grade_to_sign(grade_to_sign),
      grade_to_exec(grade_to_exec)
{
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw AForm::GradeTooLowException();
    std::cout << this->name << " form constructed" << std::endl;
}

const std::string AForm::getName() const
{
    return (this->name);
}

int AForm::getGradeToSign() const
{
    return (this->grade_to_sign);
}

int AForm::getGradeToExec() const
{
    return (this->grade_to_exec);
}

bool AForm::getSignStatus() const
{
    return (this->is_signed);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->grade_to_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output_stream, const AForm &form)
{
    output_stream << form.getName()
                  << ", form grade to sign is "
                  << form.getGradeToSign()
                  << " and grade to execute is "
                  << form.getGradeToExec()
                  << ". The form is actually ";
    if (form.getSignStatus())
        output_stream << "signed." << std::endl;
    else
        output_stream << "not signed." << std::endl;

    return (output_stream);
}