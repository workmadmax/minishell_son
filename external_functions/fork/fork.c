/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:53:04 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/10 18:23:00 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Is used on Unix-based operating systems such as Linux and MacOs to create new
	process from the parent process, including all environment variables, file   
	descriptors, and so on. The new process is called the child process and the  
	original process is called the parent.
*/

/*
	Nas minhas palavras fork() vai "clonar" o processo, vão existir dois processos
	que "rodaram" simultaneamente cada um executando o corpo da(s) sua(s) instruções.
	Retorna zero(0) para o proceso filho, positivo(id do filho) para o processo pai, e -1 em caso
	de error.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		printf("I am the child process ... (pid %d)\n", getpid());
	else
		printf("I am the parent process (pid %d)\n", getpid());
	return (0);
}
