/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);  //cuenta cantidad de elementos que tengo en la lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//agrega un elemento a la lista
void* ll_get(LinkedList* this, int index); // devuelve un dato
int ll_set(LinkedList* this, int index,void* pElement);  // reemplaza un elemento por otro  ,indice q quiero reemplar y el elemento por el q quiero reemplazar
int ll_remove(LinkedList* this,int index);	//remueve un elemento
int ll_clear(LinkedList* this); //limpia la lista
int ll_deleteLinkedList(LinkedList* this); //elimina la lista de memoria
int ll_indexOf(LinkedList* this, void* pElement); //duelve el indice de un elemento específico
int ll_isEmpty(LinkedList* this); //estado del indice
int ll_push(LinkedList* this, int index, void* pElement); // agrega un elemento en el indice especificado
void* ll_pop(LinkedList* this,int index); //remueve el ultimo elemento
int ll_contains(LinkedList* this, void* pElement); //pregunta si algo existe o no dentro de un elemento
int ll_containsAll(LinkedList* this,LinkedList* this2); //para verificar si una lista esta en otra lista
LinkedList* ll_subList(LinkedList* this,int from,int to); //te hace una copia de la lista desde un lugar hasta el otro
LinkedList* ll_clone(LinkedList* this);//lo mimso  de arriba pero toda la lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //ordena
