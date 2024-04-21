/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 06:37:51 by sbouheni         ###   ########.fr       */
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
        // Form wrongForm("Wrong", 134334, -23423);
        ShrubberyCreationForm bar;
        PresidentialPardonForm foo("Richard");
        RobotomyRequestForm robot("Elias");
        salah.signForm(foo);
        foo.execute(salah);
        salah.signForm(robot);
        robot.execute(salah);
        // ShrubberyCreationForm zip;
        std::cout << bar << std::endl;
        salah.signForm(bar);
        std::cout << bar << std::endl;
        // std::cout << zip << std::endl;
        ShrubberyCreationForm zip(bar);
        // zip = bar;
        std::cout << zip << std::endl;
        std::cout << salah << std::endl;
        std::cout << joakoeni << std::endl;
        joakoeni.incrementGrade();
        std::cout << joakoeni << std::endl;
        salah.decrementGrade();
        std::cout << salah << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
