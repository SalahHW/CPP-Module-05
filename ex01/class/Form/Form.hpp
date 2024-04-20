/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:43:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/20 06:37:19 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Form
{
private:
    const std::string name;
    const int requiredGradeToSign;
    const int requiredGradeToExecute;
    bool isSigned;

public:
    Form();
    ~Form();
    Form(Form const &);
    Form &operator=(Form const &);

    Form(std::string const &name, int requiredGradeToSign, int requiredGradeToExecute);

    std::string const& getName() const;
    int getRequiredGradeToSign() const;
    int getRequiredGradeToExecute() const;
    bool getSignStatus() const;

    // Exceptions
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, Form const& form);
#endif