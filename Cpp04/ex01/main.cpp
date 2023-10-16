/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:08:12 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/16 14:44:02 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main(void)
{
	Bureucrat bureucrat("Prot", 150);
	Bureucrat bureucrat2("Top", 1);
	Form form("Form", 1, 1);
	Form form2("Form2", 149, 149);

	try
	{
		Form form3("Form3", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	bureucrat2.signForm(form);
	std::cout << form;
	bureucrat.signForm(form2);
	std::cout << form2;
	try
	{
		bureucrat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	bureucrat.signForm(form2);
	std::cout << form2;
}
