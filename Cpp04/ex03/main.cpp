/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:14:02 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/27 16:29:25 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main () {

	Bureucrat bureaucrat("Sto Cazzo", 1);
	Intern someRandomIntern;
	AForm *rrf;
	AForm *ppf;
	AForm *scf;

	ppf = someRandomIntern.makeForm("presidential pardon", "Philip");
	rrf = someRandomIntern.makeForm("robotomy request", "Sheldon");
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	someRandomIntern.makeForm("Daje Roma", "JAJAJAHOOo");
	bureaucrat.signForm(*ppf);
	bureaucrat.executeForm(*ppf);
	bureaucrat.signForm(*rrf);
	bureaucrat.executeForm(*rrf);
	bureaucrat.signForm(*scf);
	bureaucrat.executeForm(*scf);

	delete ppf;
	delete rrf;
	delete scf;

	return (0);
}
