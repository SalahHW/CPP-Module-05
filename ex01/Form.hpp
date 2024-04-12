/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/12 01:44:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

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
};

#endif