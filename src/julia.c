/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:28:18 by adaifi            #+#    #+#             */
/*   Updated: 2022/04/13 22:35:50 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	itter(double cr, double ci, double max, t_data *fra)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = cr;
	zi = ci;
	i = 0;
	while (i <= max && (zr * zr + zi * zi) <= 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi - fra->zoom.corx;
		zi = 2 * zi * tmp + fra->zoom.cory;
		i++;
	}
	return (i);
}

void	draw_julia(t_data *fractol)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x < 500)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / 500;
		y = 0;
		while (y < 500)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini)
				* y / 500;
			i = itter(fractol->cr, fractol->ci, fractol->itter, fractol);
			if (i == fractol->itter)
				fractol->addr[(y * 500) + x] = 0x000000;
			else
				fractol->addr[(y * 500) + x] = 0xff0000 * i;
			y++;
		}
		x++;
	}
}

void	ft_julia(t_data *data)
{
	data->zoom.corx = 0.285;
	data->zoom.cory = 0.1;
	data->minr = -2;
	data->mini = -2;
	data->maxr = 2;
	data->maxi = 2;
	data->itter = 250;
	draw_julia(data);
}
