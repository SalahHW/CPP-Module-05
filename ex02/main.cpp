/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/15 13:45:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    // Bureaucrat undefined;
    Bureaucrat salah("Salah", 10);
    Bureaucrat joakoeni("Joakoeni", 150);
    AForm s12("12S", 9, 9);
    std::cout << s12;
    salah.signForm(s12);
    std::cout << s12;
    salah.incrementGrade();
    salah.signForm(s12);
    std::cout << s12;

    try
    {
        std::cout << s12;
        s12.beSigned(salah);
        std::cout << s12;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}