/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:23:27 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/27 16:29:39 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    return ;
}

Intern::~Intern()
{
    return ;
}

Intern::Intern(Intern &other)
{
    *this = other;
    return ;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    std::string form_Names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    int j = 0;
    while (i < 3)
    {
        while (!formName.compare(form_Names[i]))
        {
            j = i + 1;
            break;
        }
        i++;
    }
    switch (j)
        {
        case 1:
        {
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << formName << std::endl;
            break;
        }
        case 2:
        {
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << formName << std::endl;
            break;
        }
        case 3:
        {
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << formName << std::endl;
            break;
        }       
        default:
        {
            std::cout << "Intern can't create " << formName << " Intern not available!" << std::endl;
            break;
        }
        }
    return (form);
}    
    