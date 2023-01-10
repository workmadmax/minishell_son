/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:19:23 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/10 18:51:21 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Pipe is a form of inter-process communication. A pipe allows one process to
	write data over a communication "pipe" and another process to read that data.
	Pipe() is used to create a pipe and return two "FD's" tha can be used to read
	and write the pipe. The first descriptor file is used to read data from the
	pipe and the second to write data to the pipe.
*/

/*
	Nas minhas palavras pipe é a conexão entre dois processos de modo que a saída
	padrão de um processo se torne a entrada padrão de outro processo.
	Retorna zero(0) em caso de sucesso e -1 em caso de error.
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

// prototype int pipe(int fd[2]);

int	main()
{
	int		nbr_bytes;
	int		fd[2];
	char	buffer[42];
	pid_t	pid;
	
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		// child proc
		close(fd[0]);
		printf("I am the child process and I am writing to the pipe\n");
		write(fd[1], "Hello World!", 12);
		close(fd[1]);
	}
	else
	{
		// parent proc
		close(fd[1]);
		nbr_bytes = read(fd[0], buffer, sizeof(buffer));
		printf("I am the parent process and read %d bytes from the pipe: %s\n", nbr_bytes, buffer);
		close(fd[0]);
	}
}