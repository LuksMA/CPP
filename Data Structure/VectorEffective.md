1. Avoid unnecessary reallocate and copy cycles by reserving the size of vector ahead of time.      
testVector2.reserve(10000);    
FillVector(testVector2);     
cout << "Time to Fill Vector With Reservation:" << sw.ElapsedUs() << endl;      
2. Use shrink_to_fit() to release memory consumed by the vector – clear() or erase() does not release memory.     
testVector1.shrink_to_fit();     
3. When filling up or copying into a vector, prefer assignment over insert() or push_back().     
4. While iterating through elements in a std::vector, avoid the std::vector::at() function.      
5. Try to avoid inserting an element in front of the vector.
6. Prefer emplace_back() instead of push_back() while inserting into a vector.
