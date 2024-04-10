/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/10 15:33:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat undefined;
    Bureaucrat salah("Salah", 1);
    try
    {
        Bureaucrat joakoeni("Joakoeni", 150);
        joakoeni.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "Bureaucrat name : " << undefined.getName() << " have grade "
              << undefined.getGrade() << "\n";

    std::cout << "Bureaucrat name : " << salah.getName() << " have grade "
              << salah.getGrade() << "\n";

    undefined = salah;
    std::cout << "Bureaucrat name : " << undefined.getName() << " have grade "
              << undefined.getGrade() << "\n";

    try
    {
        salah.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}