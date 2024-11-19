/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:30:36 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/19 11:10:30 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			tot;
	void			*ran;
	unsigned char	*str;

	tot = size * nmemb;
	ran = malloc(tot);
	if (!ran)
		return (NULL);
	str = ran;
	while (tot != 0)
	{
		*str = 0;
		str++;
		tot--;
	}
	return (ran);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*cup_buffer;

	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(cup_buffer), NULL);
	return (cup_buffer);
}
/* char *append_buffer(char *basin_buffer, char *read_buffer)
{
 char *temp;

 temp = ft_strjoin(basin_buffer, read_buffer);
 free(basin_buffer);
 return (temp);
}

char *read_from_file(char *basin_buffer, int fd)
{
 char *cup_buffer;
 int  bytes_read;

 cup_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
 if (!cup_buffer)
  return (NULL);
 bytes_read = 1;
 while (bytes_read > 0)
 {
  bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
  if (bytes_read == -1)
   return (free(cup_buffer), NULL);
  cup_buffer[bytes_read] = '\0';
  basin_buffer = append_buffer(basin_buffer, cup_buffer);
  if (ft_strchr(basin_buffer, '\n'))
   break ;
 }
 free (cup_buffer);
 return (basin_buffer);
}

char *get_next_line(int fd)
{
 static char *basin_buffer;
 char  *line;

 if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0) 
  return (NULL);
 if (!basin_buffer)
  basin_buffer = ft_calloc(1, sizeof (char)); 
 if (!ft_strchr(basin_buffer, '\n'))
  basin_buffer = read_from_file(basin_buffer, fd);
 if (!basin_buffer)
  return (free(basin_buffer), NULL);
 //line = extract_line(basin_buffer);
 //basin_buffer = obtain_remaining(basin_buffer);
 return (line);
} */

/* #include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int		fd;
	char	*next_line;
	
	fd = open("get_next_line.text", O_RDONLY);
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = NULL;
		next_line = get_next_line(fd);
	}
	free(next_line);
	next_line = NULL;
	close(fd);
	return (0);
} */