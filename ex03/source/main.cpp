/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/23 19:27:33 by sbouheni         ###   ########.fr       */
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
        Intern francis(richard);
        richard = francis;

        AForm *pardon = francis.makeForm("PresidentialPardonForm", "Jacques");
        AForm *lol = francis.makeForm("Patate", "four");
        basket = richard.makeForm("ShrubberyCreationForm", "Desktop");
        if (!basket)
            return (1);
        if (!pardon)
            return (1);
        std::cout << *basket << std::endl;
        if (lol)
            salah.signForm(*lol);
        salah.signForm(*basket);
        salah.signForm(*pardon);
        salah.executeForm(*basket);
        salah.executeForm(*pardon);
        if (basket)
            delete basket;
        if (pardon)
            delete pardon;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
