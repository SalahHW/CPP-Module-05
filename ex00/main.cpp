/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/08 18:52:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat undefined;
    Bureaucrat salah("Salah", 1);
    
    std::cout << "Bureaucrat name : " << undefined.getName() << " have grade "
              << undefined.getGrade() << "\n";

    std::cout << "Bureaucrat name : " << salah.getName() << " have grade "
              << salah.getGrade() << "\n";

    undefined = salah;
    std::cout << "Bureaucrat name : " << undefined.getName() << " have grade "
              << undefined.getGrade() << "\n";
    undefined = undefined;
    std::cout << "Bureaucrat name : " << undefined.getName() << " have grade "
              << undefined.getGrade() << "\n";
    return (0);
}