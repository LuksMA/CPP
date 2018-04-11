* Best way to extract a **subvector** from a vector
```
vector<T>::const_iterator first = myVec.begin() + 100000;
vector<T>::const_iterator last = myVec.begin() + 101000;
vector<T> newVec(first, last);
```
It's an O(N) operation to construct the new vector, but there isn't really a better way.
