/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:52 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 14:08:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../AForm/AForm.hpp"
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const &);
    Bureaucrat &operator=(Bureaucrat const &);

    Bureaucrat(std::string const &name, int grade);

    // Exceptions
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    // Getters
    std::string const &getName() const;
    int getGrade() const;

    // Functions
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &);
    void executeForm(AForm const &) const;
};

// Overloads
std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &bureaucrat);

#endif