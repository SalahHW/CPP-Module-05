/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:32:13 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/22 16:43:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "../AForm/AForm.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>
#include <map>

class Intern
{
private:
    std::map<std::string, AForm *(Intern::*)(std::string const &)> formMap;

    // Functions
    AForm *makeShrubberyCreationForm(std::string const &target);
    AForm *makeRobotomyRequestForm(std::string const &target);
    AForm *makePresidentialPardonForm(std::string const &target);
    void validFormName(std::string const &name);

public:
    Intern();
    ~Intern();
    Intern(Intern const &);
    Intern &operator=(Intern const &);

    // Exceptions
    class NonExistingFormException : public std::exception
    {
        const char *what() const throw();
    };

    // Functions
    AForm *makeForm(std::string const &, std::string const &);
};

#endif