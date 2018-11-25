#ifndef _LIST_
#define _LIST_

//module: list.h (module interface) list.cpp (module implementation)
#include "global.h"		//u¿ytkownik ma obowi¹zek zainkludowaæ to

typedef struct tagListItem
{
	//wskaznik do zdefiniowanego typu( id sta³ej preprocesora - LISTINFO ) w global.h - m.pInfo;
	LISTINFO* pInfo;
	tagListItem* m_pNext;
}ListItem;


/*
METODY W MODULE
*/


//zwraca wskaznik do szukanego elementu jesli on istnieje
ListItem* MakeEmptyList(); // ma zrobic pusty element na poczatku
void InsertFront( ListItem* pList, /*wsk do inf*/LISTINFO* pInfo );		//odpowiednik push()
void Insert( ListItem* pAfter, /*wsk do inf*/LISTINFO* pInfo ); //wstawia gdziekolwiek po elemencie pAfter
void Remove( ListItem* pAfter );		//BEZ przesukiwania listy
void RemoveFront( ListItem* pList );		//odpowiednik pop() usuwa szczytowy element z listy
ListItem* Front( ListItem* pList ); //zwraca wierzch listy
int isEmpty( ListItem* pList );
void FreeList( ListItem* pList );
ListItem* Find( ListItem* pList, const void* value, ListItem** pPrev, cmpFoo foo );
void SortList( ListItem* pList, cmpFoo foo );

//wskaznik do funkcji otrzymujacej dwa parametry const void* i zwracajacej int
//zrobic sortowanie poprzez przewiazywanie elementow
//¿eby mo¿naby³o dzia³aæ na tej liœcie jakby to by³ stos - kolejka LIFO

//osobny program do testowania funkcji w module!!
#endif // _LIST_