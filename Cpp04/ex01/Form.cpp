/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:10:52 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/16 14:35:40 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form " << this->_name << " has been created" << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw (Form::GradeTooHighException());
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw (Form::GradeTooLowException());
    else
        std::cout << "Form " << this->_name << " has been created with " << this->_gradeToSign << " grade to sign and " << this->_gradeToExecute << " grade to execute" << std::endl;
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

std::string const Form::getName() const
{
    return (this->_name);
}

int     Form::getGradeToExecute()const
{
    return (this->_gradeToExecute);
}

int     Form::getGradeToSign()const
{
    return (this->_gradeToSign);
}

bool    Form::getSigned()const
{
    return (this->_signed);
}

void    Form::beSigned(Bureucrat &bureucrat)
{
    if (bureucrat.getGrade() > this->_gradeToSign)
        throw (Form::GradeTooLowException());
    else
        this->_signed = true;
}

const   char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const   char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream & operator<<(std::ostream & out, Form const & in)
{
    out << "Form " << in.getName() << " is ";
    if (in.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires " << in.getGradeToSign() << " grade to sign and " << in.getGradeToExecute() << " grade to execute" << std::endl;
    return (out);
}