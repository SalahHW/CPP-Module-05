/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:00:07 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/17 03:34:31 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "../AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    ShrubberyCreationForm(const std::string &target);
    virtual void execute(Bureaucrat const &executor) const;

private:
    std::string target;
};

#endif