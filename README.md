# Lista Enlazada Simple en C

Implementación desde cero de una lista enlazada simple, con manejo manual de memoria (`malloc`/`free`) y cubriendo todos los casos borde.

## Operaciones

| Función | Complejidad | Descripción |
|---|---|---|
| `insert(Node **top, int value)` | O(1) | Inserta al inicio |
| `print(Node *top)` | O(n) | Recorre e imprime |
| `pop(Node **top)` | O(1) | Elimina el primero |
| `delete_last(Node **top)` | O(n) | Elimina el último |
| `delete(Node **top, int value)` | O(n) | Elimina por valor |
| `search(Node *top, int value)` | O(n) | Devuelve el nodo o `NULL` |
| `update(Node *top, int old, int new)` | O(n) | Cambia un valor |
| `free_list(Node **top)` | O(n) | Libera todos los nodos |

## Compilar y ejecutar

```bash
gcc -fsanitize=address main.c -o main && ./main
```
