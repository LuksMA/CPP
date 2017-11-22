1. Avoid unnecessary reallocate and copy cycles by reserving the size of vector ahead of time.      
testVector2.reserve(10000);    
FillVector(testVector2);     
cout << "Time to Fill Vector With Reservation:" << sw.ElapsedUs() << endl;      
