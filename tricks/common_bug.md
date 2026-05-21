# common bug reminders

- Check index boundaries before accessing vectors and arrays.
- Remember that `unordered_map::operator[]` creates a default value.
- Be careful with iterator invalidation after `vector` reallocation.
- Use `erase-remove` for deleting values from `vector`.
- Do not compare floating point values with exact equality when precision matters.
