## LRU cache implementation
- The algorithm is more a fifo than LRU but for simplification concerns we use fifo
### inputs 
- number of commands
- capacity of the map(how many nodes in the cache)
- commands started wether with set or get
- if the command starts with set, then the next two inputs are the key and the value
- if the command starts with get, it is followed by a key(if it exists in the cache it returns it otherwise it returns -1)