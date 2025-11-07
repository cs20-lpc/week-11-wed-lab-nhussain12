template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int i = 0;
    int probes = 0;

    while (i < M) {
        int index = probeIndex(key, i);
        probes++;

        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;
            N++;
            return probes;
        }
        i++;
    }
    return probes;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    int i = 0;
    int probes = 0;

    while (i < M) {
        int index = probeIndex(key, i);
        probes++;

        if (!occupied[index]) {
            return {false, probes};
        }
        if (occupied[index] && table[index] == key) {
            return {true, probes};
        }
        i++;
    }
    return {false, probes};
}
