template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    for (int i = 0; i < this->M; ++i) {
        int index = probeIndex(key, i);

        if (!this->occupied[index]) {
            this->table[index] = key;
            this->occupied[index] = true;
            this->N++;
            return i + 1;
        }

        if (this->table[index] == key) {
            return i + 1;
        }
    }

    throw string("Hash table overflow");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    for (int i = 0; i < this->M; ++i) {
        int index = probeIndex(key, i);

        if (!this->occupied[index]) {
            return {false, i + 1};
        }

        if (this->table[index] == key) {
            return {true, i + 1};
        }
    }
    return {false, this->M};
}
