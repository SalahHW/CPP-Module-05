/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:32:11 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/22 18:09:41 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "../AForm/AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm();
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

    ShrubberyCreationForm(std::string const &);

    // Functions
    virtual void performAction() const;
};

#endif