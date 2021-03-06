#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _DEBUG_

int main()
{
	srand( time( NULL ) );

	LISTINFO *tab = ( LISTINFO * )calloc( 100, sizeof( LISTINFO ) );
	LISTINFO *v = tab;
	ListItem* lista = MakeEmptyList();
	for ( int i = 0; i < 100; i++ )
	{
		v->nKey = i;
		InsertFront( lista, v++ );
	}
#ifdef _DEBUG_
	ListItem* pIt = lista;
	while ( pIt = pIt->m_pNext )
		printf( "%d\t", pIt->pInfo->nKey );
	printf( "\n" );
#endif // DEBUG
	SortList( lista, compare );
	ListItem* pV = lista;
	printf( "\n%d\t%d\n", Find( lista, tab + 11, &pV, compare )->pInfo->nKey, pV->m_pNext->pInfo->nKey );
	while ( !isEmpty( lista ) )
	{
#ifdef _DEBUG_
		printf( "%d\t", Front( lista )->pInfo->nKey );
#endif // DEBUG
		RemoveFront( lista );
	}
	pIt = NULL;

	FreeList( lista );
	return 0;
}

//=================================================
int compare( const void* a, const void* b )
{
	if ( ( ( ListInfo* )a )->nKey < ( ( ListInfo* )b )->nKey )
		return -1;
	if ( ( ( ListInfo* )a )->nKey == ( ( ListInfo* )b )->nKey )
		return 0;
	return 1;
}