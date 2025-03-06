/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:49/18 by kfreyer           #+#    #+#             */
/*   Updated: 2025/02/17 08:49:18 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1 ) {
        std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < argc; i++) {
            std::string str = argv[i];
            for (size_t j = 0; j < str.length(); j++)
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
        }
    }
    std::cout << std::endl;
    return 0;
}
