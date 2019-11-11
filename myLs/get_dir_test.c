/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:21:45 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/11 16:20:26 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			get_dir(char w_path[PATH_MAX], char *name, t_data **data)
{
	char		path[PATH_MAX];
	t_stat		stat;

	if (!(get_path(w_path, name, path)))
		puterr_ls(name, ERR);
	if (lstat(path, &stat) == 0)
	{
		if (!*data)
			*data = new_data(w_path, name, &stat);
		else
		{
			while ()
		}
	}
	else
		puterr_ls(path, ERR);
	return (0);
}
