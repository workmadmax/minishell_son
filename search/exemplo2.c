/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemplo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:51:12 by mdouglas          #+#    #+#             */
/*   Updated: 2023/01/17 20:13:34 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"

int main()
{
	int		i = 0;
    int     arg_count;
    char    *token;
    char    *args[100];
	char	*input;
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
            execvp(args[0], args);
            exit (0);
        }
        else
            wait(NULL);
    }
}
