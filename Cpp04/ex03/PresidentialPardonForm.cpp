/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/23 12:06:42 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Undefined Target")
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm(other)
{
    *this = other;
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

std::string const PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::action() const
{
    std::cout << PresidentialPardonForm::getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}