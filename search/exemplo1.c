/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemplo1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:18:33 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/17 19:52:12 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"

int main()
{
	char	*input;
	int		i = 0;

	while(i < 10)
	{
		input = readline("MiniSHELL: ");
		add_history(input);
		char *args[] = {"/usr/bin/ls", "-l", NULL};
		execve(args[0], args, NULL);
		printf("\n");
		i++;
	}
	return (0);
}
