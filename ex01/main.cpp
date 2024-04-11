/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/11 04:41:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    // Bureaucrat undefined;
    Bureaucrat salah("Salah", 1);
    Bureaucrat joakoeni("Joakoeni", 150);

    std::cout << salah;
    std::cout << joakoeni;

    try
    {
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