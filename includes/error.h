/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:20:08 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/07 13:04:29 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define TAB_FILE_NAME_ERROR "ERROR: Incorrect filename or extension."
# define TAB_TKN_ALLOCATION_ERROR "ERROR: Failed to allocate memory for token."
# define TAB_TOKEN_GENERATION_ERROR "ERROR: Unknown lexical unit."
# define TAB_OPEN_ERROR "ERROR: Could not open file for some reason."
# define TAB_FILE_STORAGE_ERROR "ERROR: Failed to allocate memory for file."
# define TAB_PRINTING_ERROR "ERROR: Failed to allocate memory for verbose."
# define TAB_HASHTABLE_ERROR "ERROR: Failed to allocate memory label hashing."
# define TAB_NAME_MISS "ERROR: .name missing in header."
# define TAB_COMMENT_MISS "ERROR: .comment missing in header."
# define TAB_HDRFIEL "ERROR: Both .comment and .name must have a valid fields."
# define TAB_HDRNAME "ERROR: .name must be <= to PROG_NAME_LENGTH constant."
# define TAB_HDRCOMM "ERROR: .comment must be <= to COMMENT_LENGTH constant."
# define TAB_SIZE "ERROR: Code size must be <= to CHAMP_MAX_SIZE constant."
# define TAB_HDR_MERROR "ERROR: Failed to allocate memory for header encoder."
# define TAB_EXE_MERROR "ERROR: Failed to allocate memory for code encoder."
# define TAB_ENCOD_FIELD "ERROR: Value too big for argument byte size."
# define TAB_LITCONV "ERROR: Failed to convert a literal number to hexa base."
# define TAB_OPEN_DEST "ERROR: Failed to create output file."
# define TAB_WRITE_ERR "ERROR: Failed to write output file."
#endif
