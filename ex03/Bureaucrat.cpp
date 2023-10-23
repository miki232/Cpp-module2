/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:23:39 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/23 12:01:42 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureucrat::Bureucrat() : _name("default")
{
    this->_grade = 150;
    std::cout << "Bureucrat " << this->_name << " has been created" << std::endl;
}

Bureucrat::Bureucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw (Bureucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureucrat::GradeTooLowException());
    else
    {
        this->_grade = grade;
        std::cout << "Bureucrat " << this->_name << " has been created with " << this->_grade << " grade" << std::endl;
    }
}

Bureucrat::Bureucrat(const Bureucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureucrat &Bureucrat::operator=(const Bureucrat &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

Bureucrat::~Bureucrat()
{
    std::cout << "Bureucrat " << this->_name << " has been destroyed" << std::endl;
}

std::string const &Bureucrat::getName() const
{
    return (this->_name);
}

int Bureucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw (Bureucrat::GradeTooHighException());
    else
    {
        std::cout << "Bureucrat " << this->_name << " has been promoted to " << this->_grade << " grade" << std::endl;
        this->_grade--;
    }
}

void Bureucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw (Bureucrat::GradeTooLowException());
    else
    {
        this->_grade++;
        std::cout << "Bureucrat " << this->_name << " has been demoted to " << this->getGrade() << " grade" << std::endl;
    }
}

void Bureucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

void    Bureucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " can not execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

const char *Bureucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream & operator<<(std::ostream & out, Bureucrat const & in)
{
    out << in.getName() << ", bureucrat grade " << in.getGrade() << std::endl;
    return (out);
}