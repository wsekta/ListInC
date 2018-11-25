#include "List.h"
#include <stdlib.h>



//=================================================
ListItem* MakeEmptyList()
{
	//return ( ListItem* )calloc( 1, sizeof( ListItem ) );
	ListItem* list = ( ListItem* )calloc( 1, sizeof( ListItem ) );
	if ( !list )
	{
		perror( "Insert error: brak pamieci" );
	}
	return list;
}



//=================================================
void Insert( ListItem* pAfter, LISTINFO* pInfo )
{
	ListItem* pPom = pAfter->m_pNext;
	pAfter->m_pNext = ( ListItem* )calloc( 1, sizeof( ListItem ) );
	if ( !pAfter->m_pNext )
	{
		perror( "Insert error: brak pamieci" );
		return;
	}
	pAfter->m_pNext->pInfo = pInfo;
	pAfter->m_pNext->m_pNext = pPom;
}



//=================================================
void InsertFront( ListItem* pList, LISTINFO* pInfo )
{
	Insert( pList, pInfo );
}



//=================================================
void Remove( ListItem* pAfter )
{
	if ( pAfter->m_pNext )
	{
		ListItem* v = pAfter->m_pNext;
		pAfter->m_pNext = v->m_pNext;
		free( v );
	}
	else
		perror( "Remove: podano zly wskaznik" );
}



//=================================================
void RemoveFront( ListItem* pList )
{
	Remove( pList );
}


//=================================================
ListItem* Front( ListItem* pList )
{
	if ( isEmpty( pList ) )
		perror( "Front: lista jest pusta" );
	return pList->m_pNext;
}



//=================================================
int isEmpty( ListItem* pList )
{
	return !( pList->m_pNext );
}



//=================================================
void FreeList( ListItem* pList )
{
	while ( !isEmpty( pList ) )
		RemoveFront( pList );
}



//=================================================
ListItem* Find( ListItem* pList, const void* value, ListItem** pPrev, cmpFoo foo )
{
	*pPrev = pList;
	while ( ( *pPrev )->m_pNext )
	{
		if ( !foo( value, ( const void* )( ( *pPrev )->m_pNext->pInfo ) ) )
			return ( *pPrev )->m_pNext;
		*pPrev = ( *pPrev )->m_pNext;
	}
	return *pPrev = NULL;
}	//Onderka mia³ w¹ty, ale zaliczy³



//=================================================
void SortList( ListItem* pList, cmpFoo foo )
{
	ListItem* pFirst = pList;
	while ( pFirst->m_pNext )
	{
		ListItem* pMin = pFirst;
		ListItem* pIter = pFirst->m_pNext;
		while ( pIter->m_pNext )
		{
			if ( foo( ( const void* )( pMin->m_pNext->pInfo ), ( const void* )( pIter->m_pNext->pInfo ) ) == 1 )
				pMin = pIter;
			pIter = pIter->m_pNext;
		}

		if ( pMin != pFirst )
		{
			pIter = pFirst->m_pNext;
			pFirst->m_pNext = pMin->m_pNext;
			pMin->m_pNext = pMin->m_pNext->m_pNext;
			pFirst->m_pNext->m_pNext = pIter;
		}

		pFirst = pFirst->m_pNext;
	}
}