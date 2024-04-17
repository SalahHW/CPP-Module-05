/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:45:44 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/17 04:02:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy", 72, 45),
      target("Undefined")
{
  std::cout << this->getName() << " form constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << this->getName() << " form destructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()),
      target(other.target)
{
  std::cout << this->getName() << " copied" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
  this->target = other.target;
  return *this;
}