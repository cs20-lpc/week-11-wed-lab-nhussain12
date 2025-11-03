template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int i = 0;
    while (i < M) {
        int index = probeIndex(key, i);
        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;
            N++;
            return index;
        }
        i++;
    }
    throw string("insert: error, hash table overflow");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    int i = 0;
    while (i < M) {
        int index = probeIndex(key, i);
        if (!occupied[index]) {
            return {false, -1}; 
        }
        if (table[index] == key) {
            return {true, index}; 
        }
        i++;
    }
    return {false, -1};
}
