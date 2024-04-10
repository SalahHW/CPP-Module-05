/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/10 15:31:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat()
    : name("Undefined"), grade(150)
{
    std::cout << "Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << this->name << " constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat " << this->name << " copied\n";
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
    std::cout << "Bureaucrat " << name << " destroyed\n";
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
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}