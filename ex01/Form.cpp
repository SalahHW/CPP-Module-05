/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:41 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/12 22:31:52 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Undifined"),
               is_signed(false),
               grade_to_sign(1),
               grade_to_exec(1)
{
    std::cout << this->name << " form constructed" << std::endl;
}

Form::~Form()
{
    std::cout << this->name << " form destructed" << std::endl;
}

Form::Form(const Form &other) : name(other.name),
                                is_signed(other.is_signed),
                                grade_to_sign(other.grade_to_sign),
                                grade_to_exec(other.grade_to_exec)
{
    std::cout << "Form" << this->name << " copied" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    this->is_signed = other.is_signed;
    return *this;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) : name(name),
                                                                     is_signed(false),
                                                                     grade_to_sign(grade_to_sign),
                                                                     grade_to_exec(grade_to_exec)
{
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw Form::GradeTooLowException();
    std::cout << this->name << " form constructed" << std::endl;
}

const std::string Form::getName() const
{
    return (this->name);
}

int Form::getGradeToSign() const
{
    return (this->grade_to_sign);
}

int Form::getGradeToExec() const
{
    return (this->grade_to_exec);
}

bool Form::getSignStatus() const
{
    return (this->is_signed);
}

std::ostream &operator<<(std::ostream &output_stream, const Form &form)
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