/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:35:26 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 06:19:42 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "../AForm/AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &);

	PresidentialPardonForm(std::string const &);

	// Functions
	virtual void performAction() const;
};

#endif
