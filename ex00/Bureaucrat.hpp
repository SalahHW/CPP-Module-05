/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:46:52 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/09 00:55:02 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private :
        const std::string   name;
        int                 grade;
    public :
        // Constructors
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        
        // Assignation operator
        Bureaucrat& operator=(const Bureaucrat &other);
        
        //Destructor
        ~Bureaucrat();

        // Exceptions
        
        // Getters
        const std::string getName() const;
        int getGrade() const;
};

#endif