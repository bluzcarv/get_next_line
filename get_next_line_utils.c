/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:45:59 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/09/30 16:14:58 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	/* Returns a pointer to the first occurrence of character in the C string
	 * str. The terminating null-character is considered part of the C string.
	 * Therefore, it can also be located in order to retrieve a pointer to the
	 * end of a string.*/
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

	/* Strlen measures the size of the string (s). It is done through a while
	 * loop with an [i] counter. */
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	sub[len] = 0;
	while (len--)
		sub[len] = s[len + start];
	return (sub);
}

	/* Strjoin allocates the memory and returns a new string terminated by a
	 * '\0' which is the result of a concatenation of the parameters s1 and s2
	 * If fails, return NULL. We create 2 counters that will go through s1 and
	 *  s2, and third will be a string that we will apply malloc and return the
	 * concatenation. The malloc function with a combination of using our
	 * previously made ft_strlen functions. We use the ft_strlen function
	 * on both the parameter strings to figure out the full length for a
	 * concatenation and we add 1 to this added length to make sure we can
	 * add a terminating '\0'. If the allocation failed we will return NULL.
	 * We start with s1 with a standard string loop, run through the length of
	 * s1 placing each character in s1 into str.The next loop is exactly the
	 * same as the previous loop except you must take note of our use of the
	 * counter variable j. j is currently equal to 0 at this point in our
	 * function. For our new string str we set the index equal to the previous
	 * counter i plus our new counter j. This keeps us at the index position we
	 * ended on when our previous loop finished since it will be the value i
	 * was at the end of the previous loop plus j's current value of 0. We use
	 * j to set the index of our string s2 and let the loop go until we have
	 * reached the end of s2.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				i1;
	int				i2;

	i1 = 0;
	i2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i1] != '\0')
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		str[i1 + i2] = s2[i2];
		i2++;
	}
	str[i1 + i2] = '\0';
	return (str);
}

	/*Calloc uses malloc to allocate memory space and then bzero to attribute
	 * value 0 to the new incitialized mem spaces. Note: using a void pointer
	 * in malloc allow us to handle any * type of variable value. It returns
	 * a pointer to the allocated memory. count = an array of elements;
	 * size = elements number of bytes.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
