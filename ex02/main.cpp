/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:57 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/17 03:51:11 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/AForm/AForm.hpp"
#include "class/AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "class/Bureaucrat/Bureaucrat.hpp"

int main(void)
{
  Bureaucrat salah("Salah", 15);
  ShrubberyCreationForm("home");

  return (0);
}