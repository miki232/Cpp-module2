/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:14:02 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/23 12:09:35 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureucrat prot("Prot", 4);
	Bureucrat top("Top", 73);
	PresidentialPardonForm bau("bau");
	RobotomyRequestForm miao("miao");
	ShrubberyCreationForm chip("Garden");

	std::cout << std::endl << std::endl;
	prot.executeForm(chip);
	chip.beSigned(prot);
	prot.executeForm(chip);
	top.executeForm(chip);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	prot.executeForm(miao);
	miao.beSigned(prot);
	prot.executeForm(miao);
	prot.executeForm(miao);
	top.executeForm(miao);
	top.executeForm(miao);
	std::cout << std::endl << std::endl;

	prot.executeForm(bau);
	bau.beSigned(prot);
	prot.executeForm(bau);
	std::cout << std::endl;
	top.executeForm(bau);
	std::cout << std::endl << std::endl;
	return (0);
}
