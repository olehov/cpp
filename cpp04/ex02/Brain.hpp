/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:11:56 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 13:31:54 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN__H__
#define __BRAIN__H__

#include <iostream>
#include <string>

class Brain
{
private:
	const static int _ideas_len = 100;
	std::string _ideas[_ideas_len];
public:
	Brain();
	Brain(const Brain& other);

	Brain& operator=(const Brain& other);

	std::string getIdea(int index) const;
	int	getIdeasLen() const;
	void setIdea(int index, const std::string& idea);

	~Brain();
};

#endif  //!__BRAIN__H__