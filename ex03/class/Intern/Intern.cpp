/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:32:16 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/23 19:20:11 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    formNames[0] = "ShrubberyCreationForm";
    formNames[1] = "RobotomyRequestForm";
    formNames[2] = "PresidentialPardonForm";
    formCreationFunctions[0] = &Intern::makeShrubberyCreationForm;
    formCreationFunctions[1] = &Intern::makeRobotomyRequestForm;
    formCreationFunctions[2] = &Intern::makePresidentialPardonForm;
}

Intern::~Intern() {}

Intern::Intern(Intern const &other)
{
    formNames[0] = other.formNames[0];
    formNames[1] = other.formNames[1];
    formNames[2] = other.formNames[2];
    formCreationFunctions[0] = other.formCreationFunctions[0];
    formCreationFunctions[1] = other.formCreationFunctions[1];
    formCreationFunctions[2] = other.formCreationFunctions[2];
}

Intern &Intern::operator=(Intern const &other)
{
    if (this != &other)
    {
        formNames[0] = other.formNames[0];
        formNames[1] = other.formNames[1];
        formNames[2] = other.formNames[2];
        formCreationFunctions[0] = other.formCreationFunctions[0];
        formCreationFunctions[1] = other.formCreationFunctions[1];
        formCreationFunctions[2] = other.formCreationFunctions[2];
    }
    return (*this);
}

// Exceptions
const char *Intern::NotFoundFormException::what() const throw()
{
    return ("Form doesn't exist");
}

// Private Functions
AForm *Intern::makeShrubberyCreationForm(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

int Intern::getFormId(std::string const &name)
{
    for (int i = 0; i < formCount; i++)
    {
        if (formNames[i] == name)
            return (i);
    }
    throw NotFoundFormException();
}

// Functions
AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    int id;
    try
    {
        id = getFormId(name);
        std::cout << "Intern creates " << name << std::endl;
        return ((this->*formCreationFunctions[id])(target));
    }
    catch (const std::exception &e)
    {
        std::cerr << "Intern can't create " << name << " because : " << e.what() << std::endl;
        return (NULL);
    }
}