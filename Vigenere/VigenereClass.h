/* 
 * @file VigenereClass.h
 * @author Jarmo Erola
 * @version 0.1
 */

#ifndef VIGENERECLASS_H
#define	VIGENERECLASS_H

#include <stdio.h>
#include <string>
#include "libexport.h"

using namespace std;

class DLL_EXPORT VigenereClass {
private:
    string key;
public:
    VigenereClass() {}
    virtual ~VigenereClass() {}
    
    string encrypt(string txt);
    string decrypt(string txt);
};

#endif	/* SAMPLECLASS_H */

