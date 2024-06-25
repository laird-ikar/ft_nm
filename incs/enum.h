/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:46:25 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/05 10:46:41 by stage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_flag_mode {
	ACTIVE = 1
};

typedef enum e_error_codes {
	SUCCESS,
	INVALID_FLAG,
	FAILED_ALLOCATION,
}	t_error_code;

#endif
