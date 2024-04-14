/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/15 01:48:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat()
    : name("Undefined"), grade(150)
{
    std::cout << "Bureaucrat constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << this->name << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat " << this->name << " copied" << std::endl;
}

// Assignation operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->grade = other.grade;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << " destroyed" << std::endl;
}

// Getters
const std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
    std::cout << this->name << " grade have been incremented" << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
    std::cout << this->name << " grade have been decremented" << std::endl;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName()
        << " signed "
        << form.getName()
        << "."
        << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->getName()
                  << " couldn't sign "
                  << form.getName()
                  << " because "
                  << e.what()
                  << "."
                  << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &bureaucrat)
{
    output_stream << bureaucrat.getName()
                  << ", bureaucrat grade "
                  << bureaucrat.getGrade()
                  << "."
                  << std::endl;
    return (output_stream);
}