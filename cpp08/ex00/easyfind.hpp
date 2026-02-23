/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:08:38 by ogrativ           #+#    #+#             */
/*   Updated: 2026/02/20 16:14:17 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
	{
		throw std::runtime_error("Value not found in container");
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int val)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
	{
		throw std::runtime_error("Value not found in container");
	}
	return it;
}

#endif //! EASYFIND_HPP