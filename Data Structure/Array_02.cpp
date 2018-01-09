int main()
{
    int * a[3];
//also possible: int ** array =  new int*[3]; but don't forget to delete it afterwards.
    int sub1[3] = {1,2,3};
    int sub2[2] = {1,2};
    int sub3[4] = {1,2,3,4};
    a[0] = sub1;
    a[1] = sub2;
    a[2] = sub3;
}
