/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 04:11:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/17 04:15:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Robotomy", 25, 5),
      target("Undefined")
{
  std::cout << this->getName() << " form constructed" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << this->getName() << " form destructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()),
      target(other.target)
{
  std::cout << this->getName() << " copied" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
  this->target = other.target;
  return *this;
}