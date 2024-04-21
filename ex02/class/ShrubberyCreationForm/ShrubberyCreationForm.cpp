/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:32:26 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 14:03:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

void ShrubberyCreationForm::performAction() const
{
    std::string fileName(target + "_shrubbery");
    std::ofstream file(fileName.c_str());
    if (!file.is_open())
        std::cerr << "Error while creating file " << fileName << std::endl;
    file << "            ,@@@@@@@,\n"
         << "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
         << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
         << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
         << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
         << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
         << "`&%\\ ` /%&'    |.|        \\ '|8'\n"
         << "    |o|        | |         | |\n"
         << "    |.|        | |         | |\n"
         << "  \\/ ._\\//_/__/  ,\\_//_ _\\/.  \\_//__/_" << std::endl;
    file.close();
}