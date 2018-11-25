#ifndef _GLOBAL_
#define _GLOBAL_

typedef struct 
{
	//wskaznik do zdefiniowanego typu( id sta³ej preprocesora - LISTINFO ) w global.h - m.pInfo;
	int nKey;
}ListInfo;

#define LISTINFO ListInfo

typedef int (__cdecl* cmpFoo )( const void*, const void* ) ;

int compare ( const void* a, const void* b );

#endif // !_GLOBAL_