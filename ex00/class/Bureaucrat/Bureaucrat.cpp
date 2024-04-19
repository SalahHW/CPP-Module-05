/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/19 10:29:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name("Undefined"), grade(150)
{
    std::cout << this->name << " bureaucrat, constructed" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->name << " bureaucrat, destructed" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : name(other.name), grade(other.grade)
{
    std::cout << other.name << " bureaucrat, copied" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->name << " bureaucrat, constructed" << std::endl;
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade is too high !");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade is too low !");
}

// Getters
std::string const &Bureaucrat::getName() const
{
    return (this->name);
}
int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
    std::cout << this->name << " grade have been incremented to "
              << this->grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
    std::cout << this->name << " grade have been decremented to "
              << this->grade << std::endl;
}

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &bureaucrat)
{
    output_stream << bureaucrat.getName() << ", bureaucrat grade "
                  << bureaucrat.getGrade() << "." << std::endl;
    return (output_stream);
}