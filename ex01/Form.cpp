/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:41 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/12 01:43:22 by sbouheni         ###   ########.fr       */
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
    std::cout << this->name << " form constructed" << std::endl;
}