/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:05:00 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/10 21:40:39 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The dup2() system call is similar to dup() but the basic difference between
	them is that instead of using the lowest-numbered unused file descriptor,
	it uses the descriptor number specified by the user.
*/

/*
	Similar a função dup(), mas ela permite especificar qual será o file descriptor
	cópia e, se desejar, fechar o fd original. Ela retorna o novo file descriptor.
	Usei ela no pipex.
*/

// prototype int dup2(int oldfd, int newfd)

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error! when opening file");
		return (1);
	}
	if (dup2(fd, 6) == -1)
	{
		perror("Error! creating copy");
		return (1);
	}
	printf("Fd original: %d\n", fd);
	printf("Fd copy: %d\n", 6);
	close(fd);
	close(9);
	return (0);
}
