/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/20 06:32:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Bureaucrat/Bureaucrat.hpp"

int main(void)
{
    std::string name;
    
    try
    {
        // Bureaucrat wrong_grade("Wrong", 195);
        // Bureaucrat wrong_grade2("Grade", -2147483646);
        Bureaucrat salah("Salah", 1);
        Bureaucrat joakoeni("Joakoeni", 150);
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