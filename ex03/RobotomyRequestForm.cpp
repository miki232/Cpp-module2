/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:02:10 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/23 12:07:11 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Undefined Target")
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm(other)
{
    *this = other;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

std::string const RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void RobotomyRequestForm::action() const
{
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << this->_target << " robotomization failed." << std::endl;
}