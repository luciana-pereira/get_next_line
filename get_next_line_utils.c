/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:11:14 by lucperei          #+#    #+#             */
/*   Updated: 2022/06/05 06:53:34 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
    if (s != NULL)
    {
        while (*s && *s != c)
        {
            s++;
        }
        if (*s == c)
        {
            return ((char *)s);
        }
    }
    return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s && *s)
    {
        s++;
        i++;
    }
    return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t len;

    len = ft_strlen(src);
    if (size--)
    {
        while (size-- && *src)
        {
            *dst = *src;
            dst++;
            src++;
        }
        *dst = '\0';
    }
    return (len);
}

void attach(char **s1, const char *s2, size_t size)
{
    char *temp;
    size_t len;

    temp = NULL;
    if (s2[0])
    {
        len = ft_strlen(*s1);
        temp = (char *)malloc((len + size + 1) * sizeof(char));
        if (temp != NULL)
        {
            ft_strlcpy(temp, *s1, len + 1);
            ft_strlcpy(temp + len, s2, size + 1);
        }
    }
    free(*s1);
    *s1 = temp;
}
