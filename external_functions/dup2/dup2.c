/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:05:00 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/10 19:30:54 by mdouglas         ###   ########.fr       */
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

int	main()
{
	int	fd1;
	int	fd2;

	fd1 = open("arquivo.txt", O_RDONLY);
	fd2 = dup2(fd1, 10);
	// fd1 and fd2 point to the same file
	close(fd1);
	// fd2 is still open and can be used to read from "arquivo.txt"
	close(fd2);
	return (0);
}