/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/15 00:56:28 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "../Bureaucrat/Bureaucrat.hpp"
#include <iostream>
#include <exception>

class AForm
{
private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_exec;

public:
    AForm();
    ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    AForm(std::string name, int grade_to_sign, int grade_to_exec);
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

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &output_stream, const AForm &form);

#endif