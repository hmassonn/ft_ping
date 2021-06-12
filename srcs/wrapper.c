/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:05:58 by hmassonn          #+#    #+#             */
/*   Updated: 2021/06/12 19:26:56 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ping.h"

const char      *wrap_inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
    const char *result;

    if ((int)ft_strlen(dst) < INET_ADDRSTRLEN && (int)ft_strlen(dst) < INET6_ADDRSTRLEN)
    {
        printf("dst too short %d at least %d or ipv6 %d", (int)ft_strlen(dst), INET_ADDRSTRLEN, INET6_ADDRSTRLEN);
    }
    if ((result = inet_ntop(af, src, dst, size)) == NULL)
    {
        printf("error in inet_ntop maybe dst is null ?");
    }
    return result;
}
