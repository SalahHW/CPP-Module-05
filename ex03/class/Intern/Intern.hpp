/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:32:13 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/23 19:15:40 by sbouheni         ###   ########.fr       */
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

class Intern
{
private:
    static const int formCount = 3;
    std::string formNames[formCount];
    AForm *(Intern::*formCreationFunctions[formCount])(std::string const&);

    // Functions
    AForm *makeShrubberyCreationForm(std::string const &target);
    AForm *makeRobotomyRequestForm(std::string const &target);
    AForm *makePresidentialPardonForm(std::string const &target);
    int getFormId(std::string const &name);

public:
    Intern();
    ~Intern();
    Intern(Intern const &);
    Intern &operator=(Intern const &);

    // Exceptions
    class NotFoundFormException : public std::exception
    {
        const char *what() const throw();
    };

    // Functions
    AForm *makeForm(std::string const &, std::string const &);
};

#endif