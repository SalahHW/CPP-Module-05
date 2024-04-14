/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/12 22:23:32 by sbouheni         ###   ########.fr       */
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
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_exec;

public:
    Form();
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    Form(std::string name, int grade_to_sign, int grade_to_exec);
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Grade too high !";
        }
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Grade too low !";
        }
    };

    const std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getSignStatus() const;
};

std::ostream &operator<<(std::ostream &output_stream, const Form &form);

#endif