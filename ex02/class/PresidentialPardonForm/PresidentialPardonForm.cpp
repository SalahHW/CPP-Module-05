/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:37:40 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/20 23:47:32 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("Undefined target") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

// Functions
void PresidentialPardonForm::performAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}
