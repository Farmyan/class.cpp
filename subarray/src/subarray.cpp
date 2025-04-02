bool SubArray(int* array, int size1, int* sub_array, int size2) 
{
    for (int index1 = 0; index1 <= size1 - size2; index1++) 
    {
        bool isSub = true;
        for (int index2 = 0; index2 < size2; index2++) 
        {
            if (*(array + index1 + index2) != *(sub_array + index2)) 
            {
                isSub = false;
                break;  
            }
        }
        if (isSub) return true;  
    }
    return false;
}