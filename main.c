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

bool insert(Node **top, int value) { // O(1)
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = *top;
  *top = new_node;
  return true;
}

void print(Node *top) { // O(n)
  if (!top) {
    printf("Lista vacía\n");
    return;
  }
  while (top) {
    printf("%d ", top->value);
    top = top->next;
  }
  printf("\n");
  return;
}

bool pop(Node **top) { // O(1)
  if (*top) {
    Node *deleted = (*top);
    *top = deleted->next;
    free(deleted);
    return true;
  }
  return false;
}

bool delete_last(Node **top) { // O(n)
  if (!*top)
    return false;
  if ((*top)->next == NULL) {
    free(*top);
    *top = NULL;
    return true;
  }
  Node *prev = *top;
  Node *aux = (*top)->next;
  while (aux) {
    if ((aux)->next == NULL) {
      free(aux);
      prev->next = NULL;
      return true;
    }
    prev = prev->next;
    aux = aux->next;
  }
  return false;
}

bool delete(Node **top, int value) { // O(n)
  if (!*top)
    return false;
  if ((*top)->value == value) {
    Node *old = *top;
    *top = (*top)->next;
    free(old);
    return true;
  }
  Node *prev = *top;
  Node *cur = (*top)->next;
  while (cur) {
    if (cur->value == value) {
      prev->next = cur->next;
      free(cur);
      return true;
    }
    prev = prev->next;
    cur = cur->next;
  }
  return false;
}

Node *search(Node *top, int value) {
  Node *cur = top;
  while (cur) {
    if (cur->value == value) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

int length(Node *top) {
  int counter = 0;
  while (top) {
    counter++;
    top = top->next;
  }
  return counter;
}

bool update(Node *top, int old_value, int new_value) {
  Node *cur = top;
  while (cur) {
    if (cur->value == old_value) {
      cur->value = new_value;
      return true;
    }
    cur = cur->next;
  }
  return false;
}

bool free_list(Node **top){
  while (*top) {
    Node* old = *top;
    *top = (*top)->next;
    free(old);
  }
  return false;
}

int main() {
  Node *top = NULL;

  insert(&top, 3);
  insert(&top, 8);
  insert(&top, 9);

  printf("Longitud: %d\n", length(top));
  print(top);

  Node *resultado = search(top, 3);
  if (resultado) {
    printf("%d\n", resultado->value);
  } else {
    printf("No hay resultado\n");
  }

  update(top, 3, 4);

  delete(&top, 9);
  print(top);
  delete(&top, 3);
  print(top);

  free_list(&top);
  free_list(&top);

  print(top);

  return 0;
}
