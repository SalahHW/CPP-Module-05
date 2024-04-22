/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:32:16 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/22 17:09:07 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    formMap["ShrubberyCreationForm"] = &Intern::makeShrubberyCreationForm;
    formMap["RobotomyRequestForm"] = &Intern::makeRobotomyRequestForm;
    formMap["PresidentialPardonForm"] = &Intern::makePresidentialPardonForm;
}

Intern::~Intern() {}

Intern::Intern(Intern const &other) 
{
    (void) other;
}

Intern &Intern::operator=(Intern const &other) 
{
    (void) other;
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

void Intern::validFormName(std::string const &name)
{
    if (formMap.find(name) == formMap.end())
        throw NotFoundFormException();
}

// Functions
AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    try
    {
        validFormName(name);
        std::cout << "Intern creates " << name << std::endl;
        return ((this->*(formMap[name]))(target));
    }
    catch(const std::exception& e)
    {
        std::cerr << "Intern can't create " << name << " because : " << e.what() << std::endl;
        return (NULL);
    }
}