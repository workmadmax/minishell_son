/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:20:06 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/10 21:33:07 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The dup function takes an existing file descriptor as an parameter and creates
	a double copy of the descriptor. The new copy has a different descriptor number
	than the original and points to the same file or device. The function returns the
	new double copy descriptor number, or -1 on error.
*/

/*
	Dup serve para copiar o 'fd' ela pega o descritor não utilizado de menor número para
	o novo descritor. preferivel usar dup2() já que se pode escolher o 'fd' a ser copiado.
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	new_fd;

	// open file for reading
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error when opening file");
		return (1);
	}
	// creating a copy fd
	new_fd = dup(fd);
	if (new_fd == -1)
	{
		perror("Error create double copy");
		return (1);
	}
	// fd and newfd point to the same file
	printf("Fd original: %d\n", fd);
	printf("Fd copy: %d\n", new_fd);
	//closing fd
	close(fd);
	close(new_fd);
	return (0);
}