/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:20:47 by mtoia             #+#    #+#             */
/*   Updated: 2023/10/23 12:23:08 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        //*data*//
    public:
        Intern();
        Intern(Intern &other);
        ~Intern();
        AForm *makeForm(std::string formName, std::string target);
}

#endif