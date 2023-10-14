/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:08:18 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/14 16:23:36 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureucrat();
		Bureucrat(std::string const &name, int grade);
		Bureucrat(const Bureucrat &other);
		~Bureucrat();
		Bureucrat &operator=(const Bureucrat &other);

		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureucrat &bureucrat);

#endif