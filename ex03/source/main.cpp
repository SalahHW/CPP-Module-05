/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/22 17:20:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Bureaucrat/Bureaucrat.hpp"
#include "../class/AForm/AForm.hpp"
#include "../class/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../class/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../class/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "../class/Intern/Intern.hpp"

int main(void)
{
    std::string name;
    
    try
    {
        AForm *basket;
        Intern richard;
        Bureaucrat salah("Salah", 1);

        basket = richard.makeForm("ShrubberyCreationForm", "Desktop");
        if (!basket)
            return (1);
        std::cout << *basket << std::endl;
        // salah.signForm(*basket);
        salah.executeForm(*basket);
        if (basket)
            delete basket;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
