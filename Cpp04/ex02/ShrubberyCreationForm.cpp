/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:24:34 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/23 11:54:48 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined Target")
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm(other)
{
    *this = other;
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

std::string const ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void ShrubberyCreationForm::action() const
{
    std::string file = this->_target + "_shrubbery";
    std::ofstream shrubbery_file(file.c_str());

    shrubbery_file << "       _-_" << std::endl;
    shrubbery_file << "    /~~   ~~\\" << std::endl;
    shrubbery_file << " /~~         ~~\\" << std::endl;
    shrubbery_file << "{               }" << std::endl;
    shrubbery_file << " \\  _-     -_  /" << std::endl;
    shrubbery_file << "   ~  \\\\ //  ~" << std::endl;
    shrubbery_file << "_- -   | | _- _" << std::endl;
    shrubbery_file << "  _ -  ___   -_" << std::endl;

    shrubbery_file.close();    
}