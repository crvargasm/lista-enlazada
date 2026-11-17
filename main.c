/*
 * lista-enlazada-c - Implementación de una lista enlazada simple
 * Copyright (C) 2026 Cristian Camilo Vargas Morales
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct List {
  Node *top;
  int size;
} List;

bool insert(List *list, int value) { // O(1)
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = list->top;
  list->top = new_node;
  list->size += 1;
  return true;
}

void print(List list) { // O(n)
  Node *aux = list.top;
  if (!aux) {
    printf("Empty list\n");
    return;
  }
  while (aux) {
    printf("%d ", aux->value);
    aux = aux->next;
  }
  printf("\n");
  return;
}

bool pop(List *list) { // O(1)
  if (list->top) {
    Node *deleted = (list->top);
    list->top = deleted->next;
    free(deleted);
    list->size -= 1;
    return true;
  }
  return false;
}

bool delete_last(List *list) { // O(n)
  Node *head = list->top;
  if (!head)
    return false;
  if (head->next == NULL) {
    free(head);
    list->top = NULL;
    list->size -= 1;
    return true;
  }
  Node *prev = head;
  Node *aux = head->next;
  while (aux) {
    if ((aux)->next == NULL) {
      free(aux);
      prev->next = NULL;
      list->size -= 1;
      return true;
    }
    prev = prev->next;
    aux = aux->next;
  }
  return false;
}

bool delete(List *list, int value) { // O(n)
  Node *aux = list->top;
  if (!aux)
    return false;
  if (aux->value == value) {
    Node *old = aux;
    list->top = aux->next;
    free(old);
    list->size -= 1;
    return true;
  }
  Node *prev = aux;
  Node *cur = aux->next;
  while (cur) {
    if (cur->value == value) {
      prev->next = cur->next;
      free(cur);
      list->size -= 1;
      return true;
    }
    prev = prev->next;
    cur = cur->next;
  }
  return false;
}

Node *search(List list, int value) {
  Node *cur = list.top;
  while (cur) {
    if (cur->value == value) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

int length(List list) {
  int counter = 0;
  Node *aux = list.top;
  while (aux) {
    counter++;
    aux = aux->next;
  }
  return counter;
}

bool update(List list, int old_value, int new_value) {
  Node *cur = list.top;
  while (cur) {
    if (cur->value == old_value) {
      cur->value = new_value;
      return true;
    }
    cur = cur->next;
  }
  return false;
}

bool free_list(List *list) {
  while (list->top) {
    Node *old = list->top;
    list->top = list->top->next;
    free(old);
  }
  list->size = 0;
  return true;
}

int main() {
  List *mi_lista = malloc(sizeof(List));

  insert(mi_lista, 3);
  insert(mi_lista, 8);
  insert(mi_lista, 9);
  print(*mi_lista);

  delete_last(mi_lista);
  pop(mi_lista);

  print(*mi_lista);
  printf("Longitud function: %d\n", length(*mi_lista));
  printf("Longitud value: %d\n", mi_lista->size);

  Node *resultado = search(*mi_lista, 4);
  if (resultado) {
    printf("%d\n", resultado->value);
  } else {
    printf("No hay resultado\n");
  }

  update(*mi_lista, 2, 4);

  print(*mi_lista);
  delete(mi_lista, 2);
  print(*mi_lista);

  free_list(mi_lista);
  print(*mi_lista);

  return 0;
}
