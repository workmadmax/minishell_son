/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:44:02 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/10 21:59:28 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Used to open a directory for reading.
	-man page-
	The opendir(3) function opens a directory stream corresponding to the directory name,
	and returns a pointer to the directory stream. The stream is positioned at the first
	entry in the directory.
*/

/*
	Usado pra abrir pasta. é possivel com ela percorrer recursivamente todo o conteúdo de um
	diretório, pode criar uma listagem dos arquivos e subdiretórios. e depois de aberto é possivel
	usar readdir para ler os arquivos e subdiretórios.
*/

// prototype DIR *opendir(const char *name);

#include <dirent.h>
#include <stdio.h>

int	main()
{
	DIR	*dir;
	
	dir = opendir("laele"); // open current directory
	if (dir == NULL)
	{
		perror("Error!");
		return (1);
	}
	printf("success open fd!\n");
	closedir(dir);
	return (0);
}
