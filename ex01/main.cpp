/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/12 01:46:49 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // Bureaucrat undefined;
    Bureaucrat salah("Salah", 1);
    Bureaucrat joakoeni("Joakoeni", 150);
    Form s12("12S", 2, 1);

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