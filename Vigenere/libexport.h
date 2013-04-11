/* 
 * @file libexport.h
 * @author Jarmo Erola
 * @version 0.1
 */

#ifndef LIBEXPORT_H
#define	LIBEXPORT_H

#ifndef __cplusplus
extern "C" {
#endif
    
#ifndef VIGENERE_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
    
#ifndef __cplusplus
}
#endif

#endif	/* LIBEXPORT_H */

