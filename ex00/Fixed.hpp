/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:15 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/19 16:22:22 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					fixedComma;
	static const int	fractionalBits = 8;
public:
	Fixed();
	Fixed(Fixed const & src);
	Fixed& operator=(Fixed const & src); 	
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif