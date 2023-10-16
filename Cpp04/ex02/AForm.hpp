/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:04:56 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/16 15:06:53 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _signed;
        int         const   _gradeToSign;
        int         const   _gradeToExecute;
    public:
        AForm();
        AForm(std::string const name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        ~AForm();
        AForm &operator=(const AForm &other);
        std::string const getName() const;
        bool    getSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecute() const;
        void    beSigned(Bureucrat &bureaucrat);
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &in);

#endif