/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/19 06:57:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Bureaucrat.hpp"

int main(void)
{
    try
    {
        // Bureaucrat wrong_grade("Wrong", 195);
        // Bureaucrat wrong_grade2("Grade", -2147483646);
        Bureaucrat salah("Salah", 1);
        Bureaucrat joakoeni("Joakoeni", 150);
        std::cout << salah;
        std::cout << joakoeni;
        joakoeni.incrementGrade();
        std::cout << joakoeni;
        salah.incrementGrade();
        std::cout << salah;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}