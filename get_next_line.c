/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:40:39 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/09/30 19:10:42 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	/* This function reads the file descriptor and checks if there's a
	 * line break ('\n'), if it doesn't find a line break the function will
	 * return everything read. It reads bytes_read and stores everything found
	 * in -variable- temp. */
char	*ft_read_and_join(int fd, char *bytes_read, char *temp)
{
	char	*aux_temp;
	int		verification;

	verification = 1;
	while (verification)
	{
		verification = read (fd, bytes_read, BUFFER_SIZE);
		if (verification <= 0 && temp[0] == 0)
		{
			free(temp);
			free(bytes_read);
			return (NULL);
		}
		bytes_read[verification] = '\0';
		aux_temp = temp;
		temp = ft_strjoin(temp, bytes_read);
		if (!temp)
			return (NULL);
		free(aux_temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	return (temp);
}

	/*This funcion will allocate suficient memory for BUFFER_SIZE + '\0' and
	 * store it in bytes_read. Also does NULL verification. */
char	*ft_alloc_for_bytes(void)
{
	char		*bytes_read;

	bytes_read = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!bytes_read)
	{
		free(bytes_read);
		return (NULL);
	}
	return (bytes_read);
}

	/* This function will return the line read. It allocates memory (plus
	 * +1 for '\0') and stores the content of temp in line. Also, will free
	 * the variable storing bytes_read and temp itself to avoid memory
	 * garbage. */
char	*ft_line_and_free(char *temp, char *bytes_read, int i)
{
	char	*line;

	line = ft_substr(temp, 0, i + 1);
	free(temp);
	free(bytes_read);
	return (line);
}

	/* This is the main function of the project. We start by applying
	 * ft_alloc_for_bytes to have mem space to store the bytes read by
	 * BUFFER_SIZE. Then we do the malloc verification and backup verification,
	 * if there is something in backup we will then store the content in temp.
	 * Else, we will apply calloc to temp because C language only recognizes a
	 * null-terminated string. We will then use ft_read_and_join to read and
	 * concatenate temp and bytes_read. We initialize the index (i) and
	 * increment the index until '\n' and '\0' is found. The backup will keep
	 * the rest (what is read after '\n') of bytes_read, we apply ft_substr
	 * with size_t len -1 because to burst to the maximum positive so it
	 * creates enough space to read the whole line (regardless of gigantic line)
	 * If the first char of backup is '\0', we free backup and apply zero to
	 * it (as a veriable needs to be initialized). Finally, we return line
	 * through ft_line_and_free.*/
char	*get_next_line(int fd)
{
	static char	*backup;
	char		*bytes_read;
	char		*temp;
	size_t		i;

	bytes_read = ft_alloc_for_bytes();
	if (!bytes_read)
		return (NULL);
	if (backup)
		temp = backup;
	else
		temp = ft_calloc(1, sizeof(char));
	temp = ft_read_and_join(fd, bytes_read, temp);
	if (!temp || !bytes_read)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	backup = ft_substr(temp, i + 1, -1);
	if (*backup == '\0')
	{
		free(backup);
		backup = 0;
	}
	return (ft_line_and_free(temp, bytes_read, i));
}
