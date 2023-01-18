/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemplo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:16:31 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/17 22:54:16 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    char    *pos;

    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    pos = str;
    while (*s1)
        *str++ = *s1++;
    while (*s2)
        *str++ = *s2++;
    *str = '\0';
    return (pos);
}

char	*find_path(char *ptr, char *cmd)
{
	char	*path;

	path = ft_strjoin(ptr, cmd);
	free(ptr);
	return (path);
}


int main()
{
    int     arg_count;
    char    *token;
    char    **args[100];
	char	*input;
    char    *path;
    char    *path_token;
    char    cmd[100];
    pid_t   pid;
    
    while (1)
    {
        input = readline("MiniSHELL: ");
        add_history(input);
        arg_count = 0;
        token = strtok(input, " ");
        while (token != NULL)
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;
        if (strcmp(args[0], "exit") == 0)
            break;
        pid = fork();
        if (pid == 0)
        {
            path = getenv("PATH");
            path_token = strtok(path, ":");
            while (path_token != NULL)
            {
                strcpy(cmd, path_token);
                strcat(cmd, "/");
                strcat(cmd, args[0]);
                if (access(cmd, F_OK) == 0)
                {
                    execve(cmd, &args[0], NULL);
                    exit (0);
                }
                path_token = strtok(NULL, ":");
            }
            printf("Command not found\n");
            exit(1);
        }
        else
            wait(NULL);
    }
}
