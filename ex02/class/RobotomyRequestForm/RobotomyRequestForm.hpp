/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:35:28 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/21 06:19:12 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "../AForm/AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &);

    RobotomyRequestForm(std::string const &);

    // Functions
    virtual void performAction() const;
};

#endif