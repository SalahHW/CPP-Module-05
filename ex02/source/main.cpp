/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 14:25:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Bureaucrat/Bureaucrat.hpp"
#include "../class/AForm/AForm.hpp"
#include "../class/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../class/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../class/PresidentialPardonForm/PresidentialPardonForm.hpp"

int main(void)
{
    std::string name;
    
    try
    {
        Bureaucrat salah("Salah", 1);
        Bureaucrat joakoeni("Joakoeni", 150);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Richard");
        PresidentialPardonForm pardon("Richard");
        joakoeni.signForm(shrubbery);
        joakoeni.executeForm(shrubbery);
        salah.signForm(shrubbery);
        joakoeni.executeForm(shrubbery);
        salah.executeForm(shrubbery);
        salah.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
