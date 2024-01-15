/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:49:44 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/10 16:37:03 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>

/* Mandatory part */
int		ft_putadd(unsigned long int n, int fd );
void		ft_putuint(unsigned int nb, int fd, int *count);
int		ft_puthexa(int nbr, int fd ,char c);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd, int *count);

#endif
