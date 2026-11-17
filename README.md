# Lista Enlazada Simple en C

Implementación desde cero de una lista enlazada simple, con manejo manual de memoria (`malloc`/`free`) y cubriendo todos los casos borde.

## Operaciones

| Función | Complejidad | Descripción |
|---|---|---|
| `insert(List *list, int value)` | O(1) | Inserta al inicio |
| `print(List list)` | O(n) | Recorre e imprime |
| `pop(List *list)` | O(1) | Elimina el primero |
| `delete_last(List *list)` | O(n) | Elimina el último |
| `delete(List *list, int value)` | O(n) | Elimina por valor |
| `search(List list, int value)` | O(n) | Devuelve el nodo o `NULL` |
| `update(List list, int old, int new)` | O(n) | Cambia un valor |
| `free_list(List *list)` | O(n) | Libera todos los nodos |

## Compilar y ejecutar

```bash
gcc -fsanitize=address main.c -o main && ./main
```
