/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:11:18 by lucperei          #+#    #+#             */
/*   Updated: 2022/06/05 08:44:03 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *pos;
    char *line;
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    bytes_read = 1;
    while (!ft_strchr(line, '\n') && bytes_read > 0)
    {
        pos = ft_strchr(buffer, '\n');
        if (pos++)
        {
            attach(&line, buffer, pos - buffer);
            ft_strlcpy(buffer, pos, ft_strlen(pos) + 1);
            continue;
        }
        attach(&line, buffer, ft_strlen(buffer));
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        buffer[bytes_read] = '\0';
    }
    return (line);
}
