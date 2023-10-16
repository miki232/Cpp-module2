/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:10:52 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/16 14:35:40 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm " << this->_name << " has been created" << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw (AForm::GradeTooHighException());
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw (AForm::GradeTooLowException());
    else
        std::cout << "AForm " << this->_name << " has been created with " << this->_gradeToSign << " grade to sign and " << this->_gradeToExecute << " grade to execute" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm " << this->_name << " has been destroyed" << std::endl;
}

std::string const AForm::getName() const
{
    return (this->_name);
}

int     AForm::getGradeToExecute()const
{
    return (this->_gradeToExecute);
}

int     AForm::getGradeToSign()const
{
    return (this->_gradeToSign);
}

bool    AForm::getSigned()const
{
    return (this->_signed);
}

void    AForm::beSigned(Bureucrat &bureucrat)
{
    if (bureucrat.getGrade() > this->_gradeToSign)
        throw (AForm::GradeTooLowException());
    else
        this->_signed = true;
}

const   char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const   char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream & operator<<(std::ostream & out, AForm const & in)
{
    out << "AForm " << in.getName() << " is ";
    if (in.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires " << in.getGradeToSign() << " grade to sign and " << in.getGradeToExecute() << " grade to execute" << std::endl;
    return (out);
}